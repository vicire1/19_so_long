/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdecleir <vdecleir@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 22:05:08 by vdecleir          #+#    #+#             */
/*   Updated: 2023/12/12 16:57:31 by vdecleir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

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
    int     width;
    int     height;
    int     x;
    int     y;

    mlx = mlx_init();
    if(!mlx)
        return (0);
    width = 1500;
    height = 1000;
    mlx_win = mlx_new_window(mlx, width, height, "Hello World!");
    img.img = mlx_new_image(mlx, width, height);
    img.addr = mlx_get_data_addr(img.img, &img.bpp, &img.line_len, &img.endian);
    x = 0;
    y = 0;
    // while (x < width)
    // {
    //     my_mlx_pixel_put(&img, 1, 1, 0x00FF0000);
        
    // }
    mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
    mlx_loop(mlx);
}
