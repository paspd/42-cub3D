#include "../../incs/libft.h"

int ft_rand_in_range(int lower, int upper)
{
    int num;
    
    num = (rand() % (upper - lower + 1)) + lower;
    return (num);
}