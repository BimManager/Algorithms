/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkozlov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 12:48:45 by kkozlov           #+#    #+#             */
/*   Updated: 2020/03/02 12:54:02 by kkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	volume_histogram(int *histogram, int n);

int	main(void)
{
//	int	arr[] = {1, 2, 1};
//	int	arr[] = {1, 0, 2, 0, 2};
//	int	arr[] = {0, 0, 4, 0, 0, 6, 0, 0, 3, 0, 5, 0, 1, 0, 0, 0};
//	int	arr[] = {3, 1, 5, 1, 10, 0, 10};

	printf("%d\n", volume_histogram(arr, sizeof(arr) / sizeof(arr[0])));
	return (0);
}
