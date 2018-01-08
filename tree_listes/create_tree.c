/*
** create_tree.c for minishell2 in /home/arthur/rendu/semestre2/PSU_2016/PSU_2015_minishell2
** 
** Made by arthur
** Login   <chenne_a@epitech.net>
** 
** Started on  Mon Apr  4 16:29:45 2016 arthur
** Last update Sun Jun  5 13:43:38 2016 arthur
*/

#include <stdio.h>
#include <stdlib.h>
#include "minishell.h"

t_op            red_tab[] =
{
  {";", 1, &semicolon_case},
  {"&&", 2, &double_and_case},
  {"|", 1, &pipe_case},
  {"||", 2, &double_pipe_case},
  {">", 1, &redirect_case},
  {">>", 2, &double_redirect_case},
  {"<", 1, &indirect_case},
  {"<<", 2, &double_indirect_case},
  {NULL, 0, NULL}
};

int		pos_search(char *str, int *op, int i)
{
  *op = 0;
  while (red_tab[*op].str != NULL)
    {
      while (str[i++] != '\0')
	{
	  if (str[i] == red_tab[*op].str[0])
	    {
	      if (str[i + 1] != '\0')
		{
		  if (str[i + 1] == str[i])
		    {
		      while (red_tab[*op].str[1] != str[i + 1])
			*op = *op + 1;
		    }
		  return (i);
		}
	      else
		return (i);
	    }
	}
      *op = *op + 1;
      i = 0;
    }
  return (-1);
}

char		*right_div(char *str, int pos)
{
  char		*new;
  int		i;

  i = 0;
  if ((new = malloc(sizeof(char) * (my_strlen(str) - pos + 1))) == NULL)
    exit(EXIT_FAILURE);
  while (str[pos] == ' ' && str[pos] != '\0')
    pos = pos + 1;
  while (str[pos] != '\0')
    {
      new[i] = str[pos];
      i = i + 1;
      pos = pos + 1;
    }
  new[i] = '\0';
  if (i == 0)
    return (NULL);
  return (new);
}

t_bin		*end_node(char *str, t_bin *node)
{
  node->name = str;
  node->left = NULL;
  node->right = NULL;
  return (node);
}

t_bin		*create_tree(char *str, int pos_op, int n_op)
{
  t_bin		*node;
  char		*new;

  if (str == NULL)
    return (NULL);
  if ((node = malloc(sizeof(t_bin))) == NULL)
    exit(EXIT_FAILURE);
  pos_op = pos_search(str, &n_op, 0);
  if (pos_op == -1)
    node = end_node(str, node);
  else
    {
      if ((node->name =
	   malloc(sizeof(char) * (my_strlen(red_tab[n_op].str) + 1))) == NULL)
	exit(EXIT_FAILURE);
      node->name = my_strcpy(node->name, red_tab[n_op].str);
      new = right_div(str, pos_op + red_tab[n_op].size);
      str[pos_op] = '\0';
      if (pos_op == 0)
	return (NULL);
      node->left = create_tree(str, 0, 0);
      node->right = create_tree(new, 0, 0);
      check_ambiguous(node);
    }
  return (node);
}
