/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkozlov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 08:48:13 by kkozlov           #+#    #+#             */
/*   Updated: 2020/03/05 09:10:14 by kkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int		gold_gain(int **mine, int n);
void	tabput(int **tab, int n);

int	main(void)
{
	int	**mine;
	int	n;
	int	i;
	int	j;

	n = 5;
	sranddev();
	mine = malloc(n * sizeof(void *));
	i = -1;
	while (++i < n)
		mine[i] = malloc(n * sizeof(int));
	i = -1;
	while (++i < n)
	{
		j = -1;
		while (++j < n)
			mine[i][j] = rand() % 10;
	}
	tabput(mine, n);
	printf("\n");
	printf("%d\n", gold_gain(mine, n));
	return (0);
}
