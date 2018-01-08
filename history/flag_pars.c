/*
** flag_pars.c for flag_pars in /home/clement/for42
** 
** Made by clement
** Login   <clement@clement-HP-EliteBook-840-G2>
** 
** Started on  Sat Jun  4 19:41:05 2016 clement
** Last update Sun Jun  5 15:30:46 2016 chauvi_d
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "minishell.h"

int	check_error_pars(char **str, int n, int i)
{
  if (strlen(str[0]) <= (unsigned int)n)
    {
      printf("history: Command not found.\n");
      return (-1);
    }
  if (hist->head == NULL || str[0][i + 1] == 0)
    {
      printf("history: Event not found.\n");
      return (-1);
    }
  return (0);
}

int	increase_k(int k, char **str, int i)
{
  while (str[0][k] != ' ' && str[0][k] != ';' && str[0][k] != '|' &&
	 str[0][k] != '>' && str[0][k] != '<' && str[0][k] != '&' &&
	 str[0][k])
    {
      if (i == 1 && str[0][k] == '?')
	return (k);
      k++;
    }
  return (k);
}

int	nigma(char **str, int i)
{
  t_list	*elem;
  int		k;
  int		num;

  if (check_error_pars(str, 2, i) == -1)
    return (-1);
  k = i + 2;
  num = hist->length;
  k = increase_k(k, str, 1);
  elem = hist->head->prev;
  while (word_cmp(str[0], elem->name) != 0 && num >= 0 && elem)
    {
      elem = elem->prev;
      num--;
    }
  if (num == -1)
    {
      printf("history: Event not found.\n");
      return (-1);
    }
  if ((str[0] = put_in_str(str[0], elem->name, i, k)) == NULL)
    return (-1);
  k = increase_k(k, str, 0);
    k++;
  return (k);
}

int	dash(char **str, int i)
{
  t_list	*elem;
  char		*cmp;
  int		j;
  int		k;

  if (check_error_pars(str, 2, i) == -1)
    return (-1);
  k = i + 2;
  j = 0;
  if ((cmp = malloc(sizeof(char) * (my_strlen(str[0]) + 1))) == NULL)
    return (-1);
  while (str[0][k] != ' ' && str[0][k] != ';' && str[0][k] != '|' &&
	 str[0][k] != '>' && str[0][k] != '<' && str[0][k] != '&' && str[0][k])
    cmp[j++] = str[0][k++];
  cmp[j] = 0;
  if (is_num(cmp) == -1)
    return (i);
  if ((elem = dash_extend(cmp)) == NULL)
    return (-1);
  k = i + my_strlen(cmp) + 2;
  if ((str[0] = put_in_str(str[0], elem->name, i, k)) == NULL)
    return (-1);
  k = increase_k(k, str, 0);
  return (k);
}

int	excl(char **str, int i)
{
  t_list	*elem;
  int		k;

  k = i;
  if (check_error_pars(str, 1, i) == -1)
    return (-1);
  elem = hist->head->prev;
  k = increase_k(k, str, 0);
  if ((str[0] = put_in_str(str[0], elem->name, i, k)) == NULL)
    return (-1);
  k = increase_k(k, str, 0);
  return (k);
}
