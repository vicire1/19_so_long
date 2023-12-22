/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdecleir <vdecleir@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 12:55:51 by vdecleir          #+#    #+#             */
/*   Updated: 2023/12/22 19:27:49 by vdecleir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int escape(int keycode, t_data *data)
{
    (void)keycode;
    mlx_destroy_window(data->mlx.ptr, data->mlx.win);
    exit (0);
}

int move(t_data *data, int x, int y, int orientation)
{
    if (data->map.layout[y][x] == '1')
        return (1);
    if(data->map.layout[y][x] == 'C')
    {
        data->collec.game++;
        data->map.layout[y][x] = '0';
    }
    mlx_put_image_to_window(data->mlx.ptr, data->mlx.win, data->xpm.bg, data->player.x * PXL, data->player.y * PXL);
    mlx_put_image_to_window(data->mlx.ptr, data->mlx.win, data->xpm.bg, x * PXL, y * PXL);
    if (data->collec.count == data->collec.game)
        mlx_put_image_to_window(data->mlx.ptr, data->mlx.win, data->xpm.exit_o, data->exit.x * PXL, data->exit.y * PXL);
    else
        mlx_put_image_to_window(data->mlx.ptr, data->mlx.win, data->xpm.exit_c, data->exit.x * PXL, data->exit.y * PXL);
    if (orientation == 1)
        mlx_put_image_to_window(data->mlx.ptr, data->mlx.win, data->xpm.player_l, x * PXL, y * PXL);
    else
        mlx_put_image_to_window(data->mlx.ptr, data->mlx.win, data->xpm.player_r, x * PXL, y * PXL);
    data->player.look = orientation;
    data->player.x = x;
    data->player.y = y;
    data->count_moves++;
    printf("Number of moves : %d\n", data->count_moves);
    if (data->collec.count == data->collec.game && data->player.x == data->exit.x && data->player.y == data->exit.y)
        escape(0, data);
    return (1);
}

int key_press(int keycode, t_data *data)
{
    (void)data;
    if (keycode == D)
        move(data, data->player.x + 1, data->player.y, 0);
    if (keycode == A)
        move(data, data->player.x - 1, data->player.y, 1);
    if (keycode == W)
        move(data, data->player.x, data->player.y - 1, data->player.look);
    if (keycode == S)
        move(data, data->player.x, data->player.y + 1, data->player.look);
    if (keycode == 53)
        escape(keycode, data);
    return (0);
}

// int move_right(t_data *data)
// {
//     if (data->map.layout[data->player.y][data->player.x + 1] == '1')
//         return (1);
//     else
//     {
//         if (data->map.layout[data->player.y][data->player.x + 1] == 'E')
//         {
//             mlx_put_image_to_window(data->mlx.ptr, data->mlx.win, data->xpm.bg, data->player.x * PXL, data->player.y * PXL);
//             mlx_put_image_to_window(data->mlx.ptr, data->mlx.win, data->xpm.player_r, (data->player.x + 1) * PXL, data->player.y * PXL);
//         }
//         else
//         {
//             mlx_put_image_to_window(data->mlx.ptr, data->mlx.win, data->xpm.bg, data->player.x * PXL, data->player.y * PXL);
//             mlx_put_image_to_window(data->mlx.ptr, data->mlx.win, data->xpm.bg, (data->player.x + 1) * PXL, data->player.y * PXL);
//             mlx_put_image_to_window(data->mlx.ptr, data->mlx.win, data->xpm.player_r, (data->player.x + 1) * PXL, data->player.y * PXL);
//             if(data->map.layout[data->player.y][data->player.x + 1] == 'C')
//             {
//                 data->collec.game++;
//                 data->map.layout[data->player.y][data->player.x + 1] = '0';
//             }
//         }
//         data->player.x = data->player.x + 1;
//         if (data->collec.count == data->collec.game && data->player.x == data->exit.x && data->player.y == data->exit.y)
//             escape(0, data);
//     }
//     return (1);
// }

// int move_left(t_data *data)
// {
//     if (data->map.layout[data->player.y][data->player.x - 1] == '1')
//         return (1);
//     else
//     {
//         if (data->map.layout[data->player.y][data->player.x - 1] == 'E')
//         {
//             mlx_put_image_to_window(data->mlx.ptr, data->mlx.win, data->xpm.bg, data->player.x * PXL, data->player.y * PXL);
//             mlx_put_image_to_window(data->mlx.ptr, data->mlx.win, data->xpm.player_l, (data->player.x - 1) * PXL, data->player.y * PXL);
//         }
//         else
//         {
//             mlx_put_image_to_window(data->mlx.ptr, data->mlx.win, data->xpm.bg, data->player.x * PXL, data->player.y * PXL);
//             mlx_put_image_to_window(data->mlx.ptr, data->mlx.win, data->xpm.bg, (data->player.x - 1) * PXL, data->player.y * PXL);
//             mlx_put_image_to_window(data->mlx.ptr, data->mlx.win, data->xpm.player_l, (data->player.x - 1) * PXL, data->player.y * PXL);
//             if(data->map.layout[data->player.y][data->player.x - 1] == 'C')
//             {
//                 data->collec.game++;
//                 data->map.layout[data->player.y][data->player.x - 1] = '0';
//             }
//         }
//         data->player.x = data->player.x - 1;
//         if (data->collec.count == data->collec.game && data->player.x == data->exit.x && data->player.y == data->exit.y)
//             escape(0, data);
//     }
//     return (1);
// }

// int move_up(t_data *data)
// {
//     if (data->map.layout[data->player.y - 1][data->player.x] == '1')
//         return (1);
//     else
//     {
//         if (data->map.layout[data->player.y - 1][data->player.x] == 'E')
//         {
//             mlx_put_image_to_window(data->mlx.ptr, data->mlx.win, data->xpm.bg, data->player.x * PXL, data->player.y * PXL);
//             mlx_put_image_to_window(data->mlx.ptr, data->mlx.win, data->xpm.player_r, data->player.x * PXL, (data->player.y - 1) * PXL);
//         }
//         else
//         {
//             mlx_put_image_to_window(data->mlx.ptr, data->mlx.win, data->xpm.bg, data->player.x * PXL, data->player.y * PXL);
//             mlx_put_image_to_window(data->mlx.ptr, data->mlx.win, data->xpm.bg, data->player.x * PXL, (data->player.y - 1) * PXL);
//             mlx_put_image_to_window(data->mlx.ptr, data->mlx.win, data->xpm.player_r, data->player.x * PXL, (data->player.y - 1) * PXL);
//             if(data->map.layout[data->player.y - 1][data->player.x] == 'C')
//             {
//                 data->collec.game++;
//                 data->map.layout[data->player.y - 1][data->player.x] = '0';
//             }
//         }
//         data->player.y = data->player.y - 1;
//         if (data->collec.count == data->collec.game && data->player.x == data->exit.x && data->player.y == data->exit.y)
//             escape(0, data);
//     }
//     return (1);
// }

// int move_down(t_data *data)
// {
//     if (data->map.layout[data->player.y + 1][data->player.x] == '1')
//         return (1);
//     else
//     {
//         if (data->map.layout[data->player.y + 1][data->player.x] == 'E')
//         {
//             mlx_put_image_to_window(data->mlx.ptr, data->mlx.win, data->xpm.bg, data->player.x * PXL, data->player.y * PXL);
//             mlx_put_image_to_window(data->mlx.ptr, data->mlx.win, data->xpm.player_l, data->player.x * PXL, (data->player.y + 1) * PXL);
//         }
//         else
//         {
//             mlx_put_image_to_window(data->mlx.ptr, data->mlx.win, data->xpm.bg, data->player.x * PXL, data->player.y * PXL);
//             mlx_put_image_to_window(data->mlx.ptr, data->mlx.win, data->xpm.bg, data->player.x * PXL, (data->player.y + 1) * PXL);
//             mlx_put_image_to_window(data->mlx.ptr, data->mlx.win, data->xpm.player_l, data->player.x * PXL, (data->player.y + 1) * PXL);
//             if(data->map.layout[data->player.y + 1][data->player.x] == 'C')
//             {
//                 data->collec.game++;
//                 data->map.layout[data->player.y + 1][data->player.x] = '0';
//             }
//         }
//         data->player.y = data->player.y + 1;
//         if (data->collec.count == data->collec.game && data->player.x == data->exit.x && data->player.y == data->exit.y)
//             escape(0, data);
//     }
//     return (1);
// }

// int key_press(int keycode, t_data *data)
// {
//     (void)data;
//     if (keycode == 2)
//         move_right(data);
//     if (keycode == 0)
//         move_left(data);
//     if (keycode == 13)
//         move_up(data);
//     if (keycode == 1)
//         move_down(data);
//     if (keycode == 53)
//         escape(keycode, data);
//     return (0);
// }