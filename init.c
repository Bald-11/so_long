/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabarhda <yabarhda@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 15:06:49 by yabarhda          #+#    #+#             */
/*   Updated: 2024/12/26 10:49:31 by yabarhda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	init_grid_case_handling(t_mlx *vars, char c, int x, int y)
{
	if (c == '1')
		mlx_put_image_to_window(vars->mlx, vars->win, vars->wall, x, y);
	else if (c == '0')
		mlx_put_image_to_window(vars->mlx, vars->win, vars->background, x, y);
	else if (c == 'E')
		mlx_put_image_to_window(vars->mlx, vars->win, vars->exit, x, y);
	else if (c == 'G')
		mlx_put_image_to_window(vars->mlx, vars->win, vars->enemy, x, y);
	else if (c == 'C')
		mlx_put_image_to_window(vars->mlx, vars->win, \
		vars->coin_frames[vars->current_frame], x, y);
}

void	init_putgrid(t_mlx *vars)
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
			init_grid_case_handling(vars, vars->grid[i][j], x, y);
			x += IMG_SIZE;
			j++;
		}
		x = 0;
		y += IMG_SIZE;
		i++;
	}
}

void	intput_movecount(t_mlx *vars)
{
	int		y;
	char	*tmp;

	y = vars->ls_c * IMG_SIZE;
	tmp = NULL;
	mlx_clear_window(vars->mlx, vars->win);
	tmp = ft_itoa(vars->move_count);
	if (!vars->str)
	{
		vars->str = (char *)malloc(sizeof(char) * 20);
		ft_strcpy(vars->str, "Move count: ");
		ft_strcat(vars->str, tmp);
	}
	init_putgrid(vars);
	mlx_string_put(vars->mlx, vars->win, 5, y - 12, 0xFFFFFF, vars->str);
	mlx_do_sync(vars->mlx);
	free(tmp);
	free(vars->str);
	vars->str = NULL;
}

void	init_game(t_mlx *vars)
{
	vars->mlx = mlx_init();
	if (!vars->mlx)
		(error_handling(8), exit(1));
	init_sprites(vars);
	pre_load_sprites(vars);
	vars->win = mlx_new_window(vars->mlx, (vars->l_len - 1) * IMG_SIZE, \
	vars->ls_c * IMG_SIZE, "so_long");
	putgrid(vars);
	intput_movecount(vars);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->player_s, \
	vars->pos_x, vars->pos_y);
	mlx_hook(vars->win, 2, 1L << 0, keyboard_hooks, vars);
	mlx_hook(vars->win, 17, 1L << 0, close_window, vars);
	mlx_loop_hook(vars->mlx, on_game_update, vars);
	mlx_loop(vars->mlx);
}
