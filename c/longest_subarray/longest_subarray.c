/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   longest_subarray.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkozlov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 16:02:43 by kkozlov           #+#    #+#             */
/*   Updated: 2020/02/28 16:19:39 by kkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int	lencalc(char *arr)
{
	int	even;
	int	odd;
	int	len;
	int	i;

	len = 0;
	even = 0;
	odd = 0;
	i = -1;

	while (arr[++i])
	{
		if (0 == (arr[i] - '0') % 2)
			++even;
		else
			++odd;
		++len;
	}
	while (arr[--i] && odd != even)
	{
		if (0 == (arr[i] - '0') % 2)
			--even;
		else
			--odd;
		--len;

	}
	return (len);
}

char	*longest_subarray(char *arr)
{
	int	len;
	int	calc;
	int	max;
	int	idx;
	int	i;
	char	*res;

	len = strlen(arr);
	max = 0;
	i = -1;
	idx = 0;
	while (++i < len)
	{
		calc = lencalc(arr + i);
		if (calc > max)
		{
			max = calc;
			idx = i;
		}
	}
	res = malloc((max + 1) * sizeof(char));
	i = -1;
	while (++i < max)
		res[i] = arr[idx + i];
	return (res);
}

int	main(int argc, char **argv)
{
	if (2 == argc)
		printf("%s\n", longest_subarray(argv[1]));
	return (0);
}



