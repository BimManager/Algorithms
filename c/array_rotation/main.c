/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkozlov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 10:00:49 by kkozlov           #+#    #+#             */
/*   Updated: 2020/03/01 18:07:14 by kkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	array_rotation(int *arr, int n, int k);
void	array_rotation2(int *arr, int n, int k);

void	arrput(int *arr, int n)
{
	int	i;

	i = -1;
	while (++i < n)
		printf("%3d", arr[i]);
	printf("\n");
}

int	main(void)
{
	int	arr[] = {1, 2, 3, 4, 5};
	int	k;
	
	k = 3;
	array_rotation2(arr, sizeof(arr) / sizeof(arr[0]), k);
	arrput(arr, sizeof(arr) / sizeof(arr[0]));
	return (0);
}
