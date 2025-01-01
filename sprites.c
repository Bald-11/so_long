/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabarhda <yabarhda@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 14:13:31 by yabarhda          #+#    #+#             */
/*   Updated: 2024/12/25 15:41:03 by yabarhda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	preload_anim(t_mlx *n)
{
	char	*path;
	int		w;
	int		h;
	int		i;

	i = 0;
	path = (char *)malloc(sizeof(char) * 38);
	ft_strcpy(path, "./textures/coin_anim/coin_frame_0.xpm");
	while (i < 8)
	{
		path[32] = i + '0';
		n->coin_frames[i] = mlx_xpm_file_to_image(n->mlx, path, &w, &h);
		if (!n->coin_frames[i])
			(error_handling(9), free(path), image_err_free(n), exit(1));
		i++;
	}
	free(path);
}

void	load_player_sprite(t_mlx *vars)
{
	int	w;
	int	h;

	vars->player_s = mlx_xpm_file_to_image(vars->mlx, \
	"./textures/player/mario.xpm", &w, &h);
	vars->player_w = mlx_xpm_file_to_image(vars->mlx, \
	"./textures/player/mario_w.xpm", &w, &h);
	vars->player_n = mlx_xpm_file_to_image(vars->mlx, \
	"./textures/player/mario_n.xpm", &w, &h);
	vars->player_e = mlx_xpm_file_to_image(vars->mlx, \
	"./textures/player/mario_e.xpm", &w, &h);
	if (!vars->player_s || !vars->player_w || !vars->player_n
		|| !vars->player_e)
		(error_handling(9), image_err_free(vars), exit(1));
}

void	pre_load_sprites(t_mlx *vars)
{
	int	w;
	int	h;

	vars->exit = mlx_xpm_file_to_image(vars->mlx, \
	"./textures/exit.xpm", &w, &h);
	load_player_sprite(vars);
	vars->wall = mlx_xpm_file_to_image(vars->mlx, \
	"./textures/wall.xpm", &w, &h);
	vars->background = mlx_xpm_file_to_image(vars->mlx, \
	"./textures/background.xpm", &w, &h);
	vars->enemy = mlx_xpm_file_to_image(vars->mlx, \
	"./textures/goomba.xpm", &w, &h);
	if (!vars->exit || !vars->wall || !vars->background)
		(error_handling(9), image_err_free(vars), exit(1));
	preload_anim(vars);
}

void	grid_case_handling(t_mlx *vars, char c, int x, int y)
{
	if (c == '1')
		mlx_put_image_to_window(vars->mlx, vars->win, vars->wall, x, y);
	else if (c == '0')
		mlx_put_image_to_window(vars->mlx, vars->win, vars->background, x, y);
	else if (c == 'C')
	{
		mlx_put_image_to_window(vars->mlx, vars->win, vars->background, x, y);
		vars->coin_pos[vars->coin_index][0] = x;
		vars->coin_pos[vars->coin_index][1] = y;
		vars->coin_index++;
	}
	else if (c == 'P')
	{
		vars->pos_x = x;
		vars->pos_y = y;
		mlx_put_image_to_window(vars->mlx, vars->win, vars->player_s, x, y);
	}
	else if (c == 'E')
	{
		vars->exit_x = x;
		vars->exit_y = y;
		mlx_put_image_to_window(vars->mlx, vars->win, vars->exit, x, y);
	}
	else if (c == 'G')
		mlx_put_image_to_window(vars->mlx, vars->win, vars->enemy, x, y);
}

void	putgrid(t_mlx *vars)
{
	int	x;
	int	y;
	int	i;
	int	j;

	x = 0;
	y = 0;
	i = 0;
	while (vars->grid[i])
	{
		j = 0;
		while (vars->grid[i][j])
		{
			grid_case_handling(vars, vars->grid[i][j], x, y);
			x += IMG_SIZE;
			j++;
		}
		x = 0;
		y += IMG_SIZE;
		i++;
	}
}
