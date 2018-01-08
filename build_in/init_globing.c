/*
** init_globing.c for 42sh in /home/arthur/rendu/semestre2/PSU_2016/PSU_2015_42sh
** 
** Made by arthur
** Login   <chenne_a@epitech.net>
** 
** Started on  Fri Jun  3 15:56:06 2016 arthur
** Last update Fri Jun  3 16:18:02 2016 arthur
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <glob.h>
#include "minishell.h"
#include "get_next_line.h"
#include "print.h"

int		in_the_word(char *str)
{
  int           i;

  i = 0;
  while (str[i])
    {
      if (str[i] == '*' || str[i] == '?')
        return (1);
      i += 1;
    }
  return (-1);
}

char		**local_init(char **new, glob_t globuff, t_globb *var)
{
  if ((new[var->y] =
       malloc(sizeof(char) *
	      (my_strlen(globuff.gl_pathv[var->glob_count]) + 1))) == NULL)
    return (NULL);
  var->y = var->y + 1;
  return (new);
}

char		**second_init_new(char **tab, char **new, int begin)
{
  glob_t	globuff;
  t_globb	var;

  var.i = begin;
  var.y = begin;
  while (tab[var.i])
    {
      if (glob(tab[var.i], 0, NULL, &globuff) != GLOB_NOMATCH)
        {
          var.glob_count = 0;
          while (globuff.gl_pathv[var.glob_count])
            {
	      if ((new = local_init(new, globuff, &var)) == NULL)
		return (NULL);
              var.glob_count = var.glob_count + 1;
            }
        }
      else
        if ((new[var.y++] = malloc(sizeof(char)
				   * (my_strlen(tab[var.i]) + 1))) == NULL)
          return (NULL);
      var.i = var.i + 1;
    }
  return (new);
}

char		**init_arg_new(char **tab, char **new, int begin)
{
  int		i;

  i = 0;
  while (i < begin)
    {
      if ((new[i] = malloc(sizeof(char) * (my_strlen(tab[i]) + 1))) == NULL)
        return (NULL);
      new[i] = my_strcpy(new[i], tab[i]);
      i = i + 1;
    }
  return (new);
}

char		**init_new(char **tab, int begin)
{
  glob_t	globuff;
  char		**new;
  int		i;
  int		size;

  i = begin;
  size = 0;
  while (tab[i])
    {
      if (glob(tab[i], 0, NULL, &globuff) != GLOB_NOMATCH)
        size = size + tab_len(globuff.gl_pathv);
      else
        size = size + 1;
      i = i + 1;
    }
  if ((new = malloc(sizeof(char*) * (size + (begin + 1)))) == NULL)
    return (NULL);
  if ((new = init_arg_new(tab, new, begin)) == NULL)
    return (NULL);
  if ((new = second_init_new(tab, new, begin)) == NULL)
    return (NULL);
  return (new);
}
