/*
** path_functions.c for minishell in /home/chenne_a/rendu/PSU_tek1/PSU_2015_minishell1/bootstrap
** 
** Made by Arthur Chennetier
** Login   <chenne_a@epitech.net>
** 
** Started on  Mon Jan 18 15:37:10 2016 Arthur Chennetier
** Last update Mon May 30 15:42:43 2016 arthur
*/

#include <stdio.h>
#include <stdlib.h>
#include "minishell.h"
#include "print.h"

int		my_double_strlen(char **str)
{
  int		i;

  i = 0;
  while (str[i] != NULL)
    i = i + 1;
  return (i);
}

t_path		path_nbr(char *env, t_path param)
{
  int		i;
  int		n;

  n = 0;
  i = 5;
  while (env[i] != '\0')
    {
      if (env[i] == ':')
	n = n + 1;
      i = i + 1;
    }
  if (n == 0 && i == 5)
    param.j = 0;
  else
    param.j = n + 1;
  param.s_max = i;
  return (param);
}

char		*create_path(char *tab, char *path)
{
  char		*new;
  int		i;
  int		j;

  j = 0;
  i = my_strlen(tab) + my_strlen(path) + 1;
  if ((new = malloc(sizeof(char) * (i + 1))) == NULL)
    exit(EXIT_FAILURE);
  i = 0;
  while (path[i] != '\0')
    {
      new[i] = path[i];
      i = i + 1;
    }
  new[i] = '/';
  i = i + 1;
  while (tab[j] != '\0')
    {
      new[i] = tab[j];
      j = j + 1;
      i = i + 1;
    }
  new[i] = '\0';
  return (new);
}

char		**write_path(char **path, char *env)
{
  int		i;
  int		j;
  int		k;

  i = 5;
  j = 0;
  k = 0;
  while (env[i] != '\0')
    {
      if (env[i] == ':')
        {
          path[j][k] = '\0';
          j = j + 1;
          i = i + 1;
          k = 0;
        }
      path[j][k] = env[i];
      i = i + 1;
      k = k + 1;
    }
  path[j][k] = '\0';
  path[j + 1] = NULL;
  return (path);
}

char		**init_path(char **env)
{
  char		**path;
  t_path	ct;

  ct = init_path_var(ct);
  while (env[ct.i] != NULL)
    {
      if (env[ct.i][0] == 'P' && env[ct.i][1] == 'A' && env[ct.i][2] == 'T'
          && env[ct.i][3] == 'H' && env[ct.i][4] == '=')
        {
          ct = path_nbr(env[ct.i], ct);
          if ((path = malloc(sizeof(char*) * (ct.j + 1))) == NULL)
	    return (NULL);
          while (ct.k <= ct.j)
            {
              if ((path[ct.k] = malloc(sizeof(char) * ct.s_max + 2)) == NULL)
		return (NULL);
              ct.k = ct.k + 1;
            }
          path = write_path(path, env[ct.i]);
          return (path);
        }
      ct.i = ct.i + 1;
    }
  path = prepare_path();
  return (path);
}
