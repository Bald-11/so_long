/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabarhda <yabarhda@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 11:44:12 by yabarhda          #+#    #+#             */
/*   Updated: 2024/12/26 13:09:11 by yabarhda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	get_coin_id(t_mlx *vars, int x, int y)
{
	int	id;

	id = 0;
	while (id < vars->ttl_coins)
	{
		if ((vars->coin_pos[id][0] / IMG_SIZE == x) && \
		(vars->coin_pos[id][1] / IMG_SIZE == y))
			break ;
		id++;
	}
	return (id);
}

void	hz_pmv_hook(t_mlx *v, char c, int inter)
{
	int	coin_id;
	int	old_pos;

	(v->grid)[v->pos_y / IMG_SIZE][v->pos_x / IMG_SIZE] = '0';
	(v->grid)[v->pos_y / IMG_SIZE][(v->pos_x / IMG_SIZE) + (inter)] = 'P';
	old_pos = v->pos_x;
	if (inter == 1)
		v->pos_x += IMG_SIZE;
	else if (inter == -1)
		v->pos_x -= IMG_SIZE;
	if (c == 'C')
	{
		v->coins_collected++;
		coin_id = get_coin_id(v, v->pos_x / IMG_SIZE, v->pos_y / IMG_SIZE);
		v->coin_pos[coin_id][0] = 0;
		v->coin_pos[coin_id][1] = 0;
	}
	if (inter == 1)
		mlx_put_image_to_window(v->mlx, v->win, v->player_e, v->pos_x, \
		v->pos_y);
	else if (inter == -1)
		mlx_put_image_to_window(v->mlx, v->win, v->player_w, v->pos_x, \
		v->pos_y);
	mlx_put_image_to_window(v->mlx, v->win, v->background, old_pos, v->pos_y);
}

void	vt_pmv_hook(t_mlx *v, char c, int inter)
{
	int	coin_id;
	int	old_pos;

	(v->grid)[v->pos_y / IMG_SIZE][v->pos_x / IMG_SIZE] = '0';
	(v->grid)[(v->pos_y / IMG_SIZE) + (inter)][v->pos_x / IMG_SIZE] = 'P';
	old_pos = v->pos_y;
	if (inter == 1)
		v->pos_y += IMG_SIZE;
	else if (inter == -1)
		v->pos_y -= IMG_SIZE;
	if (c == 'C')
	{
		v->coins_collected++;
		coin_id = get_coin_id(v, v->pos_x / IMG_SIZE, v->pos_y / IMG_SIZE);
		v->coin_pos[coin_id][0] = 0;
		v->coin_pos[coin_id][1] = 0;
	}
	if (inter == 1)
		mlx_put_image_to_window(v->mlx, v->win, v->player_s, v->pos_x, \
		v->pos_y);
	else if (inter == -1)
		mlx_put_image_to_window(v->mlx, v->win, v->player_n, v->pos_x, \
		v->pos_y);
	mlx_put_image_to_window(v->mlx, v->win, v->background, v->pos_x, old_pos);
}

void	player_movement(t_mlx *vars, char c, int inter, char direction)
{
	if (c == '0' || c == 'C')
	{
		vars->move_count++;
		intput_movecount(vars);
		if (direction == 'H')
			hz_pmv_hook(vars, c, inter);
		else if (direction == 'V')
			vt_pmv_hook(vars, c, inter);
	}
	else if (c == 'E')
	{
		if (vars->coins_collected == vars->c_count)
		{
			vars->move_count++;
			ft_printf("You won!\nMario is proud of you.\n");
			close_window(vars);
		}
	}
	else if (c == 'G')
	{
		ft_printf("You lost!\n(!) Mario will remember that.\n");
		close_window(vars);
	}
}
