/*
** create_liste.c for minishell2 in /home/arthur/rendu/semestre2/PSU_2016/PSU_2015_minishell2
** 
** Made by arthur
** Login   <chenne_a@epitech.net>
** 
** Started on  Thu Apr  7 16:13:59 2016 arthur
** Last update Sun Jun  5 13:47:04 2016 arthur
*/

#include <dirent.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "minishell.h"
#include "get_next_line.h"
#include "print.h"

t_list		*add_new_elem(t_list *node, char **env, int i)
{
  t_list	*new;

  if (env[i] == NULL)
    return (NULL);
  if ((new = malloc(sizeof(t_list))) == NULL)
    exit(EXIT_FAILURE);
  if ((new->name = malloc(sizeof(char) * (my_strlen(env[i]) + 2))) == NULL)
    exit(EXIT_FAILURE);
  new->name = my_strcpy(new->name, env[i]);
  new->prev = node;
  node->next = new;
  new->next = add_new_elem(new, env, i + 1);
  return (new);
}

t_list		*create_list(char **env)
{
  t_list	*node;

  if (env[0] == NULL)
    return (NULL);
  if ((node = malloc(sizeof(t_list))) == NULL)
    return (NULL);
  if ((node->name = malloc(sizeof(char) * (my_strlen(env[0]) + 1))) == NULL)
    return (NULL);
  node->name = my_strcpy(node->name, env[0]);
  node->prev = NULL;
  node->next = add_new_elem(node, env, 1);
  return (node);
}

int		list_size(t_list *tmp, int size)
{
  while (tmp != NULL)
    {
      size = size + 1;
      tmp = tmp->next;
    }
  return (size);
}

char		*env_malloc(t_list *tmp)
{
  char		*env;

  if ((env = malloc(sizeof(char)
			  * (my_strlen(tmp->name) + 1))) == NULL)
    exit(EXIT_FAILURE);
  return (env);
}

char		**create_env(t_list *node)
{
  char		**env;
  t_list	*tmp;
  int		size;

  size = 0;
  tmp = node;
  size = list_size(tmp, size);
  if ((env = malloc(sizeof(char**) * (size + 1))) == NULL)
    exit(EXIT_FAILURE);
  if (size <= 1)
    {
      env[0] = NULL;
      return (env);
    }
  size = 0;
  tmp = node;
  while (tmp != NULL)
    {
      env[size] = env_malloc(tmp);
      env[size] = my_strcpy(env[size], tmp->name);
      size = size + 1;
      tmp = tmp->next;
    }
  env[size] = NULL;
  return (env);
}
