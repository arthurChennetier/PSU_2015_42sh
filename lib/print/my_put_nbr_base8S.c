/*
** my_put_nbr_base8.c for my_put_nbr_base8 in /home/chenne_a
** 
** Made by Arthur Chennetier
** Login   <chenne_a@epitech.net>
** 
** Started on  Thu Nov 12 16:02:47 2015 Arthur Chennetier
** Last update Fri Dec 18 17:20:15 2015 Arthur Chennetier
*/

#include <stdarg.h>
#include "print.h"

int	my_put_nbr_base8S(unsigned int nb)
{
  int		divide;
  unsigned int	digit;
  char		*base;

  base = "01234567";
  divide = 1;
  while (nb / divide >= 8)
    divide = divide * 8;
  while (divide > 0)
    {
      digit = (nb / divide) % 8;
      my_putchar(base[digit]);
      divide = divide / 8;
    }
  return (0);
}
