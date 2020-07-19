#include <stdlib.h>
#include <stdio.h>

static int  xfac(int n)
{
    int res;
    
    res = 1;
    while (n)
        res *= n--;
    return (res);
}

static int  ft_lfind(int *nums, int n, int key)
{
    int i;
    
    i = -1;
    while (++i < n)
        if (nums[i] == key)
            return (i + 1);
    return (-1);
}

static int  get_mobile(int *nums, int *dirs, int n)
{
    int prev;
    int curr;
    int i;
    
    prev = 0;
    curr = 0;
    i = -1;
    while (++i < n)
    {
        if (-1 == dirs[nums[i] - 1] && 0 != i)
            if (nums[i] > nums[i - 1] && nums[i] > prev)
            {
                curr = nums[i];
                prev = curr;
            }
        if (0 == dirs[nums[i] - 1] && n - 1 != i)
            if (nums[i] > nums[i + 1] && nums[i] > prev)
            {
                curr = nums[i];
                prev = curr;
            }
    }
    if (!prev && !curr)
        return (0);
    return (curr);
}

static void get_permute(int *nums, int *dirs, int n)
{
    int mobile;
    int pos;
    int i;
    
    mobile = get_mobile(nums, dirs, n);
    pos = ft_lsearch(nums, n, mobile);
    if (-1 == dirs[nums[pos - 1] - 1])
        intswap(&nums[pos - 1], &nums[pos - 2]);
    else if (0 == dirs[nums[pos - 1] - 1])
        intswap(&nums[pos], &nums[pos - 1]);
    i = -1;
    while (++i < n)
    {
        if (nums[i] > mobile)
        {
            if (0 == dirs[nums[i] - 1])
                dirs[nums[i] - 1] = -1;
            else
                dirs[nums[i] - 1] = 0;
        }
    }
    intput(nums, n);
}

static void sjt(int *nums, int n)
{
    int *dirs;
    int i;
    int n_perms;
    
    dirs = malloc(n * sizeof(int));
    i = -1;
    while (++i < n)
        dirs[i] = -1;
    intput(nums, n);
    n_perms = xfac(n);
    printf("n_perms: %d\n", n_perms);
    i = -1;
    while (++i < n_perms)
        get_permute(nums, dirs, n);
    free(dirs);
}

char * getPermutation(int n, int k)
{
    int *nums;
    int i;
    
    nums = malloc(n * sizeof(int));
    i = 0;
    while (++i <= n)
        nums[i - 1] = i;
//    generate(nums, n, n);
    //permute(nums, n, n);
    sjt(nums, n);
    free(nums);
    return ("");
}

int		main(void)
{
  getPermutations(3, 3);
  return (0);
}
