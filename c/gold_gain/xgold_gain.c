/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gold_gain.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkozlov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 09:44:58 by kkozlov           #+#    #+#             */
/*   Updated: 2020/01/09 10:33:03 by kkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

typedef struct	s_tab
{
	int			**tab;
	size_t		rows;
	size_t		cols;
}				t_tab;

static t_tab	*ft_tabnew(size_t rows, size_t cols)
{
	t_tab	*tab;

	tab = malloc(sizeof(t_tab));
	tab->rows = rows;
	tab->cols = cols;

	tab->tab = malloc(tab->rows * sizeof(void *));
	while (rows--)
	{
		cols = tab->cols;
		(tab->tab)[rows] = malloc(cols * sizeof(int));
		while (cols--)
			(tab->tab)[rows][cols] = 0;
	}
	return (tab);
}

static void		ft_tabput(t_tab *tab)
{
	size_t	r;
	size_t	c;

	r = -1;
	while (++r < tab->rows)
	{
		c = -1;
		while (++c < tab->cols)
			ft_printf("%5d", (tab->tab)[r][c]);
		ft_printf("\n");
	}
}

static int	ft_maxthree(int a, int b, int c)
{
	int	max;
	
	max = a > b ? a : b;
	max = max > c ? max : c;
	return (max);
}

void		ft_tabfill(t_tab *tab, int **mine, int n)
{
	int	row;
	int	col;
	int	up;
	int	right;
	int	down;

	col = 0;
	while (++col <= n)
	{
		row = 0;
		while (row++ < n)
		{
			up = (tab->tab)[row - 1][col - 1];
			right = (tab->tab)[row][col - 1];
			down = (tab->tab)[row + 1][col - 1];
			ft_printf("up = %d, right = %d, down = %d\n",
					  up, right, down);
			(tab->tab)[row][col] = ft_maxthree(up, right, down) 
				+ mine[row - 1][col - 1];
		}
	}
}

int			gold_gain(int **mine, int n)
{
	t_tab	*tab;
	int		max;

	tab = ft_tabnew(n + 2, n + 1);
	ft_tabfill(tab, mine, n);
	max = 0;
	while (n--)
		if ((tab->tab)[n + 1][tab->cols - 1] > max)
			max = (tab->tab)[n + 1][tab->cols - 1];
	ft_tabput(tab);
	return (max);
}

static void	mineput(int **mine, int n)
{
	int	row;
	int	col;

	row = -1;
	while (++row < n)
	{
		col = -1;
		while (++col < n)
			ft_printf("%5d", mine[row][col]);
		ft_printf("\n");
	}
}

static int	**minenew(int n)
{
	int	**mine;
	int	i;
	int	j;

	mine = malloc(n * sizeof(void *));
	i = n;
	while (i--)
	{
		mine[i] = malloc(n * sizeof(int));
		j = n;
		while (j--)
			mine[i][j] = 0;
	}
	return (mine);
}

static void	minefill(int **mine, int n)
{
	(void)n;
/*	mine[0][0] = 1;
	mine[0][1] = 2;
	mine[0][2] = 3;
	mine[1][0] = 3;
	mine[1][1] = 4;
	mine[1][2] = 8;
	mine[2][0] = 9;
	mine[2][1] = 6;
	mine[2][2] = 7;*/
	mine[0][0] = 1;
	mine[0][1] = 3;
	mine[0][2] = 1;
	mine[0][3] = 5;

	mine[1][0] = 2;
	mine[1][1] = 2;
	mine[1][2] = 4;
	mine[1][3] = 1;

	mine[2][0] = 5;
	mine[2][1] = 0;
	mine[2][2] = 2;
	mine[2][3] = 3;

	mine[3][0] = 0;
	mine[3][1] = 6;
	mine[3][2] = 1;
	mine[3][3] = 2;
}

int	main(int argc, char **argv)
{
	int	**mine;
	int	n;

//	int	xmine[][3] = { { 1, 2, 3 },
//					  { 3, 4, 8 },
//					  { 9, 6, 7 } };

	if (2 == argc)
	{
		n = ft_atoi(argv[1]);
//		n = (int)(sizeof(xmine) / sizeof(xmine[0][0]));
//		n = 3;
		n = 4;
		mine = minenew(n);
		minefill(mine, n);
		mineput(mine, n);
//		mineput(xmine, n);
		ft_printf("\n");
		ft_printf("max = %d\n", gold_gain(mine, n));
	}
	return (EXIT_SUCCESS);
}

