#include "../../incs/libft.h"

char    *ft_strcat(char *s1, char *s2)
{
    char    *temp;
    int     i;
    int     j;
    
    temp = NULL;
    i = 0;
    j = 0;
    while (s1[i++])
        temp[i] = s1[i];
    while (s2[i++])
        temp[j + i] = s2[j];
    temp[j + i] = 0;
    return (temp);
}

char    *ft_strcatchar(char *s1, int c)
{
    char    *temp;
    int     i;
    
    temp = NULL;
    i = 0;
    while (s1[i++])
        temp[i] = s1[i];
    temp[i] = c;
    temp[i + 1] = 0;
    return (temp);
}