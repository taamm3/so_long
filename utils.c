/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tapetros <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/24 17:40:32 by tapetros          #+#    #+#             */
/*   Updated: 2021/07/24 17:40:35 by tapetros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int		close_win()
{
	exit(0);
	return(0);
}

int		ft_strlen_t(const char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

void	ft_putstr_fd(char *s, int fd)
{
	int i;

	i = 0;
	while (s[i] != '\0')
	{
		write(fd, &s[i], 1);
		i++;
	}
}

int		get_next_line(int fd, char **line)
{
	int		i;
	int		n;
	char	c;
	char	*str;

	i = 0;
	if (!(str = (char *)malloc(1000 + 1)))
		return (-1);
	while ((n = read(fd, &c, 1)) && c != '\n' && c != '\0')
	{
		str[i] = c;
		++i;
	}

	str[i] = '\0';
	*line = str;
	return (n);
}

int my_rgb(int r, int g, int b)
{
	return (r << 16 | g << 8 | b);
}

static void	ft_putchar(char c, int fd)
{
	write(fd, &c, 1);
}

void		ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
	{
		ft_putchar('-', fd);
		ft_putchar('2', fd);
		ft_putnbr_fd(147483648, fd);
	}
	else if (n < 0)
	{
		ft_putchar('-', fd);
		n = n * (-1);
		ft_putnbr_fd(n, fd);
	}
	else if (n > 9)
	{
		ft_putnbr_fd(n / 10, fd);
		ft_putnbr_fd(n % 10, fd);
	}
	else
		ft_putchar(n + 48, fd);
}
