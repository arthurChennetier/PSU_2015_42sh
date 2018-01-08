/*
** dash_extend.c for 42sh in /home/chauvi_d/Rendu-2015-Epitech/rendu/Systunix/for42/history
** 
** Made by chauvi_d
** Login   <chauvi_d@epitech.net>
** 
** Started on  Sun Jun  5 15:04:34 2016 chauvi_d
** Last update Sun Jun  5 15:09:41 2016 chauvi_d
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "minishell.h"

t_list	*dash_extend(char *cmp)
{
  t_list	*elem;
  int		k;
  int		num;

  num = hist->length;
  elem = hist->head->prev;
  k = my_getnbr(cmp) - 1;
  if (k < 0)
    {
      printf("history: Event not found.\n");
      return (NULL);
    }
  while (k > 0 && num >= 0)
    {
      elem = elem->prev;
      k--;
      num--;
    }
  return (elem);
}
