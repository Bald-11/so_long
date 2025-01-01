/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabarhda <yabarhda@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 14:07:56 by yabarhda          #+#    #+#             */
/*   Updated: 2024/12/25 16:01:01 by yabarhda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static int	dfs(char **tab, int x, int y)
{
	int	count;

	count = 1;
	if (tab[x][y] == '1' || tab[x][y] == 'F')
		return (0);
	tab[x][y] = 'F';
	if (tab[x + 1][y] == '0' || tab[x + 1][y] == 'C' || tab[x + 1][y] == 'E')
		count += dfs(tab, x + 1, y);
	if (tab[x - 1][y] == '0' || tab[x - 1][y] == 'C' || tab[x - 1][y] == 'E')
		count += dfs(tab, x - 1, y);
	if (tab[x][y + 1] == '0' || tab[x][y + 1] == 'C' || tab[x][y + 1] == 'E')
		count += dfs(tab, x, y + 1);
	if (tab[x][y - 1] == '0' || tab[x][y - 1] == 'C' || tab[x][y - 1] == 'E')
		count += dfs(tab, x, y - 1);
	return (count);
}

int	deep_map_check(t_mlx *vars, int lines, int line_len)
{
	int		i;
	int		return_val;
	char	**grid_copy;

	i = 0;
	grid_copy = (char **)malloc(sizeof(char *) * (lines + 1));
	if (!grid_copy)
		return (0);
	grid_copy[lines] = NULL;
	while (vars->grid[i])
	{
		grid_copy[i] = (char *)malloc(sizeof(char) * (line_len + 1));
		ft_strcpy(grid_copy[i], vars->grid[i]);
		i++;
	}
	i = 0;
	grid_copy[vars->player_grid_x][vars->player_grid_y] = '0';
	return_val = dfs(grid_copy, vars->player_grid_x, vars->player_grid_y);
	while (grid_copy[i])
		(free(grid_copy[i]), i++);
	free(grid_copy);
	if (return_val == (vars->ttl_coins + vars->ttl_zeros + 2))
		return (1);
	return (0);
}

int	map_case_handling(t_mlx *vars, char c)
{
	if (c == '0')
		vars->total_zeros++;
	else if (c == 'E')
		vars->e_count++;
	else if (c == 'P')
		vars->p_count++;
	else if (c == 'C')
		vars->c_count++;
	else if (c == '1' || c == 'G')
		return (1);
	else
		return (0);
	return (1);
}

int	standard_map_check(t_mlx *vars)
{
	int	i;
	int	j;

	i = 0;
	while (vars->grid[i])
	{
		j = 0;
		while (vars->grid[i][j])
		{
			if (!map_case_handling(vars, vars->grid[i][j]))
				return (0);
			j++;
		}
		i++;
	}
	if (vars->e_count != 1 || vars->p_count != 1 || vars->c_count < 1)
		return (0);
	return (1);
}

int	basic_map_check(t_mlx *vars)
{
	int	i;
	int	j;

	i = 0;
	while (vars->grid[i])
	{
		j = 0;
		while (vars->grid[i][j])
		{
			if (i == 0 && vars->grid[i][j] != '1')
				return (0);
			else if (vars->grid[i + 1] == NULL && vars->grid[i][j] != '1')
				return (0);
			else if (j == 0 && vars->grid[i][j] != '1')
				return (0);
			else if ((vars->grid)[i][j + 1] == '\0' && vars->grid[i][j] != '1')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
