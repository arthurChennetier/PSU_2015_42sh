/*
** my_str_to_wordtab.c for minishell in /home/chenne_a/rendu/PSU_tek1/PSU_2015_minishell1/bootstrap
** 
** Made by Arthur Chennetier
** Login   <chenne_a@epitech.net>
** 
** Started on  Sun Jan 17 20:52:56 2016 Arthur Chennetier
** Last update Mon Apr 11 14:21:00 2016 arthur
*/

#include <stdlib.h>
#include "minishell.h"
#include "print.h"

int		space_nbr(char *str)
{
  int		i;
  int		nb;

  if (str == NULL)
    return (0);
  i = 0;
  nb = 0;
  while (str[i] != '\0')
    {
      if (str[i] == ' ')
        nb = nb + 1;
      if (i > 0)
	{
	  if (str[i] == ';' && str[i - 1] != ' ' && str[i + 1] != ' ')
	    nb = nb + 2;
	  else if (str[i] == ';')
	    nb = nb + 1;
	}
      i = i + 1;
    }
  return (nb);
}

t_wtab		inter_command(t_wtab tab, char *str)
{
  if ((tab.arg[tab.i] = malloc(sizeof(char) * (my_strlen(str) + 2))) == NULL)
    exit(EXIT_FAILURE);
  tab.arg[tab.i][0] = str[tab.k];
  tab.arg[tab.i][1] = '\0';
  while (str[tab.k] == ';' || str[tab.k] == ' ')
    tab.k = tab.k + 1;
  tab.i = tab.i + 1;
  return (tab);
}

char		**my_str_to_wordtab(char *str)
{
  t_wtab	tab;

  tab.k = 0;
  tab.j = 0;
  tab.i = 0;
  tab.nb = space_nbr(str);
  if ((tab.arg = malloc(sizeof(char*) * (tab.nb + 3))) == NULL)
    return (NULL);
  while (tab.i < tab.nb + 1)
    {
      if ((tab.arg[tab.i] = malloc(sizeof(char)
				   * (my_strlen(str) + 2))) == NULL)
	return (NULL);
      while (str[tab.k] != ' ' && str[tab.k] != '\0' && str[tab.k] != ';')
	tab.arg[tab.i][tab.j++] = str[tab.k++];
      tab.arg[tab.i][tab.j] = '\0';
      tab.i = tab.i + 1;
      if (str[tab.k] == ';')
	tab = inter_command(tab, str);
      else
	tab.k = tab.k + 1;
      tab.j = 0;
    }
  tab.arg[tab.i] = NULL;
  return (tab.arg);
}

int		check_next(char *str)
{
  if (str == NULL)
    return (-1);
  else if (str[0] == '\0')
    return (-1);
  else if (str[0] == ';')
    return (-1);
  else
    return (0);
}

int		next_exec(char **tab, int j)
{
  if (j == 0)
    {
      while (tab[j] != NULL && tab[j][0] != ';')
	j = j + 1;
      return (j);
    }
  if (j != 0 && tab[j] != NULL)
    j = j + 1;
  if (tab[j] == NULL)
    return (j);
  while (tab[j] != NULL && check_next(tab[j]) != -1)
    j = j + 1;
  if (j != 1)
    if (tab[j] != NULL)
      if (tab[j][0] == ';')
	j = j - 1;
  return (j);
}
