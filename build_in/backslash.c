/*
** backslash.c for 42sh in /home/arthur/rendu/semestre2/PSU_2016/PSU_2015_42sh
** 
** Made by arthur
** Login   <chenne_a@epitech.net>
** 
** Started on  Sat Jun  4 16:23:29 2016 arthur
** Last update Sat Jun  4 16:25:40 2016 arthur
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "minishell.h"
#include "get_next_line.h"
#include "print.h"

int		check_backslash(char *str)
{
  int		i;

  i = 0;
  while (str[i])
    {
      if (str[i] == 92)
        return (1);
      i = i + 1;
    }
  return (-1);
}

int		backslash_case(char *str)
{
  int		i;
  int		size;

  size = my_strlen(str);
  i = 0;
  while (i < size)
    {
      if (str[i] == 92 && i + 1 < size)
        {
          if ((i = check_double_backslash(str, i)) == -1)
            return (-1);
        }
      else
        my_putchar(str[i]);
      i = i + 1;
    }
  return (0);
}
