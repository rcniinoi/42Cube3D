/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchiewli <rchiewli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 18:39:07 by psuanpro          #+#    #+#             */
/*   Updated: 2023/03/23 22:30:03 by rchiewli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	init_xyangle()
{
	// char tmp[6][6] = {{'1', '1', '1', '1', '1'}, {'1', '0', '0', '0', '1'}, {'1', '0', '1', '0', '1'}, {'1', '0', '0', '0', '1'}, {'1', '1', '1', '1', '1'}, {NULL}};
	g_xstart = 250;
	g_ystart = 250;
	g_angle = 270;
	g_gridsize = 75;
	g_linecounter = 0;
	// g_map = {{'1', '1', '1', '1', '1'}, {'1', '0', '0', '0', '1'}, {'1', '0', '1', '0', '1'}, {'1', '0', '0', '0', '1'}, {'1', '1', '1', '1', '1'}, {NULL}};
}

void	init_mlx_st(t_mlx *mlx)
{
	mlx->mlx = NULL;
	mlx->win = NULL;
}

void	init_map_st(t_map *map)
{
	map->map = NULL;
}

// char	**init_mocking_map(t_map *map)
// {
// 	char tmap[6][6] = {{'1', '1', '1', '1', '1'}, {'1', '0', '0', '0', '1'}, {'1', '0', '1', '0', '1'}, {'1', '0', '0', '0', '1'}, {'1', '1', '1', '1', '1'}};
// 	// tmap = "11111", "11111"
// 	// map = malloc(sizeof(char *) * 6);
//  	// map->map = "11111"
// 	return (tmap);
// }

void	init_pro(t_pro *p)
{
	init_mlx_st(&p->mlx);
	init_map_st(&p->map);
}

void	init_cube(t_pro *p)
{
	init_pro(p);
	return ;
}

/*
11111
10001
10101
10N01
11111
*/
