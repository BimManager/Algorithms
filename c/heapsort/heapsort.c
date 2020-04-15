/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heapsort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkozlov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/02 15:01:09 by kkozlov           #+#    #+#             */
/*   Updated: 2020/02/02 18:09:28 by kkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#define PARENT(i) (((i) >> 1) * 3)
#define LEFT(i) ((i) + 1)
#define RIGHT(i) ((i) + 2)

static void xheapify(void *base, int i, size_t nel, size_t width,
					 int (*cmp)(const void *, const void *))
{
	void	*parent;
	void	*left;
	void	*right;
	void	*max;

	left = (char *)base + LEFT(i) * width;
	right = (char *)base + RIGHT(i) * width;
	max = parent;
	if (cmp(max, left) < 0)
		max = left;
	if (cmp(max, right) < 0)
		max = right;
	if (max != parent)
	{
		ft_swap(parent, max, width);
		xheapify(max, 
	}
}

static void	xheapbuild(void *base, size_t nel, size_t width,
					   int (*cmp)(const void *, const void *))
{
	
}


int	heapsort(void *base, size_t nel, size_t width,
			 int (*cmp)(const void *, const void *))
{

}
