#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define BUFFSIZE 128

static void arrput(int *arr, int n);

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
static int  is_anagram(const char *s1, const char *s2)
{
    static int  buffer[BUFFSIZE];
    int         i;
    
//    bzero(buffer, BUFFSIZE * sizeof(int));
    while (*s1)
        buffer[(int)*s1++] += 1;
    while (*s2)
        buffer[(int)*s2++] -= 1;
    i = -1;
    while (++i < BUFFSIZE)
        if (buffer[i])
        {
            bzero(buffer, BUFFSIZE * sizeof(int));
            return (0);
        }
    return (1);
}

static int  strlencmp(const void *pv1, const void *pv2)
{
    const char  **s1_p;
    const char  **s2_p;
    int         s1_len;
    int         s2_len;
    
    s1_p = (const char **)pv1;
    s2_p = (const char **)pv2;
    s1_len = strlen(*s1_p);
    s2_len = strlen(*s2_p);
    if (s1_len > s2_len)
        return (1);
    else if (s1_len < s2_len)
        return (-1);
    return (0);
}

char *** groupAnagrams(char ** strs, int strsSize, int* returnSize, int** returnColumnSizes)
{
    int     i;
    int     j;
    int     k;
    char    ***groups;
    int     *idxs;
    char    *grouped;

    qsort(strs, strsSize, sizeof(void *), &strlencmp);
    groups = malloc(strsSize * sizeof(void *));
    *returnSize = 0;
    *returnColumnSizes = malloc(strsSize * sizeof(int));
    idxs = malloc(strsSize * sizeof(int));
    grouped = malloc(strsSize * sizeof(char));
    bzero(grouped, strsSize);
    i = -1;
    while (++i < strsSize)
    {
        if (grouped[i])
            continue ;
        j = i;
        k = 0;
        while (++j < strsSize)
        {
            if (strlen(strs[i]) < strlen(strs[j]))
                break ;
            if (!grouped[j] && is_anagram(strs[i], strs[j]))
            {
                idxs[k++] = j;
                grouped[j] = 1;
            }
        }
        (*returnColumnSizes)[*returnSize] = ++k;
        groups[*returnSize] = malloc(k * sizeof(void *));
        groups[*returnSize][0] = strs[i];
        while (--k)
            groups[*returnSize][k] = strs[idxs[k - 1]];
        ++*returnSize;
    }
    free(idxs);
    free(grouped);
    return (groups);
}

static void arrput(int *arr, int n)
{
  int	i;

  i = -1;
  while (++i < n)
	printf("%3d", arr[i]);
  printf("\n");
}

int	main(int argc, char **argv)
{
  int	ret_size;
  int	*ret_col_size;
  
  if (1 < argc)
	{
	  groupAnagrams(argv, argc, &ret_size, &ret_col_size);
	  printf("ret_size: %d\n", ret_size);
	  arrput(ret_col_size, ret_size);
	}
  return (0);
}
