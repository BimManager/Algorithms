/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_anagram.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkozlov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 14:20:05 by kkozlov           #+#    #+#             */
/*   Updated: 2020/02/21 09:17:13 by kkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#ifdef BUFF_SIZE
# undef BUFF_SIZE
#endif

#define BUFF_SIZE	255

int	is_anagram(const char *s1, const char *s2)
{
	char	buffer[BUFF_SIZE];
	int		i;
	
	i = -1;
	while (++i < BUFF_SIZE)
		buffer[i] = 0;
	while (*s1)
		buffer[(int)*s1++] += 1;
	while (*s2)
		buffer[(int)*s2++] -= 1;
	i = -1;
	while (++i < BUFF_SIZE)
		if (buffer[i])
			return (0);
	return (1);
}

int	main(int argc, char **argv)
{
	if (3 == argc)
		ft_printf("%d\n", is_anagram(argv[1], argv[2]));
	return (EXIT_SUCCESS);
}
