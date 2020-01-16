/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sastantua.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtai <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/10 21:27:10 by dtai              #+#    #+#             */
/*   Updated: 2020/01/16 12:51:31 by dtai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prototypes.h"

int			find_stars(int num_pyr, int num_plat)
{
	int i_pyr;
	int stars;
	int i_plat;

	if (num_pyr == 1 && num_plat == 1)
		return (1);
	stars = 1;
	i_pyr = 2;
	while (i_pyr <= num_pyr)
	{
		stars += 2 * (i_pyr / 2);
		num_plat += i_pyr + 2;
		i_pyr++;
	}
	i_plat = 1;
	while (i_plat < num_plat)
	{
		stars += 2;
		i_plat++;
	}
	return (stars);
}

void		print_door2(int i_plat, int iter, int size)
{
	int chars;

	chars = size + size % 2;
	while (--chars > 0)
	{
		if (size >= 5 && chars == 2 && iter == size / 2 + size % 2)
			ft_putchar('$');
		else
			ft_putchar('|');
	}
	chars = (find_stars(size, i_plat) + 1) / 2 - (size - 1 + size % 2) / 2;
	while (--chars > 0)
		ft_putchar('*');
	ft_putchar('\\');
	ft_putchar('\n');
}

void		print_door(int plat, int size, int width)
{
	int chars;
	int i_plat;
	int iter;

	iter = 0;
	i_plat = plat - 1;
	while (++i_plat <= size + 2)
	{
		iter++;
		chars = find_stars(size, i_plat) + 1;
		chars = width / 2 - (chars + 1) / 2 + 1;
		while (--chars > 0)
			ft_putchar(' ');
		ft_putchar('/');
		chars = (find_stars(size, i_plat) + 1) / 2 - (size - 1 + size % 2) / 2;
		while (--chars > 0)
			ft_putchar('*');
		print_door2(i_plat, iter, size);
	}
}

void		print_board(int size, int width)
{
	int i_pyr;
	int i_plat;
	int chars;

	i_pyr = 0;
	while (++i_pyr < size)
	{
		i_plat = 0;
		while (++i_plat <= i_pyr + 2)
		{
			chars = find_stars(i_pyr, i_plat) + 1;
			chars = width / 2 - (chars + 1) / 2 + 1;
			while (--chars > 0)
				ft_putchar(' ');
			ft_putchar('/');
			chars = find_stars(i_pyr, i_plat) + 1;
			while (--chars > 0)
				ft_putchar('*');
			ft_putchar('\\');
			ft_putchar('\n');
		}
	}
}

void		sastantua(int size)
{
	int	width;
	int	chars;
	int i_plat;

	if (size <= 0)
		return ;
	width = find_stars(size, size + 2) + 2;
	print_board(size, width);
	i_plat = 0;
	while (++i_plat <= 3 - (size % 2))
	{
		chars = find_stars(size, i_plat) + 1;
		chars = width / 2 - (chars + 1) / 2 + 1;
		while (--chars > 0)
			ft_putchar(' ');
		ft_putchar('/');
		chars = find_stars(size, i_plat) + 1;
		while (--chars > 0)
			ft_putchar('*');
		ft_putchar('\\');
		ft_putchar('\n');
	}
	print_door(i_plat, size, width);
}

#include <stdlib.h>
#include <stdio.h>

int			main(int argc, char **argv)
{;
	if (argc != 2)
		printf("usage: %s integer\n", argv[0]);
	else
		sastantua(atoi(argv[1]));
	return (0);
}
