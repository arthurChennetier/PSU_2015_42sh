/*
** my_put_nbr_base16maj.c for my_put_nbr_base16maj in /home
** 
** Made by Arthur Chennetier
** Login   <chenne_a@epitech.net>
** 
** Started on  Thu Nov 12 15:52:07 2015 Arthur Chennetier
** Last update Fri Dec 18 17:18:27 2015 Arthur Chennetier
*/

#include <stdarg.h>
#include "print.h"

int	my_put_nbr_base16maj(va_list va)
{
  int		divide;
  unsigned int	digit;
  unsigned int	nb;
  char		*base;

  base = "0123456789ABCDEF";
  nb = va_arg(va, unsigned int);
  divide = 1;
  while (nb / divide >= 16)
    divide = divide * 16;
  while (divide > 0)
    {
      digit = (nb / divide) % 16;
      my_putchar(base[digit]);
      divide = divide / 16;
    }
  return (0);
}
