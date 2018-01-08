/*
** check_node.c for 4ésh in /home/arthur/rendu/semestre2/PSU_2016/PSU_2015_42sh
** 
** Made by arthur
** Login   <chenne_a@epitech.net>
** 
** Started on  Thu May 26 16:43:58 2016 arthur
** Last update Mon Jun  6 10:55:38 2016 arthur
*/

#include <stdlib.h>
#include <stdio.h>
#include "minishell.h"

int		check_output_redirect_2(t_bin *node)
{
  if (my_strcmp(node->name, ">") == 1 || my_strcmp(node->name, ">>") == 1)
    {
      if (my_strcmp(node->right->name, ">") == 1 ||
	  my_strcmp(node->right->name, ">>") == 1)
	{
	  fprintf(stderr, "Ambiguous output redirect.\n");
	  ambig = 1;
	  return (-1);
	}
    }
  return (1);
}

int		check_output_redirect(t_bin *node)
{
  if (my_strcmp(node->name, "|") == 1)
    {
      if (my_strcmp(node->left->name, ">") == 1 ||
	  my_strcmp(node->left->name, ">>") == 1)
	{
	  fprintf(stderr, "Ambiguous output redirect.\n");
	  ambig = 1;
	  return (-1);
	}
      if ((my_strcmp(node->right->name, ">") == 1 ||
	   my_strcmp(node->right->name, ">>") == 1)
	  && (my_strcmp(node->left->name, ">") == 1 ||
	      my_strcmp(node->left->name, ">>") == 1))
	{
	  fprintf(stderr, "Ambiguous output redirect.\n");
	  ambig = 1;
	  return (-1);
	}
    }
  if (check_output_redirect_2(node) == -1)
    {
      ambig = 1;
      return (-1);
    }
  return (1);
}

int		check_input_redirect(t_bin *node)
{
  if (my_strcmp(node->name, "<") == 1 || my_strcmp(node->name, "<<") == 1)
    {
      if (my_strcmp(node->right->name, "<") == 1 ||
	  my_strcmp(node->right->name, "<<") == 1)
	{
	  fprintf(stderr, "Ambiguous input redirect.\n");
	  ambig = 1;
	  return (-1);
	}
    }
  return (1);
}

void		check_ambiguous(t_bin *node)
{
  if (node->right == NULL || node->left == NULL)
    return ;
  pipe_epur(node->name, NULL);
  pipe_epur(node->right->name, node->left->name);
  if (ambig == 0)
    check_output_redirect(node);
  if (ambig == 0)
    check_input_redirect(node);
}

int		check_node(t_bin *node, int i)
{
  if (node == NULL && i == 1)
    return (0);
  if (node == NULL && i == 0)
    {
      fprintf(stderr, "42sh: invalid NULL command\n");
      return (-1);
    }
  if ((node->left == NULL && node->right != NULL) ||
      (node->left != NULL && node->right == NULL))
    {
      fprintf(stderr, "42sh: invalid NULL command\n");
      return (-1);
    }
  if (check_node(node->right, 1) == -1)
    return (-1);
  if (check_node(node->left, 1) == -1)
    return (-1);
  return (0);
}
