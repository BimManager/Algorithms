/*
**  Copyright 2020 kkozlov
*/

#include <stdlib.h>
#include <string.h>

#define THREE	3

static int  intcmp(const void *pv1, const void *pv2)
{
    int a;
    int b;
    
    a = *(int *)pv1;
    b = *(int *)pv2;
    if (a > b)
        return (1);
    else if (a < b)
        return (-1);
    return (0);
}

static int helper(int *nums, int numsSize, int **ret, char calcSize)
{
    int buffer[THREE];
    int i;
    int front;
    int back;
    int target;
    int sum;
    int n;
    
    i = -1;
    n = 0;
    --numsSize;
    while (++i < numsSize)
    {
        target = -nums[i];
        front = i + 1;
        back = numsSize;
        while (front < back)
        {
            sum = nums[front] + nums[back];
            if (sum < target)
                ++front ;
            else if (sum > target)
                --back ;
            else
            {
                buffer[0] = nums[front];
                buffer[1] = nums[back];
                buffer[2] = nums[i];
                if (calcSize)
                    ++n;
                else
                    memcpy(*ret++, buffer, THREE * sizeof(int));
                while (front < back && buffer[0] == nums[front])
                    ++front;
                while (front < back && buffer[1] == nums[back])
                    --back;
            }
        }
        while (i < numsSize && nums[i] == nums[i + 1])
            ++i;
    }
    return (n);
}

int **threeSum(int *nums, int numsSize, int *returnSize, int **returnColumnSizes)
{
    int i;
    int **ret;
    
    qsort(nums, numsSize, sizeof(int), &intcmp);
    *returnSize = helper(nums, numsSize, NULL, 1);
    i = *returnSize;
    ret = malloc(i * sizeof(void *));
    *returnColumnSizes = malloc(i * sizeof(int));
    while (i--)
    {
        ret[i] = malloc(THREE * sizeof(int));
        (*returnColumnSizes)[i] = THREE;
    }
    helper(nums, numsSize, ret, 0);
    return (ret);
}
