#include <stdlib.h>
#include <stdio.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int	*productExceptSelf(int* nums, int numsSize, int* returnSize)
{
    int *ret;
    int tmp;
    int i;
    
    ret = malloc(numsSize * sizeof(int));
    *returnSize = numsSize;
    ret[0] = nums[0];
    tmp = 1;
    i = -1;
    while (++i < numsSize)
    {
        ret[i] = tmp;
        tmp *= nums[i];
    }
    tmp = 1;
    i = numsSize;
    while (i--)
    {
        ret[i] *= tmp;
        tmp *= nums[i];
    }
    return (ret);
}

