/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_int.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkozlov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/28 19:42:30 by kkozlov           #+#    #+#             */
/*   Updated: 2019/12/28 20:01:58 by kkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>

#include "libft.h"

int	reverse_int(int n)
{
	int	ret;

	ret = 0;
	while (n)
	{
		if (INT_MAX / 10 < ret || INT_MIN / 10 > ret)
			return (0);
		ret = ret * 10 + n % 10;
		n /= 10;
	}
	return (ret);
}
