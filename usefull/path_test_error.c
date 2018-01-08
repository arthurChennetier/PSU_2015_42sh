/*
** exit_norm.c for minishell2 in /home/arthur/rendu/semestre2/PSU_2016/PSU_2015_minishell2
** 
** Made by arthur
** Login   <chenne_a@epitech.net>
** 
** Started on  Tue Apr 12 14:04:59 2016 arthur
** Last update Sun Jun  5 14:00:11 2016 arthur
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

char		**bad_exit(char **env)
{
  fprintf(stderr, "exit: Expression Syntax.\n");
  return (env);
}

t_epur		norm_epur(t_epur var, char *str)
{
  var.new[var.y++] = str[var.i++];
  var.indic = 0;
  return (var);
}

void		test_siggsev(int status, char **path)
{
  if (WIFSIGNALED(status) && WTERMSIG(status) == SIGSEGV)
    fprintf(stderr, "Erreur de Segmentation\n");
  if (path != NULL)
    free_path(path);
}

void		path_case(t_exec exec, t_exec *var)
{
  t_path	size_carac;

  if ((exec.path = init_path(var->env)) == NULL)
    {
      fprintf(stderr, "Problem while loading PATH\n");
      var->indic = 1;
      fail = 1;
      return ;
    }
  size_carac.s_max = my_double_strlen(exec.path);
  exec.indic = check_exec(exec.tab[0], exec.path, size_carac.s_max);
  if (exec.indic == -1)
    {
      fprintf(stderr, "%s: Command not found.\n", exec.tab[0]);
      fail = 1;
      var->indic = 1;
    }
  else if (fork() == 0 && exec.indic != -1)
    {
      exec.new = create_path(exec.tab[0], exec.path[exec.indic]);
      execve(exec.new, exec.tab, var->env);
    }
  else
    waitpid(exec.pid, &exec.status, WUNTRACED | WCONTINUED);
  test_siggsev(exec.status, exec.path);
}

t_path		init_path_var(t_path param)
{
  param.k = 0;
  param.i = 0;
  return (param);
}
