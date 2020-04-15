/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redo_volume_histogram.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkozlov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 08:22:15 by kkozlov           #+#    #+#             */
/*   Updated: 2020/03/02 12:51:02 by kkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define MIN(a, b) ((a) < (b) ? (a) : (b))

static int	calc_rhsmax(int *histogram, int n)
{
	int	rhs_max;
	int	i;

	if (1 == n)
		return (histogram[0]);
	rhs_max = 0;
	i = -1;
	while (++i < n)
		if (histogram[i] > rhs_max)
			rhs_max = histogram[i];
	return (rhs_max);
}

int			volume_histogram(int *histogram, int n)
{
	int	total;
	int	lhs_max;
	int	rhs_max;
	int	i;

	if (0 >= n)
		return (-1);
	lhs_max = histogram[0];
	rhs_max = calc_rhsmax(histogram, n);
	total = 0;
	i = -1;
	while (++i < n)
	{
		if (histogram[i] > lhs_max)
			lhs_max = histogram[i];
		total += MIN(lhs_max, rhs_max) - histogram[i];
		if (i != (n - 1) && rhs_max == histogram[i])
			rhs_max = calc_rhsmax(histogram + i + 1, n - i - 1);
	}
	return (total);
}
