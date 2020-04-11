#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define NLETTERS	128
#define NDIGITS		10

static char *g_words[] = {
    "zero", "one", "two",
    "three", "four", "five",
    "six", "seven", "eight",
    "nine"
};

/*
**static void	arrput(int *arr, int n)
**{
**	int	i;
**
**	i = -1;
**	while (++i < n)
**		printf("%8d", arr[i]);
**	printf("\n");
**}
*/

static void decrement(int idx, int *letters)
{
    char    *it;
    
    it = g_words[idx];
    while (*it)
        --letters[(int)*it++];
}

static void unique_digits(char *s, int *letters, int *digits)
{
    char    *it;
    
    it = s - 1;
    while (*++it)
    {
        if ('z' == *it)
        {
            ++digits[0];
            decrement(0, letters);
        }
        else if ('w' == *it)
        {
            ++digits[2];
            decrement(2, letters);
        }
        else if ('g' == *it)
        {
            ++digits[8];
            decrement(8, letters);
        }
        else if ('x' == *it)
        {
            ++digits[6];
            decrement(6, letters);
        }
        else if ('u' == *it)
        {
            ++digits[4];
            decrement(4, letters);
        }
        else
            ++letters[(int)*it];
    }
}

static void other_digits(int *letters, int *digits)
{
    int i;
    
    i = 'a' - 1;
    while (++i < 'z')
    {
        if (0 >= letters[i])
            continue ;
        while ('f' == i && letters[i])
        {
            ++digits[5];
            decrement(5, letters);
        }
        while ('s' == i && letters[i])
        {
            ++digits[7];
            decrement(7, letters);
        }
        while ('h' == i && letters[i])
        {
            ++digits[3];
            decrement(3, letters);
        }
        while ('o' == i && letters[i])
        {
            ++digits[1];
            decrement(1, letters);
        }
    }
}

static void	nine_digits(int *letters, int *digits)
{
	while (0 < letters['n'])
	{
		++digits[9];
		decrement(9, letters);
	}
}

static int  arrsum(int *arr, int n)
{
    int i;
    int total;

    total = 0;
    i = -1;
    while (++i < n)
        total += arr[i];
    return (total);
}

static void arrfill(char *arr, int *digits)
{
    int     i;
    char    *it;
    
    i = -1;
    it = arr;
    while (++i < 10)
        while (0 < digits[i])
        {
            *it++ = i + '0';
            --digits[i];
        }
    *it = '\0';
}

char * originalDigits(char * s)
{
    int     letters[NLETTERS];
	int		digits[NDIGITS];
    char    *ret;
    int     total;
    
    bzero(letters, NLETTERS * sizeof(int));
	bzero(digits, NDIGITS * sizeof(int));
    unique_digits(s, letters, digits);
    other_digits(letters, digits);
	nine_digits(letters, digits);
    total = arrsum(digits, NDIGITS);
    ret = malloc(total + 1);
    arrfill(ret, digits);
    return (ret);
}

int	main(int argc, char **argv)
{
	char	*res;

	if (2 == argc)
	{
		res = originalDigits(argv[1]);
		printf("%s\n", res);
	}
	return (0);
}
