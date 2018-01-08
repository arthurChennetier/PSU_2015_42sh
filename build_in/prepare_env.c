/*
** prepare_env.c for minishell2 in /home/arthur/PSU_2015_minishell2
** 
** Made by arthur
** Login   <chenne_a@epitech.net>
** 
** Started on  Wed Apr 13 16:44:10 2016 arthur
** Last update Fri Jun  3 18:24:30 2016 arthur
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "minishell.h"

char		**prepare_path()
{
  char		**path;

  if ((path = malloc(sizeof(char*) * 4)) == NULL)
    return (NULL);
  path[0] = malloc(sizeof(char) * 15);
  path[1] = malloc(sizeof(char) * 5);
  path[2] = malloc(sizeof(char) * 9);
  path[3] = NULL;
  if (path[0] == NULL || path[1] == NULL || path[2] == NULL)
    return (NULL);
  path[0] = my_strcpy(path[0], "/usr/local/bin");
  path[1] = my_strcpy(path[1], "/bin");
  path[2] = my_strcpy(path[2], "/usr/bin");
  return (path);
}

char		*prepare_no_pwd(char *pwd)
{
  char          *last;
  int           i;
  int           y;

  i = 0;
  y = 4;
  if ((last = malloc(sizeof(char) * (my_strlen(pwd) + 5))) == NULL)
    exit(EXIT_FAILURE);
  last[0] = 'P';
  last[1] = 'W';
  last[2] = 'D';
  last[3] = '=';
  while (pwd[i] != '\0')
    last[y++] = pwd[i++];
  last[y] = '\0';
  return (last);
}

char		**prepare_env()
{
  t_exec	var;
  char		**env;
  char		*pwd;

  if ((pwd = malloc(sizeof(char) * 4096)) == NULL)
    exit(EXIT_FAILURE);
  pwd = getcwd(pwd, 4096);
  if ((env = malloc(sizeof(char**) * 3)) == NULL)
    exit(EXIT_FAILURE);
  if ((env[0] = malloc(sizeof(char) * 34)) == NULL)
    exit(EXIT_FAILURE);
  if ((env[1] = malloc(sizeof(char) * (my_strlen(pwd) + 100))) == NULL)
    exit(EXIT_FAILURE);
  env[0] = my_strcpy(env[0], "PATH=/usr/local/bin:/bin:/usr/bin");
  env[1] = prepare_no_pwd(pwd);
  env[2] = NULL;
  var.env = env;
  setenv_old(pwd, &var);
  env = var.env;
  return (env);
}
