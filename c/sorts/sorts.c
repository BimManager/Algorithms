/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bubble_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkozlov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 11:03:31 by kkozlov           #+#    #+#             */
/*   Updated: 2020/01/17 09:18:30 by kkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	arrput(int *arr, int k, char *fmt)
{
	int	i;

	i = -1;
	while (++i < k)
		ft_printf(fmt, arr[i]);
	ft_printf("\n");
}

static void	arrdput(double *arr, int k, char *fmt)
{
	int	i;

	i = -1;
	while (++i < k)
		ft_printf(fmt, arr[i]);
	ft_printf("\n");
}

void	ft_bubblesort(int *arr, size_t n)
{
	int	i;
	int	pass;
	int	swap;

	swap = 1;
	pass = n;
	while (0 < --pass && swap)
	{
		swap = 0;
		i = -1;
		while (++i < pass)
			if (arr[i] > arr[i + 1])
			{
				swap = 1;
				ft_swap(&arr[i], &arr[i + 1], sizeof(int));
			}
	}
}

void	ft_selectionsort(int *arr, size_t n)
{
	int	min;
	int	i;
	int	j;

	i = -1;
	while (++i < n - 1)
	{
		min = i;
		j = i;
		while (++j < n)
			if (arr[min] > arr[j])
				min = j;
		ft_swap(&arr[i], &arr[min], sizeof(int));
	}
}

void	ft_insertionsort(int *arr, size_t n)
{
	int	i;
	int	j;

	i = 0;
	while (++i < n)
	{
		j = i;
		while (0 < j && arr[j - 1] > arr[j])
		{
			ft_swap(&arr[j - 1], &arr[j], sizeof(int));
			--j;
		}
	}
}

static int	intcmp(const void *pa, const void *pb)
{
	return (*(int *)pa - *(int *)pb);
}

static int	dblcmp(const void *pa, const void *pb)
{
	return (*(double *)pa - *(double *)pb);
}

int	main(void)
{
	int	arr[] = {-243, -1, 42, 1, 33, 16, 2, 4, 299, 1, 4};
	double	arr2[] = {-42.42, -400.1, 10.05, 99.12, 41.1, 1};
	size_t	n;
	size_t	n2;

	n = sizeof(arr) / sizeof(arr[0]);
	n2 = sizeof(arr2) / sizeof(arr2[0]);
//	ft_bubblesort(arr, n);
//	ft_selectionsort(arr, n);
//	ft_insertionsort(arr, n);
	ft_insrtsort(arr, n, sizeof(int), &intcmp);
//	ft_insrtsort(arr2, n2, sizeof(arr2[0]), &dblcmp);
	ft_qsort(arr2, n2, sizeof(arr2[0]), &dblcmp);
	arrput(arr, n, "%5d");
	ft_printf("%f\n", arr2[1]);
	arrdput(arr2, n2, "%7.2f");
	return (EXIT_SUCCESS);
}


