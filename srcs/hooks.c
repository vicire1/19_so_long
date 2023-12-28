/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdecleir <vdecleir@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 12:55:51 by vdecleir          #+#    #+#             */
/*   Updated: 2023/12/28 02:19:11 by vdecleir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	escape(int keycode, t_data *data, int i)
{
	(void)keycode;
	if (i == -1)
		ft_printf("WASTED\n");
	if (i == 1)
		ft_printf("You Won !\n");
	freetab(data, data->map.high, 0, "");
	mlx_destroy_window(data->mlx.ptr, data->mlx.win);
	system("leaks so_long");
	exit(0);
}

int	cross_escape(t_data *data)
{
	escape(0, data, 0);
	return (1);
}

static int	orientation_player(t_data *data, int x, int y, int orientation)
{
	if (orientation == 0)
		put_image(data, data->xpm.plr_l, x * PXL, y * PXL);
	else if (orientation == 1)
		put_image(data, data->xpm.plr_r, x * PXL, y * PXL);
	else if (orientation == 2)
		put_image(data, data->xpm.plr_u, x * PXL, y * PXL);
	else if (orientation == 3)
		put_image(data, data->xpm.plr_d, x * PXL, y * PXL);
	return (1);
}

static int	move(t_data *data, int x, int y, int orientation)
{
	if (data->map.layout[y][x] == '1')
		return (1);
	data->count_moves++;
	ft_printf("Number of moves : %d\n", data->count_moves);
	if (data->map.layout[y][x] == 'X')
		return (escape(0, data, -1));
	if (data->map.layout[y][x] == 'C')
	{
		data->collec.game++;
		data->map.layout[y][x] = '0';
	}
	put_image(data, data->xpm.bg, data->player.x * PXL, data->player.y * PXL);
	put_image(data, data->xpm.bg, x * PXL, y * PXL);
	if (data->collec.count == data->collec.game)
		put_image(data, data->xpm.esc_o, data->esc.x * PXL, data->esc.y * PXL);
	else
		put_image(data, data->xpm.esc_c, data->esc.x * PXL, data->esc.y * PXL);
	orientation_player(data, x, y, orientation);
	data->player.x = x;
	data->player.y = y;
	if (data->collec.count == data->collec.game && data->player.x == data->esc.x
		&& data->player.y == data->esc.y)
		escape(0, data, 1);
	return (1);
}

int	key_press(int keycode, t_data *data)
{
	(void)data;
	if (keycode == A)
		move(data, data->player.x - 1, data->player.y, 0);
	if (keycode == D)
		move(data, data->player.x + 1, data->player.y, 1);
	if (keycode == W)
		move(data, data->player.x, data->player.y - 1, 2);
	if (keycode == S)
		move(data, data->player.x, data->player.y + 1, 3);
	if (keycode == ESC)
		escape(keycode, data, 0);
	return (0);
}
