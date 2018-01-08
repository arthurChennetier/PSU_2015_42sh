/*
** small_functions.c for 42sh in /home/arthur/rendu/semestre2/PSU_2016/PSU_2015_42sh
** 
** Made by arthur
** Login   <chenne_a@epitech.net>
** 
** Started on  Fri Jun  3 12:13:13 2016 arthur
** Last update Fri Jun  3 12:21:13 2016 arthur
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

t_check		init_check(t_check exec, int i, int s_max)
{
  if (i == 0)
    {
      s_max = s_max;
      exec.j = 0;
      exec.i = 0;
    }
  if (i == 1)
    {
      exec.j = 0;
      exec.indic = 0;
      exec.i = exec.i + 1;
      closedir(exec.dir);
    }
  return (exec);
}
