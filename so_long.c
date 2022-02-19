/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tapetros <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/24 17:29:52 by tapetros          #+#    #+#             */
/*   Updated: 2021/07/24 17:29:54 by tapetros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int      key_hook(int keycode, t_vars *vars)
{
  if (keycode == 13 || keycode == 126)
  	move_up(vars);
  if (keycode == 1 || keycode == 125)
   move_down(vars);
  if (keycode == 0 || keycode == 123)
   move_left(vars);
  if (keycode == 2 || keycode == 124)
   move_right(vars);
  if (keycode == 53)
    close_win();
  return (0);
}

void struct_init(t_vars *vars)
{
    map.length = 0;
	map.height = 0;
	count.exit_count = 0; 
	count.collectible_count = 0;
	count.start_count = 0;
    vars->count = 0;
	vars->col_count = 0;
    tile.l = 50;
	tile.h = 50;
}

void images(t_vars *vars)
{
    int texH, texW;

    vars->player.img = mlx_xpm_file_to_image(vars->mlx, "./imgs/L.xpm", &texW, &texH);
	vars->player.addr = mlx_get_data_addr(vars->player.img, &vars->player.bits_per_pixel, &vars->player.line_length,
								&vars->player.endian);
	vars->exit.img = mlx_xpm_file_to_image(vars->mlx, "./imgs/exit.xpm", &texW, &texH);
	vars->exit.addr = mlx_get_data_addr(vars->exit.img, &vars->exit.bits_per_pixel, &vars->exit.line_length,
								&vars->exit.endian);
	vars->collectible.img = mlx_xpm_file_to_image(vars->mlx, "./imgs/deathnote.xpm", &texW, &texH);
	vars->collectible.addr = mlx_get_data_addr(vars->collectible.img, &vars->collectible.bits_per_pixel, &vars->collectible.line_length,
								&vars->collectible.endian);
}