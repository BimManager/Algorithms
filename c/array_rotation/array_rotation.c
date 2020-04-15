/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_rotation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkozlov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 09:49:42 by kkozlov           #+#    #+#             */
/*   Updated: 2020/03/01 18:07:51 by kkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static void	intswap(int *a, int *b)
{
	*a ^= *b;
	*b ^= *a;
	*a ^= *b;
}

void		array_rotation(int *arr, int n, int k)
{
	int	i;
	static int	buffer[256];

	i = -1; 
	while (++i < n)
		buffer[(i + k) % n] = arr[i];
	i = -1;
	while (++i < n)
		arr[i] = buffer[i];
}

#include <stdio.h>

/*static void	arrput(int *arr, int n)
{
	int	i;

	i = -1;
	while (++i < n)
		printf("%3d", arr[i]);
	printf("\n");
	}*/

void		array_rotation2(int *arr, int n, int k)
{
	int	i;
	int	j;

	i = -1;
	while (++i < k)
		intswap(&arr[i], &arr[n - k + i]);
	i = -1;
	while (++i < k)
	{
		j = n - k + i;
		while (j > k + i)
		{
			intswap(&arr[j], &arr[j - 1]);			
			--j;
		}
	}
}
