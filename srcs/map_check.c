/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdecleir <vdecleir@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 16:57:45 by vdecleir          #+#    #+#             */
/*   Updated: 2023/12/12 19:09:31 by vdecleir         ###   ########.fr       */
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

int map_check(t_so_long *t_so_long)
{
    char    *line;
    t_map   *map;
    int     len;
    
    t_so_long->map.fd = open(t_so_long->test, O_RDONLY);
    t_so_long->map.high = 0;
    line = get_next_line(t_so_long->map.fd);
    t_so_long->map.len = strlen_map(line);
    while (line)
    {
        t_so_long->map.high++;
        free(line);
        line = get_next_line(t_so_long->map.fd);
        if (!line)
            break ;
        len = strlen_map(line);
        if (len != t_so_long->map.len)
        {
            free(line);
            line = NULL;
            return (0);
        }
    }
    return (1);
}

int main()
{
    t_so_long t_so_long;
    t_so_long.test = "./maps/test.txt";
    printf("%d", map_check(&t_so_long));
}