/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   longest_substr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkozlov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 10:18:23 by kkozlov           #+#    #+#             */
/*   Updated: 2020/01/29 17:35:47 by kkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

typedef struct	s_tab
{
	int			**cells;
	int			n_rows;
	int			n_cols;
}				t_tab;

static t_tab	*ft_tabnew(size_t nr, size_t nc)
{
	t_tab	*tab;

	tab = malloc(sizeof(t_tab));
	tab->rows = nr;
	tab->cols = nc;
	tab->tab = malloc(tab->rows *  sizeof(void *));
	while (nr--)
	{
		nc = tab->cols;
		(tab->tab)[nr] = malloc(tab->cols * sizeof(int));
		while (nc--)
			(tab->tab)[nr][nc] = 0;
		
	}
	return (tab);
}

static void		ft_tabfill(t_tab *tab, const char *str1, const char *str2)
{
	int	r;
	int	c;

	r = 0;
	while (++r < tab->rows)
	{
		c = 0;
		while (++c < tab->cols)
			if (str1[r - 1] == str2[c - 1])
				(tab->tab)[r][c] = (tab->tab)[r - 1][c - 1] + 1;
	}
}

static void		ft_tabput(t_tab *tab)
{
	int	r;
	int	c;

	r = -1;
	while (++r < tab->rows)
	{
		c = -1;
		while (++c < tab->cols)
			ft_printf("%5d", (tab->tab)[r][c]);
		ft_printf("\n");
	}
}

static void		ft_maxfind(t_tab *tab, const char *str1)
{
	int	r;
	int	c;
	int	i;
	int	j;
	int	max;
	char	*str;

	r = tab->rows;
	max = 0;
	while (r--)
	{
		c = tab->cols;
		while (c--)
			if ((tab->tab)[r][c] > max)
			{
				max = (tab->tab)[r][c];
				i = r;
				j = c;
			}
	}
	ft_printf("i = %d; j = %d; max = %d\n", i, j, max);
	str = malloc((max + 1) * sizeof(char));
	*(str + max) = 0;
	while (max--)
		*(str + max) = *(str1 + --i);
	ft_printf("%s\n", str);
}

char	*longest_substr(const char *str1, const char *str2)
{
	int		ln1;
	int		ln2;
	t_tab	*tab;

	ln1 = ft_strlen(str1);
	ln2 = ft_strlen(str2);
	tab = ft_tabnew(ln1 + 1, ln2 + 1);
	ft_tabfill(tab, str1, str2);
	ft_tabput(tab);
	ft_maxfind(tab, str1);
	return (NULL);
}

int		main(int argc, char **argv)
{
	if (3 == argc)
		longest_substr(argv[1], argv[2]);
	return (0);
}
