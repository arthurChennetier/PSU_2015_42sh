/*
** flags_history.c for 42sh in /home/chauvi_d/Rendu-2015-Epitech/rendu/Systunix/for42/build_in
** 
** Made by chauvi_d
** Login   <chauvi_d@epitech.net>
** 
** Started on  Sat Jun  4 16:58:04 2016 chauvi_d
** Last update Sun Jun  5 19:29:21 2016 chauvi_d
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

int	clear_history(char *str, char *flag, int j)
{
  str = str;
  flag = flag;
  j = j;
  my_free_list(&hist);
  hist = my_init_l();
  return (0);
}

int	simple_history(char *str, char *flag, int j)
{
  int	i;

  if ((i = check_np_flag(flag, 'h', j, str)) ==  -2)
    return (0);
  if (i == -1)
    return (-1);
  if (str != NULL)
    {
      if (strlen(str) > 0 && is_num(str) == -1)
	{
	  my_printf("history: Badly formed number.\n");
	  return (-1);
	}
      if (strlen(str) > 0)
	putn_list_simple(hist, my_getnbr(str));
    }
  else
    putn_list_simple(hist, hist->length);
  return (0);
}

int	reverse_history(char *str, char *flag, int j)
{
  int	i;

  if ((i = check_np_flag(flag, 'r', j, str)) ==  -2)
    return (0);
  else if (i == -1)
    return (-1);
  if (str != NULL)
    {
      if (my_strlen(str) > 0 && is_num(str) == -1)
      {
	my_printf("history: Badly formed number.\n");
	return (-1);
      }
      if (strlen(str) > 0)
	putn_list_reverse(hist, my_getnbr(str));
    }
  else
    putn_list_reverse(hist, hist->length);
  return (0);
}

int		save_history(char *str, char *flag, int j)
{
  struct stat	sb;

  flag = flag;
  j = j;
  if (str != NULL && my_strlen(str) > 0)
    {
      if (stat(str, &sb) != -1)
	{
	  if ((sb.st_mode & S_IFMT) == S_IFREG)
	    {
	      if (my_strlen(str) > 0)
		if (write_history(hist, str) == -1)
		  return (-1);
	    }
	  else
	    if (write_history(hist, ".42_history") == -1)
	      return (-1);
	}
    }
  else
    if (write_history(hist, ".42_history") == -1)
      return (-1);
  return (0);
}

int		load_history(char *str, char *flag, int j)
{
  t_dlist	*tmp;

  tmp = hist;
  flag = flag;
  j = j;
  if (str != NULL && my_strlen(str) > 0)
    {
      if (load_history_extend(str, tmp) == -1)
	return (-1);
    }
  else if ((hist = create_history(".42_history")) == NULL)
    {
      hist = tmp;
      return (-1);
    }
  return (0);
}
