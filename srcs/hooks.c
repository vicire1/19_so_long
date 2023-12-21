/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdecleir <vdecleir@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 12:55:51 by vdecleir          #+#    #+#             */
/*   Updated: 2023/12/21 17:44:49 by vdecleir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int escape(int keycode, t_data *data)
{
    (void)keycode;
    mlx_destroy_window(data->mlx.ptr, data->mlx.win);
    exit (0);
}

int move_right(t_data *data)
{
    if (data->map.layout[data->player.y][data->player.x + 1] == '1')
        return (1);
    else
    {
        if (data->map.layout[data->player.y][data->player.x + 1] == 'E')
        {
            mlx_put_image_to_window(data->mlx.ptr, data->mlx.win, data->xpm.background, data->player.x * 100, data->player.y * 100);
            mlx_put_image_to_window(data->mlx.ptr, data->mlx.win, data->xpm.player_r, (data->player.x + 1) * 100, data->player.y * 100);
        }
        else
        {
            mlx_put_image_to_window(data->mlx.ptr, data->mlx.win, data->xpm.background, data->player.x * 100, data->player.y * 100);
            mlx_put_image_to_window(data->mlx.ptr, data->mlx.win, data->xpm.background, (data->player.x + 1) * 100, data->player.y * 100);
            mlx_put_image_to_window(data->mlx.ptr, data->mlx.win, data->xpm.player_r, (data->player.x + 1) * 100, data->player.y * 100);
            if(data->map.layout[data->player.y][data->player.x + 1] == 'C')
            {
                data->collec.game++;
                data->map.layout[data->player.y][data->player.x + 1] = '0';
            }
        }
        data->player.x = data->player.x + 1;
        if (data->collec.count == data->collec.game && data->player.x == data->exit.x && data->player.y == data->exit.y)
            escape(0, data);
    }
    return (1);
}

int move_left(t_data *data)
{
    if (data->map.layout[data->player.y][data->player.x - 1] == '1')
        return (1);
    else
    {
        if (data->map.layout[data->player.y][data->player.x - 1] == 'E')
        {
            mlx_put_image_to_window(data->mlx.ptr, data->mlx.win, data->xpm.background, data->player.x * 100, data->player.y * 100);
            mlx_put_image_to_window(data->mlx.ptr, data->mlx.win, data->xpm.player_l, (data->player.x - 1) * 100, data->player.y * 100);
        }
        else
        {
            mlx_put_image_to_window(data->mlx.ptr, data->mlx.win, data->xpm.background, data->player.x * 100, data->player.y * 100);
            mlx_put_image_to_window(data->mlx.ptr, data->mlx.win, data->xpm.background, (data->player.x - 1) * 100, data->player.y * 100);
            mlx_put_image_to_window(data->mlx.ptr, data->mlx.win, data->xpm.player_l, (data->player.x - 1) * 100, data->player.y * 100);
            if(data->map.layout[data->player.y][data->player.x - 1] == 'C')
            {
                data->collec.game++;
                data->map.layout[data->player.y][data->player.x - 1] = '0';
            }
        }
        data->player.x = data->player.x - 1;
        if (data->collec.count == data->collec.game && data->player.x == data->exit.x && data->player.y == data->exit.y)
            escape(0, data);
    }
    return (1);
}

int move_up(t_data *data)
{
    if (data->map.layout[data->player.y - 1][data->player.x] == '1')
        return (1);
    else
    {
        if (data->map.layout[data->player.y - 1][data->player.x] == 'E')
        {
            mlx_put_image_to_window(data->mlx.ptr, data->mlx.win, data->xpm.background, data->player.x * 100, data->player.y * 100);
            mlx_put_image_to_window(data->mlx.ptr, data->mlx.win, data->xpm.player_r, data->player.x * 100, (data->player.y - 1) * 100);
        }
        else
        {
            mlx_put_image_to_window(data->mlx.ptr, data->mlx.win, data->xpm.background, data->player.x * 100, data->player.y * 100);
            mlx_put_image_to_window(data->mlx.ptr, data->mlx.win, data->xpm.background, data->player.x * 100, (data->player.y - 1) * 100);
            mlx_put_image_to_window(data->mlx.ptr, data->mlx.win, data->xpm.player_r, data->player.x * 100, (data->player.y - 1) * 100);
            if(data->map.layout[data->player.y - 1][data->player.x] == 'C')
            {
                data->collec.game++;
                data->map.layout[data->player.y - 1][data->player.x] = '0';
            }
        }
        data->player.y = data->player.y - 1;
        if (data->collec.count == data->collec.game && data->player.x == data->exit.x && data->player.y == data->exit.y)
            escape(0, data);
    }
    return (1);
}

int move_down(t_data *data)
{
    if (data->map.layout[data->player.y + 1][data->player.x] == '1')
        return (1);
    else
    {
        if (data->map.layout[data->player.y + 1][data->player.x] == 'E')
        {
            mlx_put_image_to_window(data->mlx.ptr, data->mlx.win, data->xpm.background, data->player.x * 100, data->player.y * 100);
            mlx_put_image_to_window(data->mlx.ptr, data->mlx.win, data->xpm.player_l, data->player.x * 100, (data->player.y + 1) * 100);
        }
        else
        {
            mlx_put_image_to_window(data->mlx.ptr, data->mlx.win, data->xpm.background, data->player.x * 100, data->player.y * 100);
            mlx_put_image_to_window(data->mlx.ptr, data->mlx.win, data->xpm.background, data->player.x * 100, (data->player.y + 1) * 100);
            mlx_put_image_to_window(data->mlx.ptr, data->mlx.win, data->xpm.player_l, data->player.x * 100, (data->player.y + 1) * 100);
            if(data->map.layout[data->player.y + 1][data->player.x] == 'C')
            {
                data->collec.game++;
                data->map.layout[data->player.y + 1][data->player.x] = '0';
            }
        }
        data->player.y = data->player.y + 1;
        if (data->collec.count == data->collec.game && data->player.x == data->exit.x && data->player.y == data->exit.y)
            escape(0, data);
    }
    return (1);
}

int key_press(int keycode, t_data *data)
{
    (void)data;
    if (keycode == 2)
        move_right(data);
    if (keycode == 0)
        move_left(data);
    if (keycode == 13)
        move_up(data);
    if (keycode == 1)
        move_down(data);
    if (keycode == 53)
        escape(keycode, data);
    return (0);
}