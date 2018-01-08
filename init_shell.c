/*
** init_shell.c for 42sh in /home/chauvi_d/Rendu-2015-Epitech/rendu/Systunix/PSU_2015_42sh
** 
** Made by chauvi_d
** Login   <chauvi_d@epitech.net>
** 
** Started on  Sun Jun  5 19:35:29 2016 chauvi_d
** Last update Sun Jun  5 19:58:20 2016 chauvi_d
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

t_exec	init_shell(t_exec var, char **env)
{
  if (env[0] == NULL)
    var.env = prepare_env();
  else
    var.env = env;
  if ((hist = create_history(".42_history")) == NULL)
    {
      my_printf("history: File is not readdable\n");
      exit(1);
    }
  if (isatty(0))
    my_putstr("[MY_SHELL] ------> ");
  return (var);
}
