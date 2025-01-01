/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabarhda <yabarhda@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 11:55:43 by yabarhda          #+#    #+#             */
/*   Updated: 2024/12/26 16:15:20 by yabarhda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	fill_map_grid(int l_len, char *grid, char *arr)
{
	int	j;

	j = 0;
	while (j < l_len)
	{
		if (grid[j] == '\n' || grid[j] == '\0')
		{
			arr[j] = '\0';
			free(grid);
			break ;
		}
		arr[j] = grid[j];
		j++;
	}
}

int	last_line(char *grid)
{
	int	i;

	i = 0;
	while (grid[i])
	{
		if (grid[i] == '\n')
			return (0);
		i++;
	}
	return (1);
}

char	**read_write_map(char *grid, int ls_c, int l_len, int fd)
{
	char	**arr;
	int		i;
	int		tmp;

	(1) && (i = 0, arr = (char **)malloc((sizeof(char *)) * (ls_c + 1)));
	if (!arr)
		return (NULL);
	arr[ls_c] = NULL;
	while (i < ls_c)
	{
		(1) && (grid = get_next_line(fd), tmp = ft_strlen(grid));
		if (tmp == l_len || ((i + 1 == ls_c) && (tmp == l_len - 1)))
		{
			if (i + 1 == ls_c && last_line(grid))
				arr[i] = (char *)malloc(sizeof(char) * l_len);
			else
				arr[i] = (char *)malloc(sizeof(char) * l_len + 1);
			fill_map_grid(l_len, grid, arr[i]);
		}
		else
			(error_handling(3), free(grid), \
			arr[i] = (char *)malloc(sizeof(char)), free_arr(arr), exit(1));
		i++;
	}
	return (arr);
}

int	get_grid(int fd, char *grid, int l_len, char *path)
{
	int	i;
	int	ls_c;
	int	ll_len;

	ls_c = 0;
	i = 0;
	while (grid)
	{
		ll_len = ft_strlen(grid);
		if (ll_len != l_len && !last_line(grid))
			force_free_grid(fd, grid, path);
		if (grid[i] == '\n' || grid[i] == '\0')
		{
			ls_c++;
			(1) && (free(grid), grid = get_next_line(fd));
			i = 0;
			continue ;
		}
		if (!grid)
			break ;
		i++;
	}
	close(fd);
	return (ls_c);
}

int	check_map_file(t_mlx *vars, char *path)
{
	int		fd;
	char	*grid;
	int		ls_c;
	int		l_len;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		(error_handling(1), free(path), exit(1));
	grid = get_next_line(fd);
	if (!grid)
		(error_handling(2), free(path), exit(1));
	(1) && (l_len = ft_strlen(grid), ls_c = get_grid(fd, grid, l_len, path));
	if (l_len < 5 || ls_c < 3)
		(error_handling(7), free(path), exit(1));
	(1) && (fd = open(path, O_RDONLY), free(path), vars->grid = \
	read_write_map(grid, ls_c, l_len, fd));
	simple_grid_check(fd, grid);
	init_basic_vars(vars, ls_c, l_len);
	if (!basic_map_check(vars))
		(error_handling(4), free_arr(vars->grid), exit(1));
	if (!standard_map_check(vars))
		(error_handling(5), free_arr(vars->grid), exit(1));
	if (!deep_map_check(vars, ls_c, l_len))
		(error_handling(6), free_arr(vars->grid), exit(1));
	return (1);
}
