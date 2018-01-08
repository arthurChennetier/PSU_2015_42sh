/*
** cd.c for minishell2 in /home/arthur/rendu/semestre2/PSU_2016/PSU_2015_minishell2
** 
** Made by arthur
** Login   <chenne_a@epitech.net>
** 
** Started on  Tue Apr 12 13:14:05 2016 arthur
** Last update Sat Jun  4 15:27:17 2016 arthur
*/

#include <stdlib.h>
#include "get_next_line.h"
#include "minishell.h"
#include "print.h"

void		last_cd(t_exec build, t_exec *var, char *old, int i)
{
  char		*last;

  while (var->env[i] != NULL)
    {
      if (my_strlen(var->env[i]) > 7)
        {
          if (var->env[i][0] == 'O' &&
	      var->env[i][1] == 'L' && var->env[i][2] == 'D'
              && var->env[i][3] == 'P' &&
	      var->env[i][4] == 'W' && var->env[i][5] == 'D'
              && var->env[i][6] == '=')
            {
              last = change_last(var->env[i]);
              if (chdir(last) == -1)
                my_printf("Problem in Oldpwd\n");
              else
                {
                  change_pwd(var, build);
                  change_old(old, var);
                }
            }
        }
      i = i + 1;
    }
  change_pwd(var, build);
}

void		home_case(t_exec *var, char *home, t_exec build, char *old)
{
  if (chdir(home) == -1)
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

void		my_cd(t_exec build, t_exec *var)
{
  char		*home;
  char		*old;
  int		i;

  old = prepare_old();
  i = find_home(var->env);
  home = prepare_home(build, i, var->env);
  if (build.tab[1] == NULL)
    home_case(var, home, build, old);
  else
    {
      if (my_strcmp(build.tab[1], "-") == 1)
        last_cd(build, var, old, 0);
      else
	classic_cd(build, var, old);
    }
  free(old);
  free(home);
}

char		*prepare_old()
{
  char		*pwd;

  if ((pwd = malloc(sizeof(char) * 4096)) == NULL)
    exit(EXIT_FAILURE);
  pwd = getcwd(pwd, 4096);
  return (pwd);
}

char		*change_last(char *pwd)
{
  char		*last;
  int		i;
  int		y;

  i = 7;
  y = 0;
  if ((last = malloc(sizeof(char) * (my_strlen(pwd + 5)))) == NULL)
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
