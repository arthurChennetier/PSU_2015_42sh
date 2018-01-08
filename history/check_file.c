/*
** check_file.c for 42sh in /home/chauvi_d/Rendu-2015-Epitech/rendu/Systunix/for42/history
** 
** Made by chauvi_d
** Login   <chauvi_d@epitech.net>
** 
** Started on  Sun Jun  5 14:43:38 2016 chauvi_d
** Last update Sun Jun  5 19:59:45 2016 chauvi_d
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

char	*get_file(char *file)
{
  int	fd;
  char	*s;
  char	*buf;
  int	i;

  if ((s = malloc(sizeof(char) * 4096 + 1)) == NULL)
    return (NULL);
  if ((buf = malloc(sizeof(char) * 1)) == NULL)
    return (NULL);
  buf[0] = 0;
  if ((fd = open(file, O_RDONLY)) == -1)
    return (NULL);
  while ((i = read(fd, s, 4096)) != 0)
    {
      s[i] = 0;
      buf = my_realloc(buf, my_strlen(s) + my_strlen(buf));
      buf = my_strcat(buf, s);
    }
  i++;
  buf[my_strlen(buf)] = 0;
  free(s);
  return (buf);
}

t_dlist		*create_history(char *file)
{
  char		*s;
  char		**tmp;
  t_dlist	*history;
  int		fd;

  if ((history = my_init_l()) == NULL)
    return (NULL);
  if ((s = get_file(file)) == NULL)
    {
      if ((fd = open(file, O_CREAT, 07777)) == -1)
	return (NULL);
      close(fd);
      return (history);
    }
  if (strlen(s) > 0)
    {
      if ((tmp = str_to_wordtab(s, '\n')) == NULL)
	return (NULL);
      if ((history = get_content(history, tmp)) == NULL)
	return (NULL);
    }
  return (history);
}

t_dlist		*put_in_history(char *str, t_dlist *history)
{
  t_list	*elem;

  if ((elem = malloc(sizeof(t_list))) == NULL)
    return (NULL);
  if ((elem->name = malloc(sizeof(char) * my_strlen(str) + 1)) == NULL)
    return (NULL);
  elem->n = history->nb_com;
  elem->time = my_time();
  elem->name = my_strcpy(elem->name, str);
  elem->name[my_strlen(elem->name)] = 0;
  if ((history = add_last_elem(history, elem)) == NULL)
    return (NULL);
  if (history->length > 1000)
    history = my_del_elem(history, history->head);
  history->nb_com = history->nb_com + 1;
  return (history);
}

t_dlist	*get_content(t_dlist *history, char **tmp)
{
  int	i;

  i = my_strlen2d(tmp) - 1;
  while (i >= 0)
    {
      if (strlen(tmp[i]) > 0 && (history =
				 get_from_history(tmp[i], history)) == NULL)
	return (NULL);
      i--;
    }
   return (history);
}

int		write_history(t_dlist *history, char *file)
{
  t_list       	*elem;
  int		fd;
  int		i;

  i = 0;
  elem = history->head->prev;
  if ((fd = open(file, O_TRUNC | O_RDWR | O_CREAT, 07777)) == -1)
    {
      printf("File history is not readable\n");
      return (-1);
    }
  while (i != history->length)
    {
      write(fd, int_to_str(elem->n), strlen(int_to_str(elem->n)));
      write(fd, " ", 1);
      write(fd, elem->time, strlen(elem->time));
      write(fd, " ", 1);
      write(fd, elem->name, strlen(elem->name));
      write(fd, "\n", 1);
      elem = elem->prev;
      i++;
    }
  return (0);
}
