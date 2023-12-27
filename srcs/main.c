/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdecleir <vdecleir@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 22:05:08 by vdecleir          #+#    #+#             */
/*   Updated: 2023/12/27 17:37:32 by vdecleir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static int	declaration(t_data *data)
{
	data->collec.count = 0;
	data->collec.game = 0;
	data->esc.count = 0;
	data->esc.x = 0;
	data->esc.y = 0;
	data->map.fd = 0;
	data->map.len = 0;
	data->map.high = 0;
	data->player.count = 0;
	data->player.x = 0;
	data->player.y = 0;
	data->count_moves = 0;
	data->anim_collec = 0;
	data->ennemy.count = 0;
	data->pars.collec = 0;
	data->pars.exit = 0;
	return (1);
}

int	main(int ac, char *av[])
{
	t_data	data;

	if (ac < 2)
		return (error_message(FEW_ARG));
	else if (ac > 2)
		return (error_message(MUCH_ARG));
	declaration(&data);
	data.map.name = av[1];
	if (map_check(&data) == -1)
		return (-1);
	if (render_map(&data) == -1)
		return (-1);
	return (1);
}
