/*
** flag_str.c for 42sh in /home/chauvi_d/Rendu-2015-Epitech/rendu/Systunix/for42
** 
** Made by chauvi_d
** Login   <chauvi_d@epitech.net>
** 
** Started on  Sun Jun  5 13:44:35 2016 chauvi_d
** Last update Sun Jun  5 15:37:21 2016 chauvi_d
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "minishell.h"

int	flag_str_extend(int num, char **str, char *name, int i)
{
  int	k;

  k = i;
  while (str[0][k] != ' ' && str[0][k] != ';' && str[0][k] != '|' &&
         str[0][k] != '>' && str[0][k] != '<' && str[0][k] != '&' && str[0][k])
    k++;
  if (num == -1)
    {
      printf("history: Event not found.\n");
      return (-1);
    }
  if ((str[0] = put_in_str(str[0], name, i, k)) == NULL)
    return (-1);
  while (str[0][k] != ' ' && str[0][k] != ';' && str[0][k] != '|' &&
         str[0][k] != '>' && str[0][k] != '<' && str[0][k] != '&' &&
         str[0][k])
    k++;
  return (k);
}

int	flag_str(char **str, int i)
{
  t_list	*elem;
  int		num;

  if (hist->head == NULL || str[0][i + 1] == 0)
    {
      printf("history: Event not found.\n");
      return (-1);
    }
  num = hist->length;
  elem = hist->head->prev;
  while (word_cmp(str[0], elem->name) != 0 && num >= 0 && elem)
    {
      elem = elem->prev;
      num--;
    }
  if ((i = flag_str_extend(num, str, elem->name, i)) == -1)
    return (-1);
  return (i);
}
