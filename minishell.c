/*
** minishell.c for minishell in /home/chenne_a/rendu/PSU_tek1/PSU_2015_minishell1/bootstrap
** 
** Made by Arthur Chennetier
** Login   <chenne_a@epitech.net>
** 
** Started on  Wed Jan 13 15:44:03 2016 Arthur Chennetier
** Last update Mon Jun  6 10:58:06 2016 arthur
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

int		check_exec(char *s, char **path, int s_max)
{
  t_check	exec;

  exec.indic = 0;
  exec = init_check(exec, 0, s_max);
  while (path[exec.i] != NULL)
    {
      if ((exec.dir = opendir(path[exec.i])) == NULL)
	exec.indic = 1;
      if (exec.indic != 1)
	{
	  if ((exec.info = readdir(exec.dir)) == NULL)
	    return (-1);
	  while (exec.j != -1 && exec.j != 1)
	    {
	      if (my_strcmp(exec.info->d_name, s) == 1)
		exec.j = 1;
	      if ((exec.info = readdir(exec.dir)) == NULL)
		exec.j = -1;
	    }
	  if (exec.j == 1)
	    return (send_j(exec.i, exec.dir));
	}
      exec = init_check(exec, 1, s_max);
    }
  return (-1);
}

void		check_exec_op(t_bin *node, t_exec *exec)
{
  int		i;

  i = 0;
  while (red_tab[i].str != NULL)
    {
      if (my_strcmp(red_tab[i].str, node->name) == 1)
	{
	  if (node->right != NULL && node->left != NULL)
	    red_tab[i].ptr(exec, node);
	  return ;
	}
      i = i + 1;
    }
  exec_no_fork(exec, node);
}

int		first_check_tree(char *name)
{
  int		i;

  i = 0;
  while (red_tab[i].str != NULL)
    {
      if (my_strcmp(red_tab[i].str, name) == 1)
	return (-1);
      i = i + 1;
    }
  return (1);
}

t_exec		exec(char *s, t_exec var)
{
  t_bin		*node;
  t_use		*use;
  t_exec	exec;

  exec.env = var.env;
  exec.indic = 0;
  ambig = 0;
  fail = 0;
  if ((use = malloc(sizeof(t_use))) == NULL)
    exit(EXIT_FAILURE);
  node = create_tree(s, 0, 0);
  if (check_node(node, 0) == -1)
    return (exec);
  if (first_check_tree(node->name) == -1 && ambig == 0)
    check_exec_op(node, &exec);
  else if (ambig == 0)
    simple_exec(node, &exec);
  return (exec);
}

int		main(int argc, char **argv, char **env)
{
  t_exec	var;
  char		*s;

  (void)argc;
  (void)argv;
  env = env;
  var = init_shell(var, env);
  while (42)
    {
      s = epur_str(get_next_line(0));
      if ((s = cmd(s)) != NULL)
	{
	  if ((hist = put_in_history(s, hist)) == NULL)
	    return (1);
	  fail = 0;
	  if (s != NULL)
	    {
	      var = exec(s, var);
	      free(s);
	    }
	}
	  if (isatty(0))
	    my_putstr("[MY_SHELL] ------> ");
    }
  return (0);
}
