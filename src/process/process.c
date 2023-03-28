/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchiewli <rchiewli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 18:41:08 by psuanpro          #+#    #+#             */
/*   Updated: 2023/03/27 18:21:25 by rchiewli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"
#include <math.h>

// # define WIN_WIDTH 500
// # define WIN_HEIGHT 500
// # define COLOR 0xFFFFFF

void get_point_on_circle(t_xy *txy, float angle)
{
	angle = angle * M_PI / 180.0;

	txy->x2 = txy->x1 + 10 * cos(angle);
	txy->y2 = txy->y1 + 10 * sin(angle);
}

void	draw_line(t_mlx *tmlx, t_xy *txy,float ang, int ladex)
{
	float	dx;
	float	dy;
	float	sx;
	float	sy;
	float	err;
	float	distance;
	int		i;

	showgrid(tmlx);
	get_point_on_circle(txy, ang);
	dx = fabsf(txy->x2 - txy->x1);
	dy = fabsf(txy->y2 - txy->y1);
	if (txy->x1 < txy->x2)
		sx = 1;
	else
		sx = -1;
	if (txy->y1 < txy->y2)
		sy = 1;
	else
		sy = -1;
	err = dx - dy;
	txy->x1 += g_xstart;
	txy->y1 += g_ystart;
	while (txy->x1 != 0 && txy->x1 != (WIN_WIDTH / 2) && txy->y1 != 0 && txy->y1 != WIN_HEIGHT && txy->x1 >= (g_gridsize * 2) && txy->y1 >= (g_gridsize * 3))
	{
		// if (txy->x1 >= (g_gridsize * 2) || txy->y1 >= (g_gridsize * 3))
		// {
		// 	printf("distance of line %d ---> %f\n", g_linecounter, distance);
		// }
		mlx_pixel_put(tmlx->mlx, tmlx->win, txy->x1, txy->y1, COLOR);
		if (ladex != -1)
		{
			// printf("%d\n", ladex);
			tmlx->larray[ladex].x2 = txy->x1;
			tmlx->larray[ladex].y2 = txy->y1;
		// 	printf("larray[%d]. x2 = %f . y2 = %f\n", ladex, tmlx->larray[ladex].x2, tmlx->larray[ladex].y2);
		}
		if (err * 2 > -dy)
		{
			err -= dy;
			txy->x1 += sx;
		}
		if (err * 2 < dx)
		{
			err += dx;
			txy->y1 += sy;
		}
	}
	// if (txy->x1 == 0 || txy->x1 == WIN_WIDTH || txy->y1 == 0 || txy->y1 == WIN_HEIGHT || txy->x1 < (g_gridsize * 2) || txy->y1 < (g_gridsize * 3))
	// {
		if (ladex >= 0)
		{
			tmlx->larray[ladex].distance = sqrt(pow((g_xstart - tmlx->larray[ladex].x2), 2) + pow((g_ystart - tmlx->larray[ladex].y2), 2));
			printf("line array [%d] x = %f y = %f distance %f\n", ladex, tmlx->larray[ladex].x2, tmlx->larray[ladex].y2, tmlx->larray[ladex].distance);
		}
	// }
	txy->x1 = 1;
	txy->y1 = 1;
}

int rotate_hook(int keycode, t_pro *p)
{
	if (keycode == 124 || keycode == 123)
		anglechange(keycode, p);
	else if (keycode == 0 || keycode == 2 || keycode == 1 || keycode == 13)
		movechange(keycode, p);
	else
		printf("keykode = %d\n", keycode);
	return 0;
}

void	xy_become_start(t_xy *txy, int xstart, int ystart)
{
	txy->x1 = 1;
	txy->y1 = 1;
}

void	circle(t_pro *p, t_xy *txy)
{
	float	r;
	float	x;
	float	y;

	r = 5;
	x = txy->x1 - r;
	while (r > 0)
	{
		while (x <= txy->x1 + r)
		{
			y = txy->y1 + sqrt(r * r - (x - txy->x1) * (x - txy->x1));
			mlx_pixel_put(p->mlx.mlx, p->mlx.win, x, y, COLOR);
			y = txy->y1 - sqrt(r * r - (x - txy->x1) * (x - txy->x1));
			mlx_pixel_put(p->mlx.mlx, p->mlx.win, x, y, COLOR);
			x += 0.01;
		}
		x = txy->x1 - r;
		r -= 2;
	}
}

void	process_cube(t_pro *p)
{
	t_xy	*txy;
	t_hwa	*hwa;
	// int		i;

	// i = 0;
	hwa = malloc(sizeof(t_hwa));
	txy = malloc(sizeof(t_xy));
	p->mlx.txy = txy;
	txy->x2 = 0;
	txy->x2 = 0;
	hwa->angle = 270;

	p->mlx.mlx = mlx_init();
	p->mlx.win = mlx_new_window(p->mlx.mlx, WIN_WIDTH,  WIN_HEIGHT, "My Window");
	p->mlx.img.img = mlx_new_image(p->mlx.mlx, WIN_WIDTH, WIN_HEIGHT);
	p->mlx.img.addr = mlx_get_data_addr(&p->mlx.img.img, &p->mlx.img.bits_per_pixel, \
		&p->mlx.img.line_length, &p->mlx.img.endian);

	// while (i < 7)
	// {
	// 	printf ("bfore i\n");
	// 	p->mlx.larray[i].linenum = i;
	// 	printf ("aftr i\n");
	// }

	xy_become_start(txy, hwa->xstart, hwa->ystart);
	// circle(p,txy);
	ini_ray(p);
	// draw_line(&p->mlx, txy, hwa->angle, -1);
	// draw_plane(&p->mlx, g_xstart, g_ystart, g_angle);
	xy_become_start(txy, hwa->xstart, hwa->ystart);
	mlx_hook(p->mlx.win, 2, 0, rotate_hook, p);
	xy_become_start(txy, hwa->xstart, hwa->ystart);
	mlx_loop(p->mlx.mlx);
}
