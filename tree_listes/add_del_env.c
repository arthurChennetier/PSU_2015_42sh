/*
** add_del_env.c for minishell2 in /home/arthur/rendu/semestre2/PSU_2016/PSU_2015_minishell2
** 
** Made by arthur
** Login   <chenne_a@epitech.net>
** 
** Started on  Thu Apr  7 18:01:44 2016 arthur
** Last update Wed Jun  1 12:25:40 2016 arthur
*/

#include <stdlib.h>
#include "minishell.h"
#include "print.h"

void		add_env(char **tab, t_list *node)
{
  t_list	*new;
  int		i;
  int		j;

  j = 0;
  i = 0;
  if ((new = malloc(sizeof(t_list))) == NULL)
    exit(EXIT_FAILURE);
  if ((new->name =
       malloc(sizeof(char) * ((my_strlen(tab[1])
			       + my_strlen(tab[2]) + 2)))) == NULL)
    exit(EXIT_FAILURE);
  while (tab[1][i] != '\0')
    {
      new->name[i] = tab[1][i];
      i = i + 1;
    }
  new->name[i++] = '=';
  if (tab[2] != NULL)
    while (tab[2][j] != '\0')
      new->name[i++] = tab[2][j++];
  new->name[i] = '\0';
  new->next = node->next;
  node->next = new;
  new->prev = node;
}

int		my_envcmp(char *name, char *env)
{
  int		i;

  i = 0;
  while (name[i] != '\0' && env[i] != '\0')
    {
      if (name[i] != env[i])
	return (-1);
      i = i + 1;
    }
  if (env[i] == '\0')
    return (-1);
  if (env[i] == '=')
    return (1);
  return (-1);
}

t_list		*sup_elem(char *str, t_list *node)
{
  t_list	*tmp;

  if (node == NULL)
    return (NULL);
  if (my_envcmp(str, node->name) == 1)
    {
      tmp = node->next;
      free(node);
      tmp = sup_elem(str, tmp);
      return (tmp);
    }
  else
    {
      node->next = sup_elem(str, node->next);
      return (node);
    }
}

void		del_env(char **tab, t_list *node)
{
  int		i;

  i = 1;
  while (tab[i] != NULL)
    {
      sup_elem(tab[i], node);
      i = i + 1;
    }
}
