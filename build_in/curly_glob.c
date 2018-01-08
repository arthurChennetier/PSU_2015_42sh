/*
** curly_glob.c for curly in /home/benama_m/PSU_2015_42sh
** 
** Made by mahdi Benamar
** Login   <benama_m@epitech.net>
** 
** Started on  Mon May 30 18:35:41 2016 mahdi Benamar
** Last update Sun Jun  5 17:04:46 2016 chauvi_d
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <glob.h>
#include "minishell.h"
#include "get_next_line.h"
#include "print.h"

int		curly(char *str)
{
  int		i;

  if (you_can_curly(str) == 1)
    {
      while (str[i])
	{
	  if (str[i] == '{')
	    str[i] = '[';
	  if (str[i] == '}')
	    str[i] = ']';
	  i += 1;
	}
    }
  else
    return (-1);
  return (0);
}

int		you_can_curly(char *str)
{
  int		i;
  int		curly_star;

  i = curly_star = 0;
  while (str[i])
    {
      if (str[i] == '{' || str[i] == '}')
	curly_star += 1;
      i += 1;
    }
  if (curly_star == 2)
    return (1);
  else
    return (0);
}
