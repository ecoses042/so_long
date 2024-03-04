#include "so_long.h"
int main(int ac, char **av)
{
    if (init_av(av+1))
        return (1);
        
    return (0);
}