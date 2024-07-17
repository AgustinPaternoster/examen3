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



int ft_putnbr(int nb,int base)
{
	char number[12];
	int i;
	int result;
	long nbl;

	result = 0;
	i = 0;
	nbl = nb;
	if (nbl < 0 )
	{ 
		if (write(1,"-",1) < 0)
                	return (-1);
		nbl *= -1;
	}
	while (nbl > 0) 
	{
		number[i] = hex[nbl % base];
		nbl = nbl / base;
		i++;
	}
	while ( --i >= 0 )
	{
		if (write(1,&number[i],1) < 0)
			return (-1);
		result++;
	}
	return (result);
}

int p_fuctions(va_list arg, char c)
{
    int result;
    result = 0;
    if (c == 'x')
        result = ft_putnbr(va_arg(arg, int),16);
    if (c == 'd')
        result = ft_putnbr(va_arg(arg,int),10);
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
    i = ft_printf("test %x, %d, %s\n",1234 , 1234 , "1234");
    ft_printf("%d",i);
    return (0);
}
