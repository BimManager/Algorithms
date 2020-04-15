/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hamming_weight.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkozlov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/30 08:30:18 by kkozlov           #+#    #+#             */
/*   Updated: 2019/12/30 09:00:17 by kkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#define BPB	8

int	hamming_weight(t_uint32 n)
{
	int	bits;
	int	res;

	bits = BPB * sizeof(t_uint32);
	res =  0;
	while (bits--)
		if (n & (1U << bits))
			++res;
	return (res);
}
int	ft_hamming_weight(const void *pv, size_t elem_size)
{
	int	bits;
	int	res;

	bits = BYTE * elem_size;
	res = 0;
	while (elem_size--)
	{
		bits = BYTE;
		while (bits--)
			if (*((char *)pv + elem_size) & (1 << bits))
				++res;
	}
	return (res);
}

int	main(int argc, char **argv)
{
	int	nb;

	if (2 == argc)
	{
		nb = ft_atoi(argv[1]);
		ft_printf("res = %d\n", hamming_weight(nb));
		ft_printf("res = %d\n", ft_hamming_weight(&nb, sizeof(nb)));
	}
	return (EXIT_SUCCESS);
}
