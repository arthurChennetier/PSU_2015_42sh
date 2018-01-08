/*
** simple_redirect.c for minishell2 in /home/arthur/rendu/semestre2/PSU_2016/PSU_2015_minishell2
** 
** Made by arthur
** Login   <chenne_a@epitech.net>
** 
** Started on  Mon Apr 11 13:08:03 2016 arthur
** Last update Mon Jun  6 10:56:45 2016 arthur
*/

#include <dirent.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "minishell.h"
#include "get_next_line.h"
#include "print.h"

void		redirect_case(t_exec *var, t_bin *node)
{
  int		fd;
  int		pid;
  int		status;

  if ((fd = open(node->right->name, O_RDWR | O_CREAT | O_TRUNC, 0664)) == -1)
    exit(EXIT_FAILURE);
  if ((pid = fork()) == -1)
    exit(EXIT_FAILURE);
  if (pid == 0)
    {
      dup2(fd, 1);
      check_exec_op(node->left, var);
      exit(EXIT_SUCCESS);
    }
  close(fd);
  waitpid(pid, &status, WUNTRACED | WCONTINUED);
}

void		double_redirect_case(t_exec *var, t_bin *node)
{
  int		fd;
  int		pid;
  int		status;

  if ((fd = open(node->right->name, O_APPEND | O_RDWR)) == -1)
    if ((fd = open(node->right->name, O_RDWR | O_CREAT, 0664)) == -1)
      exit(EXIT_FAILURE);
  if ((pid = fork()) == -1)
    exit(EXIT_FAILURE);
  if (pid == 0)
    {
      dup2(fd, 1);
      check_exec_op(node->left, var);
      exit(EXIT_SUCCESS);
    }
  close(fd);
  waitpid(pid, &status, WUNTRACED | WCONTINUED);
}

void		double_indirect_exec(int pid, int fd, t_bin *node, t_exec *var)
{
  if (pid == 0)
    {
      dup2(fd, 0);
      check_exec_op(node->left, var);
      exit(EXIT_SUCCESS);
    }
  close(fd);
}

void		double_indirect_case(t_exec *var, t_bin *node)
{
  char		*s;
  int		fd;
  int		pid;
  int		status;

  if ((fd = open(".indirect", O_RDWR | O_CREAT, 0664)) == -1)
    exit(EXIT_FAILURE);
      write(1, "? ", 2);
      while ((s = get_next_line(0)) && my_strcmp(s, node->right->name) != 1)
    {
      write(1, "? ", 2);
      write(fd, s, my_strlen(s));
      write(fd, "\n", 1);
    }
  close(fd);
  if ((fd = open(".indirect", O_RDONLY)) == -1)
    exit(EXIT_FAILURE);
  if ((pid = fork()) == -1)
    exit(EXIT_FAILURE);
  double_indirect_exec(pid, fd, node, var);
  waitpid(pid, &status, WUNTRACED | WCONTINUED);
  if ((remove(".indirect")) == -1)
    fprintf(stderr, "error while removing .indirect file\n");
}

void		indirect_case(t_exec *var, t_bin *node)
{
  int		fd;
  int		pid;
  int		status;

  if ((fd = open(node->right->name, O_RDONLY)) == -1)
    {
      fprintf(stderr, "%s: No such file or directory.\n", node->right->name);
      return ;
    }
  if ((pid = fork()) == -1)
    exit(EXIT_FAILURE);
  if (pid == 0)
    {
      dup2(fd, 0);
      check_exec_op(node->left, var);
      exit(EXIT_SUCCESS);
    }
  close(fd);
  waitpid(pid, &status, WUNTRACED | WCONTINUED);
}
