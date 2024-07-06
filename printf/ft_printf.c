#include "ft_printf.h"

int ft_putstr(char * str)
{
    int i;
    int total;

    i = 0;
    total = 0;
    while (str[i])
    {
        if (write(1,&str[i],1) == -1)
            return (-1);
        i++;
        total++;
    }
    return (total);
    
}

int p_fuctions(va_list arg, char c)
{
    
    return (0);
}

int ft_printf(char *str, ...)
{
    int i;
    va_list arg;
    int result;

    va_start(arg, str);
    i = 0;
    while (str[i])
    {
        if (str[i] == '%')
            result += p_fuctions(arg,str[i++]);
        i++;
    }
    

}

int main(int arc, char **argv)
{
    test_variadic(2,"test",123);
    return (0);
}