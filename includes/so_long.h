/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdecleir <vdecleir@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 16:56:03 by vdecleir          #+#    #+#             */
/*   Updated: 2023/12/20 19:27:09 by vdecleir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <mlx.h>
# include "./get_next_line.h"

# define FEW_ARG    "Path to the map is missing.\n"
# define MUCH_ARG   "Too much arguments.\n"
# define INV_CHAR   "There are some invalids characters in the map.\n"
# define INV_WALL   "The map is not surrounded by '1'.\n"
# define INV_CPE    "Check the amount of collectibles, players and exit.\n"
# define INV_MAP    "The map is not a rectangular.\n"


typedef struct  s_player {
    int count;
    int x;
    int y;
}               t_player;

typedef struct  s_exit {
    int count;
    int x;
    int y;
}               t_exit;

typedef struct  s_collec {
    int count;
}               t_collec;

typedef struct  s_map {
    char    *name;
    char    **layout;
    int     fd;
    int     len;
    int     high;
}               t_map;

typedef struct  s_xpm {
    void    *player_l;
    void    *player_r;
    void    *exit;
    void    *background;
    void    *wall;
    void    *collec;
}               t_xpm;

typedef struct  s_mlx {
    void    *ptr;
    void    *win;
}               t_mlx;


typedef struct  s_data {
    t_map       map;
    t_player    player;
    t_collec    collec;
    t_exit      exit;
    t_xpm       xpm;
    t_mlx       mlx;
}               t_data;

int map_check(t_data *data);
int freetab(t_data *data, int boolean, char *mess);
int strlen_map(char *str);
int error_message(char *str);
int	render_map(t_data *data);
int	put_background(t_data *data);
int put_wall(t_data *data);
int put_player(t_data *data);
int put_exit(t_data *data);
int put_collec(t_data *data);
int escape(int keycode, t_data *data);
int key_press(int keycode, t_data *data);



#endif