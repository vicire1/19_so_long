/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdecleir <vdecleir@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 16:57:45 by vdecleir          #+#    #+#             */
/*   Updated: 2023/12/14 18:34:56 by vdecleir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int check_line(char *str, t_data *data, int a)
{
    int i;

    i = 0;
    while (i < data->map.len)
    {
        if (a == 0 && str[i] != '1')
            return (error_message(INV_WALL));
        else if (str[i] == 'C')
            data->collec.count++;
        else if (str[i] == 'P')
            data->player.count++;
        else if (str[i] == 'E')
            data->exit.count++;
        else if (str[i] != '0' && str[i] != '1')
            return (error_message(INV_CHAR));
        i++;
    }
    if (str[0] != '1' || str[data->map.len - 1] != '1')
        return (error_message(INV_WALL));
    return (0);
}

int tab_size(t_data *data)
{
    char    *line;
    
    data->map.fd = open(data->map.name, O_RDONLY);
    if (data->map.fd == -1)
        return (-1);
    line = get_next_line(data->map.fd);
    while (line)
    {
        data->map.high++;
        line = get_next_line(data->map.fd);
    }
    close(data->map.fd);
    return (data->map.high);
}

int map_in_tab(t_data *data)
{
    int     i;
    int     len;

    data->map.layout = malloc(sizeof(char *) * (tab_size(data) + 1));
    data->map.fd = open(data->map.name, O_RDONLY);
    if (data->map.fd == -1 || !data->map.layout)
        return (-1);
    i = 0;
    data->map.layout[i] = get_next_line(data->map.fd);
    data->map.len = strlen_map(data->map.layout[i]);
    while (data->map.layout[i])
    {
        if (check_line(data->map.layout[i], data, i) == -1)
            return (freetab(data->map.layout, 0, ""));
        i++;
        data->map.layout[i] = get_next_line(data->map.fd);
        if (!data->map.layout[i])
            break ;
        len = strlen_map(data->map.layout[i]);
        if (len != data->map.len)
            return (freetab(data->map.layout, 0, ""));
    }
    close(data->map.fd);
    return (1);
}

// int check_last_line(t_data *data)
// {
//     char    *line;
//     int     i;
    
//     i = 0;
//     data->map.fd = open(data->map.name, O_RDONLY);
//     if (data->map.fd == -1)
//         return (-1);
//     while (i < (data->map.high - 1))
//     {
//         get_next_line(data->map.fd);
//         i++;
//     }
//     line = get_next_line(data->map.fd);
//     i = 0;
//     while (i < data->map.len)
//     {
//         if (line[i] != '1')
//             return (-1);
//         i++;
//     }
//     freenull(line);
//     close(data->map.fd);
//     return (1);
// }

// int map_in_tab(t_data *data)
// {
//     int i;

//     i = 0;
//     data->map.layout = malloc(sizeof(char *) * (data->map.high + 1));
//     if (!data->map.layout)
//         return (-1);
//     data->map.fd = open(data->map.name, O_RDONLY);
//     if (data->map.fd == -1)
//         return (-1);
//     while(i < data->map.high)
//     {
//         data->map.layout[i] = get_next_line(data->map.fd);
//         i++;
//     }
//     data->map.layout[i] = NULL;
//     return (1);
// }

int map_check(t_data *data)
{
    int i;

    i = 0;
    if (map_in_tab(data) == -1)
        return (-1);
    // printf("%d\n", data->collec.count);
    // printf("%d\n", data->exit.count);
    // printf("%d\n", data->player.count);
    if (data->exit.count != 1 || data->player.count != 1 ||
    data->collec.count < 1)
        return (freetab(data->map.layout, 1, INV_CPE));
    while (i < data->map.len)
    {
        if (data->map.layout[data->map.high - 1][i] != '1')
            return (freetab(data->map.layout, 1, INV_WALL));
        i++;
    }
    return (1);
}
