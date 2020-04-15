/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkozlov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 15:16:08 by kkozlov           #+#    #+#             */
/*   Updated: 2020/03/06 15:17:01 by kkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*longest_subarray(char *arr);

int		main(int argc, char **argv)
{
	if (2 == argc)
		printf("%s\n", longest_subarray(argv[1]));
	return (0);
}
