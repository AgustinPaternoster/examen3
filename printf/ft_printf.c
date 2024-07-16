#include "ft_printf.h"

// string
// decimal
// hexadecimal lowercas
int ft_putstr(char * str)
{
    int i;
    int result;

    result = 0;
    i = 0;
    while (str[i])
    {
        if(write(1,&str[i],1) < 0)
            return (-1);
        i++;
    }
    return (i);    
}



int putnbr(int nb)
{
        
}

int puthex(int nb)
{
    return (printf("%x", nb));
}
int p_fuctions(va_list arg, char c)
{
    int result;
    result = 0;
    if (c == 'x')
        result = puthex(va_arg(arg, int));
    if (c == 'd')
        result = putnbr(va_arg(arg,int));
    if (c == 's')
        result = ft_putstr(va_arg(arg, char *));
    return (result);
}

int ft_printf(char *str, ...)
{
    int i;
    va_list arg;
    int result;
    int check;

    va_start(arg, str);
    i = 0;
    result = 0;
    while (str[i])
    {
        check = result;
        if (str[i] == '%')
        {   
            result += p_fuctions(arg,str[++i]);
        }
        else
            result += write(1,&str[i],1);
        if (check > result)
            return (-1);
        i++;

    }
    return (result); 
}

int main(int arc, char **argv)
{
    int i;
    printf("%c",hex[15]);
    return (0);
}