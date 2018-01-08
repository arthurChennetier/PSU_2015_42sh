/*
** my_printf.c for my_printf in /home/chenne_a/rendu/PSU_2015_my_printf
** 
** Made by Arthur Chennetier
** Login   <chenne_a@epitech.net>
** 
** Started on  Wed Nov  4 16:16:44 2015 Arthur Chennetier
** Last update Sat Nov 28 16:47:16 2015 Arthur Chennetier
*/

#include <stdarg.h>
#include <stdlib.h>
#include "print.h"

t_print	g_tab[12] =
  {
    {&my_putchar_va, "c"},
    {&long_long, "z"},
    {&my_put_nbr_va, "i"},
    {&my_putstr_va, "s"},
    {&my_put_nbr_base2, "b"},
    {&my_put_nbr_va, "d"},
    {&my_putstr_S, "S"},
    {&my_put_nbr_base16, "x"},
    {&my_put_nbr_base16maj, "X"},
    {&my_put_unva, "u"},
    {&my_put_nbr_base8, "o"},
    {0, NULL}
  };

int	print_flag(int i, const char *str, va_list va)
{
  int	j;
  int	x;

  j = 0;
  x = 0;
  while (g_tab[j].flags[x] != str[i + 1] && g_tab[j].flags[x] != 0)
    j = j + 1;
  g_tab[j].str(va);
  i = i + 1;
  return (i);
}

int	my_printf(const char *str, ...)
{
  va_list	va;
  int		i;

  if (str == NULL)
    return (-1);
  i = 0;
  va_start(va, str);
  while (str[i] != '\0')
    {
      if (str[i] == '%' && str[i + 1] == '%')
	{
	  my_putchar('%');
	  i = i + 1;
	}
      else if (str[i] == '%' && str[i + 1] != '%')
	i = print_flag(i, str, va);
      else
	my_putchar(str[i]);
      i = i + 1;
    }
  return (0);
}
