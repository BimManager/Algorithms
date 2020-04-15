/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   roman_to_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkozlov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/04 10:35:55 by kkozlov           #+#    #+#             */
/*   Updated: 2020/01/04 10:54:24 by kkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	g_rmndgts[] =
{
	[0] = 0,
	['I'] = 1,
	['V'] = 5,
	['X'] = 10,
	['L'] = 50,
	['C'] = 100,
	['D'] = 500,
	['M'] = 1000,
	[127] = 0,
};

int	roman_to_int(const char *str)
{
	const char	*it;
	int			res;
	int			prv;
	int			cur;

	it = str;
	while (*it)
		++it;
	res = 0;
	prv = 0;
	while (it-- > str)
	{
		cur = g_rmndgts[(int)*it];
		if (!cur)
			return (res);
		if (cur < prv)
			res -= cur;
		else
			res += cur;
		prv = cur;
	}
	return (res);
}

int	main(int argc, char **argv)
{
	if (2 == argc)
		ft_printf("res = %d\n", roman_to_int(argv[1]));
	return (0);
}
