#include <stdlib.h>
#include <stdio.h>

/* static void	arrput(int *arr, int n) */
/* { */
/* 	int	i; */

/* 	i = -1; */
/* 	while (++i < n) */
/* 		printf("%3d", arr[i]); */
/* 	printf("\n"); */
//}

static int  *sum_left(int *nums, int numsSize, int *min, int *max)
{
    int *sum;
    int i;

    sum = malloc(numsSize * sizeof(int));
    sum[0] = nums[0] ? 1 : -1;
    i = 0;
    *min = nums[0] ? 1 : -1;
    *max = nums[0] ? 1 : -1;
    while (++i < numsSize)
    {
        sum[i] = sum[i - 1] + (nums[i] ? 1 : -1);
        if (sum[i] < *min)
            *min = sum[i];
        if (sum[i] > *max)
            *max = sum[i];
    }
    return (sum);
}

static int	calc_max(int *sum, int min, int max, int n)
{
	int	i;
	int	maxsize;
	int	*hash;

	i = max - min + 1;
	hash = malloc(i * sizeof(int));
    while (i--)
        hash[i] = -1;
	maxsize = 0;
	while (++i < n)
    {
        if (0 == sum[i])
            maxsize = i + 1;    
        if (-1 == hash[sum[i] - min])
            hash[sum[i] - min] = i;
        else
            if ((i - hash[sum[i] - min]) > maxsize)
                maxsize = i - hash[sum[i] - min];
    }
	free(hash);
	return (maxsize);
}

static int  max_length(int *nums, int numsSize)
{
    int *sum;
    int min;
    int max;

	if (0 >= numsSize)
		return (0);
    sum = sum_left(nums, numsSize, &min, &max);
	max = calc_max(sum, min, max, numsSize);
    free(sum);
    return (max);
}

int		main(void)
{
	int	arr[] = {1, 0, 1, 1, 0, 1};
	int	n = sizeof(arr) / sizeof(arr[0]);
	int	max;

	max = max_length(arr, n);
	printf("max: %d\n", max);
	return (0);
}
		
