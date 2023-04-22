/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_spt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psuanpro <psuanpro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 14:42:39 by psuanpro          #+#    #+#             */
/*   Updated: 2023/04/20 22:42:13 by psuanpro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

char	find_char_player(char **map, int x, int y)
{
	return (map[y][x]);
}

int	findxy_player(char **map, int mode)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (chrstr_player(map[i][j]))
			{
				if (mode == 0)
					return (j);
				else if (mode == 1)
					return (i);
			}
			j++ ;
		}
		i++ ;
	}
	return (-1);
}

t_vei	get_pos_spt(char **map)
{
	t_vei	vector_int;

	vector_int.x = findxy_player(map, 0);
	vector_int.y = findxy_player(map, 1);
	return (vector_int);
}

int	get_direction_player(char player)
{
	printf("player -> %c\n", player);
	if (player == 'N')
		return (270);
	else if (player == 'E')
		return (0);
	else if (player == 'S')
		return (90);
	else if (player == 'W')
		return (180);
	else
		return (-1);

}


t_spt	set_spt(char **map)
{
	t_spt	spt;

	spt.pos = get_pos_spt(map);
	spt.di = get_direction_player(map[spt.pos.y][spt.pos.x]);
	spt.cstart = map[spt.pos.y][spt.pos.x];
	map[spt.pos.y][spt.pos.x] = 'P';
	return (spt);
}

// N=270 E=0 S=90 W=180
