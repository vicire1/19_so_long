/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdecleir <vdecleir@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 17:51:59 by vdecleir          #+#    #+#             */
/*   Updated: 2023/12/28 18:57:16 by vdecleir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	freetab(t_data *data, int high, int boolean, char *mess)
{
	int	i;

	i = 0;
	while (i < high)
	{
		free(data->map.layout[i]);
		data->map.layout[i] = NULL;
		i++;
	}
	free(data->map.layout);
	data->map.layout = NULL;
	if (boolean == 1)
		error_message(mess);
	return (-1);
}

int	strlen_map(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] && str[i] != '\n')
		i++;
	return (i);
}

int	error_message(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	write(1, "Error\n", 7);
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	return (-1);
}

int	put_image(t_data *data, void *xpm, int x, int y)
{
	mlx_put_image_to_window(data->mlx.ptr, data->mlx.win, xpm, x, y);
	return (1);
}

// static int	count_char(int n)
// {
// 	int	i;

// 	i = 1;
// 	if (n == -2147483648)
// 		return (11);
// 	if (n < 0)
// 	{
// 		n = -n;
// 		i++;
// 	}
// 	while (n > 9)
// 	{
// 		i++;
// 		n = n / 10;
// 	}
// 	return (i);
// }

// static void	int_cpy(int n, int len, char *a)
// {
// 	if (n == 0)
// 		a[0] = '0';
// 	if (n < 0)
// 	{
// 		a[0] = '-';
// 		n = -n;
// 	}
// 	while (n > 0)
// 	{
// 		a[len] = (n % 10) + 48;
// 		n = n / 10;
// 		len --;
// 	}
// }

// char	*ft_itoa(int n)
// {
// 	char	*a;
// 	int		i;
// 	int		len;
// 	char	*tmp;

// 	len = count_char(n);
// 	a = malloc(sizeof(char) * (len + 1));
// 	if (a == NULL)
// 		return (NULL);
// 	a[len] = '\0';
// 	len--;
// 	if (n == -2147483648)
// 	{
// 		tmp = "-2147483648";
// 		i = 0;
// 		while (i <= len)
// 		{
// 			a[i] = tmp[i];
// 			i++;
// 		}
// 	}
// 	else
// 		int_cpy(n, len, a);
// 	return (a);
// }
