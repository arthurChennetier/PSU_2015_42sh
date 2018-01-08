/*
** many_exec.c for minishell2 in /home/chenne_a/rendu/semestre2/PSU_2016/PSU_2015_minishell2
** 
** Made by Arthur Chennetier
** Login   <chenne_a@epitech.net>
** 
** Started on  Wed Mar 23 15:29:06 2016 Arthur Chennetier
** Last update Fri Apr  1 15:07:34 2016 arthur
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

t_many		*init_var(char **tab)
{
  t_many	*var;

  if ((var = malloc(sizeof(t_many))) == NULL)
    return (NULL);
  var->i = next_exec(tab, 0);
  var->j = 0;
  return (var);
}

t_many		*next_var(char **tab, t_many *var)
{
  int		tmp;
  int		tmp_i;
  int		i;

  i = 0;
  tmp_i = var->i;
  if (tab[var->i] != NULL)
    if (tab[var->i][0] == ';' && tab[var->i + 1] != NULL)
      tmp_i = var->i + 1;
  tmp = var->j;
  var->new = malloc(sizeof(char*) * (var->i - var->j + 1));
  while (tmp < var->i)
    {
      var->new[i] = malloc(sizeof(char) * (my_strlen(tab[tmp]) + 1));
      my_strcpy(var->new[i++], tab[tmp++]);
    }
  var->new[i] = NULL;
  var->i = tmp_i;
  var->j = var->i;
  var->i = next_exec(tab, var->i);
  if (tab[var->i] != NULL)
    if (tab[var->i + 1] != NULL)
      if (tab[var->i + 1][0] == ';')
	var->i = var->i + 1;
  return (var);
}

char		**init_exec(char **tab, int j, int y)
{
  char		**new;

  new = malloc(sizeof(char*) * (y + 1));
  while (j < y)
    {
      new[y] = malloc(sizeof(char) * (my_strlen(tab[j]) + 1));
      my_strcpy(new[y], tab[j]);
      y = y + 1;
      j = j + 1;
    }
  new[y] = NULL;
  return (new);
}
