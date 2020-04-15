/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gold_gain.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkozlov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 08:26:47 by kkozlov           #+#    #+#             */
/*   Updated: 2020/03/05 09:10:46 by kkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include <stdio.h>

void	tabput(int **tab, int n)
{
	int	i;
	int	j;

	i = -1;
	while (++i < n)
	{
		j = -1;
		while (++j < n)
			printf("%3d", tab[i][j]);
		printf("\n");
	}
}

static int	threemax(int a, int b, int c)
{
	//printf("a: %d b: %d c: %d\n", a, b, c);
	if (a > b && a > c)
		return (a);
	else if (b > a && b > c)
		return (b);
	return (c);
}

int			gold_gain(int **mine, int n)
{
	int	**tab;
	int	i;
	int	j;
	int	max;
	
	tab = malloc((n + 2) * sizeof(void *));
	i = -1;
	while (++i < n + 2)
	{
		tab[i] = malloc((n + 2) * sizeof(int));
		j = -1;
		while (++j < n + 2)
			tab[i][j] = 0;
	}
	j = 0;
	while (++j < n + 1)
	{
		i = 0;
		while (++i < n + 1)
		{
			max = threemax(tab[i - 1][j - 1],
						   tab[i][j - 1], tab[i + 1][j - 1]);
			//printf("max: %d\n", max);
			tab[i][j] = max + mine[i - 1][j - 1];
		}
	}
	tabput(tab, n + 2);
	i = 0;
	max = 0;
	while (++i < n + 1)
		if (tab[i][n] > max)
			max = tab[i][n];
	i = -1;
	while (++i < n + 2)
		free(tab[i]);
	free(tab);
	return (max);
}


