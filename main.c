/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tapetros <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/24 18:25:05 by tapetros          #+#    #+#             */
/*   Updated: 2021/07/24 18:25:07 by tapetros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main(int argc, char **argv)
{
    t_vars	vars;
	int fd;
	char *s;
	int a = 1;
	int h;
	int l;
	int sizex, sizey;

    if(argc != 2)
	{
		ft_putstr_fd("Wrong number of arguments\n", 1);
		close_win();
	}
	if(!check_arg_name(argv[1]))
	{
		ft_putstr_fd("Wrong extension of the map file\n", 1);
		close_win();
	}
	if(((fd = open(argv[1], O_RDONLY)) == -1))
	{
		ft_putstr_fd("Can't open the file\n", 1);
		close_win();
	}
    struct_init(&vars);
    while(a > 0)
	{
		a = get_next_line(fd, &s);
		map.height++;
		if(!map.length)
			map.length = ft_strlen_t(s);
		if(check_map(s) == 0)
		{
			ft_putstr_fd("Invalid map\n", 1);
			close_win();
		}
	}
	if(!(count.exit_count) || !(count.collectible_count) || !(count.start_count))
	{
		ft_putstr_fd("Invalid map\n", 1);
		close_win();
	}
	map_malloc();
	close(fd);
	if(((fd = open(argv[1], O_RDONLY)) == -1))
	{
		ft_putstr_fd("Can't open the file\n", 1);
		close_win();
	}
	fill_map(fd, &vars);
	if(walls(map.length, map.height) == 0)
	{
			ft_putstr_fd("Map is not surrounded by walls\n", 1);
			close_win();
	}
    vars.mlx = mlx_init();
	mlx_get_screen_size(vars.mlx, &sizex, &sizey);
	l = map.length * tile.l;
	h = map.height * tile.h;
	if(l > sizex)
		{
			l = sizex;
			tile.h /= 2;
			tile.l /= 2;
		}
	if(h > sizey)
		{
			h = sizey;
			tile.h /= 2;
			tile.l /= 2;
		}
	vars.win = mlx_new_window(vars.mlx, l, h, "So long");
	vars.data.img = mlx_new_image(vars.mlx, l, h);
	vars.data.addr = mlx_get_data_addr(vars.data.img, &vars.data.bits_per_pixel, &vars.data.line_length,
								&vars.data.endian);
	images(&vars);
	mlx_loop_hook(vars.mlx,draw,&vars);
	mlx_hook(vars.win, 2, 1L << 0, key_hook, &vars);
	mlx_hook(vars.win, 17, 1L << 0, close_win, 0);
	mlx_loop(vars.mlx);
    return (0);
}