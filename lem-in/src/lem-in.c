# include "lem-in.h"

int main(void)
{
    t_ways  *ways;
    
    if (!reading(&ways))
    {
        ft_printf("%sERROR\n%s", RED, RESET);
        return (0);
    }
    //road_to_the_hellend(&ways);
    delete_ways(&ways);
    return (0);
}