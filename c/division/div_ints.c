/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   div_ints.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkozlov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/27 09:42:41 by kkozlov           #+#    #+#             */
/*   Updated: 2019/12/28 18:00:52 by kkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#define IS_POW2(x) (0 < (x)) && !((x) & ((x) - 1))

#define FT_MSB(x, s) ((x) & (~0U << (BYTE * (s) - 1)))

int	restoring_da(int q, int m)
{
	int	a;
	int	i;

	a = 1;
	i = -1;
	while (++i < 32)
	{
		q <<= 1;
		if (!q)
			q = 1;
		a <<= 1;
		a -= m;
		if (FT_MSB(a, sizeof(int)))
		{
			q &= (~1);
			a += m;
		}
		else 
			q += 1;
		a <<= 1;
	}
	return (q);
}

int	longdiv(int n, int d)
{
	int	q;
	int	r;
	int	i;

	q = 0;
	r = 0;
	i = -1;
	while (++i < BYTE * sizeof(int))
	{
		r <<= 1;
		r += (n & (1 << i));
		if (r >= d)
		{
			r -= d;
			q 
		}
	}
}

int	div_ints(int dividend, int divisor)
{
	(void)dividend;
	(void)divisor;
	return (0);
}

int	main(void)
{
	int	div;
	int	dvsr;

	div = 8;
	dvsr = 3;
	ft_printf("%d\n", restoring_da(div, dvsr));
	div = -1;
	ft_printf("%#b\n", &div);
	ft_printf("sb = %d\n", FT_MSB(div, sizeof(int)));
	div = ~0U << (BYTE * sizeof(int) - 1);
	ft_printf("%#b\n", &div);
	return (0);
}
