/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tapetros <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/24 17:32:56 by tapetros          #+#    #+#             */
/*   Updated: 2021/07/24 17:32:58 by tapetros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void  	move_up(t_vars *vars)
{
	if(map.map[vars->plr.x - 1][vars->plr.y] != '1')
	{
		if(map.map[vars->plr.x - 1][vars->plr.y] == 'C')
		{
			map.map[vars->plr.x - 1][vars->plr.y] = '0';
			vars->col_count++;
		}
		if(map.map[vars->plr.x - 1][vars->plr.y] == 'E' && vars->col_count == count.collectible_count)
			close_win();
		vars->plr.x--;
		vars->count++;
		ft_putnbr_fd(vars->count, 1);
		write(1, "\n", 1);
	}
}

void  	move_down(t_vars *vars)
{
	if(map.map[vars->plr.x + 1][vars->plr.y] != '1')
	{
		if(map.map[vars->plr.x + 1][vars->plr.y] == 'C')
		{
			map.map[vars->plr.x + 1][vars->plr.y] = '0';
			vars->col_count++;
		}
		if(map.map[vars->plr.x + 1][vars->plr.y] == 'E' && vars->col_count == count.collectible_count)
			close_win();
		vars->plr.x++;
		vars->count++;
		ft_putnbr_fd(vars->count, 1);
		write(1, "\n", 1);
	}
}

void  	move_left(t_vars *vars)
{
	if(map.map[vars->plr.x][vars->plr.y - 1] != '1')
	{
		if(map.map[vars->plr.x][vars->plr.y - 1] == 'C')
		{
			map.map[vars->plr.x][vars->plr.y - 1] = '0';
			vars->col_count++;
		}
		if(map.map[vars->plr.x][vars->plr.y - 1] == 'E' && vars->col_count == count.collectible_count)
			close_win();
		vars->plr.y--;
		vars->count++;
		ft_putnbr_fd(vars->count, 1);
		write(1, "\n", 1);
	}
}

void  	move_right(t_vars *vars)
{
	if(map.map[vars->plr.x][vars->plr.y + 1] != '1')
	{
		if(map.map[vars->plr.x][vars->plr.y + 1] == 'C')
		{
			map.map[vars->plr.x][vars->plr.y + 1] = '0';
			vars->col_count++;
		}
		if(map.map[vars->plr.x][vars->plr.y + 1] == 'E' && vars->col_count == count.collectible_count)
			close_win();
		vars->plr.y++;
		vars->count++;
		ft_putnbr_fd(vars->count, 1);
		write(1, "\n", 1);
	}
}
