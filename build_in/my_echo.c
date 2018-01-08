/*
** my_echo.c for echo in /home/benama_m/PSU_2015_42sh/benama_m
** 
** Made by mahdi Benamar
** Login   <benama_m@epitech.net>
** 
** Started on  Wed May 25 19:41:59 2016 mahdi Benamar
** Last update Sat Jun  4 16:22:54 2016 arthur
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "minishell.h"
#include "get_next_line.h"
#include "print.h"

char            *the_variable(char *str, char c)
{
  int           i;
  int           j;
  char          *tmp;

  i = j = 0;
  if ((tmp = malloc(sizeof(char) * my_strlen(str) + 1)) == NULL)
    return (NULL);
  while (str[i])
    {
      if (str[i] != c)
        {
          tmp[j] = str[i];
          j += 1;
        }
      i += 1;
    }
  tmp[j] = '\0';
  return (tmp);
}

char		*line_path(char *path, char *env)
{
  int		i;
  int		l;

  i = l = 0;
  while (env[l] != 61)
    l += 1;
  l += 1;
  while (env[l])
    {
      path[i] = env[l];
      l += 1;
      i += 1;
    }
  path[i] = '\0';
  return (path);
}

char            *all_path(char *str, char **env, int size)
{
  int           i;
  char          *path;

  i = 0;
  path = NULL;
  while (env[i])
    {
      if (strncmp(env[i], str, size) == 0)
        {
	  if ((path = malloc(sizeof(char) * my_strlen(env[i]))) == NULL)
	    return (NULL);
	  path = line_path(path, env[i]);
          return (path);
        }
      i += 1;
    }
  return (0);
}

char            *variable_line(char *str, char **env)
{
  char          *tmp;
  char          *path;

  path = NULL;
  if (str[0] == '$')
    {
      if ((tmp = malloc(sizeof(char) * my_strlen(str) + 1)) == NULL)
	return (NULL);
      tmp = the_variable(str, '$');
      if ((path = all_path(tmp, env, my_strlen(tmp))) != 0)
	  return (path);
      else
	{
	  printf("%s: Undefined variable.\n", tmp);
	  return (NULL);
	}
    }
  return (0);
}

char		*my_clean_putstr(char *str, char **env)
{
  char		*tmp;

  if ((tmp = malloc(sizeof(char) * my_strlen(str) + 1)) == NULL)
    return (NULL);
  if (str[0] == '$' && (tmp = variable_line(str, env)) == NULL)
    return (NULL);
  if (str[0] == '~' && (tmp = my_tilde(str, env)) == NULL)
      return (NULL);
  return (tmp);
}
