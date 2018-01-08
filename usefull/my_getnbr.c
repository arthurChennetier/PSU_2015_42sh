/*
** my_getnbr.c for my_getnbr in /home/chenne_a/rendu/CPE_2015_Pushswap/lib/push
** 
** Made by Arthur Chennetier
** Login   <chenne_a@epitech.net>
** 
** Started on  Fri Nov 20 15:16:01 2015 Arthur Chennetier
** Last update Thu Apr  7 17:28:41 2016 arthur
*/

#include <stdlib.h>
#include "minishell.h"

void	free_exec(t_exec build, char **env)
{
  int	i;

  i = 0;
  env = env;
  free(build.s);
  while (build.tab[i] != NULL)
    {
      free(build.tab[i]);
      i = i + 1;
    }
}

int	test_exit(char *str)
{
  int	i;

  i = 0;
  if (str[i] == '-')
    i = i + 1;
  while (str[i] != '\0')
    {
      if (str[i] < '0' || str[i] > '9')
	return (-1);
      i = i + 1;
    }
  return (1);
}

int	my_getnbr(char *str)
{
  int	i;
  int	nbr;
  int	sign;

  i = 0;
  nbr = 0;
  sign = 1;
  while (str[i] < '0' || str[i] > '9')
    {
      if (str[i] == '\0')
	return (0);
      i = i + 1;
    }
  if (i > 0)
    if (str[i - 1] == '-')
      sign = -1;
  while (str[i] >= '0' && str[i] <= '9')
    {
      if (str[i] == '\0')
	return (nbr * sign);
      nbr = nbr * 10 + str[i] - '0';
      i = i + 1;
    }
  return (nbr * sign);
}
