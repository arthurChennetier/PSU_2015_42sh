/*
** direct_functions.c for minishell in /home/chenne_a/rendu/PSU_tek1/PSU_2015_minishell1/bootstrap
** 
** Made by Arthur Chennetier
** Login   <chenne_a@epitech.net>
** 
** Started on  Fri Jan 22 14:16:27 2016 Arthur Chennetier
** Last update Sun Jun  5 14:06:34 2016 arthur
*/

#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "minishell.h"
#include "print.h"

void		current_exec(t_exec *var, char **tab, int j)
{
  char		*new;
  int		i;
  int		status;

  status = -1;
  i = 2;
  if ((new = malloc(sizeof(char) * my_strlen(tab[0]))) == NULL)
    exit(EXIT_FAILURE);
  while (tab[0][i] != '\0')
    {
      new[j] = tab[0][i++];
      j = j + 1;
    }
  new[j] = '\0';
  if (access(new, F_OK) == -1)
    {
      my_printf("Wrong pathfile for execution\n");
      var->indic = 1;
      fail = 1;
    }
  else if (fork() == 0)
    execve(new, tab, var->env);
  else
    waitpid(0, &status, WUNTRACED | WCONTINUED);
  test_siggsev(status, NULL);
}

int		path_exec(t_exec *var, char **tab)
{
  int		status;

  if (access(tab[0], F_OK) == -1 || my_strlen(tab[0]) == 1)
    return (-1);
  else if (fork() == 0)
    execve(tab[0], tab, var->env);
  else
    waitpid(0, &status, WUNTRACED | WCONTINUED);
  test_siggsev(status, tab);
  return (0);
}

int		direct_exec(char **tab, t_exec *var)
{
  if (tab[0][0] == '.' && my_strlen(tab[0]) > 2)
    current_exec(var, tab, 0);
  else
    if (path_exec(var, tab) == -1)
      return (-1);
  return (0);
}
