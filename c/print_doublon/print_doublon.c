/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_doublon.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkozlov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 09:44:57 by kkozlov           #+#    #+#             */
/*   Updated: 2020/03/06 15:27:20 by kkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>


/*void	print_doublon(int *a, int na, int *b, int nb)
{
	int	min;
	int	i;
	int	j;
	int	fst;

	i = -1;
	j = -1;
	fst = 1;
	while (++i < na && ++j < nb)
	{
		min = a[i] > b[j] ? a[i] : b[j];
		while (i < na && a[i] < min)
			++i;
		while (j < nb && b[j] < min)
			++j;
		if (i == na || j == nb)
			return ;
		else if (a[i] == b[j])
		{
			fst ? printf("%d", a[i]) : printf(" %d", a[i]);
			fst = 0;
		}
	}
	}*/


void	print_doublon(int *a, int na, int *b, int nb)
{
	int	i;
	int	j;
	int	fst;

	i = 0;
	j = 0;
	fst = 1;
	while (i < na && j < nb)
	{
		if (a[i] == b[j])
		{
			if (fst)
				fst = 0;
			else
				printf(" ");
			printf("%d", a[i]);
			++i;
			++j;
		}
		else if (a[i] < b[j])
			++i;
		else
			++j;
	}
	printf("\n");
}

int	main(void)
{
	int	a[] = {0, 7};
	int	b[] = {1, 2, 4, 5, 42, 55};
//	int	a[] = {42, 55};
//	int	b[] = {1, 2, 4, 5, 42, 55};
//	int	a[] = {1, 2, 10, 15};
//	int	b[] = {2, 20, 40, 70};
//	int a[] = {-5, 2, 10, 15, 50, 70, 100, 200, 300, 1200, 5000};
//	int b[] = {2,  4,  5,  6,  7, 10,  40,  70};
//	int a[] = {3, 42, 55, 999};
//	int b[] = {1, 2, 3, 42, 55, 689};
	print_doublon(a, sizeof(a) / sizeof(a[0]),
				  b, sizeof(b) / sizeof(b[0]));
//	printf("\n");
	return (0);
}

