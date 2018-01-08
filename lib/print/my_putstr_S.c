/*
** my_putstr_S.c for my_putstr_S in /home/chenne_a/
** 
** Made by Arthur Chennetier
** Login   <chenne_a@epitech.net>
** 
** Started on  Thu Nov 12 16:16:10 2015 Arthur Chennetier
** Last update Fri Dec 18 17:19:23 2015 Arthur Chennetier
*/

#include <stdarg.h>
#include "print.h"

int	my_putstr_S(va_list va)
{
  char	*str;
  int	a;

  a = 0;
  str = va_arg(va, char*);
  while (str[a] != '\0')
    {
      if (str[a] < 32 || str[a] >= 127)
	{
	  my_putchar('\\');
	  if (str[a] < 8)
	    {
	      my_putchar('0');
	      my_putchar('0');
	    }
	  if (str[a] >= 8 && str[a] <= 63)
	    my_putchar('0');
	  my_put_nbr_base8S(str[a]);
	}
      else
	my_putchar(str[a]);
      a = a + 1;
    }
  return (0);
}
