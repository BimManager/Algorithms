#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define BUFFSIZE 42

static void	tohexrec(unsigned num, char **it)
{
    unsigned    mask;
        
    if (!num)
        return ;
    tohexrec(num >> 4, it);
    mask = 0b1111;
    num &= mask;
    if (9 < num)
        **it = 'a' + num - 10;
    else
        **it = num + '0';
    ++*it;
}

char		*tohex(int num)
{
    char        buffer[BUFFSIZE];
    char        *it;
    unsigned    len;
    
    it = buffer;
    tohexrec(num, &it);
    *it = '\0';
    len = strlen(buffer);
    it = malloc((len ? len : 1) + 1);
    if (len)
        memcpy(it, buffer, len + 1);
    else
        memcpy(it, "0", 2);
    return (it);
}

int		main(int argc, char **argv)
{
  if (2 == argc)
    printf("%s\n", tohex(atoi(argv[1])));
  return (0);
}
