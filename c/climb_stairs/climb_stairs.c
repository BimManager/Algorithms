#include <stdlib.h>
#include <stdio.h>
#include <string.h>

static void	arrput(int *arr, int n)
{
  int	i;

  i = -1;
  while (++i < n)
	printf("%7d", arr[i]);
  printf("\n");
}  

/*static void rec(int n, int *n_ways)
{
    if (0 >= n)
    {
        if (!n)
            ++*n_ways;
        return ;
    }
    rec(n - 1, n_ways);
    rec(n - 2, n_ways);
	}*/

static void mem(int n, int *n_ways, int *cache)
{
    if (cache[n])
    {
        *n_ways += cache[n];
        return ;
    }
	if (0 >= n)
	  {
		if (!n)
		  ++*n_ways;
		return ;
	  }
    mem(n - 1, n_ways, cache);
    mem(n - 2, n_ways, cache);
    cache[n] = *n_ways;
}

static int	climbStairs(int n)
{
    int n_ways;
    int *cache;
    
    n_ways = 0;
    cache = malloc((n + 1) * sizeof(int));
    bzero(cache, (n + 1) * sizeof(int));
    mem(n, &n_ways, cache);
//    rec(n, &n_ways);
	arrput(cache, n + 1);
    free(cache);
    return (n_ways);
}

int	main(int argc, char **argv)
{
  if (2 == argc)
	printf("%d\n", climbStairs(atoi(argv[1])));
  return (0);
}
