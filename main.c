/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leng-chu <-chu@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 11:33:51 by leng-chu          #+#    #+#             */
/*   Updated: 2022/09/15 16:38:51 by leng-chu         ###   ########.fr       */
/*   Updated: 2021/12/07 11:48:40 by leng-chu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"
#include <unistd.h>
#include <stdio.h>

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		px;
	int		len;
	int		end;
}	t_data;

int	rgbtohex(int r, int g, int b)
{
	r = (r & 0xff) << 16;
	g = (g & 0xff) << 8;
	b = b & 0xff;
	return (r + g + b);
}

int	rgbtohex2(double a, double r, double g, double b)
{
	int	ac;
	int	rc;
	int	gc;
	int	bc;

	ac = (int)(255.999 * a);
	rc = (int)(255.999 * r);
	gc = (int)(255.999 * g);
	bc = (int)(255.999 * b);
	return ((ac << 24) + (rc << 16) + (gc << 8) + bc);
}

void	ft_pixel2(t_data *data, int x, int y, int color)
{
	int	i;

	i = (x * data->px / 8) + (y * data->len);
	data->addr[i] = color >> 16;
	data->addr[++i] = color >> 8;
	data->addr[++i] = color;
}

void	ft_pixel(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->len + x * (data->px / 8));
	*(int *)dst = color;
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	deal_key(int key, void *param)
{
	int	*test;

	test = param;
	(void)key;
	ft_putchar('X');
	printf("param: %d\n", *test);
	return (0);
}

int	rgb_to_int(double r, double g, double b)
{
	int	color;

	color = 0;
	color |= (int)(b * 255);
	color |= (int)(g * 255) << 8;
	color |= (int)(r * 255) << 16;
	return (color);
}

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1000, 500, "HELLO");
	img.img = mlx_new_image(mlx, 300, 300);
	img.addr = mlx_get_data_addr(img.img, &img.px, &img.len, &img.end);
	for (int i = 0; i < 300; i++)
		for (int j = 0; j < 150; j++)
			ft_pixel(&img, i, j, rgbtohex2(0.5, (double)j / 150.0, (double)i / 300.0, 0.25));
	mlx_put_image_to_window(mlx, mlx_win, img.img, 100, 0);
	
	int lol = 42;
	mlx_key_hook(mlx_win, deal_key, &lol);
	mlx_loop(mlx);
	(void)mlx_win;
	return (0);
}
