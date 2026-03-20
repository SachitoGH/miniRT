/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constants.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzapata <dzapata@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 23:40:58 by dzapata           #+#    #+#             */
/*   Updated: 2025/05/30 15:19:39 by dzapata          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONSTANTS_H
# define CONSTANTS_H

# define KEY_PRESS				2
# define KEY_RELEASE			3
# define MOUSE_PRESS			4
# define MOUSE_RELEASE			5
# define MOUSE_MOTION			6
# define DESTROY_NOTIFY			17

# define KEY_PRESS_MASK			1
# define KEY_RELEASE_MASK		2
# define MOUSE_PRESS_MASK		4
# define MOUSE_RELEASE_MASK		8
# define MOUSE_MOTION_MASK		64

# define DEFAULT_WINDOW_WIDTH	1440
# define DEFAULT_WINDOW_HEIGHT	768

# define RENDER_PERCENT			0.64f
# define CONTROL_PERCENT		0.18f
# define GENERAL_PERCENT		0.18f

# define DEG_RADIANTS			0.017453293
# define TO_CHAR				0.003921568f
# define COS_30					0.8660254
# define COS_45					0.7071068
# define SIN_45					0.7071068

# define TEMP_SIZE				24

# define CONTROL_BACKGROUND		0x00141414
# define RENDER_BACKGROUND		0x00000000
# define TEXT_COLOR				0x00FFFFFF
# define VALUES_COLOR			0x00FFFFFF

#endif