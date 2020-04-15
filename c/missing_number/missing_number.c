/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   missing_number.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkozlov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 09:35:21 by kkozlov           #+#    #+#             */
/*   Updated: 2020/02/29 09:47:52 by kkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** S = n * (n + 1) / 2
*/

int	missing_number(int *arr, int n, int size)
{
	int	expected_sum;
	int	actual_sum;

	expected_sum = n * (n + 1) / 2;
	actual_sum = 0;
	while (size--)
		actual_sum += arr[size];
	return (expected_sum - actual_sum);
}


