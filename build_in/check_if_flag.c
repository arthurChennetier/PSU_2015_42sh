/*
** check_if_flag.c for 42sh in /home/chauvi_d/Rendu-2015-Epitech/rendu/Systunix/PSU_2015_42sh
** 
** Made by chauvi_d
** Login   <chauvi_d@epitech.net>
** 
** Started on  Sun Jun  5 18:24:47 2016 chauvi_d
** Last update Sun Jun  5 19:30:26 2016 chauvi_d
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include "get_next_line.h"
#include "minishell.h"
#include "print.h"

int	simple_reverse_history(char *str)
{
  if (str != NULL)
    {
      if (strlen(str) > 0 && is_num(str) == -1)
	{
	  my_printf("history: Badly formed number.\n");
	  return (-1);
	}
      if (strlen(str) > 0)
	putn_list_simple_r(hist, my_getnbr(str));
    }
  else
    putn_list_simple_r(hist, hist->length);
  return (0);
}

int	check_r(int pos_h, int pos_r, char *str, char c)
{
  if (pos_r > pos_h && c == 'r')
    {
      if (pos_h != 0)
	{
	  if (simple_reverse_history(str) == -1)
	    return (-1);
	  return (-2);
	}
      else
	return (0);
    }
  return (-2);
}

int	check_h(int pos_h, int pos_r, char *str, char c)
{
  if (pos_h > pos_r && c == 'h')
    {
      if (pos_r != 0)
	{
	  if (simple_reverse_history(str) == -1)
	    return (-1);
	  return (-2);
	}
      else
	return (0);
    }
  return (-2);
}

int	check_np_flag(char *flag, char c, int j, char *str)
{
  int	pos_h;
  int	pos_r;
  int	i;

  pos_r = 0;
  pos_h = 0;
  i = 0;
  while (flag[i])
    {
      if (flag[i] == 'h')
	pos_h = i;
      if (flag[i] == 'r')
	pos_r = i;
      i++;
    }
  if (c == 'h' && pos_h > j)
    return (-2);
  else if (c == 'r' && pos_r > j)
    return (-2);
  i = check_h(pos_h, pos_r, str, c);
  i = check_r(pos_h, pos_r, str, c);
  return (i);
}

int		load_history_extend(char *str, t_dlist *tmp)
{
  struct stat	sb;

  if (stat(str, &sb) != -1)
    {
      if ((sb.st_mode & S_IFMT) == S_IFREG)
	{
	  if ((hist = create_history(str)) == NULL)
	    {
	      hist = tmp;
	      return (-1);
	    }
	}
    }
  else
    {
      if ((hist = create_history(".42_history")) == NULL)
	{
	  hist = tmp;
	  return (-1);
	}
    }
  return (0);
}
