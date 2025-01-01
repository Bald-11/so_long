/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_vars.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabarhda <yabarhda@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 19:56:53 by yabarhda          #+#    #+#             */
/*   Updated: 2024/12/25 17:16:14 by yabarhda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	init_sprites(t_mlx *vars)
{
	int	i;

	i = 0;
	vars->exit = NULL;
	vars->player_w = NULL;
	vars->player_e = NULL;
	vars->player_s = NULL;
	vars->player_n = NULL;
	vars->wall = NULL;
	vars->background = NULL;
	vars->coin_frames = (void **)malloc(sizeof(void *) * 8);
	while (i < 8)
		vars->coin_frames[i++] = NULL;
	vars->coin_pos = (int **)malloc(sizeof(int *) * vars->c_count);
	i = 0;
	while (i < vars->c_count)
	{
		vars->coin_pos[i] = (int *)malloc(sizeof(int) * 2);
		vars->coin_pos[i][0] = 0;
		vars->coin_pos[i][1] = 0;
		i++;
	}
}

void	init_init_basic(t_mlx *vars)
{
	vars->str = NULL;
	vars->ttl_coins = 0;
	vars->ttl_zeros = 0;
	vars->move_count = 0;
	vars->coin_index = 0;
	vars->player_grid_x = 0;
	vars->player_grid_y = 0;
	vars->total_zeros = 0;
	vars->e_count = 0;
	vars->p_count = 0;
	vars->c_count = 0;
	vars->frame_count = 0;
	vars->frame_rate = FPS;
	vars->current_frame = 0;
	vars->coins_collected = 0;
	vars->new_exit = 0;
}

void	init_basic_vars(t_mlx *vars, int ls_c, int l_len)
{
	int	i;
	int	j;

	i = 0;
	init_init_basic(vars);
	vars->ls_c = ls_c;
	vars->l_len = l_len;
	while (vars->grid[i])
	{
		j = 0;
		while (vars->grid[i][j])
		{
			if (vars->grid[i][j] == 'P')
			{
				vars->player_grid_x = i;
				vars->player_grid_y = j;
			}
			else if (vars->grid[i][j] == 'C')
				vars->ttl_coins++;
			else if (vars->grid[i][j] == '0')
				vars->ttl_zeros++;
			j++;
		}
		i++;
	}
}
