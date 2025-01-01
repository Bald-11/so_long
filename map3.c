/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map3.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabarhda <yabarhda@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 08:54:42 by yabarhda          #+#    #+#             */
/*   Updated: 2024/12/26 16:13:22 by yabarhda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	valid_map(t_mlx *vars, char *map)
{
	char	*path;

	path = (char *)malloc(sizeof(char) * (7 + ft_strlen(map) + 1));
	ft_strcpy(path, "./maps/");
	ft_strcat(path, map);
	if (check_map_file(vars, path))
		return (1);
	return (0);
}

void	force_free_grid(int fd, char *grid, char *path)
{
	int	i;

	i = 0;
	while (grid)
	{
		if (grid[i] == '\n' || grid[i] == '\0')
		{
			(1) && (free(grid), grid = get_next_line(fd));
			i = 0;
			continue ;
		}
		if (!grid)
			break ;
		i++;
	}
	close(fd);
	(error_handling(3), free(grid), free(path), exit(1));
}

void	simple_grid_check(int fd, char *grid)
{
	if (grid)
		grid = get_next_line(fd);
	if (grid)
		free(grid);
	close(fd);
}
