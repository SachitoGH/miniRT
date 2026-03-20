/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzapata <dzapata@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 01:52:30 by dzapata           #+#    #+#             */
/*   Updated: 2025/05/30 05:06:30 by dzapata          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H 1

# include "../Libft_ref/Libft/headers/libft_bonus.h"
# include "../Libft_ref/ft_printf/ft_printf.h"
# include "../Libft_ref/Get_Next_Line/get_next_line.h"
# include "../widgets/headers/widgets.h"
# include "dimensions.h"
# include "constants.h"
# include "fcntl.h"
# include "limits.h"
# include "time.h"

# ifdef __linux__
#  include "../minilibx/mlx.h"
#  include "constants_linux.h"
# endif

# ifdef __APPLE__
#  include "TargetConditionals.h"
#  ifdef TARGET_OS_MAC
#   include "../minilibx_macos/mlx.h"
#   include "constants_mac.h"
#  endif
# endif

# define AMOUNT_DECIMALS		2
# define CONTROL_PARAMS			5
# define GENERAL_PARAMS			12
# define PARAMS_PADDING			10
# define INIT_TEXT_MARGINY		20
# define PARAM_MARGINX			20

# define RIGHT_PADDING			15
# define PANEL_PADDING			33
# define TEXT_PADDING			17
# define VALUES_PADDING			27

# define DEF_FOCAL_LENGTH		1.0f

# define MIN_FOV				0
# define MAX_FOV				180
# define MIN_COLOR				0
# define MAX_COLOR				0xFF
# define MIN_BRIGHTNESS			0.0f
# define MAX_BRIGHTNESS			1.0f
# define MIN_ORIENTATION		-1.0f
# define MAX_ORIENTATION		1.0f
# define MIN_MAT_VAL			0.0f
# define MAX_MAT_VAL			4096
# define MIN_VALUES				-50000
# define MAX_VALUES				50000
# define MAX_INTERSECTIONS		4
# define STEPS					0.25f
# define ROTATION				5.0f
# define QUALITY				5

# define DEF_BCOLOR				0x00FFFFFF
# define DEF_BGBCOLOR			CONTROL_BACKGROUND
# define DEF_RENDER_COLOR		0x00000000

# define CHANGE_VAL_F			0.1f
# define CHANGE_VAL_I			10

# define UNKNOWN_ERR			1
# define MLX_ERR				2
# define MALLOC_ERR				3
# define MLX_IMG_ERR			4
# define TEXTURE_ERR			5

# define UNKNOWN_OBJ_ERR		6
# define MULTI_INIT_ERR			7
# define NO_TEXT_ID_ERR			8
# define NO_MAT_ID_ERR			9
# define NO_PAT_ID_ERR			10
# define BAD_ID_ERR				11
# define BAD_VALUE_ERR			12
# define EXTRA_ARGS_ERR			13
# define MISSING_ARGS_ERR		14
# define NO_CAMERA_ERR			15
# define NO_OBJECT_ERR			16
# define INVALID_PAT_ERR		17
# define BAD_NUM_ARGS_ERR		18
# define BAD_PANEL_SIZE_ERR		19
# define ARGS_DECIMAL_ERR		20
# define REPEATED_ID_ERR		21

# define N_ERRORS				21
# define N_OBJ_FILE				11
# define N_PATTERNS				4
# define OBJ_MAX_LEN			2
# define ID_MAX_LEN				25

// Strings ====================================================================

# define WINDOW_TITLE			"MiniRT"

# define INIT_MSG				"Welcome to MiniRT"
# define WIN_WIDTH_TXT			"Window width"
# define WIN_HEIGHT_TXT			"Window height"
# define AMB_LIGHTB_TXT			"Ambient Lightning Brightness"
# define AMB_LIGHTC_TXT			"Ambient Lightning Color"
# define FOV_TXT				"Field of View (FOV)"
# define COLOR_TXT				"Color"
# define POSITION_TXT			"Position"
# define ROTATION_TXT			"Rotation"
# define SCALE_TXT				"Scale"
# define BRIGHTNESS_TXT			"Brightness"
# define OBJ_TYPE_TXT			"Object Type"
# define TEXTURES_TXT			"Textures Loaded"
# define AMOUNT_LIGHTS_TXT		"Amount Lights"
# define AMOUNT_OBJ_TXT			"Amount Objects"
# define AMOUNT_MATERIALS_TXT	"Amount Materials"
# define AMOUNT_PATTERNS_TXT	"Amount Patterns"

# define TRUE_TXT				"Yes"
# define FALSE_TXT				"No"

# define FILE_EXT				".rt"
# define ARGS_SEP				","
# define DEC_SEP				"."

# define CAMERA_ID				"C"
# define AMB_LIGHT_ID			"A"

# define LIGHT_ID				"l"
# define PLANE_ID				"pl"
# define ELLIPSOID_ID			"sp"
# define CYLINDER_ID			"cy"
# define CUBOID_ID				"cb"
# define CONOID_ID				"cn"
# define TEXTURE_ID				"t"
# define MATERIAL_ID			"m"
# define PATTERN_ID				"p"

# define STRIP_ID				"st"
# define RING_ID				"rn"
# define CHECK_ID				"ch"
# define GRADIENT_ID			"gr"

# define PLANE_TXT				"Plane"
# define ELLIPSOID_TXT			"Ellipsoid"
# define CUBOID_TXT				"Cuboid"
# define CONOID_TXT				"Conoid"
# define CYLINDER_TXT			"Cylinder"
# define LIGHT_TXT				"Light"
# define UNKNOWN_ELEMENT		"Unknown"

# define ERR					"Error: "
# define WARNING				"Warning: "
# define BAD_PANEL_SIZE_ERR_MSG	"Bad panels size"
# define UNKNOWN_ERR_MSG		"Unknown error"
# define MLX_ERR_MSG			"Mlx failed"
# define MALLOC_ERR_MSG			"Memory allocation failed"
# define MLX_IMG_ERR_MSG		"Image could not be created"
# define TEXTURE_ERR_MSG		"Texture could not be created"
# define UNKNOWN_OBJ_ERR_MSG	"Unknown object found"
# define MULTI_INIT_ERR_MSG		"Multiple declarations of unique objects"
# define NO_TEXT_ID_ERR_MSG		"Textures must have an ID"
# define NO_MAT_ID_ERR_MSG		"Materials must have an ID"
# define NO_PAT_ID_ERR_MSG		"Patterns must have an ID"
# define BAD_ID_ERR_MSG			"IDs must be alpha numeric"
# define INVALID_PAT_ERR_MSG	"Invalid pattern type"
# define REPEATED_ID_ERR_MSG	"There are two or more objects with the same ID"
# define BAD_VALUE_ERR_MSG		"Object with bad values"
# define ARGS_DECIMAL_ERR_MSG	"Arguments and decimal separators are the same"
# define NO_OBJECT_ERR_MSG		"Object is refering to an undeclared object"
# define EXTRA_ARGS_ERR_MSG		"Object has extra arguments"
# define MISSING_ARGS_ERR_MSG	"Object has missing arguments"
# define NO_CAMERA_ERR_MSG		"The file does not contain a camera object"
# define BAD_NUM_ARGS_ERR_MSG	"Bad number of arguments"

// Enums ======================================================================

typedef enum s_element
{
	OBJECT,
	LIGHT,
	TEXTURE,
	MATERIAL,
	PATTERN,
	OTHER
}	t_element;

typedef enum s_objtype
{
	UNKNOWN,
	PLANE,
	ELLIPSOID,
	CUBOID,
	CONOID,
	CYLINDER
}	t_objtype;

typedef enum s_pattern_type
{
	P_STRIPE,
	P_GRADIENT,
	P_RING,
	P_CHECKER
}	t_pattern_type;

// Unions =====================================================================

typedef union u_number32
{
	int		integer;
	float	decimal;
}	t_number32;

// Structs ====================================================================

typedef struct s_error
{
	char	*message;
	int		code;
	bool	warning;
	bool	system;	
}	t_error;

typedef struct s_texture
{
	char	id[ID_MAX_LEN + 1];
	void	*img;
	int		width;
	int		height;
}	t_texture;

typedef struct s_material
{
	char	id[ID_MAX_LEN + 1];
	float	ambient;
	float	diffuse;
	float	specular;
	float	shininess;
	float	reflective;
	float	refractive;
	float	transparence;
}	t_material;

typedef struct s_color
{
	t_fvector3	normalized;
	int			rgb;
}	t_color;

struct	s_def_pat_data;
struct	s_def_obj_data;

typedef struct s_pattern
{
	t_smatrix4				transform;
	t_smatrix4				inverse;
	char					id[ID_MAX_LEN + 1];
	t_fvector3				position;
	t_fvector3				rotation;
	t_fvector3				scale;
	t_color					color_a;
	t_color					color_b;
	struct s_def_pat_data	*data;
	t_pattern_type			type;
}	t_pattern;

typedef struct s_def_pat_data
{
	char			*id;
	t_fvector3		(*apply_at)(t_pattern * self, t_fvector4 point);
	t_pattern_type	type;
}	t_def_pat_data;

typedef struct s_special
{
	float	min;
	float	max;
	bool	closed;
}	t_special;

typedef struct s_object3d
{
	t_material				material;
	t_smatrix4				transform;
	t_smatrix4				inverse;
	t_smatrix4				transpose;
	t_fvector4				l_origin;
	t_fvector3				position;
	t_fvector3				e_rotation;
	t_fvector3				scale;
	t_special				special;
	t_color					color;
	t_texture				*texture;
	t_pattern				*pattern;
	struct s_def_obj_data	*data;
	t_objtype				type;
}	t_object3d;

typedef struct s_light
{
	t_fvector3	position;
	t_fvector3	color_attenuated;
	t_color		color;
	float		brightness;
}	t_light;

typedef struct s_viewport
{
	float			pixel_size;
	float			half_width;
	float			half_height;
	float			aspect_ratio;
	unsigned int	fov;
}	t_viewport;

typedef struct s_camera
{
	t_viewport		viewport;
	t_smatrix4		transform;
	t_smatrix4		inverse;
	t_smatrix4		rotation;
	t_fvector4		origin;
	t_fvector3		forward;
	t_fvector3		right;
	t_fvector3		up;
	t_fvector3		position;
	t_color			alight_color;
	float			alight_brightness;
}	t_camera;

typedef struct s_object_data
{
	t_fvector3				normal;
	t_object3d				*obj;
	float					t;
}	t_object_data;

typedef struct s_scene
{
	t_camera		camera;
	t_color			background;
	t_texture		*textures;
	t_material		*materials;
	t_pattern		*patterns;
	t_light			*lights;
	t_object3d		*objects;
	t_object_data	*depth;
	int				amount_textures;
	int				amount_materials;
	int				amount_patterns;
	int				amount_lights;
	int				amount_objects;
	unsigned int	depth_count;
}	t_scene;

typedef struct s_mouse
{
	int		draggin;
	short	last_x;
	short	last_y;
}	t_mouse;

typedef struct s_number_spinner
{
	t_spinner	spinner;
	t_number32	value;
	t_number32	low_limit;
	t_number32	high_limit;
	t_number32	step;
	bool		is_decimal;
}	t_number_spinner;

typedef struct s_render_info
{
	t_fvector4				origin;
	t_fvector4				dir;
	t_fvector4				light_dir;
	t_fvector4				p;
	t_fvector4				p_object;
	t_fvector4				eye;
	t_fvector4				normal;
	t_fvector4				p_moved;
	t_fvector4				reflect;
	t_fvector3				ambient;
	t_fvector3				color;
	t_color					bg_color;
	int						n_hits;
	float					t[MAX_INTERSECTIONS];
	int						depth;
}	t_render_info;

typedef struct s_def_obj_data
{
	char		*str;
	int			(*verify)(char *str);
	int			(*parse)(t_scene *s, int index, char *str, t_objtype t);
	bool		(*hit)(t_object3d * obj, t_fvector4 dir, t_fvector4 origin,
		t_render_info * i);
	t_fvector4	(*normal_at)(t_object3d * obj, t_fvector4 hit);
	t_element	e_type;
	t_objtype	o_type;
	int			max_intersect;
	bool		has_init;
}	t_def_obj_data;

typedef struct s_minirt
{
	t_scene				scene;
	t_image				render;
	t_image				control;
	t_image				general;
	t_mouse				mouse;
	t_mlx				mlx;
	t_def_obj_data		o_data[N_OBJ_FILE];
	t_def_pat_data		p_data[N_PATTERNS];
	void				*elem;
	char				str_buffer[TEMP_SIZE];
	t_number_spinner	*spinners;
	t_element			elem_select;
	int					key;
}	t_minirt;

typedef struct s_event
{
	t_minirt			*rt;
	t_number_spinner	*param;
	t_image				*img;
}	t_event;

typedef struct s_parser
{
	unsigned int	n_init[5];
	int				err;
	char			*str;
	t_list			*temp;
	t_def_obj_data	*obj;
}	t_parser;

// Functions ==================================================================

void			place_general(t_minirt *rt);
void			place_control(t_minirt *rt);
int				minirt(int fd, int w_width, int w_height);
void			set_rt_null(t_minirt *rt);
void			clean_rt_stack(t_minirt *rt);
void			print_err(int err_code);
bool			equal(float a, float b);
void			set_hooks(t_minirt *rt);
t_fvector3		euler_to_radiants(t_fvector3 e);

int				control_header_strings(t_minirt *rt, t_ivector2 *point,
					bool draw);
int				place_spinner(t_ivector2 init_point, int n,
					t_number_spinner *params);
unsigned char	to_char(float n);
int				normalized_to_rgb(t_fvector3 normalized);
void			sort_data(t_object_data *hits, int count);
t_fvector3		normalize_color(int color);

// Linkers

void			link_control_values(t_minirt *rt);
void			relink_control_values(t_minirt *rt);
void			link_object(t_minirt *rt);
void			link_spinners(t_minirt *rt);
void			relink_object(t_minirt *rt);

// Draw Values

void			draw_bool(t_mlx *mlx, bool b, t_ivector2 *point, int color);
void			draw_int(t_minirt *rt, int number, t_ivector2 *point,
					int color);
void			draw_float(t_minirt *rt, float number, t_ivector2 *point,
					int color);
void			draw_double(t_minirt *rt, double number, t_ivector2 *point,
					int color);
void			draw_string(t_mlx *mlx, char *str, t_ivector2 *point,
					int color);

void			draw_triads_strings(t_mlx *mlx, t_ivector2 *points,
					char *textes[3], t_number_spinner *spinner);
void			draw_rgb_panel(t_mlx *mlx, t_ivector2 *point, char *panel,
					t_number_spinner *params);
void			draw_axis_panel(t_mlx *mlx, t_ivector2 *point, char *panel,
					t_number_spinner *params);
void			draw_control_strings(t_minirt *rt, t_image *img);
void			draw_general_strings(t_minirt *rt, t_image *img);

void			init_number_spinner(t_number_spinner *s, int x, int y,
					bool is_decimal);
void			draw_number_spinner_strings(t_mlx *mlx, t_image *img,
					void *spinner);
void			set_spinner_values(t_number_spinner *s, t_number32 low,
					t_number32 high, bool is_decimal);
void			init_params(t_number_spinner *spinners, int amount);

// Events

int				key_press(int key, t_minirt *rt);
int				key_release(int key, t_minirt *rt);
int				mouse_press(int button, int x, int y, t_minirt *rt);
int				mouse_release(int button, int x, int y, t_minirt *rt);
int				mouse_motion(int x, int y, t_minirt *rt);
void			has_clicked_button(t_minirt *rt, int x, int y);

void			set_rt_null(t_minirt *rt);
void			set_integers(t_number_spinner *spinners);
void			set_floats(t_number_spinner *spinners);

void			*increase_val(void *arg);
void			*decrease_val(void *arg);

void			select_object(t_minirt *rt, int x, int y);
int				end(t_minirt *rt);

// Movements

void			move_right(t_minirt *rt, float steps);
void			move_up(t_minirt *rt, float steps);
void			move_forward(t_minirt *rt, float steps);
void			rotate_up(t_minirt *rt, float steps);
void			rotate_sides(t_minirt *rt, float steps);

// Preloaded

bool			new_texture(t_mlx *mlx, t_texture *t, char *path);
bool			is_unique_id(char *str, t_scene *s);
bool			is_texture(char *str, t_texture *textures, int n_textures);
bool			is_material(char *str, t_material *m, int n_materials);
bool			is_pattern(char *str, t_pattern *p, int n_patterns);
t_texture		*get_texture(char *str, t_texture *textures, int n_textures);
t_material		*get_material(char *str, t_material *m, int n_materials);
t_pattern		*get_pattern(char *str, t_pattern *p, int n_patterns);

// Get Strings

char			*get_element_type(t_element type, void *elem);

// Integers

bool			i_in_bounds(int n, int lower_limit, int upper_limit);
int				verify_int(char *str, size_t args_len, int min_val,
					int max_val);
int				verify_ints(char **str, unsigned int n_ints, int min_val,
					int max_val);

// Floats

bool			d_in_bounds(double n, double lower_limit, double upper_limit);
int				verify_double(char *s, size_t args_len, double min_val,
					double max_val);
int				verify_doubles(char **str, unsigned int n_floats,
					double min_val, double max_val);

// Default Data

void			init_def_data_obj(t_def_obj_data *ver);
void			init_def_pat_data(t_def_pat_data *data);
void			default_material(t_material *m);
t_def_obj_data	*get_object_by_type(t_objtype type, t_def_obj_data *obj);
t_def_obj_data	*get_object_by_str(char *str, t_def_obj_data *obj);
t_def_pat_data	*get_pattern_by_str(char *str, t_def_pat_data *obj);
t_def_pat_data	*get_pattern_by_type(t_pattern_type type, t_def_pat_data *p);

// Verifier

char			*move_arg(char *str);
char			*move_args(char *str);
int				verify_basics(char **str);
bool			verify_unique_id(char *str, t_scene *s, size_t *len);
int				verify_content(t_text *text, t_scene *s, t_def_obj_data *data);
int				verify_position(char **str);
int				verify_orientation(char **str);
int				verify_color(char **str);
int				verify_plane(char *str);
int				verify_special(char *str);
int				verify_object(char *str);
int				verify_texture(char *str);
int				verify_material(char *str);
int				verify_pattern(char *str);
int				verify_camera(char *str);
int				verify_amb_light(char *str);
int				verify_light(char *str);
int				verify_pattern_type(char *str);
int				verify_values(char **str, unsigned int n_args,
					unsigned int optional, bool end);

// Parsers

int				parse_rt_file(t_mlx *mlx, t_scene *rt, t_text *text,
					t_def_obj_data *data);
int				parse_plane(t_scene *s, int index, char *str, t_objtype t);
int				parse_light(t_scene *s, int index, char *str, t_objtype t);
int				parse_amb_light(t_scene *s, int index, char *str, t_objtype t);
int				parse_object(t_scene *s, int index, char *str, t_objtype t);
int				parse_camera(t_scene *s, int index, char *str, t_objtype t);
int				parse_texture(t_scene *s, int index, char *str, t_objtype t);
int				parse_material(t_scene *s, int index, char *str, t_objtype t);
int				parse_pattern(t_scene *s, int index, char *str, t_objtype t);
int				parse_special(t_scene *s, int index, char *str, t_objtype t);
void			parse_ftriad(t_fvector3 *triad, char *str);
void			parse_color(int *color, char *s);

// Hitters

bool			hit_ellipsoid(t_object3d *obj, t_fvector4 dir,
					t_fvector4 origin, t_render_info *i);
bool			hit_conoid(t_object3d *obj, t_fvector4 dir, t_fvector4 origin,
					t_render_info *i);
bool			hit_cuboid(t_object3d *obj, t_fvector4 dir, t_fvector4 origin,
					t_render_info *i);
bool			hit_cylinder(t_object3d *obj, t_fvector4 dir, t_fvector4 origin,
					t_render_info *i);
bool			hit_plane(t_object3d *obj, t_fvector4 dir, t_fvector4 origin,
					t_render_info *i);

bool			check_cap(t_fvector4 origin, t_fvector4 dir, float t,
					float limit);
void			manage_hits_special(t_object3d *obj, t_fvector4 dir,
					t_fvector4 origin, t_render_info *i);
bool			quadratic_formula(float a, float b, float c, t_render_info *i);
void			cap_conoid(t_object3d *obj, t_fvector4 dir, t_fvector4 origin,
					t_render_info *i);

// Normals

t_fvector4		normal_ellipsoid(t_object3d *obj, t_fvector4 hit);
t_fvector4		normal_cuboid(t_object3d *obj, t_fvector4 hit);
t_fvector4		normal_conoid(t_object3d *obj, t_fvector4 hit);
t_fvector4		normal_cylinder(t_object3d *obj, t_fvector4 hit);
t_fvector4		normal_plane(t_object3d *obj, t_fvector4 hit);

// Patterns

t_fvector3		gradient_at(t_pattern *p, t_fvector4 point);
t_fvector3		check_at(t_pattern *p, t_fvector4 point);
t_fvector3		ring_at(t_pattern *p, t_fvector4 point);
t_fvector3		strip_at(t_pattern *p, t_fvector4 point);

// Render

t_fvector4		get_hitted(t_render_info *i, float t);
t_fvector4		reflect(t_fvector4 in, t_fvector4 normal);
t_fvector4		ray_for_pixel(t_camera *c, int px, int py);
t_fvector3		pattern_color(t_pattern *p, t_render_info *i);
t_fvector3		lightning(t_object_data *o, t_render_info *info, t_light *l);
int				shade_point(t_scene *s, t_render_info *info, int i);
int				hit_objects(t_scene *s, t_render_info *info);
int				hit_objects(t_scene *s, t_render_info *info);
bool			is_shadowed(t_scene *s, t_render_info *info, t_light *l);
bool			is_valid_hit(t_render_info *info, float magnitude);
void			render_init(t_scene *s, t_render_info *i);
void			set_hits(t_scene *s, t_render_info *info, int i, int *j);
void			render(t_scene *s, t_image *img);
void    		low_render(t_scene *s, t_image *img);

// Calculations

void			calculus(t_scene *s);
void			calculate_camera(t_camera *c, t_image *img);
void			calculate_objects_camera(t_scene *s);
void			camera_transform(t_camera *c);
void			calculate_object(t_object3d *o, t_camera *c);
void			calculate_pattern(t_pattern *o, t_camera *c);
void			calculate_light(t_light *l);

#endif