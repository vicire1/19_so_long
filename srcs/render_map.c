/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdecleir <vdecleir@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 16:10:31 by vdecleir          #+#    #+#             */
/*   Updated: 2023/12/16 16:53:29 by vdecleir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	render_map(t_data *data)
{
	void	*mlx;
	void	*mlx_win;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, (data->map.high * 100), (data->map.len * 100),
    "So_Long");
	img.img = mlx_new_image(mlx, (data->map.high * 100), (data->map.len * 100));
	my_mlx_pixel_put(&img, 5, 5, 0x00FF0000);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}

int xpm_in_struct(t_data *data)
{
    mlx_xpm_file_to_image(data->xpm.player_l, "../img/plr_l1.xpm", 100, 100);
    mlx_xpm_file_to_image(data->xpm.player_r, "../img/plr_r1.xpm", 100, 100);
    mlx_xpm_file_to_image(data->xpm.exit, "../img/exit.xpm", 100, 100);
    mlx_xpm_file_to_image(data->xpm.background, "../img/grass.xpm", 100, 100);
    mlx_xpm_file_to_image(data->xpm.wall, "../img/water.xpm", 100, 100);
    mlx_xpm_file_to_image(data->xpm.collec, "../img/barrel.xpm", 100, 100);
    return (0);
}