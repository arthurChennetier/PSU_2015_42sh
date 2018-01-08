/*
** my_putstr.c for my_putstr in /home/chenne_a/rendu/Piscine_C_J04
** 
** Made by Arthur Chennetier
** Login   <chenne_a@epitech.net>
** 
** Started on  Thu Oct  1 11:51:56 2015 Arthur Chennetier
** Last update Fri Dec 18 17:13:59 2015 Arthur Chennetier
*/

#include <stdarg.h>
#include <stdlib.h>
#include "print.h"

int	my_putstr_va(va_list va)
{
  char	*str;
  int	a;

  a = 0;
  str = va_arg(va, char*);
  if (str == NULL)
    my_putstr("(null)");
  while (str[a] != '\0')
    {
      my_putchar(str[a]);
      a = a + 1;
    }
  return (0);
}
