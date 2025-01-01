/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   anim.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabarhda <yabarhda@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 08:55:19 by yabarhda          #+#    #+#             */
/*   Updated: 2024/12/26 10:47:16 by yabarhda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	animate_coin(t_mlx *n)
{
	int	i;
	int	current_frame;

	i = 0;
	current_frame = 0;
	while (i < n->c_count)
	{
		current_frame = n->current_frame;
		if (n->coin_pos[i][0] == 0 && n->coin_pos[i][1] == 0)
		{
			i++;
			continue ;
		}
		mlx_put_image_to_window(n->mlx, n->win, n->coin_frames[current_frame], \
		n->coin_pos[i][0], n->coin_pos[i][1]);
		i++;
	}
}

void	draw_new_exit(t_mlx *vars)
{
	int	h;
	int	w;

	mlx_destroy_image(vars->mlx, vars->exit);
	vars->exit = mlx_xpm_file_to_image(vars->mlx, "./textures/exit2.xpm", \
	&w, &h);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->exit, vars->exit_x, \
	vars->exit_y);
	vars->new_exit = 1;
}

int	on_game_update(t_mlx *n)
{
	n->frame_count++;
	if (n->frame_count >= n->frame_rate)
	{
		n->frame_count = 0;
		n->current_frame++;
		if (n->current_frame >= 7)
			n->current_frame = 0;
		animate_coin(n);
	}
	if (n->coins_collected == n->c_count)
	{
		if (!n->new_exit)
			draw_new_exit(n);
	}
	return (0);
}
