/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_items.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdecleir <vdecleir@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 13:14:34 by vdecleir          #+#    #+#             */
/*   Updated: 2023/12/22 18:29:38 by vdecleir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	put_items(t_data *data, int x, int y)
{
	mlx_put_image_to_window(data->mlx.ptr, data->mlx.win, data->xpm.bg, x, y);
	if (data->map.layout && data->map.layout[y / PXL][x / PXL] == '1')
		mlx_put_image_to_window(data->mlx.ptr, data->mlx.win, data->xpm.wall, x, y);
	else if (data->map.layout && data->map.layout[y / PXL][x / PXL] == 'P')
	{
		mlx_put_image_to_window(data->mlx.ptr, data->mlx.win, data->xpm.player_r, x, y);
		data->player.x = x / PXL;
		data->player.y = y / PXL;
	}
	else if (data->map.layout && data->map.layout[y / PXL][x / PXL] == 'E')
	{
		mlx_put_image_to_window(data->mlx.ptr, data->mlx.win, data->xpm.exit_c, x, y);
		data->exit.x = x / PXL;
		data->exit.y = y / PXL;
	}
	else if (data->map.layout && data->map.layout[y / PXL][x / PXL] == 'C')
		mlx_put_image_to_window(data->mlx.ptr, data->mlx.win, data->xpm.collec, x, y);
	return (1);
}

int	put_map(t_data *data)
{
	int x;
	int y;

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
