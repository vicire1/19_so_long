/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdecleir <vdecleir@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 16:56:03 by vdecleir          #+#    #+#             */
/*   Updated: 2023/12/29 15:06:52 by vdecleir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./get_next_line.h"
# include <fcntl.h>
# include <mlx.h>
# include <stdlib.h>
# include <unistd.h>

# define FEW_ARG "Path to the map is missing.\n"
# define MUCH_ARG "Too much arguments.\n"
# define INV_CHAR "There are some invalids characters in the map.\n"
# define INV_WALL "The map is not surrounded by '1'.\n"
# define INV_CPE "Check the amount of collectibles, players and exit.\n"
# define INV_MAP "The map is not a rectangular.\n"
# define PARS "It is not possible to finish this map.\n"
# define TOO_BIG "The map is too big.\n"
# define XPM "There was a problem with the xpm conversion.\n"
# define BER_FILE "The map is not a '.ber' file.\n"
# define PXL 64
# define A 0
# define S 1
# define D 2
# define W 13
# define ESC 53

typedef struct	s_player {
	size_t		count;
	int			x;
	int			y;
}				t_player;

typedef struct	s_exit {
	size_t		count;
	int			x;
	int			y;
}				t_exit;

typedef struct	s_collec {
	size_t		count;
	size_t		game;
}				t_collec;

typedef struct	s_ennemy {
	size_t		count;
}				t_ennemy;

typedef struct	s_map {
	char		*name;
	char		**layout;
	int			fd;
	size_t		len;
	size_t		high;
}				t_map;

typedef struct	s_xpm {
	void		*plr_l;
	void		*plr_r;
	void		*plr_u;
	void		*plr_d;
	void		*esc_o;
	void		*esc_c;
	void		*bg;
	void		*wall;
	void		*collec1;
	void		*collec2;
	void		*collec3;
	void		*collec4;
	void		*collec5;
	void		*ennemy1;
	void		*ennemy2;
}				t_xpm;

typedef struct	s_mlx {
	void		*ptr;
	void		*win;
}				t_mlx;

typedef struct	s_pars {
	size_t		collec;
	size_t		exit;
	char		**map;
}				t_pars;

typedef struct	s_data {
	t_map		map;
	t_player	player;
	t_collec	collec;
	t_exit		esc;
	t_xpm		xpm;
	t_mlx		mlx;
	t_ennemy	ennemy;
	t_pars		pars;
	size_t		count_moves;
	int			anim_collec;
}				t_data;

int		map_check(t_data *data);
int		freetab(t_data *data, size_t high, int boolean, char *mess);
size_t	strlen_map(char *str);
int		error_message(char *str);
int		render_map(t_data *data);
int		key_press(int keycode, t_data *data);
int		put_image(t_data *data, void *xpm, size_t x, size_t y);
int		anim(t_data *data);
int		cross_escape(t_data *data);
int		check_playable(t_data *data);
int 	move_to_screen(t_data *data);
int		escape(int keycode, t_data *data);

#endif