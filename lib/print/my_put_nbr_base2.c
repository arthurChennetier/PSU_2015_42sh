/*
** my_put_nbr_base2.c for my_put_nbr_base2 in /home
** 
** Made by Arthur Chennetier
** Login   <chenne_a@epitech.net>
** 
** Started on  Thu Nov 12 15:29:19 2015 Arthur Chennetier
** Last update Fri Dec 18 17:17:58 2015 Arthur Chennetier
*/

#include <stdarg.h>
#include "print.h"

int	my_put_nbr_base2(va_list va)
{
  int		divide;
  unsigned int	digit;
  unsigned int	nb;
  char		*base;

  base = "01";
  nb = va_arg(va, unsigned int);
  if (nb == 0)
    my_putchar('0');
  divide = 1;
  while (nb / divide >= 2)
    divide = divide * 2;
  while (divide > 0)
    {
      digit = (nb / divide) % 2;
      my_putchar(base[digit]);
      divide = divide / 2;
    }
  return (0);
}
