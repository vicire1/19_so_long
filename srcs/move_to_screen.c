/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_to_screen.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdecleir <vdecleir@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 11:33:54 by vdecleir          #+#    #+#             */
/*   Updated: 2023/12/29 14:38:07 by vdecleir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static int	count_char(long n)
{
	int	i;

	i = 1;
	while (n > 9)
	{
		i++;
		n = n / 10;
	}
	return (i);
}

char	*ft_itoa(long n)
{
	char	*a;
	int		len;

	len = count_char(n);
	a = malloc(sizeof(char) * (len + 1));
	if (!a)
		return (NULL);
	a[len] = '\0';
	len--;
	if (n == 0)
		a[0] = '0';
	while (n > 0)
	{
		a[len] = (n % 10) + 48;
		n = n / 10;
		len--;
	}
	return (a);
}

int	move_to_screen(t_data *data)
{
	char	*str;

	if (data->count_moves > INT32_MAX)
		return (escape(0, data));
	str = ft_itoa(data->count_moves);
	put_image(data, data->xpm.bg, PXL, 0);
	put_image(data, data->xpm.wall, PXL, 0);
	put_image(data, data->xpm.bg, 2 * PXL, 0);
	put_image(data, data->xpm.wall, 2 * PXL, 0);
	mlx_string_put(data->mlx.ptr, data->mlx.win, 85, 20, 000, str);
	free(str);
	str = NULL;
	return (1);
}
