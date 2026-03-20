/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzapata <dzapata@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 19:27:41 by dzapata           #+#    #+#             */
/*   Updated: 2025/05/19 17:17:36 by dzapata          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/miniRT.h"

void	init_error(t_error *e)
{
	e[0] = (t_error){UNKNOWN_ERR_MSG, UNKNOWN_ERR, false, false};
	e[1] = (t_error){MLX_ERR_MSG, MLX_ERR, false, true};
	e[2] = (t_error){MALLOC_ERR_MSG, MALLOC_ERR, false, true};
	e[3] = (t_error){MLX_IMG_ERR_MSG, MLX_IMG_ERR, false, true};
	e[4] = (t_error){TEXTURE_ERR_MSG, TEXTURE_ERR, false, true};
	e[5] = (t_error){UNKNOWN_OBJ_ERR_MSG, UNKNOWN_OBJ_ERR, false, false};
	e[6] = (t_error){MULTI_INIT_ERR_MSG, MULTI_INIT_ERR, false, false};
	e[7] = (t_error){NO_TEXT_ID_ERR_MSG, NO_TEXT_ID_ERR, false, false};
	e[8] = (t_error){NO_MAT_ID_ERR_MSG, NO_MAT_ID_ERR, false, false};
	e[9] = (t_error){NO_PAT_ID_ERR_MSG, NO_PAT_ID_ERR, false, false};
	e[10] = (t_error){BAD_ID_ERR_MSG, BAD_ID_ERR, false, false};
	e[11] = (t_error){BAD_VALUE_ERR_MSG, BAD_VALUE_ERR, false, false};
	e[12] = (t_error){EXTRA_ARGS_ERR_MSG, EXTRA_ARGS_ERR, false, false};
	e[13] = (t_error){MISSING_ARGS_ERR_MSG, MISSING_ARGS_ERR, false, false};
	e[14] = (t_error){NO_CAMERA_ERR_MSG, NO_CAMERA_ERR, false, false};
	e[15] = (t_error){NO_OBJECT_ERR_MSG, NO_OBJECT_ERR, false, false};
	e[16] = (t_error){INVALID_PAT_ERR_MSG, INVALID_PAT_ERR, false, false};
	e[17] = (t_error){BAD_NUM_ARGS_ERR_MSG, BAD_NUM_ARGS_ERR, false, false};
	e[18] = (t_error){BAD_PANEL_SIZE_ERR_MSG, BAD_PANEL_SIZE_ERR, true, false};
	e[19] = (t_error){ARGS_DECIMAL_ERR_MSG, ARGS_DECIMAL_ERR, false, false};
	e[20] = (t_error){REPEATED_ID_ERR_MSG, REPEATED_ID_ERR, false, false};
}

t_error	*get_error(int code, t_error *errors)
{
	t_error	*unknown;
	int		i;

	unknown = errors;
	i = -1;
	while (++i < N_ERRORS)
	{
		if (errors[i].code == code)
			return (&errors[i]);
		else if (errors[i].code == UNKNOWN_ERR)
			unknown = &errors[i];
	}
	return (unknown);
}

void	print_err(int err_code)
{
	t_error	errors[N_ERRORS];
	t_error	*err;
	char	*type;

	init_error(errors);
	err = get_error(err_code, errors);
	if (err->warning)
		type = WARNING;
	else
		type = ERR;
	ft_printf_fd(STDERR_FILENO, "%s", type);
	if (err->system)
		perror(err->message);
	else
		ft_printf_fd(STDERR_FILENO, "%s\n", err->message);
}
