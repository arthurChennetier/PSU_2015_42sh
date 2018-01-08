/*
** check_exit.c for 42sh in /home/chauvi_d/Rendu-2015-Epitech/rendu/Systunix/PSU_2015_42sh/build_in
** 
** Made by chauvi_d
** Login   <chauvi_d@epitech.net>
** 
** Started on  Sun Jun  5 17:01:05 2016 chauvi_d
** Last update Sun Jun  5 17:01:59 2016 chauvi_d
*/

#include <stdio.h>
#include <stdlib.h>
#include "minishell.h"
#include "get_next_line.h"
#include "print.h"

int	check_exit(int i, t_exec *var)
{
  if (i > 2)
    {
      my_putstr("exit: too many arguments\n");
      var->indic = 0;
      fail = 1;
      return (-1);
    }
  return (0);
}
