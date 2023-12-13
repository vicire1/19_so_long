/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdecleir <vdecleir@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 16:57:45 by vdecleir          #+#    #+#             */
/*   Updated: 2023/12/13 19:36:21 by vdecleir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int check_line(char *str, t_so_long *so_long)
{
    int i;

    i = 0;
    while (i < so_long->map.len)
    {
        if (so_long->map.high == 1 && str[i] != '1')
            return (-1);
        else if (str[i] == 'C')
            so_long->map.collec++;
        else if (str[i] == 'P')
            so_long->map.player++;
        else if (str[i] == 'E')
            so_long->map.exit++;
        else if (str[i] != '0' && str[i] != '1')
            return (-1);
        i++;
    }
    if (str[0] != '1' || str[so_long->map.len - 1] != '1')
        return (-1);
    return (0);
}

int first_gnl(t_so_long *so_long)
{
    char    *line;
    int     len;

    so_long->map.fd = open(so_long->map.name, O_RDONLY);
    if (so_long->map.fd == -1)
        return (-1);
    line = get_next_line(so_long->map.fd);
    so_long->map.len = strlen_map(line);
    while (line)
    {
        so_long->map.high++;
        if (check_line(line, so_long) == -1)
            return (freenull(line));
        free(line);
        line = get_next_line(so_long->map.fd);
        if (!line)
            break ;
        len = strlen_map(line);
        if (len != so_long->map.len)
            return (freenull(line));
    }
    close(so_long->map.fd);
    return (1);
}

int check_last_line(t_so_long *so_long)
{
    char    *line;
    int     i;
    
    i = 0;
    so_long->map.fd = open(so_long->map.name, O_RDONLY);
    if (so_long->map.fd == -1)
        return (-1);
    while (i < (so_long->map.high - 1))
    {
        get_next_line(so_long->map.fd);
        i++;
    }
    line = get_next_line(so_long->map.fd);
    i = 0;
    while (i < so_long->map.len)
    {
        if (line[i] != '1')
            return (-1);
        i++;
    }
    freenull(line);
    close(so_long->map.fd);
    return (1);
}

int map_in_tab(t_so_long *so_long)
{
    int i;

    i = 0;
    so_long->map.layout = malloc(sizeof(char *) * (so_long->map.high + 1));
    if (!so_long->map.layout)
        return (-1);
    so_long->map.fd = open(so_long->map.name);
    if (so_long->map.fd == -1)
        return (-1);
    while(i < so_long->map.high)
    {
        so_long->map.layout[i] = get_next_line(so_long->map.fd);
        i++;
    }
    so_long->map.layout[i] = NULL;
    return (1);
}

int map_check(t_so_long *so_long)
{
    so_long->map.high = 0;
    so_long->map.collec = 0;
    so_long->map.player = 0;
    so_long->map.exit = 0;
    if (first_gnl(so_long) == -1 || so_long->map.exit != 1 ||
    so_long->map.player != 1 || so_long->map.collec < 1)
        return (-1);
    if (check_last_line(so_long) == -1)
        return (-1);
    return (1);
}
