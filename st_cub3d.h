/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   st_cub3d.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psuanpro <Marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 21:29:18 by psuanpro          #+#    #+#             */
/*   Updated: 2023/03/15 22:44:25 by psuanpro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ST_CUB3D_H
# define ST_CUB3D_H

typedef struct s_vec
{
	float	x;
	float	y;
	float	z;
} t_vec;

typedef struct s_map
{
	char	**map;
} t_map;

typedef struct s_spt
{
	t_vec	axis;
} t_spt;

typedef struct s_tex
{

} t_tex;

typedef struct s_mlx
{
	void	*mlx;
	void	*win;
} t_mlx;

typedef struct s_var
{
	char	*file;


} t_var;

typedef struct s_pro
{
	t_mlx	mlx;
	t_map	map;
	t_var	var;
} t_pro;


#endif
