/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabarhda <yabarhda@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 13:20:30 by yabarhda          #+#    #+#             */
/*   Updated: 2024/12/26 10:51:51 by yabarhda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	error_handling(int error)
{
	ft_printf("Error\n");
	if (error == 1)
		ft_printf("No such file.\n");
	else if (error == 2)
		ft_printf("Empty file.\n");
	else if (error == 3)
		ft_printf("Imbalance in map grid.\n");
	else if (error == 4)
		ft_printf("The map has no boundaries.\n");
	else if (error == 5)
		ft_printf("The map doesn't meet the basic requirements.\n");
	else if (error == 6)
		ft_printf("The map has no valid path.\n");
	else if (error == 7)
		ft_printf("Not enough map data.\n");
	else if (error == 8)
		ft_printf("Mlx error.\n");
	else if (error == 9)
		ft_printf("Invalid sprite name/file.\n");
}
