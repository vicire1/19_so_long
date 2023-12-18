/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdecleir <vdecleir@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 17:51:59 by vdecleir          #+#    #+#             */
/*   Updated: 2023/12/18 17:45:35 by vdecleir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int freetab(t_data *data, int boolean, char *mess)
{
    int i;

    i = 0;
    while (data->map.layout[i])
    {
        free(data->map.layout[i]);
        data->map.layout[i] = NULL;
        i++;
    }
    free(data->map.layout);
    data->map.layout = NULL;
    if (boolean == 1)
        error_message(mess);
    return (-1);
}

int strlen_map(char *str)
{
    int i;

    i = 0;
    if (!str)
        return (0);
    while (str[i] && str[i] != '\n')
        i++;
    return (i);
}

int error_message(char *str)
{
    int i;

    i = 0;
    if (!str)
        return (0);
    write (1, "Error.\n", 8);
    while(str[i])
    {
        write(1, &str[i], 1);
        i++;
    }
    return (-1);
}