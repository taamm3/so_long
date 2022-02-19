/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tapetros <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/24 17:30:01 by tapetros          #+#    #+#             */
/*   Updated: 2021/07/24 17:30:03 by tapetros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int check_map(char *s)
{
	int i;
	
	if(ft_strlen_t(s) != map.length)
		return (0);
	i = 0;
	while(s[i] == '0' || s[i] == '1' || s[i] == 'C' ||
			s[i] == 'E' || s[i] == 'P')
	{
		if(s[i] == 'E')
			count.exit_count++;
		if(s[i] == 'C')
			count.collectible_count++;
		if(s[i] == 'P')
			count.start_count++;
		i++;
	}
	if(s[i] == '\n' || s[i] == '\0')
		return (1);
	else
		return (0);
}

int		walls(int a, int b)
{
	int i;
	int j;

	i = 0;
	while (i < b)
	{
		j = 0;
		while (j < a)
		{
			if (i == 0 || i == b - 1 || j == 0 || j == a - 1)
				if(map.map[i][j] != '1')
					return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void 	map_malloc()
{
	int i;

	i = 0;
	if(!(map.map = malloc((map.height + 1) * sizeof(char *))))
	{
		ft_putstr_fd("Error while allocating\n", 1);
		close_win();
	}
	while(i < map.height)
	{
		if(!(map.map[i] = malloc((map.length + 1) * sizeof(char *))))
		{
			ft_putstr_fd("Error while allocating\n", 1);
			close_win();
		}
		i++;
	}
}

int 	fill_map(int fd, t_vars *vars)
{
	int a = 1;
	char *s;
	int i = 0, j;

	while (i < map.height)
	{
		a = get_next_line(fd, &s);
		j = 0;
		while (j < map.length)
		{
			map.map[i][j] = s[j];
			if (map.map[i][j] == 'P')
			{
				vars->plr.x = i;
				vars->plr.y = j;
				map.map[i][j] = '0';
			}
			++j;
		}
		map.map[i][j] = '\0';
		++i;
	}
	map.map[i] = NULL;
	return (0);
}	

int		check_arg_name(char *argv)
{
	if (argv[ft_strlen_t(argv) - 1] == 'r' && argv[ft_strlen_t(argv) - 2] == 'e'
		&& argv[ft_strlen_t(argv) - 3] == 'b' && argv[ft_strlen_t(argv) - 4] == '.')
		return (1);
	else
		return (0);
}
