/*
** double_pipe_and.c for 42sh in /home/arthur/rendu/semestre2/PSU_2016/PSU_2015_42sh
** 
** Made by arthur
** Login   <chenne_a@epitech.net>
** 
** Started on  Thu May 26 12:15:54 2016 arthur
** Last update Sun Jun  5 13:39:46 2016 arthur
*/

#include <stdio.h>
#include "minishell.h"

void		double_and_case(t_exec *var, t_bin *node)
{
  t_exec	exec;

  pipe_epur(node->left->name, node->right->name);
  exec.pid = 0;
  exec.direct = 0;
  exec.env = var->env;
  if (node->left != NULL)
    side_case(var, node->left, exec);
  if (node->right != NULL && var->indic == 0 && fail == 0)
    side_case(var, node->right, exec);
}

void		double_pipe_case(t_exec *var, t_bin *node)
{
  t_exec	exec;

  pipe_epur(node->left->name, node->right->name);
  exec.pid = 0;
  exec.direct = 0;
  exec.env = var->env;
  if (node->left != NULL)
    side_case(var, node->left, exec);
  if (node->right != NULL && var->indic == 1 && fail == 1)
    side_case(var, node->right, exec);
}
