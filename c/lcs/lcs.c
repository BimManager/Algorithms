/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lcs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkozlov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 16:54:49 by kkozlov           #+#    #+#             */
/*   Updated: 2020/03/05 17:51:49 by kkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct		s_tab
{
	int				**cells;
	int				n_rows;
	int				n_cols;
}					t_tab;

static t_tab	*tabnew(int nr, int nc)
{
	t_tab	*tab;
	int		i;

	tab = malloc(sizeof(t_tab));
	tab->n_rows = nr;
	tab->n_cols = nc;
	tab->cells = malloc(nr * sizeof(void *));
	i = -1;
	while (++i < nr)
		(tab->cells)[i] = malloc(nc * sizeof(int));
	return (tab);
}

#include <stdio.h>

static char		*tabfill(t_tab *tab, const char *s1, const char *s2)
{
	int	r;
	int	c;
	int	max_len;
	int	idx;
	char	*sub;

	r = -1;
	max_len = 0;
	idx = 0;
	while (++r < tab->n_rows)
	{
		c = -1;
		while (++c < tab->n_cols)
		{
			if (!r || !c)
				tab->cells[r][c] = 0;
			else
			{
				if (s1[r - 1] == s2[c - 1])
				{
					tab->cells[r][c] = tab->cells[r - 1][c - 1] + 1;
					if (tab->cells[r][c] > max_len)
					{
						max_len = tab->cells[r][c];
						idx = r - max_len;
					}
				}
				else
				{
					tab->cells[r][c] = 0;
				}
			}
		}
	}
	printf("max_len: %d idx: %d\n", max_len, idx);
	sub = malloc(max_len * sizeof(char));
	sub[max_len] = '\0';
	r = -1;
	while (++r < max_len)
		sub[r] = s1[idx + r];
	return (sub);
}

char	*lcs(const char *s1, const char *s2)
{
	t_tab	*tab;
	int		s1_len;
	int		s2_len;
	char	*sub;

	s1_len = strlen(s1);
	s2_len = strlen(s2);
	tab = tabnew(s1_len + 1, s2_len + 1);
	sub = tabfill(tab, s1, s2);
	return (sub);
}
