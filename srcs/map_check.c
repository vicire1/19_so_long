/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdecleir <vdecleir@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 16:57:45 by vdecleir          #+#    #+#             */
/*   Updated: 2023/12/27 18:17:04 by vdecleir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static int	check_line(char *str, t_data *data, int i, int j)
{
	while (j < data->map.len)
	{
		if (i == 0 && str[j] != '1')
			return (error_message(INV_WALL));
		else if (str[j] == 'C')
			data->collec.count++;
		else if (str[j] == 'P')
		{
			data->player.x = j;
			data->player.y = i;	
			data->player.count++;
		}
		else if (str[j] == 'E')
			data->esc.count++;
		else if (str[j] == 'X')
			data->ennemy.count++;
		else if (str[j] != '0' && str[j] != '1')
			return (error_message(INV_CHAR));
		j++;
	}
	if (str[0] != '1' || str[data->map.len - 1] != '1')
		return (error_message(INV_WALL));
	return (0);
}

static int	tab_size(t_data *data)
{
	char	*line;

	data->map.fd = open(data->map.name, O_RDONLY);
	if (data->map.fd == -1)
		return (-1);
	line = get_next_line(data->map.fd);
	while (line)
	{
		free(line);
		line = NULL;
		data->map.high++;
		line = get_next_line(data->map.fd);
	}
	close(data->map.fd);
	return (data->map.high);
}

static int	map_in_tab(t_data *data)
{
	int	i;
	int	j;

	j = 0;
	data->map.layout = malloc(sizeof(char *) * (tab_size(data) + 1));
	data->map.fd = open(data->map.name, O_RDONLY);
	if (data->map.fd == -1 || !data->map.layout)
		return (-1);
	i = 0;
	data->map.layout[i] = get_next_line(data->map.fd);
	data->map.len = strlen_map(data->map.layout[i]);
	while (data->map.layout[i])
	{
		if (check_line(data->map.layout[i], data, i, j) == -1)
			return (freetab(data, i, 0, ""));
		i++;
		data->map.layout[i] = get_next_line(data->map.fd);
		if (!data->map.layout[i])
			break ;
		if (strlen_map(data->map.layout[i]) != data->map.len)
			return (freetab(data, i, 1, INV_MAP));
	}
	close(data->map.fd);
	return (1);
}

int	map_check(t_data *data)
{
	int	i;

	i = 0;
	if (map_in_tab(data) == -1)
		return (-1);
	if (data->map.high > 21 || data->map.len > 40)
		return (freetab(data, data->map.high, 1, TOO_BIG));
	if (data->esc.count != 1 || data->player.count != 1
		|| data->collec.count < 1)
		return (freetab(data, data->map.high, 1, INV_CPE));
	while (i < data->map.len)
	{
		if (data->map.layout[data->map.high - 1][i] != '1')
			return (freetab(data, data->map.high, 1, INV_WALL));
		i++;
	}
	if (check_playable(data) == -1)
		return (freetab(data, data->map.high, 1, PARS));
	return (1);
}
