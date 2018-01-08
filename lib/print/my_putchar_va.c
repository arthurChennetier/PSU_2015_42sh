/*
** my_putchar.c for my_putchar in /home/chenne_a/rendu/Piscine_C_J06
** 
** Made by Arthur Chennetier
** Login   <chenne_a@epitech.net>
** 
** Started on  Mon Oct  5 09:30:41 2015 Arthur Chennetier
** Last update Fri Dec 18 17:12:54 2015 Arthur Chennetier
*/

#include <unistd.h>
#include <stdarg.h>

int	my_putchar_va(va_list va)
{
  char	c;

  c = va_arg(va, int);
  if (c == '\0')
    return (0);
  write(1, &c, 1);
  return (0);
}
