#include "gnl.h"

int findchar(char *str)
{
    int i = 0;
    while (str[i])
    {
        if (str[i] == '\n')
            return (1);
    }
    return (0);
}