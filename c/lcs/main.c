/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkozlov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 17:14:26 by kkozlov           #+#    #+#             */
/*   Updated: 2020/03/05 17:22:56 by kkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*lcs(const char *s1, const char *s2);


int		main(int argc, char **argv)
{
	char	*sub;

	if (3 == argc)
	{
		sub = lcs(argv[1], argv[2]);
		printf("%s\n", sub);
	}
	return (0);
}
