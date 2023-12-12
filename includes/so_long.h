/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdecleir <vdecleir@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 16:56:03 by vdecleir          #+#    #+#             */
/*   Updated: 2023/12/12 19:05:52 by vdecleir         ###   ########.fr       */
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

typedef struct  s_data {
    void    *img;
    char    *addr;
    int     bpp;
    int     line_len;
    int     endian;
}               t_data;

typedef struct  s_map {
    int fd;
    int len;
    int high;
}               t_map;

typedef struct  s_so_long {
t_map   map;
char *test;
}               t_so_long;

#endif