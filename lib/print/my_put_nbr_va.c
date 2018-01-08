/*
** my_put_nbr.c for my_put_nbr in /home/chenne_a/rendu/Piscine_C_J03
** 
** Made by Arthur Chennetier
** Login   <chenne_a@epitech.net>
** 
** Started on  Sat Oct 17 14:43:33 2015 Arthur Chennetier
** Last update Fri Dec 18 17:13:18 2015 Arthur Chennetier
*/

#include <stdarg.h>
#include "print.h"

int	my_put_nbr_va(va_list va)
{
  int	divide;
  int	digit;
  int	nb;

  nb = va_arg(va, int);
  if (nb == 0)
    {
      my_putchar('0');
      return (0);
    }
  divide = 1;
  if (nb < 0 && nb >= - 2147483647)
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
