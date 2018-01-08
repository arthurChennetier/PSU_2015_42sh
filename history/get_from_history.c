/*
** get_from_history.c for 42h in /home/chauvi_d/Rendu-2015-Epitech/rendu/Systunix/for42/history
** 
** Made by chauvi_d
** Login   <chauvi_d@epitech.net>
** 
** Started on  Sat Jun  4 14:58:20 2016 chauvi_d
** Last update Sat Jun  4 15:44:57 2016 chauvi_d
*/

#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <stdio.h>
#include "get_next_line.h"
#include "minishell.h"

char	*get_n(char *str)
{
  char	*tmp;
  int	i;

  i = 0;
  if ((tmp = malloc(sizeof(char) * (my_strlen(str) + 1))) == NULL)
    return (NULL);
  while (str[i] !=  ' ' && str[i])
    {
      tmp[i] = str[i];
      i++;
    }
  tmp[i] = 0;
  return (tmp);
}

char	*get_time(char *str)
{
  char	*tmp;
  int	i;
  int	j;
  int	space;

  space = 0;
  i = 0;
  j = 0;
  if ((tmp = malloc(sizeof(char) * (my_strlen(str) + 1))) == NULL)
    return (NULL);
  while (space != 1 && str[i])
    {
      if (str[i] == ' ')
	space++;
      i++;
    }
  while (str[i] != ' ' && str[i])
    tmp[j++] = str[i++];
  tmp[j] = 0;
  return (tmp);
}

char	*get_name(char *str)
{
  char	*tmp;
  int	i;
  int	j;
  int	space;

  space = 0;
  i = 0;
  j = 0;
  if ((tmp = malloc(sizeof(char) * (my_strlen(str) + 1))) == NULL)
    return (NULL);
  while (space != 2 && str[i])
    {
      if (str[i] == ' ')
	space++;
      i++;
    }
  while (str[i] != '\n' && str[i])
    tmp[j++] = str[i++];
  tmp[j] = 0;
  return (tmp);
}

t_dlist         *get_from_history(char *str, t_dlist *history)
{
  t_list        *elem;

  if ((elem = malloc(sizeof(t_list))) == NULL)
    return (NULL);
  elem->name = get_n(str);
  elem->n = my_getnbr(elem->name);
  history->nb_com = elem->n;
  elem->time = get_time(str);
  elem->name = get_name(str);
  if ((history = add_last_elem(history, elem)) == NULL)
    return (NULL);
  history->nb_com++;
  return (history);
}
