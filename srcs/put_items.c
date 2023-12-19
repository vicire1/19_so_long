/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_items.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdecleir <vdecleir@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 13:14:34 by vdecleir          #+#    #+#             */
/*   Updated: 2023/12/19 13:15:45 by vdecleir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	put_background(t_data *data)
{
	int x;
	int y;

	x = 0;
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
	return (1);
}

int put_wall(t_data *data)
{
	int x;
	int y;

	x = 0;
	while (x < (data->map.len * 100))
	{
		y = 0;
		while (y < (data->map.high * 100))
		{
			if (data->map.layout && data->map.layout[y / 100][x / 100] == '1')
				mlx_put_image_to_window(data->mlx.ptr, data->mlx.win, data->xpm.wall, x, y);
			y += 100;
		}
		x += 100;
	}
	return (1);
}

int put_player(t_data *data)
{
	int x;
	int y;

	x = 0;
	while (x < (data->map.len * 100))
	{
		y = 0;
		while (y < (data->map.high * 100))
		{
			if (data->map.layout && data->map.layout[y / 100][x / 100] == 'P')
			{
				mlx_put_image_to_window(data->mlx.ptr, data->mlx.win, data->xpm.player_r, x, y);
				data->player.x = x / 100;
				data->player.y = y / 100;
			}
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
	while (x < (data->map.len * 100))
	{
		y = 0;
		while (y < (data->map.high * 100))
		{
			if (data->map.layout && data->map.layout[y / 100][x / 100] == 'E')
			{
				mlx_put_image_to_window(data->mlx.ptr, data->mlx.win, data->xpm.exit, x, y);
				data->exit.x = x / 100;
				data->exit.y = y / 100;
			}
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
