#include "../../incs/libft.h"

int ft_rand_percent(int nb1, int percent_nb1, int nb2)
{
    int num;

    if (percent_nb1 == 100)
        return (nb1);
    num = ft_rand_in_range(1, 100);
    if (num < percent_nb1)
        return (nb1);
    else
        return (nb2);
}