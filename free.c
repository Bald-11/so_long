/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabarhda <yabarhda@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 14:06:33 by yabarhda          #+#    #+#             */
/*   Updated: 2024/12/25 16:00:34 by yabarhda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	free_arr(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
		(free(arr[i]), i++);
	free(arr);
}

void	free_vars(t_mlx *vars)
{
	int	i;

	i = 0;
	while (vars->grid[i])
		(free(vars->grid[i]), i++);
	i = 0;
	while (i < vars->c_count)
		(free(vars->coin_pos[i]), i++);
	free(vars->coin_pos);
	free(vars->grid);
	free(vars->coin_frames);
}

void	destroy_sprites(t_mlx *vars)
{
	int	i;

	i = 0;
	if (vars->exit)
		mlx_destroy_image(vars->mlx, vars->exit);
	if (vars->player_w)
		mlx_destroy_image(vars->mlx, vars->player_w);
	if (vars->player_e)
		mlx_destroy_image(vars->mlx, vars->player_e);
	if (vars->player_s)
		mlx_destroy_image(vars->mlx, vars->player_s);
	if (vars->player_n)
		mlx_destroy_image(vars->mlx, vars->player_n);
	if (vars->wall)
		mlx_destroy_image(vars->mlx, vars->wall);
	if (vars->background)
		mlx_destroy_image(vars->mlx, vars->background);
	if (vars->enemy)
		mlx_destroy_image(vars->mlx, vars->enemy);
	while (i < 8 && vars->coin_frames[i])
		mlx_destroy_image(vars->mlx, vars->coin_frames[i++]);
}

int	close_window(t_mlx *vars)
{
	destroy_sprites(vars);
	free_vars(vars);
	mlx_destroy_window(vars->mlx, vars->win);
	mlx_destroy_display(vars->mlx);
	free(vars->mlx);
	exit(0);
}

void	image_err_free(t_mlx *vars)
{
	destroy_sprites(vars);
	free_vars(vars);
	mlx_destroy_display(vars->mlx);
	free(vars->mlx);
}
