/*
** Given a non-negative index k where k ≤ 33,
**	return the kth index row of the Pascal's triangle.
** Note that the row index starts from 0.
*/

#include <string.h>

static void fill(int *arr, int idx)
{
    int i;
    
    if (1 == idx)
        return ;
    fill(arr, idx - 1);
    i = idx / 2 + 1;
    while (--i)
    {
        if (!arr[i])
            arr[i] = 2 * arr[i - 1];
        else
            arr[i] = arr[i] + arr[i - 1];
    }
}

static void mirror(int *arr, int idx)
{
    int i;
    
    i = idx / 2 + ((idx & 1) ? 1 : 0);
    while (--i >= 0)
        arr[idx - i] = arr[i];
}

int			*getRow(int idx, int *retsize)
{
    int *arr;
    
    if (0 > idx)
        return (NULL);
    *retsize = idx + 1;
    arr = malloc(*retsize * sizeof(int));
    bzero(arr, *retsize * sizeof(int));
    arr[0] = 1;
    if (!idx)
        return (arr);
    arr[1] = 1;
    fill(arr, idx);
    mirror(arr, idx);
    return (arr);
}
