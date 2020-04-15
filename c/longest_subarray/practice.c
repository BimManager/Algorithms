/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   practice.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkozlov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 15:07:40 by kkozlov           #+#    #+#             */
/*   Updated: 2020/03/06 15:17:31 by kkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	lencalc(char *arr)
{
	int	odd;
	int	even;
	int	len;
	char	*it;
	
	odd = 0;
	even = 0;
	len = 0;
	it = arr;
	while (*it)
	{
		if (*it & 1)
			++odd;
		else
			++even;
		++len;
		++it;
	}
	while (--it >= arr && odd != even)
	{
		if (*it & 1)
			--odd;
		else 
			--even;
		--len;
	}
	return (len);
}

char	*longest_subarray(char *arr)
{
	char	*it;
	int		max_len;
	int		cur_len;
	int		idx;
	char	*sub;
	char	*ret;

	it = arr;
	max_len = 0;
	while (*it)
	{
		if (max_len < (cur_len = lencalc(it)))
		{
			max_len = cur_len;
			idx = it - arr;
		}
		++it;
	}
	sub = malloc((max_len + 1) * sizeof(char));
	sub[max_len] = '\0';
	ret = sub;
	it = arr + idx;
	while (max_len--)
		*sub++ = *it++;
	return (ret);
}
