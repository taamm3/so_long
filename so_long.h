/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tapetros <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/24 17:29:32 by tapetros          #+#    #+#             */
/*   Updated: 2021/07/24 17:29:36 by tapetros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "mlx/mlx.h"
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct s_player{
	int x;
	int y;
}			t_player;

typedef struct	s_vars {
	void	*mlx;
	void	*win;
	t_data  data;
	t_data	player;
	t_data	exit;
	t_data	collectible;
	t_player plr;
	int		 count;
	int		 col_count;
}				t_vars;

struct	s_map {
	int length;
	int height;
	char **map;
}		map;

struct s_count{
	int exit_count;
	int collectible_count;
	int start_count;
}		count;

struct s_tile{
	int l;
	int h;
}	tile;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
int		close_win();
int		ft_strlen_t(const char *str);
int		check_map(char *s);
void	ft_putstr_fd(char *s, int fd);
int		get_next_line(int fd, char **line);
int		walls(int a, int b);
void 	map_malloc();
int 	fill_map(int fd, t_vars *vars);
int		check_arg_name(char *argv);	
void	draw_square(t_data	*img, int x, int y, int color);
void	draw_xpm(t_data *img, t_data	*texture, int x, int y);
int		my_rgb(int r, int g, int b);
int 	draw(t_vars *vars);
void  	move_up(t_vars *vars);
void  	move_down(t_vars *vars);
void  	move_left(t_vars *vars);
void  	move_right(t_vars *vars);
void    struct_init(t_vars *vars);
int     get_pixel(t_data *texture, int x, int y);
void    images(t_vars *vars);
int     key_hook(int keycode, t_vars *vars);
void	ft_putnbr_fd(int n, int fd);


#endif