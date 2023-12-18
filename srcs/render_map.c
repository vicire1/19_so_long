/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdecleir <vdecleir@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 16:10:31 by vdecleir          #+#    #+#             */
/*   Updated: 2023/12/18 19:49:23 by vdecleir         ###   ########.fr       */
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

int put_wall(t_data *data)
{
	int x;
	int y;

	x = 0;
	y = 0;
	while (y < (data->map.len * 100))
	{
		x = 0;
		while (x < (data->map.high * 100))
		{
			if (data->map.layout && data->map.layout[x / 100][y / 100] == '1')
				mlx_put_image_to_window(data->mlx.ptr, data->mlx.win, data->xpm.wall, y, x);
			x += 100;
		}
		y += 100;
	}
	return (1);
}

int put_player(t_data *data)
{
	int x;
	int y;

	x = 0;
	y = 0;
	while (x < (data->map.len * 100))
	{
		y = 0;
		while (y < (data->map.high * 100))
		{
			if (data->map.layout && data->map.layout[y / 100][x / 100] == 'P')
				mlx_put_image_to_window(data->mlx.ptr, data->mlx.win, data->xpm.player_r, x, y);
			y += 100;
		}
		x += 100;
	}
	return (1);
}

int put_exit(t_data *data)
{
	int x;
	int y;

	x = 0;
	y = 0;
	while (x < (data->map.len * 100))
	{
		y = 0;
		while (y < (data->map.high * 100))
		{
			if (data->map.layout && data->map.layout[y / 100][x / 100] == 'E')
				mlx_put_image_to_window(data->mlx.ptr, data->mlx.win, data->xpm.exit, x, y);
			y += 100;
		}
		x += 100;
	}
	return (1);
}

int put_collec(t_data *data)
{
	int x;
	int y;

	x = 0;
	y = 0;
	while (x < (data->map.len * 100))
	{
		y = 0;
		while (y < (data->map.high * 100))
		{
			if (data->map.layout && data->map.layout[y / 100][x / 100] == 'C')
				mlx_put_image_to_window(data->mlx.ptr, data->mlx.win, data->xpm.collec, x, y);
			y += 100;
		}
		x += 100;
	}
	return (1);
}

int	render_map(t_data *data)
{
	int x;
	int y;

	x = 0;
	data->mlx.ptr = mlx_init();
	data->mlx.win = mlx_new_window(data->mlx.ptr, (data->map.len * 100), (data->map.high * 100), "So_Long");
	xpm_in_struct(data);
	while (x < (data->map.len * 100))
	{
		y = 0;
		while (y < (data->map.high * 100))
		{
			mlx_put_image_to_window(data->mlx.ptr, data->mlx.win, data->xpm.background, x, y);
			y += 100;
		}
		x += 100;
	}
	put_wall(data);
	put_collec(data);
	put_exit(data);
	put_player(data);
	mlx_loop(data->mlx.ptr);
	return (1);
}
