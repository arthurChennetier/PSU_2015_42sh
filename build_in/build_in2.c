/*
** build_in2.c for minishell in /home/chenne_a/rendu/PSU_tek1/PSU_2015_minishell1
** 
** Made by Arthur Chennetier
** Login   <chenne_a@epitech.net>
** 
** Started on  Sun Jan 24 16:20:36 2016 Arthur Chennetier
** Last update Sat Jun  4 15:30:07 2016 arthur
*/

#include <stdlib.h>
#include "get_next_line.h"
#include "minishell.h"
#include "print.h"

void		change_pwd(t_exec *var, t_exec build)
{
  char		**tab;
  char		*pwd;

  if ((tab = malloc(sizeof(char**) * 4)) == NULL)
    exit(EXIT_FAILURE);
  if ((tab[0] = malloc(sizeof(char) * (my_strlen("setenv") + 1))) == NULL)
    exit(EXIT_FAILURE);
  tab[0] = my_strcpy(tab[0], "setenv");
  if ((tab[1] = malloc(sizeof(char) * (my_strlen("PWD") + 1))) == NULL)
    exit(EXIT_FAILURE);
  tab[1] = my_strcpy(tab[1], "PWD");
  if ((pwd = malloc(sizeof(char) * 4096)) == NULL)
    exit(EXIT_FAILURE);
  pwd = getcwd(pwd, 4096);
  if ((tab[2] = malloc(sizeof(char) * (my_strlen(pwd) + 1))) == NULL)
    exit(EXIT_FAILURE);
  tab[2] = my_strcpy(tab[2], pwd);
  tab[3] = NULL;
  build.tab = tab;
  my_setenv(build, var);
}

void		setenv_old(char *old, t_exec *var)
{
  t_exec	build;

  if ((build.tab = malloc(sizeof(char**) * 4)) == NULL)
    exit(EXIT_FAILURE);
  build.tab[0] = malloc(sizeof(char) * (my_strlen("setenv") + 1));
  build.tab[1] = malloc(sizeof(char) * (my_strlen("OLDPWD") + 1));
  build.tab[2] = malloc(sizeof(char) * (my_strlen(old) + 1));
  if (build.tab[0] == NULL || build.tab[1] == NULL || build.tab[2] == NULL)
    exit(EXIT_FAILURE);
  my_strcpy(build.tab[0], "setenv");
  my_strcpy(build.tab[1], "OLDPWD");
  my_strcpy(build.tab[2], old);
  build.tab[3] = NULL;
  my_setenv(build, var);
}

void		change_old(char *old, t_exec *var)
{
  int		i;

  i = 0;
  while (var->env[i] != NULL)
    {
      if (my_strlen(var->env[i]) > 7)
	{
	  if (var->env[i][0] == 'O' && var->env[i][1] == 'L' &&
	      var->env[i][2] == 'D'
	      && var->env[i][3] == 'P' &&
	      var->env[i][4] == 'W' && var->env[i][5] == 'D'
	      && var->env[i][6] == '=')
	    setenv_old(old, var);
	}
      i = i + 1;
    }
}

void		my_unsetenv(t_exec build, t_exec *var)
{
  t_list	*node;
  int		i;

  i = 0;
  node = create_list(var->env);
  while (build.tab[i] != NULL)
    i = i + 1;
  if (i == 1)
    {
      my_putstr("unsetenv: Too few arguments.\n");
      fail = 1;
      var->indic = 0;
    }
  else
    del_env(build.tab, node);
  var->env = create_env(node);
}
