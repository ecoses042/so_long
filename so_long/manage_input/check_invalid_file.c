#include "../so_long.h"

//function to find following word in string
bool is_ber(char *av, char *to_find)
{
    int i;

    i = 0;
    while (av[i])
    {
        if (av[i] != to_find[i])
            return (false);
        i++;
    }
    return (true);
}

bool is_invalid_file(char *av)
{
    bool    first;

    first = true;
    while (*av)
    {
        if (first  == false && *av == '.')
        {
            if (is_ber(av, ".ber"))
                return (false);
        }
        av++;
        first = false;
    }
    return (true);

}