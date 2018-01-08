/*
** echo.c for echo in /home/benama_m/PSU_2015_42sh/benama_m/build_in
** 
** Made by mahdi Benamar
** Login   <benama_m@epitech.net>
** 
** Started on  Wed May 25 14:38:24 2016 mahdi Benamar
** Last update Sat Jun  4 16:24:20 2016 arthur
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "minishell.h"
#include "get_next_line.h"
#include "print.h"

t_echo		echo_tab[10] =
{
  {'a', "a", 7},
  {'b', "b", 8},
  {'c', "c", 0},
  {'e', "e", 27},
  {'f', "f", 12},
  {'n', "n", 10},
  {'r', "r", 13},
  {'t', "t", 9},
  {'v', "v", 11},
  {'0', NULL, 0}
};

char		check_flag(char c)
{
  int		i;

  i = 0;
  while (echo_tab[i].stop)
    {
      if (c == echo_tab[i].c)
	{
	  if (c == 'c')
	    return (c);
	  c = echo_tab[i].nb;
	  return (c);
	}
      i = i + 1;
    }
  my_putchar(92);
  return (c);
}

int		check_double_backslash(char *str, int i)
{
  int		indic;
  int		save;
  char		c;

  save = i;
  indic = 0;
  while (str[i] == 92 && str[i])
    {
      indic = indic + 1;
      i = i + 1;
    }
  if (indic % 2 == 1)
    return (save);
  save = save + 2;
  if (str[save] != '\0')
    c = check_flag(str[save]);
  if (c == 'c')
    return (-1);
  my_putchar(c);
  return (save);
}

void		my_echo_e(char **tab, int indic)
{
  int		i;

  i = indic;
  while (tab[i])
    {
      if (check_backslash(tab[i]) == -1)
	write(1, tab[i], my_strlen(tab[i]));
      else
	if (backslash_case(tab[i]) == -1)
	  return ;
      if (tab[i + 1] != NULL)
	write(1, " ", 1);
      i = i + 1;
    }
}

void            my_echo(t_exec build, t_exec *var)
{
  int		i;

  var = var;
  i = 0;
  while (build.tab[i])
    i = i + 1;
  if (i > 1)
    {
      if (my_strcmp(build.tab[1], "-n") == 1)
	{
	  my_echo_e(build.tab, 2);
	  return ;
	}
      else
	my_echo_e(build.tab, 1);
    }
  else
    my_echo_e(build.tab, 1);
  my_putchar('\n');
}
