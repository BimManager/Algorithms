/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heaps.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkozlov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 14:53:54 by kkozlov           #+#    #+#             */
/*   Updated: 2020/01/16 13:09:59 by kkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		tabput(int **arr, int r, int c)
{
	int	i;
	int	j;

	i = -1;
	while (++i < r)
	{
		j = -1;
		while (++j < c)
			ft_printf("%5d", arr[i][j]);
		ft_printf("\n");
	}
}



static void	arrput(int *arr, int k)
{
	int	i;

	i = -1;
	while (++i < k)
		ft_printf("%5d", arr[i]);
	ft_printf("\n");
}

static void	xgenerate(int *arr, int n, int k)
{
	int	i;

	if (1 == k)
	{
		arrput(arr, n);
		return ;
	}
	xgenerate(arr, n, k - 1);
	i = -1;
	while (++i < k - 1)
	{
		if (0 == k % 2)
			ft_swap(&arr[i], &arr[k - 1], sizeof(int));
		else
			ft_swap(&arr[0], &arr[k - 1], sizeof(int));
		xgenerate(arr, n, k - 1);
	}
}

/*static void	_xgenerate(int **tab, int *arr, int n, int k)
{
	int			i;
	static int	c;

	if (1 == k)
	{
		ft_memcpy(tab[c++], arr, n * sizeof(int));
		return ;
	}
	_xgenerate(tab, arr, n, k - 1);
	i = -1;
	while (++i < k - 1)
	{
		if (0 == k % 2)
			ft_swap(&arr[i], &arr[k - 1], sizeof(int));
		else
			ft_swap(&arr[0], &arr[k - 1], sizeof(int));
		_xgenerate(tab, arr, n, k - 1);
	}
	}*/

/*static size_t	ft_fac(int n)
{
	int		i;
	size_t	res;

	i = 0;
	res = 1;
	while (++i <= n)
		res *= i;
	return (res);
	}*/

 /*int**	permute(int* nums, int nsize, int* outsize, int** outcsizes)
{
	int		**ret;
	size_t	size;
	size_t	i;
	int		j;

	size = ft_fac(nsize);
	*outsize = size;
	*outcsizes = malloc(size * sizeof(int));
	ret = malloc(size * sizeof(void *));
	i = -1;
	while (++i < size)
	{
		ret[i] = malloc(nsize * sizeof(int));
		(*outcsizes)[i] = nsize;
	}
	_xgenerate(ret, nums, nsize, nsize);
	return (ret);
	}*/

void	test_heaps(void)
{
//	int	arr[] = {1, 2, 3, 5};
//	int	arr[] = {0, 1};
	int	arr[] = {2, 3, 100, 1};
	int	**res;
	int	r;
	int	*c;
	
//	xgenerate(arr, sizeof(arr) / sizeof(arr[0]), sizeof(arr) / sizeof(arr[0]));
//	ft_printf("\n");
	res = ft_permute(arr, sizeof(arr) / sizeof(arr[0]), &r, &c);
	ft_printf("r = %d; c = %d\n", r, c[0]);
	tabput(res, r, c[0]);
}

int	main(int argc, char **argv)
{
	if (2 == argc)
		ft_printf("%lld\n", ft_fac(ft_atoi(argv[1])));
	test_heaps();
	return (EXIT_SUCCESS);
}
