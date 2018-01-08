/*
** cd2.c for minishell2 in /home/arthur/rendu/semestre2/PSU_2016/PSU_2015_minishell2
** 
** Made by arthur
** Login   <chenne_a@epitech.net>
** 
** Started on  Tue Apr 12 13:32:00 2016 arthur
** Last update Sat Jun  4 15:26:50 2016 arthur
*/

#include <stdlib.h>
#include "get_next_line.h"
#include "minishell.h"
#include "print.h"

void		classic_cd(t_exec build, t_exec *var, char *old)
{
  if (chdir(build.tab[1]) == -1)
    {
      fprintf(stderr, "testdircd: Permission denied.\n");
      var->indic = 0;
      fail = 1;
    }
  else
    {
      change_pwd(var, build);
      change_old(old, var);
    }
}

char		*prepare_home(t_exec build, int i, char **env)
{
  char		*home;
  int		j;
  int		k;

  k = 0;
  j = 5;
  build = build;
  if ((home = malloc(sizeof(char) * (my_strlen(env[i]) - 4))) == NULL)
    exit(EXIT_FAILURE);
  while (env[i][j] != '\0')
    {
      home[k] = env[i][j];
      k = k + 1;
      j = j + 1;
    }
  home[k] = '\0';
  return (home);
}

int		find_home(char **env)
{
  int		i;
  int		j;

  i = 0;
  j = 0;
  while (env[i] != NULL && j != 5)
    {
      if (env[i][0] == 'H' && env[i][1] == 'O' &&
          env[i][2] == 'M' && env[i][3] == 'E' &&
          env[i][4] == '=')
        j = 5;
      i = i + 1;
    }
  i = i - 1;
  return (i);
}
