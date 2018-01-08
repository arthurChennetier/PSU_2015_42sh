/*
** semicolon_case.c for minishell2 in /home/arthur/rendu/semestre2/PSU_2016/PSU_2015_minishell2
** 
** Made by arthur
** Login   <chenne_a@epitech.net>
** 
** Started on  Fri Apr  8 17:40:52 2016 arthur
** Last update Sun Jun  5 13:57:14 2016 arthur
*/

#include <dirent.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "minishell.h"
#include "get_next_line.h"
#include "print.h"

void		simple_exec(t_bin *node, t_exec *var)
{
  t_exec	exec;
  int           i;

  exec.direct = 0;
  exec.pid = 0;
  exec.env = var->env;
  exec.s = node->name;
  exec.status = -1;
  exec.tab = my_str_to_wordtab(node->name);
  exec.tab = my_glob(exec.tab);
  if ((i = check_cmd(exec.tab[0])) != -1)
    build_in(i, exec, var);
  else if (direct_exec(exec.tab, var) == -1)
    path_case(exec, var);
}

void		side_case(t_exec *var, t_bin *node, t_exec exec)
{
  exec.s = node->name;
  exec.tab = my_str_to_wordtab(node->name);
  exec = exec;
  if (first_check_tree(node->name) == -1)
    check_exec_op(node, var);
  else
    simple_exec(node, var);
}

void		semicolon_case(t_exec *var, t_bin *node)
{
  t_exec        exec;

  exec.direct = 0;
  exec.pid = 0;
  exec.env = var->env;
  var->indic = 0;
  if (node->left != NULL)
    side_case(var, node->left, exec);
  var->indic = 0;
  if (node->right != NULL)
    side_case(var, node->right, exec);
}
