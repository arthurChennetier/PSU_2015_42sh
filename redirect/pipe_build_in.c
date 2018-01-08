/*
** pipe_build_in.c for 42sh in /home/arthur/rendu/semestre2/PSU_2016/PSU_2015_42sh
** 
** Made by arthur
** Login   <chenne_a@epitech.net>
** 
** Started on  Sat Jun  4 18:56:02 2016 arthur
** Last update Sat Jun  4 19:00:15 2016 arthur
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

int		check_right_build_in(char *str)
{
  int		i;
  char		*tmp;

  if ((tmp = malloc(sizeof(char) * (my_strlen(str) + 1))) == NULL)
    exit(EXIT_FAILURE);
  tmp = my_strcpy(tmp, str);
  i = 0;
  while (tmp[i] != ' ' && tmp[i])
    i = i + 1;
  tmp[i] = '\0';
  i = check_cmd(tmp);
  free(tmp);
  return (i);
}

void		build_in_pipe(t_exec *var, t_bin *node)
{
  t_exec	exec;
  int		i;

  i = check_right_build_in(node->name);
  exec.tab = my_str_to_wordtab(node->name);
  exec.s = node->name;
  build_in(i, exec, var);
}
