/*
** check_flags_history.c for 42 in /home/chauvi_d/Rendu-2015-Epitech/rendu/Systunix/for42/build_in
** 
** Made by chauvi_d
** Login   <chauvi_d@epitech.net>
** 
** Started on  Sat Jun  4 16:20:54 2016 chauvi_d
** Last update Sun Jun  5 19:31:19 2016 chauvi_d
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "get_next_line.h"
#include "minishell.h"
#include "print.h"

t_history	h_flag[] =
  {
    {'c', &clear_history},
    {'h', &simple_history},
    {'r', &reverse_history},
    {'S', &save_history},
    {'L', &load_history},
    {0, NULL}
  };

int	check_flags(char *str)
{
  int	i;
  int	j;
  int	check;

  j = 1;
  check = -1;
  while (str[j])
    {
      i = 0;
      while (h_flag[i].key != 0)
	{
	  if (h_flag[i].key == str[j])
	    check = 0;
	  i++;
	}
      if (check == -1)
	return (-1);
      check = -1;
      j++;
    }
  return (0);
}

int	check_output(char *str, int i, int j)
{
  j++;
  while (str[j])
    {
      if (h_flag[i].key == str[j])
	return (-1);
      j++;
    }
  return (0);
}

int	check_flags_history(char **tab)
{
  int	i;
  int	j;

  i = 0;
  if (my_strlen(tab[1]) <= 1 ||  check_flags(tab[1]) == -1)
    return (-1);
  while (h_flag[i].key != 0)
    {
      j = 1;
      while (tab[1][j])
	{
	  if (h_flag[i].key == tab[1][j] && check_output(tab[1], i, j) == 0)
	    h_flag[i].ptr(tab[2], tab[1], j);
	  j++;
	}
      i++;
    }
  return (0);
}
