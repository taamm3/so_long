/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tapetros <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/24 17:30:11 by tapetros          #+#    #+#             */
/*   Updated: 2021/07/24 17:30:13 by tapetros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void draw_square(t_data	*img, int x, int y, int color)
{
	int i, j;
	
	j = 0;
	while(j < tile.h)
	{
		i = 0;
		while(i < tile.l)
		{
			my_mlx_pixel_put(img, x * tile.l + i, y * tile.h + j, color);
			i++;
		}
		j++;
	}
}

void draw_xpm(t_data *img, t_data *texture, int x, int y)
{
	int i, j;
	int color;

	j = 0;
	while(j < tile.h)
	{
		i = 0;
		while(i < tile.l)
		{
			color = get_pixel(texture, i, j);
			if((unsigned int)color != 0xFF000000)
				my_mlx_pixel_put(img, x * tile.l + i, y * tile.h + j, color);
			else
				my_mlx_pixel_put(img, x * tile.l + i, y * tile.h + j, my_rgb(190,190,190));
			i++;
		}
		j++;
	}
}

int draw(t_vars *vars)
{
	int i, j;

	j = 0;
	while(j < map.height)
	{
		i = 0;
		while(i < map.length)
		{
			if(map.map[j][i] == '1')
				draw_square(&vars->data, i, j, my_rgb(255,0,0));
			if(map.map[j][i] == '0')
				draw_square(&vars->data, i, j, my_rgb(190,190,190));
			if(map.map[j][i] == 'E')
				draw_xpm(&vars->data, &vars->exit, i, j);
			if(map.map[j][i] == 'C')
				draw_xpm(&vars->data, &vars->collectible, i, j);
			if((j == (vars->plr.x)) && (i == vars->plr.y))
				draw_xpm(&vars->data, &vars->player, i, j);
			i++;
		}
		j++;
	}
	mlx_put_image_to_window(vars->mlx, vars->win, vars->data.img, 0, 0);
	return (0);
}
