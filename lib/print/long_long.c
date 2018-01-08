/*
** long_long.c for long_long in /home/chenne_a/rendu/PSUotstrap/lib
** 
** Made by Arthur Chennetier
** Login   <chenne_a@epitech.net>
** 
** Started on  Tue Nov 24 18:38:08 2015 Arthur Chennetier
** Last update Fri Dec 18 17:21:41 2015 Arthur Chennetier
*/

#include <stdarg.h>
#include "print.h"

int	long_long(va_list va)
{
  int	divide;
  int	digit;
  int	nb;

  nb = va_arg(va, long long int);
  if (nb == 0)
    {
      my_putchar('0');
      return (0);
    }
  divide = 1;
  if (nb < 0)
    {
      my_putchar('-');
      nb = - nb;
    }
  while (nb / divide > 9)
    divide = divide * 10;
  while (divide > 0)
    {
      digit = (nb / divide) % 10;
      my_putchar(digit + 48);
      divide = divide / 10;
    }
  return (0);
}
