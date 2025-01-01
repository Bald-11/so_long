/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabarhda <yabarhda@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 08:10:30 by yabarhda          #+#    #+#             */
/*   Updated: 2024/12/25 16:23:43 by yabarhda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	keyboard_hooks(int keycode, t_mlx *vars)
{
	char	c;

	if (keycode == ESC || keycode == 'q')
		close_window(vars);
	else if (keycode == 'd' || keycode == RIGHT)
	{
		c = (vars->grid)[vars->pos_y / IMG_SIZE][(vars->pos_x / IMG_SIZE) + 1];
		player_movement(vars, c, 1, 'H');
	}
	else if (keycode == 'a' || keycode == LEFT)
	{
		c = (vars->grid)[vars->pos_y / IMG_SIZE][(vars->pos_x / IMG_SIZE) - 1];
		player_movement(vars, c, -1, 'H');
	}
	else if (keycode == 'w' || keycode == UP)
	{
		c = (vars->grid)[(vars->pos_y / IMG_SIZE) - 1][vars->pos_x / IMG_SIZE];
		player_movement(vars, c, -1, 'V');
	}
	else if (keycode == 's' || keycode == DOWN)
	{
		c = (vars->grid)[(vars->pos_y / IMG_SIZE) + 1][vars->pos_x / IMG_SIZE];
		player_movement(vars, c, 1, 'V');
	}
	return (0);
}
