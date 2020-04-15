/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   max_area.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkozlov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 10:21:00 by kkozlov           #+#    #+#             */
/*   Updated: 2020/02/23 10:49:32 by kkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))

/*
**	data[0]: the max height on the left-hand side
**	data[1]: the max height on the right-hand side
**	data[2]: the current height
**	data[3]: the total area 
**	data[4]: the counter
*/

typedef struct	s_xdata
{
	int			max_lhs;
	int			max_rhs;
	int			total_area;
}				t_xdata;

int	max_area(int *height, int n)
{
	t_xdata	data;
	int		i;
	int		j;

	if (n < 2)
		return (0);
	data.max_lhs = height[0];
	data.max_rhs = height[1];
	data.total_area = 0;
	i = 1;
	while (++i < n)
		if (data.max_rhs < height[i])
			data.max_rhs = height[i];
	i = 0;
	while (++i < n)
	{
		data.total_area += MIN(data.max_lhs, data.max_rhs) - height[i - 1];
		if (height[i] > data.max_lhs)
			data.max_lhs = height[i];
		if ((i != n - 1) && height[i] == data.max_rhs)
		{
			j = i + 1;
			data.max_rhs = height[j];
			while (++j < n)
				if (height[j] > data.max_rhs)
					data.max_rhs = height[j];
		}
	}
	return (data.total_area);
}


int	main(void)
{
	int	buffer[] = {1, 8, 6, 2, 5, 4, 8, 3, 7};
	
	ft_printf("%d\n", max_area(buffer, sizeof(buffer) / sizeof(buffer[0])));
	return (EXIT_SUCCESS);
}
