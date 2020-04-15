/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkozlov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 09:42:56 by kkozlov           #+#    #+#             */
/*   Updated: 2020/02/29 09:48:39 by kkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	missing_number(int *arr, int n, int size);

int	main(void)
{
	int	last = 5;
	int	arr[] = {1, 2, 3, last};

	printf("%d\n", missing_number(arr, last, sizeof(arr) / sizeof(arr[0])));
	return (0);
}
