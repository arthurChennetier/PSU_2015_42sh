/*
** multi_pipe.c for 42sh in /home/arthur/rendu/semestre2/PSU_2016/PSU_2015_42sh
** 
** Made by arthur
** Login   <chenne_a@epitech.net>
** 
** Started on  Wed May 18 16:20:01 2016 arthur
** Last update Sat Jun  4 22:46:14 2016 arthur
*/

#include <stdlib.h>
#include "print.h"
#include "minishell.h"

void		current_exec_no_fork(t_exec *var, char **tab)
{
  char		*new;
  int		i;
  int		j;

  j = 0;
  i = 2;
  if ((new = malloc(sizeof(char) * my_strlen(tab[0]))) == NULL)
    exit(EXIT_FAILURE);
  while (tab[0][i] != '\0')
    {
      new[j] = tab[0][i];
      j = j + 1;
      i = i + 1;
    }
  new[j] = '\0';
  if (access(new, F_OK) == -1)
    {
      fprintf(stderr, "Wrong pathfile for execution : %s\n", tab[0]);
      var->indic = 1;
      exit(1);
    }
  else
    execve(new, tab, var->env);
}

void		path_exec_no_fork(t_exec *var, char **tab)
{
  if (access(tab[0], F_OK) == -1 || my_strlen(tab[0]) == 1)
    {
      fprintf(stderr, "Wrong pathfile for execution : %s\n", tab[0]);
      var->indic = 1;
      exit(1);
    }
  else
    execve(tab[0], tab, var->env);
}

void		direct_exec_no_fork(char **tab, t_exec *var)
{
  if (tab[0][0] == '.' && my_strlen(tab[0]) > 2)
    current_exec_no_fork(var, tab);
  else if (tab[0][0] == '/')
    path_exec_no_fork(var, tab);
  else
    {
      fprintf(stderr, "Wrong pathfile for execution : %s\n", tab[0]);
      var->indic = 1;
      exit(1);
    }
}

int		path_case_no_fork(t_exec exec, t_exec *var)
{
  t_path	size_carac;

  if ((exec.path = init_path(var->env)) == NULL)
    {
      fprintf(stderr, "Problem while loading PATH\n");
      var->indic = 1;
      fail = 1;
      exit(EXIT_FAILURE);
    }
  size_carac.s_max = my_double_strlen(exec.path);
  exec.indic = check_exec(exec.tab[0], exec.path, size_carac.s_max);
  if (exec.indic == -1)
    {
      fprintf(stderr, "%s: Command not found.\n", exec.tab[0]);
      var->indic = 0;
      exit(1);
    }
  else
    {
      exec.new = create_path(exec.tab[0], exec.path[exec.indic]);
      execve(exec.new, exec.tab, var->env);
    }
  return (1);
}

void		exec_no_fork(t_exec *var, t_bin *node)
{
  t_exec	exec;
  int		i;

  exec.direct = 0;
  exec.pid = 0;
  exec.env = var->env;
  exec.s = node->name;
  exec.tab = my_str_to_wordtab(node->name);
  exec.tab = my_glob(exec.tab);
  if ((i = check_cmd(exec.tab[0])) != -1)
    {
      build_in(i, exec, var);
      exit(EXIT_SUCCESS);
    }
  else if ((exec.tab[0][0] == '/' || exec.tab[0][0] == '.')
	   && my_strlen(exec.tab[0]) > 2)
    direct_exec_no_fork(exec.tab, var);
  else
    path_case_no_fork(exec, var);
}
