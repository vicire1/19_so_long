/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdecleir <vdecleir@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 12:55:51 by vdecleir          #+#    #+#             */
/*   Updated: 2023/12/20 19:27:36 by vdecleir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int escape(int keycode, t_data *data)
{
    (void)keycode;
    mlx_destroy_window(data->mlx.ptr, data->mlx.win);
    return (-1);
}

int key_press(int keycode, t_data *data)
{
    (void)data;
    if (keycode == 125)
        printf("oui\n");
    return (0);
}