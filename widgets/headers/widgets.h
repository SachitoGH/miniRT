/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   widgets.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzapata <dzapata@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 10:05:17 by dzapata           #+#    #+#             */
/*   Updated: 2025/04/13 19:58:26 by dzapata          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * Widgets.h
 * ---------------------------------------------------------------------------
 * 
 * Description:
 * This is a small library to simplify the drawing of some basic IU elements
 * using the MiniLibX.
 * 
 * Every widget is composed for basic elements to customise the drawing
 * of each widget, such as color, position and size.
 * 
 * ---------------------------------------------------------------------------
 * 
 * Requirements:
 * 
 * - The MiniLibX.
 * 
 * ---------------------------------------------------------------------------
 * 
 * Available widgets:
 * 
 * - Buttons
 * - Labels
 * - Spinners (Button + Label + Button)
 * 
 * The library also contains:
 * 
 * - Images
 * - Window
 * 
 * ---------------------------------------------------------------------------
 * 
 * Usage:
 * 
 * 1.	The widgets.h header must be included for access to all widgets and
 * 		Required functions
 * 
 * 2.	Every widget must be previously allocated.
 * 
 * 3.	Every widget has its own initializer function who sets the default
 * 		parameters and defaults functions required to be drawed.
 * 
 * Example:
 * 
 * @code
 * t_button	b;
 * 
 * btn_init(&b, 10, 10, "B_Text");
 * @endcode
 * 
 * 4.	Every widget can be drawed invoking their corresponding drawing
 * 		function. This can be made either using the default function contained
 * 		in the labrary or calling the draw function of the widget struct
 * 		contained by all widgets.
 * 
 * Example:
 * 
 * @code
 * btn_draw(&img, &b);
 * @endcode
 * OR
 * 
 * @code
 * b.widget.draw(&img, &b);
 * @endcode
 * 
 * By default, these functions are exactly the same.
 * 
 * 4.1	Another way to do it is using the widgets field of the images:
 * 
 * 4.11	When creating an image, specify a number of widgets. This will allocate
 * 		an array to store the widgets.
 * 4.12	link manually all the widgets in the image to the array
 * 4.13 invoke the corresponding function to draw the desired elements:
 * 
 * 		draw_image_widgets for the UI elements
 * 		draw_image_widgets_strings for the strings
 * 		draw_image_window for both (this will also put the image to the window)
 * 
 * ---------------------------------------------------------------------------
 * Notes:
 * 
 * -	The order of drawing matters since the UI elements are drawed over
 * 		the images but the strings are drawed directly over the window.
 * 		Therefore, the order off the operations is:
 * 		Draw the widgets -> Put image to Window -> Draw Strings
 * 
 * -	The drawing of the widgets can be customisable creating new functions
 * 		for doing so. These functions must follow the same patter established
 * 		in the widgets struct for using the automatic draw image function.
 * 
 * -	The library does not provide any mechanism for manage neither
 * 		collisions or events (Ex: clicking a button), so they must be
 * 		manage manually. Although, buttons provide an onclick function
 * 		who could be use to implement this system with abstraction.
 * 
 * -	The Labels has no draw function since they are merely text without any
 * 		other element to draw.
 * 
 * -	The width of labels are merely used for calculating distances with
 * 		others widgets since the actual size is calculated for the MiniLibX
 * 		based in the amount of characters. Modify it will no have any 
 * 		effect on how it is drawed.
 * 
 * -	Some widgets may provide setter functions for automatically recalculate
 * 		the fields who depends directly on it. Althought, more complex
 * 		widgets may require to recalculate some fields using their
 * 		corresponding recalculation function for a correct drawing in case
 * 		any field is changed after initialization.
 * 
 * -	The library does not provide any kind of bounds for drawing, so if
 * 		the width and/or height of a widget is out of image's bounds, it
 * 		may cause undefined behaviour (such as incorrect drawing or segfault)
 */

#ifndef WIDGETS_H
# define WIDGETS_H 1

# include <stdbool.h>
# include <stdlib.h>
# include <sys/param.h>

# ifdef __linux__
#  include "../../minilibx/mlx.h"
#  define WIDTH_PER_CHAR 6
#  define HEIGHT_PER_CHAR 11
#  define TEXT_OFFSETY 10
#  define TEXT_OFFSETX 0
# endif

# ifdef __APPLE__
#  include "TargetConditionals.h"
#  ifdef TARGET_OS_MAC
#   include "../../minilibx_macos/mlx.h"
#   define WIDTH_PER_CHAR 10
#   define HEIGHT_PER_CHAR 15
#   define TEXT_OFFSETY -4
#   define TEXT_OFFSETX -1
#  endif
# endif

// Default Values =============================================================

# define DEF_MARGIN_TOP			5
# define DEF_MARGIN_LEFT		5
# define DEF_MARGIN_RIGHT		5
# define DEF_MARGIN_BOTTOM		5

# define DEF_MIN_WIDTH			0
# define DEF_MIN_HEIGHT			0
# define DEF_MAX_WIDTH			0xFFF
# define DEF_MAX_HEIGHT			0xFFF

# define VAL_NONE				0b00000000
# define VAL_TOP				0b00000010
# define VAL_CENTER				0b00000100
# define VAL_BOTTOM				0b00001000

# define HAL_NONE				0b00010000
# define HAL_LEFT				0b00100000
# define HAL_CENTER				0b01000000
# define HAL_RIGHT				0b10000000

# define VAL_MASK				0b00001111
# define HAL_MASK				0b11110000

# define INC_BTN_TEXT			"+"
# define DEC_BTN_TEXT			"-"

// Default Colors =============================================================

# define DEF_TEXTCOLOR			0x00FFFFFF
# define DEF_BORDERCOLOR		0x00FFFFFF
# define DEF_BGCOLOR			0x00252525

// Structs ====================================================================

/**
 * @struct t_ivector2
 * @brief Basic struct for representing a 2D point.
 */
typedef struct s_ivector2
{
	int	x;
	int	y;
}	t_ivector2;

/**
 * @struct t_window
 * @brief Contains the pointer needed for the MiniLibX who represents the
 * window, as well as the size of it.
 */
typedef struct s_window
{
	void	*ptr;
	int		width;
	int		height;
}	t_window;

/**
 * @struct t_mlx
 * @brief Contains the pointer needed for the MiniLibX to work, as well as
 * a single window.
 */
typedef struct s_mlx
{
	void		*mlx;
	t_window	win;
}	t_mlx;

struct	s_image;

/**
 * @struct t_widget
 * @brief Basic struct who represents any widget.
 * 
 * This struct emulates an object-oriented design by allowing widgets to
 * contain a function pointer to their own draw function. the strings
 * are drawed separately due to the way the MiniLibX draw text. the object
 * field represents the object itself who must be passed by parameter in
 * the draw functions
 */
typedef struct s_widget
{
	void			(*draw)(struct s_image *img, void *self);
	void			(*draw_strngs)(t_mlx *mlx, struct s_image *img, void *self);
	void			*object;
	int				x;
	int				y;
	unsigned int	width;
	unsigned int	height;
	unsigned int	min_width;
	unsigned int	min_height;
	unsigned int	max_width;
	unsigned int	max_height;
	bool			is_visible;
}	t_widget;

typedef struct s_drawable_text
{
	char	*text;
	int		color;
	char	alignment;
}	t_drawable_text;

typedef struct s_drawable_container
{
	t_widget	widget;
	int			border_color;
	int			bg_color;
	int			margin_top;
	int			margin_bottom;
	int			margin_left;
	int			margin_right;
}	t_drawable_container;

/**
 * @struct t_image
 * @brief Basic struct who represents an image.
 * 
 * This struct contains all the information needed for the MiniLibX for
 * creating an image, as well as extra information such as the size and
 * position within the window. the widgets array is used for draw
 * automatically all the widgets assigned to the image.
 */
typedef struct s_image
{
	t_widget		**widgets;
	void			*ptr;
	char			*addr;
	int				bg_color;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
	unsigned int	amount_wigets;
	unsigned int	width;
	unsigned int	height;
	int				x;
	int				y;
}	t_image;

/**
 * @struct t_label
 * @brief Basic struct who represents a label.
 * 
 * The label is merely a single line of text with no special characters.
 * The width and height can be used just for calculations. modify them
 * will not affect the drawed string. The text field is NULLABLE
 */
typedef struct s_label
{
	t_widget	widget;
	char		*text;
	int			color;
}	t_label;

/**
 * @struct t_button
 * @brief Basic struct who represents a button.
 * 
 * The button does not react to any kind of events (clicking, focusing, etc.)
 * by itself. This system must be manually programmed due to the way the
 * MiniLibX manage events. The onclick function as well as the is_enable
 * field may help to develop an implementation with good level of abstraction.
 */
typedef struct s_button
{
	t_widget				widget;
	t_drawable_text			text;
	t_drawable_container	text_container;
	void					*(*onclick)(void *);
	bool					is_enabled;
}	t_button;

/**
 * @struct t_spinner
 * @brief Basic struct who represents a spinner.
 * 
 * This struct may be used as a base for constructing new types of
 * spinners who can listen to events and change the value of numeric
 * variables or navigating through a serie of elements.
 */
typedef struct s_spinner
{
	t_widget				widget;
	t_button				increase;
	t_button				decrease;
	t_drawable_text			text;
	t_drawable_container	text_container;
}	t_spinner;

// Functions ==================================================================

t_mlx			create_mlx(int w_window, int h_window, char *t_window);
t_window		new_window(void *mlx, int width, int height, char *title);

void			free_mlx(t_mlx *mlx);

void			draw_hline(t_image *img, t_ivector2 *a, int fx, int color);
void			draw_vline(t_image *img, t_ivector2 *a, int fy, int color);
void			draw_square(t_image *img, t_ivector2 points[2],
					int color, bool fill);

// Widgets

void			default_min_size(t_widget *w);
void			default_max_size(t_widget *w);
unsigned int	get_widget_width(t_widget *w);
unsigned int	get_widget_height(t_widget *w);

// Drawable Text

void			drwtext_init(t_drawable_text *t, char *text, int color,
					int alignment);
void			drwtext_set_halignment(t_drawable_text *t, char hal);
void			drwtext_set_valignment(t_drawable_text *t, char val);

int				get_draw_text_x(t_drawable_text *t, t_drawable_container *c);
int				get_draw_text_y(t_drawable_text *t, t_drawable_container *c);

// Drawable Container

void			drwcontainer_init(t_drawable_container *dc,
					t_ivector2 position, t_ivector2 size);
void			drwcontainer_draw_rectangle(t_image *img, void *self);
void			drwcontainer_draw_string(t_mlx *mlx, t_image *img,
					t_drawable_text *t, t_drawable_container *dc);

long			get_actual_width(t_drawable_container *dc);
long			get_actual_height(t_drawable_container *dc);

// Label

void			lbl_init(t_label *l, int x, int y, char *text);
void			lbl_draw(t_mlx *mlx, t_image *img, void *label);
void			lbl_recalculate(t_label *l);
size_t			calculate_label_width(char *str);

// Button

void			btn_init(t_button *b, int x, int y, char *text);
void			btn_draw(t_image *img, void *button);
void			btn_draw_strings(t_mlx *mlx, t_image *img, void *button);
void			btn_recalculate(t_button *b);
void			btn_set_x(t_button *b, int x);
void			btn_set_y(t_button *b, int y);

// Spinner

void			spn_init(t_spinner *s, int x, int y, char *text);
void			spn_draw(t_image *img, void *spinner);
void			spn_draw_strings(t_mlx *mlx, t_image *img, void *spinner);
void			spn_recalculate(t_spinner *s);
void			spn_set_x(t_spinner *s, int x);
void			spn_set_y(t_spinner *s, int y);

// Image

t_image			new_image(void *mlx, t_ivector2 size, int bg_color,
					unsigned int amount_widgets);
void			destroy_image(void *mlx, t_image *img);
void			draw_image_window(t_mlx *mlx, t_image *img);
void			draw_image_widgets(t_image *img);
void			draw_image_widgets_strings(t_mlx *mlx, t_image *img);
void			put_pixel_image(t_image *data, int x, int y, int color);
void			set_background(t_image *image, int color);
bool			is_within_image(t_image *img, int x, int y);
bool			image_has_widget(t_image *img, t_widget *w);

#endif