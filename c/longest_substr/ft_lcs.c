/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lcs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkozlov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 20:02:37 by kkozlov           #+#    #+#             */
/*   Updated: 2020/02/03 17:44:56 by kkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

typedef struct	s_tab
{
	int			**cells;
	int			n_rows;
	int			n_cols;
}				t_tab;

t_tab	*ft_tabnew(int n_rows, int n_cols)
{
	t_tab	*tab;
	size_t	size;

	tab = malloc(sizeof(t_tab));
	tab->n_rows = n_rows;
	tab->n_cols = n_cols;
	tab->cells = malloc(n_rows * sizeof(void *));
	size = n_cols * sizeof(int);
	while (n_rows--)
	{
		tab->cells[n_rows] = malloc(size);
		ft_bzero(tab->cells[n_rows], size);
	}
	return (tab);
}

void	ft_tabdel(t_tab **tab)
{
	while ((*tab)->n_rows--)
		free((*tab)->cells[(*tab)->n_rows]);
	free((*tab)->cells);
	free(*tab);
	*tab = NULL;
}

static int	tabfill(t_tab *tab, const char *s1, const char *s2, int *len)
{
	int	i;
	int	j;
	int	xi;

	i = -1;
	*len = 0;
	while (++i < tab->n_rows - 1)
	{
		j = -1;
		while (++j < tab->n_cols - 1)
			if (s1[i] == s2[j])
			{
				tab->cells[i + 1][j + 1] = 1 + tab->cells[i][j];
				if (*len < tab->cells[i + 1][j + 1])
				{
					*len = tab->cells[i + 1][j + 1];
					xi = i;
				}
			}
	}
	return (xi);
}

char	*ft_lcs(const char *s1, const char *s2)
{
	t_tab	*tab;
	char	*substr;
	int		len;
	int		xi;

	tab = ft_tabnew(ft_strlen(s1) + 1, ft_strlen(s2) + 1);
	xi = tabfill(tab, s1, s2, &len);
	substr = malloc((len + 1) * sizeof(char));
	substr[len] = '\0';
	while (len--)
		substr[len] = s1[xi--];
	ft_tabdel(&tab);
	return (substr);
}

static void	str_maxlenoc(int argc, char **argv)
{
	int		i;
	int		j;
	int		min;
	char	*cur;
	char	*sub;

	min = INT_MAX;
	i = -1;
	sub = NULL;
	while (++i < argc)
	{
		j = i;
		while (++j < argc)
		{
			cur = ft_lcs(argv[i], argv[j]);
			ft_printf("%s & %s = %s\n", argv[i], argv[j], cur);
			if (ft_strlen(cur) < min)
			{
				if (sub)
					free(sub);
				sub = ft_strdup(cur);
				min = ft_strlen(cur);
			}
			free(cur);
		}	
	}
	ft_printf("res = %s\n", sub);
}

int	main(int argc, char **argv)
{
	char	*substr;


	if (3 == argc)
	{
		substr = ft_lcs(argv[1], argv[2]);
		ft_printf("%s\n", substr);
		free(substr);
	}
	else if (3 < argc)
		str_maxlenoc(argc - 1, argv + 1);
	return (EXIT_SUCCESS);
}
