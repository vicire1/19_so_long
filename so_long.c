/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdecleir <vdecleir@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 22:05:08 by vdecleir          #+#    #+#             */
/*   Updated: 2023/12/10 23:56:42 by vdecleir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
    char    *dst;
    
    dst = data->addr + (y * data->line_len + x * (data->bpp / 8));
    *(unsigned int *)dst = color;
}

int main(void)
{
    void    *mlx;
    void    *mlx_win;
    t_data  img;

    mlx = mlx_init();
    if(!mlx)
        return (0);
    mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello World!");
    img.img = mlx_new_image(mlx, 1920, 1080);
    img.addr = mlx_get_data_addr(img.img, &img.bpp, &img.line_len, &img.endian);
    my_mlx_pixel_put(&img, 1, 1, 0x00FF0000);
    mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
    mlx_loop(mlx);
}