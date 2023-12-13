/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdecleir <vdecleir@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 16:56:03 by vdecleir          #+#    #+#             */
/*   Updated: 2023/12/13 19:17:59 by vdecleir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <math.h>
# include <mlx.h>
# include "./get_next_line.h"

# define FEW_ARG "Path to the map is missing.\n"
# define MUCH_ARG "Too much arguments.\n"
# define INV_MAP "The map and/or the path are/is invalid.\n"

typedef struct  s_data {
    void    *img;
    char    *addr;
    int     bpp;
    int     line_len;
    int     endian;
}               t_data;

typedef struct  s_map {
    char    *name;
    char    **layout;
    int     fd;
    int     len;
    int     high;
    int     collec;
    int     exit;
    int     player;
}               t_map;

typedef struct  s_so_long {
    t_map   map;
}               t_so_long;

int map_check(t_so_long *so_long);
int freenull(char *str);
int strlen_map(char *str);

#endif