/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdecleir <vdecleir@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 15:16:57 by vdecleir          #+#    #+#             */
/*   Updated: 2023/12/27 18:06:57 by vdecleir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static int  freepars(t_data *data, int high)
{
    int	i;

	i = 0;
	while (i < high)
	{
		free(data->pars.map[i]);
		data->pars.map[i] = NULL;
		i++;
	}
	free(data->pars.map);
	data->pars.map = NULL;
	return (-1);
}

static int parsing(t_data *data, int x, int y)
{
    if (x > 0 && x < data->map.len - 1 && y > 0 && y < data->map.high - 1)
    {
        if (data->pars.map[y][x] == '1' || data->pars.map[y][x] == 'X' || data->pars.map[y][x] == 'V')
            return (1);
        if (data->pars.map[y][x] == '0' || data->pars.map[y][x] == 'P')
            data->pars.map[y][x] = 'V';
        if (data->pars.map[y][x] == 'C')
        {
            data->pars.map[y][x] = 'V';
            data->pars.collec++;
        }
        if (data->pars.map[y][x] == 'E')
        {
            data->pars.map[y][x] = 'V';
            data->pars.exit++;
        }
        parsing(data, x + 1, y);
        parsing(data, x - 1, y);
        parsing(data, x, y + 1);
        parsing(data, x, y - 1);
    }
    return (1);
}

static int cpy_parsing_map(t_data *data)
{
    int i;
    int j;

    i = 0;
    data->pars.map = malloc(sizeof(char *) * (data->map.high + 1));
    if (!data->pars.map)
        return (-1);
    while (data->map.layout[i])
    {
        j = 0;
        data->pars.map[i] = malloc(sizeof(char) * (data->map.len + 1));
        if (!data->pars.map[i])
            return (freepars(data, i));
        while (data->map.layout[i][j])
        {
            data->pars.map[i][j] = data->map.layout[i][j];
            j++;
        }
        i++;
    }
    return (1);
}

int check_playable(t_data *data)
{
    cpy_parsing_map(data);
    parsing(data, data->player.x, data->player.y);
    freepars(data, data->map.high);
    if (data->collec.count != data->pars.collec || data->pars.exit != 1)
        return (-1);
    return (1);
}