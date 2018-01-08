/*
** redirect_functions.c for minishell2 in /home/arthur/rendu/semestre2/PSU_2016/PSU_2015_minishell2
** 
** Made by arthur
** Login   <chenne_a@epitech.net>
** 
** Started on  Wed Apr  6 16:36:06 2016 arthur
** Last update Tue Jun  7 15:13:47 2016 arthur
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

void		pipe_epur(char *right, char *left)
{
  int		i;

  if (right != NULL)
    {
      i = my_strlen(right) - 1;
      if (right[i] == ' ')
	right[i] = '\0';
    }
  if (left != NULL)
    {
      i = my_strlen(left) - 1;
      if (left[i] == ' ')
	left[i] = '\0';
    }
}

void		first_pipe(int *fd, t_exec *var, t_bin *node)
{
  close(fd[0]);
  dup2(fd[1], 1);
  check_exec_op(node->left, var);
  exit(0);
}

void		second_pipe(int *fd, t_exec *var, t_bin *node)
{
  close(fd[1]);
  dup2(fd[0], 0);
  check_exec_op(node->right, var);
  exit(0);
}

void		end_pipe(int *fd, int pid, int status)
{
  close(fd[0]);
  close(fd[1]);
  waitpid(pid, &status, WUNTRACED | WCONTINUED);
  if (status % 256 == 0)
    fail = 0;
}

void		pipe_case(t_exec *var, t_bin *node)
{
  int		fd[2];
  int		pid;
  int		status;

  fail = 1;
  status = -1;
  if (pipe(fd) == -1 || (pid = fork()) == -1)
    exit(EXIT_FAILURE);
  if (pid == 0)
    first_pipe(fd, var, node);
  else
    {
      if (check_right_build_in(node->right->name) == -1)
	{
	  if ((pid = fork()) == 0)
	    second_pipe(fd, var, node);
	}
      else
	build_in_pipe(var, node->right);
    }
  end_pipe(fd, pid, status);
}
