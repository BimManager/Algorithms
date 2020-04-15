/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   longest_subarray.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkozlov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/01 10:44:24 by kkozlov           #+#    #+#             */
/*   Updated: 2020/01/02 11:01:35 by kkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	**ft_tabnew(int rows, int cols)
{
	int	**tab;
	int	i;

	tab = malloc(rows * sizeof(void *));
	while (rows--)
	{
		*(tab + rows) = malloc(cols * sizeof(int));
		i = -1;
		while (++i < cols)
			tab[rows][i] = 0;
	}
	return (tab);
}

static void	ft_tabput(int **tab, int rows, int cols)
{
	int	row;
	int	col;

	row = -1;
	while (++row < rows)
	{
		col = -1;
		while (++col < cols)
			ft_printf("%4d", tab[row][col]);
		ft_printf("\n");
	}	
}

/*static void	ft_tabdel(int ***tab, int rows, int cols)
{
	(void)cols;
	while (rows--)
		free(*(*tab + rows));
	free(*tab);
	*tab = NULL;
	ft_printf("freed\n");
	}*/

static void	ft_tabfill(const char *arr, int	**tab, int rows, int cols)
{
	int	row;
	int	col;

	row = -1;
	while (++row < rows)
	{
		col = row;
		tab[row][col] = (*(arr + col) % 2 == 0 ? 1 : -1);
		while (++col < cols)
			tab[row][col] = tab[row][col - 1] + 
				(*(arr + col) % 2 == 0 ? 1 : -1);
	}
}

static char	*ft_tabsub(const char *arr, int **tab, int rows, int cols)
{
	char	*ret;
	int		row;
	int		col;
	int		done;
	int		i;
	
	row = -1;
	done = 0;
	while (!done && ++row < rows)
	{
		col = cols;
		while (--col > row)
			if (!tab[row][col])
			{
				done = 42;
				break;
			}
	}
	ft_printf("done\n");
	++col;
	ret = malloc((col - row + 1) * sizeof(char));
	*(ret + col - row) = '\0';
	i = col - row;
	ft_printf("row = %d; col = %d\n", row, col);
	while (col-- >= row)
		*(ret + --i) = *(arr + col);
	return (ret);
}

char	*longest_subarray(char *arr)
{
	int		size;
	int		**tab;
	char	*ret;

	size = ft_strlen(arr);
	tab = ft_tabnew(size, size);
	ft_tabfill(arr, tab, size, size);
	ft_tabput(tab, size, size);
	ret = ft_tabsub(arr, tab, size, size);
//	ft_tabdel(&tab, size, size);
	return (ret);
}

int		main(int argc, char **argv)
{
	char	*ret;

	if (2 == argc)
	{
		ret = longest_subarray(argv[1]);
		ft_printf("%s\n", ret);
		free(ret);
	}
	return (0);
}
