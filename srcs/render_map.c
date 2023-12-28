/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdecleir <vdecleir@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 16:10:31 by vdecleir          #+#    #+#             */
/*   Updated: 2023/12/28 19:16:35 by vdecleir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static int	put_items(t_data *data, int x, int y)
{
	put_image(data, data->xpm.bg, x, y);
	if (data->map.layout && data->map.layout[y / PXL][x / PXL] == '1')
		put_image(data, data->xpm.wall, x, y);
	else if (data->map.layout && data->map.layout[y / PXL][x / PXL] == 'P')
		put_image(data, data->xpm.plr_d, x, y);
	else if (data->map.layout && data->map.layout[y / PXL][x / PXL] == 'E')
	{
		put_image(data, data->xpm.esc_c, x, y);
		data->esc.x = x / PXL;
		data->esc.y = y / PXL;
	}
	else if (data->map.layout && data->map.layout[y / PXL][x / PXL] == 'C')
		put_image(data, data->xpm.collec1, x, y);
	else if (data->map.layout && data->map.layout[y / PXL][x / PXL] == 'X')
		put_image(data, data->xpm.ennemy1, x, y);
	return (1);
}

static int	put_map(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (y < (data->map.high * PXL))
	{
		x = 0;
		while (x < (data->map.len * PXL))
		{
			put_items(data, x, y);
			x += PXL;
		}
		y += PXL;
	}
	return (1);
}

int	xpm_in_struct2(t_data *data, int w, int h)
{
	data->xpm.collec1 = mlx_xpm_file_to_image(data->mlx.ptr, "./img/coin1.xpm",
			&w, &h);
	data->xpm.collec2 = mlx_xpm_file_to_image(data->mlx.ptr, "./img/coin2.xpm",
			&w, &h);
	data->xpm.collec3 = mlx_xpm_file_to_image(data->mlx.ptr, "./img/coin3.xpm",
			&w, &h);
	data->xpm.collec4 = mlx_xpm_file_to_image(data->mlx.ptr, "./img/coin4.xpm",
			&w, &h);
	data->xpm.collec5 = mlx_xpm_file_to_image(data->mlx.ptr, "./img/coin5.xpm",
			&w, &h);
	data->xpm.ennemy1 = mlx_xpm_file_to_image(data->mlx.ptr,
			"./img/ennemy1.xpm", &w, &h);
	data->xpm.ennemy2 = mlx_xpm_file_to_image(data->mlx.ptr,
			"./img/ennemy2.xpm", &w, &h);
	data->xpm.bg = mlx_xpm_file_to_image(data->mlx.ptr, "./img/grass.xpm", &w,
			&h);
	data->xpm.wall = mlx_xpm_file_to_image(data->mlx.ptr, "./img/arbre.xpm", &w,
			&h);
	return (1);
}

static int	xpm_in_struct(t_data *data)
{
	int	w;
	int	h;

	data->xpm.plr_l = mlx_xpm_file_to_image(data->mlx.ptr, "./img/player_L.xpm",
			&w, &h);
	data->xpm.plr_r = mlx_xpm_file_to_image(data->mlx.ptr, "./img/player_R.xpm",
			&w, &h);
	data->xpm.plr_d = mlx_xpm_file_to_image(data->mlx.ptr, "./img/player_D.xpm",
			&w, &h);
	data->xpm.plr_u = mlx_xpm_file_to_image(data->mlx.ptr, "./img/player_U.xpm",
			&w, &h);
	data->xpm.esc_c = mlx_xpm_file_to_image(data->mlx.ptr, "./img/exit_c.xpm",
			&w, &h);
	data->xpm.esc_o = mlx_xpm_file_to_image(data->mlx.ptr, "./img/exit_o.xpm",
			&w, &h);
	xpm_in_struct2(data, w, h);
	if (!data->xpm.bg || !data->xpm.collec1 || !data->xpm.collec2
		|| !data->xpm.collec3 || !data->xpm.collec4 || !data->xpm.collec5
		|| !data->xpm.ennemy1 || !data->xpm.ennemy2 || !data->xpm.esc_c
		|| !data->xpm.esc_o || !data->xpm.plr_d || !data->xpm.plr_l
		|| !data->xpm.plr_r || !data->xpm.plr_u || !data->xpm.wall)
		return (-1);
	return (1);
}

int	render_map(t_data *data)
{
	data->mlx.ptr = mlx_init();
	if (xpm_in_struct(data) == -1)
		return (freetab(data, data->map.high, 1, XPM));
	data->mlx.win = mlx_new_window(data->mlx.ptr, (data->map.len * PXL),
			(data->map.high * PXL), "So_Long");
	put_map(data);
	mlx_hook(data->mlx.win, 17, 0, &cross_escape, data);
	mlx_hook(data->mlx.win, 2, 0, &key_press, data);
	mlx_loop_hook(data->mlx.ptr, &anim, data);
	mlx_loop(data->mlx.ptr);
	return (1);
}
