/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_pivot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkozlov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/25 09:48:48 by kkozlov           #+#    #+#             */
/*   Updated: 2019/12/25 10:18:25 by kkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define NO_PIVOT	-1

int	find_pivot(int *arr, int n)
{
	int	left_sum;
	int	right_sum;
	int	i;

	if (3 > n)
		return (NO_PIVOT);
	i = -1;
	right_sum = 0;
	while (++i < n)
		right_sum += arr[i];
	i = -1;
	left_sum = 0;
	while (++i < n)
	{
		right_sum -= arr[i];
		if (left_sum == right_sum)
			return (i);
		left_sum += arr[i];
	}
	return (NO_PIVOT);
}
