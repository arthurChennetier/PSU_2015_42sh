/*
** pars_com.c for pars_com in /home/clement/Test_Perso/42/PSU_2015_42sh
** 
** Made by clement
** Login   <clement@clement-HP-EliteBook-840-G2>
** 
** Started on  Fri Jun  3 16:46:06 2016 clement
** Last update Sun Jun  5 17:33:41 2016 chauvi_d
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "minishell.h"
#include "get_next_line.h"

t_pars	tab_p [] =
  {
    {'?', &nigma},
    {'-', &dash},
    {'!', &excl},
    {0, NULL}
  };

int	word_cmp(char *str, char *cmp)
{
  int	i;
  int	j;

  i = 0;
  j = 0;
  while (str[i])
    {
      while (str[i] == cmp[j] && str[i] && str[j])
	{
	  i++;
	  j++;
	}
      if (cmp[j] == 0)
	return (0);
      j = 0;
      i++;
    }
  return (-1);
}

char	*put_in_str(char *str, char *src, int i, int k)
{
  int	j;
  char	*tmp;
  char	*tab;

  j = 0;
  if ((tmp = malloc(sizeof(char) * (my_strlen(str) + 1))) == NULL)
    return (NULL);
  while (str[i] && j != i)
      {
	tmp[j] = str[j];
	j++;
      }
  tmp[j] = 0;
  tab = my_strcat(tmp, src);
  if ((tab = my_realloc(tab, my_strlen(tab) + my_strlen(str) + 1)) == NULL)
    return (NULL);
  j = strlen(tab);
  while (str[k] != '?' && str[k])
    tab[j++] = str[k++];
  tab[j] = 0;
  free(tmp);
  return (tab);
}

int	alias_history(char **str, int i)
{
  int	j;
  int	check;

  j = 0;
  check = 0;
  while (tab_p[j].key != 0)
    {
      if (tab_p[j].key == str[0][i + 1])
	{
	  if ((i = tab_p[j].ptr(str, i)) == -1)
	    return (-1);
	  check = 1;
	}
      j++;
    }
  if (check == 0)
    if ((i = flag_str(str, i)) == -1)
      return (-1);
  return (i);
}

char	*cmd(char *str)
{
  int	i;

  i = 0;
  if (str == NULL)
    return (NULL);
  while (str[i])
    {
      if (str[i] == '!')
	if ((i = alias_history(&str, i)) == -1)
	  return (NULL);
      if (i < my_strlen(str))
	i++;
    }
  return (str);
}
