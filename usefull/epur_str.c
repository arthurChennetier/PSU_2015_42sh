/*
** epur_str.c for minishell in /home/chenne_a/rendu/semestre2/PSU_2016/PSU_2015_minishell2
** 
** Made by Arthur Chennetier
** Login   <chenne_a@epitech.net>
** 
** Started on  Tue Mar 22 16:53:58 2016 Arthur Chennetier
** Last update Wed Jun  1 11:13:00 2016 arthur
*/

#include <stdio.h>
#include <stdlib.h>
#include "minishell.h"

int		epur_end(char *str, int i)
{
  i = i - 1;
  while (str[i] == ' ' && i >= 0)
    i = i - 1;
  return (i + 1);
}

int		test_end(char *str, int y)
{
  while (str[y] != '\0')
    {
      if (str[y] != ' ')
	return (-1);
      y = y + 1;
    }
  return (1);
}

t_epur		algo_epur(char *str, t_epur var)
{
  while (str[var.i] != '\0')
    {
      if (str[var.i] != ' ' && str[var.i] != ';' && str[var.i] != '\t')
	var = norm_epur(var, str);
      else if ((str[var.i] == ' ' || str[var.i] == ';'
		|| str[var.i] == '\t') && var.indic == 0)
        {
	  if (str[var.i] == ';')
	    {
	      if (test_end(str, var.i + 1) == 1)
		return (var);
	      else
		var.new[var.y++] = ';';
	      var.i = var.i + 1;
	      var.indic = 1;
	    }
	  else if (str[var.i] == ' ' || str[var.i] == '\t')
	    var = space_epur(var, str);
        }
      else
        var.i = var.i + 1;
    }
  return (var);
}

t_epur		space_epur(t_epur var, char *str)
{
  while ((str[var.i] == ' ' || str[var.i] == '\t') && str[var.i] != '\0')
    var.i = var.i + 1;
  if (str[var.i] == ';')
    {
      if (test_end(str, var.i + 1) == 1)
	var.new[var.y] = '\0';
      else
	var.new[var.y++] = str[var.i++];
    }
  else if (str[var.i] != '\0')
    {
      var.new[var.y++] = ' ';
      var.new[var.y++] = str[var.i++];
    }
  return (var);
}

char		*epur_str(char *str)
{
  t_epur	var;

  var.indic = 0;
  var.i = 0;
  var.y = 0;
  if (str == NULL)
    exit(EXIT_FAILURE);
  if ((var.new = malloc(sizeof(char) * (my_strlen(str) + 1))) == NULL)
    return (NULL);
  while (str[var.i] != '\0' && (str[var.i] == ' ' || str[var.i] == '\t'))
    var.i = var.i + 1;
  if (str[var.i] == '\0')
    return (NULL);
  while (str[var.i] == ';' && str[var.i] != '\0')
    var.i = var.i + 1;
  if (str[var.i] == '\0')
    return (NULL);
  var = algo_epur(str, var);
  var.new[epur_end(var.new, var.y)] = '\0';
  free(str);
  return (var.new);
}
