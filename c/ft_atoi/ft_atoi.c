/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkozlov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/26 09:54:25 by kkozlov           #+#    #+#             */
/*   Updated: 2019/12/26 14:43:17 by kkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>

static int	ft_isws(char c)
{
	return (' ' == c || '\t' == c
			|| '\n' == c);
}

static int	ft_isdigit(char c)
{
	return ('0' <= c && '9' >= c);
}

static void	ft_sign(char **str, int *neg)
{
	if ('-' == **str)
		*neg = 1;
	else if ('+' == **str)
		*neg = 0;
	else
		return ;
	++(*str);
}

int			ft_atoi(char *str)
{
	int				res;
	int				neg;

	res = 0;
	neg = -1;
	while (ft_isws(*str))
		++str;
	ft_sign(&str, &neg);
	while (*str && ft_isdigit(*str))
	{
		if (res && (INT_MIN / 10 > res))
			return (1 == neg ? INT_MIN : INT_MAX);
		if (INT_MIN - res * 10 >= -8 && *str == '9')
			return (1 == neg ? INT_MIN : INT_MAX);
		res = res * 10 - (*str - '0');
		++str;
	}
	if (INT_MIN == res && -1 == neg)
		return (INT_MAX);
	return (1 == neg ? res : ~res + 1);
}
