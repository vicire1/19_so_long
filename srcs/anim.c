/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   anim.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdecleir <vdecleir@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 18:14:17 by vdecleir          #+#    #+#             */
/*   Updated: 2023/12/29 14:59:44 by vdecleir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static int	anim_ennemy(t_data *data, size_t x, size_t y)
{
	put_image(data, data->xpm.bg, x, y);
	if (data->anim_collec > 25)
		put_image(data, data->xpm.ennemy1, x, y);
	else
		put_image(data, data->xpm.ennemy2, x, y);
	return (1);
}

static int	anim_coin(t_data *data, size_t x, size_t y)
{
	put_image(data, data->xpm.bg, x, y);
	if (data->anim_collec > 40)
		put_image(data, data->xpm.collec5, x, y);
	else if (data->anim_collec > 30)
		put_image(data, data->xpm.collec4, x, y);
	else if (data->anim_collec > 20)
		put_image(data, data->xpm.collec3, x, y);
	else if (data->anim_collec > 10)
		put_image(data, data->xpm.collec2, x, y);
	else if (data->anim_collec > 0)
		put_image(data, data->xpm.collec1, x, y);
	return (1);
}

static int	anim_loop(t_data *data)
{
	size_t	x;
	size_t	y;

	y = 0;
	while (y < (data->map.high * PXL))
	{
		x = 0;
		while (x < (data->map.len * PXL))
		{
			if (data->map.layout[y / PXL][x / PXL] == 'C')
				anim_coin(data, x, y);
			if (data->map.layout[y / PXL][x / PXL] == 'X')
				anim_ennemy(data, x, y);
			x += PXL;
		}
		y += PXL;
	}
	return (1);
}

int	anim(t_data *data)
{
	anim_loop(data);
	if (data->anim_collec == 50)
		data->anim_collec = 0;
	data->anim_collec++;
	return (1);
}
