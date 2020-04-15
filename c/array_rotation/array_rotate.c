/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_rotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkozlov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/07 13:57:30 by kkozlov           #+#    #+#             */
/*   Updated: 2020/03/08 12:05:21 by kkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static void	xswap(void *pv1, void *pv2, unsigned n)
{
	char	t;

	while (n--)
	{
		t = *((char *)pv1 + n);
		*((char *)pv1 + n) = *((char *)pv2 + n);
		*((char *)pv2 + n) = t;
	}
}

#include <stdio.h>

void	array_rotate(int *arr, int n, int k)
{
	int	i;
	int	j;
	int	m;

	k %= n;
	i = n - k - 1;
	while (++i < n)
		xswap(&arr[i], &arr[(i + k) % n], sizeof(int));
	i = n - k - 1;
	m = 0;
	while (++i < n)  
	{
		j = i;
		while (--j - m >= k)
			xswap(&arr[j + 1], &arr[j], sizeof(int));
		++m;
	}
}



int	main(void)
{
	int	arr[] = {1, 2, 3, 4, 5, 6, 7};
	unsigned	n;
	int	i;
	int	k;

	n = sizeof(arr) / sizeof(arr[0]);
	k = 5;
	array_rotate(arr, n, k);
	i = -1;
	while (++i < n)
		printf("%3d", arr[i]);
	printf("\n");
	return (0);
}
