/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdecleir <vdecleir@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 22:05:08 by vdecleir          #+#    #+#             */
/*   Updated: 2023/12/13 18:31:59 by vdecleir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int error_message(int i)
{
    write (1, "Error\n", 7);
    if (i == 0)
        write(1, FEW_ARG, 29);
    else if (i == 1)
        write(1, MUCH_ARG, 21);
    else if (i == 2)
        write(1, INV_MAP, 41);
    return (0);
}

// int mlx(void)
// {
//     void    *mlx;
//     void    *mlx_win;
//     t_data  img;
//     int     width;
//     int     height;
//     int     x;
//     int     y;

//     mlx = mlx_init();
//     if(!mlx)
//         return (0);
//     width = 1500;
//     height = 1000;
//     mlx_win = mlx_new_window(mlx, width, height, "Hello World!");
//     img.img = mlx_new_image(mlx, width, height);
//     img.addr = mlx_get_data_addr(img.img, &img.bpp, &img.line_len, &img.endian);
//     x = 0;
//     y = 0;
//     mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
//     mlx_loop(mlx);
// }

int main(int ac, char *av[])
{
    t_so_long   so_long;
    
    if (ac < 2)
        return (error_message(0));
    else if (ac > 2)
        return (error_message(1));
    so_long.map.name = av[1];
    if (map_check(&so_long) == -1)
        return (error_message(2));
    return (1);
}
