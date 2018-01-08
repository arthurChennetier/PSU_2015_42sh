/*
** echo_tilde.c for echo_tilde in /home/benama_m/PSU_2015_42sh/benama_m
** 
** Made by mahdi Benamar
** Login   <benama_m@epitech.net>
** 
** Started on  Wed May 25 19:51:11 2016 mahdi Benamar
** Last update Thu May 26 15:38:57 2016 mahdi Benamar
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "minishell.h"
#include "get_next_line.h"
#include "print.h"

char		*my_tilde(char *str, char **env)
{
  char		*tmp;
  char		*path;
  char		*user;

  if (strcmp(str, "~") == 0)
    {
      tmp = all_path("HOME", env, 4);
      return (tmp);
    }
  else if (my_strlen(str) > 1 && str[0] == '~')
    {
      path = the_variable(str, '~');
      user = all_path("USER", env, 4);
      if (strcmp(path, user) == 0)
	{
	  tmp = all_path("HOME", env, 4);
	  return (tmp);
	}
      else
	{
	  my_printf("Unknown user: %s.\n", path);
	  return (NULL);
	}
    }
  return (NULL);
}
