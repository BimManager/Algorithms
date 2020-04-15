/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pascals_triangle.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkozlov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 09:39:06 by kkozlov           #+#    #+#             */
/*   Updated: 2020/01/13 10:05:10 by kkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_triput(int **tri, int size, int *col_sizes)
{
	int	r;
	int	c;

	r = -1;
	while (++r < size)
	{
		c = -1;
		while (++c < col_sizes[r])
			ft_printf("%5d", tri[r][c]);
		ft_printf("\n");
	}
}

void		trifill(int **tri, int i, int j)
{
	int	k;

	if (0 > i && 0 > j)
		return ;
	tri[i][j] = 1;
	trifill(tri, i - 1, j - 1);
	k = -1;
	while (++k < j)
	{
		if (!k)
			tri[i][k] = 1;
		else
			tri[i][k] = tri[i - 1][k - 1] + tri[i - 1][k];
	}
}

int			**generate(int nrows, int *size, int **col_sizes)
{
	int	**tri;

	*size = nrows;
	tri = malloc(*size * sizeof(void *));
	*col_sizes = malloc(*size * sizeof(int));
	while (nrows--)
	{
		tri[nrows] = malloc((nrows + 1) * sizeof(int));
		(*col_sizes)[nrows] = nrows + 1;
	}
	trifill(tri, *size - 1, *size - 1);
	return (tri);
}

int			main(int argc, char **argv)
{
	int	size;
	int	*col_sizes;
	int	**tri;

	if (2 == argc)
	{
		tri = generate(ft_atoi(argv[1]), &size, &col_sizes);
		ft_triput(tri, size, col_sizes);
	}
	return (0);
}
