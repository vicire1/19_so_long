/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdecleir <vdecleir@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 16:57:45 by vdecleir          #+#    #+#             */
/*   Updated: 2023/12/12 19:23:22 by vdecleir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

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

int map_check(char *str)
{
    char    *line;
    t_map   map;
    int     len;
    
    map.fd = open(str, O_RDONLY);
    map.high = 0;
    line = get_next_line(map.fd);
    map.len = strlen_map(line);
    while (line)
    {
        map.high++;
        free(line);
        line = get_next_line(map.fd);
        if (!line)
            break ;
        len = strlen_map(line);
        if (len != map.len)
        {
            free(line);
            line = NULL;
            return (0);
        }
    }
    return (1);
}
