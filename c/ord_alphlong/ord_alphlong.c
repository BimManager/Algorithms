/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ord_alphlong.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkozlov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 15:28:36 by kkozlov           #+#    #+#             */
/*   Updated: 2020/03/09 18:52:52 by kkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>


#include <stdio.h>

static void	strput(char *str)
{
	while (*str)
		write(1, str++, 1);
}

static char	xtolower(char c)
{
	if ('A' <= c && 'Z' >= c)
		return (c + ('a' - 'A'));
	return (c);
}

static int	istrcmp(char *s1, char *s2)
{
	char	c1;
	char	c2;

	while (*s1 && *s2)
	{
		c1 = xtolower(*s1);
		c2 = xtolower(*s2);
		if (c1 != c2)
		{
			return (c1 - c2);
		}
		++s1;
		++s2;
	}
	return (xtolower(*s1) - xtolower(*s2));
}

static int	xstrlen(char *str)
{
	int	len;

	len = 0;
	while (*str++)
		++len;
	return (len);
}

static int	strlencmp(char *s1, char *s2)
{
	return (xstrlen(s1) - xstrlen(s2));
}

static int	isws(char c)
{
	return (' ' == c || '\t' == c
			|| '\n' == c);
}

static int	wlen(char *word)
{
	int	len;

	len = 0;
	while (*word && !isws(*word))
	{
		++len;
		++word;
	}
	return (len);
}

static int	wc(char *str)
{
	int	nw;

	nw = 0;
	while (*str)
	{
		while (*str && isws(*str))
			++str;
		if (*str)
			++nw;
		while (*str && !isws(*str))
			++str;
	}
	return (nw);
}

static char	**strsplit(char *str, int *nw)
{
	char	**tab;
	char	*it;
	int		wl;
	int		i;

	*nw = wc(str);
	tab = malloc((*nw + 1) * sizeof(void *));
	tab[*nw] = NULL;
	i = 0;
	while (*str)
	{
		while (*str && isws(*str))
			++str;
		wl = wlen(str);
		tab[i] = malloc((wl + 1) * sizeof(char));
		tab[i][wl] = '\0';
		it = tab[i];
		while (wl--)
			*it++ = *str++;
		++i;
	}
	return (tab);
}

static void	xswap(void *pv1, void *pv2, int n)
{
	char	t;

	while (n--)
	{
		t = *((char*)pv1 + n);
		*((char *)pv1 + n) = *((char *)pv2 + n);
		*((char *)pv2 + n) = t;
	}
}

static void	insort(char **tab, int n, int (*cmp)(char *, char *))
{
	int	i;
	int	j;

	i = -1;
	while (++i < n - 1)
	{
		j = i + 1;
		while (0 < j && 0 < cmp(tab[j - 1], tab[j]))
		{
			xswap(&tab[j - 1], &tab[j], sizeof(void *));
			--j;
		}
	}
}

#include <string.h>

static void	lineput(char **tab, int nw)
{
	while (nw--)
	{
		strput(*tab++);
		if (nw)
			strput(" ");
	}
	strput("\n");
}

static void	ord_alphlong(char *str)
{
	char	**tab;
	int		nw;
	int		i;
	int		j;

	tab = strsplit(str, &nw);
	insort(tab, nw, &strlencmp);
	i = -1;
	while (++i < nw)
	{
		j = i;
		while (++j < nw && strlen(tab[j - 1]) == strlen(tab[j]))
			;
		insort(tab + i, j - i, &istrcmp);
		lineput(tab + i, j - i); 
		i = j - 1;
	}
}



int		main(int argc, char **argv)
{
	if (2 == argc)
		ord_alphlong(argv[1]);
	else
		strput("\n");
	return (0);
}
