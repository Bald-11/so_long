/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabarhda <yabarhda@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 10:22:34 by yabarhda          #+#    #+#             */
/*   Updated: 2024/12/24 13:43:07 by yabarhda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	main(int argc, char *argv[])
{
	t_mlx	vars;

	vars.c_count = 0;
	vars.p_count = 0;
	vars.e_count = 0;
	vars.total_zeros = 0;
	if (argc == 2 && valid_map(&vars, argv[1]))
	{
		init_game(&vars);
	}
	return (0);
}
