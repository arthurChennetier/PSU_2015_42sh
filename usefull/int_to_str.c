/*
** int_to_str.c for 42sh in /home/chauvi_d/Rendu-2015-Epitech/rendu/Systunix/for42/usefull
** 
** Made by chauvi_d
** Login   <chauvi_d@epitech.net>
** 
** Started on  Sat Jun  4 14:51:43 2016 chauvi_d
** Last update Sat Jun  4 15:12:23 2016 chauvi_d
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "minishell.h"

char	*int_to_str(int nb)
{
  char	*str;
  int	i;
  int   result;
  int   divisor;

  divisor = 1;
  i = 0;
  if ((str = malloc(sizeof(char) * 200)) == NULL)
    return (NULL);
  while ((nb / divisor) >= 10)
    divisor = divisor * 10;
  while (divisor > 0 && i < 200)
    {
      result = (nb / divisor) % 10;
      str[i] = 48 + result;
      divisor = divisor / 10;
      i++;
    }
  str[i] = 0;
  return (str);
}
