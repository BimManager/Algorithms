/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lcp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkozlov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 12:15:09 by kkozlov           #+#    #+#             */
/*   Updated: 2020/02/08 13:21:54 by kkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	xlcp(char **strs, int i, int n)
{
	int	j;

	j = -1;
	while (++j < n - 1)
		if (strs[j][i] != strs[j + 1][i] || !strs[j][i])
			return (i);
	return (xlcp(strs, i + 1, n));
}

char		*lcp(char **strs, int n)
{
	char	*pfx;
	int		len;

	if (!n)
		return (ft_strdup(""));
	if (1 == n)
		return (ft_strdup(strs[0]));
	len = xlcp(strs, 0, n);
	pfx = malloc((len + 1) * sizeof(char));
	pfx[len] = '\0';
	ft_strncpy(pfx, strs[0], len);
	return (pfx);
}

int	main(void)
{
	char	*strs[] = { "", "", "" };
	char	*pfx;

	pfx = lcp(strs, sizeof(strs) / sizeof(strs[0]));
	ft_printf("%s\n", pfx);
	return (EXIT_SUCCESS);
}

