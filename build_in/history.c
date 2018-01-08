/*
** history.c for 42sh in /home/chauvi_d/Rendu-2015-Epitech/rendu/Systunix/PSU_2015_42sh/chauvin/build_in
** 
** Made by chauvi_d
** Login   <chauvi_d@epitech.net>
** 
** Started on  Thu Jun  2 16:21:39 2016 chauvi_d
** Last update Sun Jun  5 18:10:21 2016 chauvi_d
*/

#include <stdlib.h>
#include <stdio.h>
#include "get_next_line.h"
#include "minishell.h"
#include "print.h"

int	my_strlen2d(char **av)
{
  int	i;

  i = 0;
  while (av[i])
    i++;
  return (i);
}

int	is_num(char *str)
{
  int	i;

  i = 0;
  if (str == NULL)
    return (-1);
  while (str[i])
    {
      if (str[i] >= '0' && str[i] <= '9')
	i++;
      else
	return (-1);
    }
  return (0);
}

void		putn_list(t_dlist *list, int n)
{
  t_list	*elem;
  int		num;

  num = list->length;
  elem = list->head;
  while (n != 0 && num >= 0)
    {
      my_printf("   %d  %s  %s\n", elem->n, elem->time, elem->name);
      elem = elem->next;
      num--;
      n--;
    }
}

void		putn_list_reverse(t_dlist *list, int n)
{
  t_list	*elem;
  int		num;

  num = list->length;
  elem = list->head->prev;
  while (n != 0 && num >= 0)
    {
      my_printf("   %d  %s  %s\n", elem->n, elem->time, elem->name);
      elem = elem->prev;
      num--;
      n--;
    }
}

void	history(t_exec build, t_exec *var)
{
  int	i;

  i = 0;
  var = var;
  if ((i = my_strlen2d(build.tab)) > 3)
    {
      my_printf("history: Too many arguments.\n");
      return ;
    }
  if (i == 1)
    {
      putn_list(hist, hist->length);
      return ;
    }
  if (is_num(build.tab[1]) != -1)
    {
      putn_list(hist, my_getnbr(build.tab[1]));
      return ;
    }
  else if (build.tab[1][0] != '-')
    my_printf("Usage: history [-chrSL] [# number of events].\n");
  else
    if (check_flags_history(build.tab) == -1)
      my_printf("Usage: history [-chrSL] [# number of events].\n");
}
