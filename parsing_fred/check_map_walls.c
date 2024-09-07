/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_walls.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftanon <ftanon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 17:29:23 by ftanon            #+#    #+#             */
/*   Updated: 2024/09/07 19:27:16 by ftanon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	check_map_walls_x(t_mlx *mlx)
{
	int y;
	int x;

	y = 0;
	while(y < mlx->map_height)
	{
		x = 0;
		while (x < mlx->map_width)
		{
			while(x < mlx->map_width && mlx->map_int_one[y][x] == 2)
				x++;
			// printf("%d %d %d\n",y, x, mlx->map_int_one[y][x]);
			if (x < mlx->map_width && mlx->map_int_one[y][x] != 1)
			{
				printf("x error 1 map %d %d\n", y ,x);
				return (1);
			}
			else if (x == mlx->map_width)
				break;
			while(x < mlx->map_width && mlx->map_int_one[y][x] != 2)
				x++;
			if (mlx->map_int_one[y][x - 1] != 1)
			{
				printf("x error 2  map %d %d\n", y ,x - 1);
				return (1);
			}
		}
		y++;
	}
	return (0);
}

int	check_map_walls_y(t_mlx *mlx)
{
	int y;
	int x;

	x = 0;
	while(x < mlx->map_width)
	{
		y = 0;
		while (y < mlx->map_height)
		{
			while(y < mlx->map_height && mlx->map_int_one[y][x] == 2)
				y++;
			// printf("%d %d %d\n", x, y, mlx->map_height);
			if (y < mlx->map_height && mlx->map_int_one[y][x] != 1)
			{
				printf("y error  1map %d %d\n", y ,x);
				return (1);
			}
			else if (y == mlx->map_height)
				break;
			while(y < mlx->map_height && mlx->map_int_one[y][x] != 2)
				y++;
			if (mlx->map_int_one[y - 1][x] != 1)
			{
				printf("y error 2 map %d %d\n", y - 1 ,x);
				return (1);
			}
		}
		x++;
	}
	return (0);
}

int	check_map_walls(t_mlx *mlx)
{
	if (check_map_walls_x(mlx) == 1)
		return (1);
	if (check_map_walls_y(mlx) == 1)
		return (1);
	return (0);
}