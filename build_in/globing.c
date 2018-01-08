/*
** globing.c for globing in /home/benama_m/PSU_2015_42sh
** 
** Made by mahdi Benamar
** Login   <benama_m@epitech.net>
** 
** Started on  Sun May 29 04:06:39 2016 mahdi Benamar
** Last update Fri Jun  3 17:44:41 2016 arthur
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <glob.h>
#include "minishell.h"
#include "get_next_line.h"
#include "print.h"

char		**disp_glob(glob_t globbuf, char **new, int **i)
{
  int		j;

  j = -1;
  while (globbuf.gl_pathv[++j] != NULL)
    {
      my_strcpy(new[**i], globbuf.gl_pathv[j]);
      **i = **i + 1;
    }
  return (new);
}

char		**glob_add(char *str, glob_t gloob, char **new, int *i)
{
  if (glob(str, 0, NULL, &gloob) == GLOB_NOMATCH)
    {
      fprintf(stderr, "%s: No Match\n", str);
      return (new);
    }
  else
    new = disp_glob(gloob, new, &i);
  return (new);
}

int		begin_glob(char **tab)
{
  int		i;
  int		j;

  i = 1;
  while (tab[i])
    {
      j = 0;
      while (tab[i][j])
	{
	  if (tab[i][j] == '*' || tab[i][j] == '?')
	    return (i);
	  j = j + 1;
	}
      i = i + 1;
    }
  return (i);
}

char		**no_glob(char *str, char **new, int *j)
{
  new[*j] = my_strcpy(new[*j], str);
  *j = *j + 1;
  return (new);
}

char		**my_glob(char **tab)
{
  glob_t        globbuf;
  char		**new;
  int		i;
  int		j;

  i = begin_glob(tab);
  if ((new = init_new(tab, i)) == NULL)
    return (tab);
  j = i;
  while (tab[i] != NULL)
    {
      curly(tab[i]);
      if (tab[i][0] == '*' || in_the_word(tab[i]) == 1)
	new = glob_add(tab[i], globbuf, new, &j);
      else
	new = no_glob(tab[i], new, &j);
      i += 1;
    }
  new[j] = NULL;
  return (new);
}
