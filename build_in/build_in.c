/*
** build_in.c for minishell in /home/chenne_a/rendu/PSU_tek1/PSU_2015_minishell1/bootstrap
** 
** Made by Arthur Chennetier
** Login   <chenne_a@epitech.net>
** 
** Started on  Fri Jan 22 16:54:20 2016 Arthur Chennetier
** Last update Sun Jun  5 17:16:04 2016 chauvi_d
*/

#include <stdio.h>
#include <stdlib.h>
#include "minishell.h"
#include "get_next_line.h"
#include "print.h"

t_cmd		g_func[8] =
  {
    {&my_exit, "exit"},
    {&my_env, "env"},
    {&my_cd, "cd"},
    {&my_setenv, "setenv"},
    {&my_unsetenv, "unsetenv"},
    {&my_echo, "echo"},
    {&history, "history"},
    {NULL, NULL}
  };

void		my_exit(t_exec build, t_exec *var)
{
  unsigned char	i;

  i = -1;
  while (build.tab[++i] != NULL);
  if (check_exit(i, var) == -1)
    return ;
  if (i == 2)
    {
      if (test_exit(build.tab[1]) == -1)
	{
	  bad_exit(var->env);
	  return ;
	}
      i = my_getnbr(build.tab[1]);
      free_exec(build, var->env);
      my_putstr("exit\n");
      write_history(hist, ".42_history");
      exit(i);
    }
  free_exec(build, var->env);
  write_history(hist, ".42_history");
  my_putstr("exit\n");
  exit(0);
}

void		my_env(t_exec build, t_exec *var)
{
  int		i;

  build = build;
  i = 0;
  while (var->env[i] != NULL)
    {
      my_putstr(var->env[i]);
      my_putchar('\n');
      i = i + 1;
    }
}

int		check_cmd(char *cmd)
{
  int		i;

  i = 0;
  while (g_func[i].cmd != NULL && my_strcmp(cmd, g_func[i].cmd) != 1)
    i = i + 1;
  if (g_func[i].cmd == NULL)
    return (-1);
  return (i);
}

void		build_in(int i, t_exec build, t_exec *var)
{
  g_func[i].str(build, var);
}

void		free_path(char **path)
{
  int		i;

  i = 0;
  while (path[i] != NULL)
    {
      free(path[i]);
      i = i + 1;
    }
}
