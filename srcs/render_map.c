/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdecleir <vdecleir@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 16:10:31 by vdecleir          #+#    #+#             */
/*   Updated: 2023/12/20 19:28:29 by vdecleir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int xpm_in_struct(t_data *data)
{
	int w;
	int h;

	data->xpm.player_l = mlx_xpm_file_to_image(data->mlx.ptr, "./img/plr_l1.xpm", &w, &h);
	data->xpm.player_r = mlx_xpm_file_to_image(data->mlx.ptr, "./img/plr_r1.xpm", &w, &h);
	data->xpm.exit = mlx_xpm_file_to_image(data->mlx.ptr, "./img/exit_c.xpm", &w, &h);
	data->xpm.background = mlx_xpm_file_to_image(data->mlx.ptr, "./img/grass.xpm", &w, &h);
	data->xpm.wall = mlx_xpm_file_to_image(data->mlx.ptr, "./img/water.xpm", &w, &h);
	data->xpm.collec = mlx_xpm_file_to_image(data->mlx.ptr, "./img/barrel.xpm", &w, &h);
	return (0);
}

int	render_map(t_data *data)
{
	data->mlx.ptr = mlx_init();
	data->mlx.win = mlx_new_window(data->mlx.ptr, (data->map.len * 100), (data->map.high * 100), "So_Long");
	xpm_in_struct(data);
	put_background(data);
	put_wall(data);
	put_collec(data);
	put_exit(data);
	put_player(data);
	if (mlx_hook(data->mlx.win, 17, 0, &escape, data) == -1)
		return (-1);
	mlx_hook(data->mlx.win, 2, 0, &key_press, data);
	mlx_loop(data->mlx.ptr);
	return (1);
}
