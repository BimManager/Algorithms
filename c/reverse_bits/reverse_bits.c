/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_bits.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkozlov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/29 09:51:55 by kkozlov           #+#    #+#             */
/*   Updated: 2019/12/29 17:09:04 by kkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#define BPB	8

uint32_t	reverse_bits(uint32_t n)
{
	uint32_t	i;
	uint32_t	lbit;
	uint32_t	rbit;
	uint32_t	nbits;

	i = 0;
	nbits = BPB * sizeof(uint32_t);
	while (++i <= nbits / 2)
	{
		lbit = n & (1U << (nbits - i));
		rbit = n & (1U << (i - 1));
		if ((lbit && rbit) || (!lbit && !rbit))
			continue ;
		if (lbit)
		{
			n |= 1U << (i - 1);
			n &= ~(1U << (nbits - i));
		}
		else
		{
			n |= 1U << (nbits - i);
			n &= ~(1U << (i - 1));
		}
	}
	return (n);
}

int			main(int argc, char **argv)
{
	t_uint32	unb;

	if (2 == argc)
	{
		unb = ft_atoi(argv[1]);
		ft_printf("%b\n", &unb);
		unb = reverse_bits(unb);
		ft_printf("%b\n", &unb);
	}
	return (0);
}
