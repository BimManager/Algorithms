/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   counting_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkozlov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 13:36:49 by kkozlov           #+#    #+#             */
/*   Updated: 2020/01/12 15:34:31 by kkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	arrput(int *arr, int n)
{
	int	i;

	i = -1;
	while (++i < n)
		ft_printf("%5d", arr[i]);
	ft_printf("\n");
}

/*static int	maxfind(int *arr, int n)
{
	int	max;

	max = INT_MIN;
	while (n--)
		max = arr[n] > max ? arr[n] : max;
	return (max);
	}*/


#include <fcntl.h>

#define BSIZE	42

/*void	*ft_fndmax(void *base, size_t nel, size_t width,
					int (*cmp)(const void *, const void *))
{
	void	*pmax;

	pmax = base;
	ft_printf("base = %d; nel = %d\n",
			  *(int *)base, nel);
	while (1 < nel--)
	{
		ft_printf("next: %d\n", *(int *)((char *)base + nel * width));
		if (cmp((char *)base + nel * width, pmax) > 0)
			pmax = (char *)base + nel * width;
	}
	return (pmax);
	}*/

int		intcmp(const void *pv1, const void *pv2)
{
	return (*(int *)pv1 - *(int *)pv2);
}

int	*counting_sort(int *arr, int n)
{
	int	max;
	int	*tmp;
	int	*ret;
	int	i;

	max = *(int *)ft_fndmax(arr, n * sizeof(int), sizeof(int), &intcmp);
	++max;
//	ft_printf("max = %d\n", max);
//	arrput(arr, n);
	tmp = malloc(max * sizeof(int));
	ft_bzero(tmp, max * sizeof(int));
	i = -1;
	while (++i < n)
		tmp[arr[i]] += 1;
//	arrput(tmp, max);
	i = 0;
	while (++i < max)
		tmp[i] += tmp[i - 1];
//	arrput(tmp, max);
	ret = malloc(n * sizeof(int));
	i = n;
	while (i--)
	{
		ret[tmp[arr[i]] - 1] = arr[i];
		tmp[arr[i]] -= 1;
	}
//	arrput(tmp, max);
	arrput(ret, n);
	free(tmp);
	return (ret);
}

void	test_findmax(void)
{
	int	arr[] = { -1, 424242, 21, 10 };
	int	*parr;
	void	*max;

	parr = arr;
	max = ft_fndmax(arr, sizeof(arr) / sizeof(arr[0]),
					 sizeof(int), &intcmp);
	ft_printf("max = %d\n", *(int *)max);
}

void	test_cntsort(void)
{
	int		*arr;
	int		n;
	int		i;
	char	buffer[BSIZE];
	t_stack	*stack;
	t_list	*node;
	long	nb;
	
	i = 0;
	stack = ft_stacknew(NULL, 0);
	while ((n = read(0, buffer, BSIZE)))
	{
		buffer[n] = '\0';
		ft_stackpush(stack, buffer, n + 1);
	}
	n = ft_stacksize(stack);
	i = n;
	arr = malloc(n * sizeof(int));
	while (i--)
	{
		node = ft_stackpop(stack);
		if (node->content_size)
		{
			nb = ft_strtol(node->content, 10);
			arr[i] = nb;
		}
	}
	counting_sort(arr, n);
}


int	main(void)
{
//	test_findmax();
	test_cntsort();
	return (EXIT_SUCCESS);
}
