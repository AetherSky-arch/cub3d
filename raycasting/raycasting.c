/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftanon <ftanon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 10:13:34 by ftanon            #+#    #+#             */
/*   Updated: 2024/09/11 15:44:51 by ftanon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	destroy(t_mlx *mlx)
{
	ender(mlx);
	exit(0);
	return (0);
}

int	key_hook(int keycode, t_mlx *mlx)
{
	if (keycode == 65307)
	{
		ender(mlx);
		exit(0);
	}
	move_up_down(mlx, keycode);
	rotate_right(mlx, keycode);
	rotate_left(mlx, keycode);
	move_left_right(mlx, keycode);
	mlx_destroy_image(mlx->mlx_p, mlx->img);
	mlx->img = mlx_new_image(mlx->mlx_p, SW, SH);
	if (mlx->img == NULL)
		return (1);
	mlx->addr = mlx_get_data_addr(mlx->img, &mlx->bits_per_pixel,
			&mlx->line_length, &mlx->endian);
	if (mlx->addr == NULL)
		return (1);
	return (0);
}

int	raycasting(t_mlx *mlx)
{
	draw_floor_ceiling(mlx);
	draw_walls(mlx);
	mlx_put_image_to_window(mlx->mlx_p, mlx->win_ptr, mlx->img, 0, 0);
	return (0);
}

int	init_minilibx(t_mlx *mlx)
{
	mlx->mlx_p = mlx_init();
	if (mlx->mlx_p == NULL)
		return (printf("Error: minilibx init failed\n"), 1);
	mlx->win_ptr = mlx_new_window(mlx->mlx_p, SW, SH, "cub3d");
	if (mlx->win_ptr == NULL)
		return (1);
	mlx->img = mlx_new_image(mlx->mlx_p, SW, SH);
	if (mlx->img == NULL)
		return (1);
	mlx->addr = mlx_get_data_addr(mlx->img, &mlx->bits_per_pixel,
			&mlx->line_length, &mlx->endian);
	if (mlx->addr == NULL)
		return (1);
	if (store_images(mlx) == 1)
		return (1);
	if (store_images_addr(mlx) == 1)
		return (1);
	if (mlx_hook(mlx->win_ptr, KeyPress, KeyPressMask, &key_hook, mlx) == 1)
		return (1);
	mlx_hook(mlx->win_ptr, DestroyNotify, StructureNotifyMask, &destroy, mlx);
	mlx_loop_hook(mlx->mlx_p, raycasting, mlx);
	mlx_loop(mlx->mlx_p);
	return (0);
}
