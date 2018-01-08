/*
** useful.c for minishell in /home/chenne_a/rendu/PSU_tek1/PSU_2015_minishell1/bootstrap
** 
** Made by Arthur Chennetier
** Login   <chenne_a@epitech.net>
** 
** Started on  Thu Jan 14 16:40:30 2016 Arthur Chennetier
** Last update Sun Jun  5 16:58:54 2016 chauvi_d
*/

#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <dirent.h>
#include <stdio.h>
#include "minishell.h"

char		*my_strcpy(char *dest, char *src)
{
  int		i;

  i = 0;
  if (src == NULL)
    return (NULL);
  if (dest == NULL)
    dest = malloc(sizeof(char) * (my_strlen(src) + 1));
  if (dest == NULL)
    return (NULL);
  while (src[i] != '\0')
    {
      dest[i] = src[i];
      i = i + 1;
    }
  dest[i] = '\0';
  return (dest);
}

int		send_j(int i, DIR *dir)
{
  closedir(dir);
  return (i);
}

int		my_strlen(char *str)
{
  int		i;

  if (str == NULL)
    return (0);
  i = 0;
  while (str[i] != '\0')
    i = i + 1;
  return (i);
}

int		my_strcmp(char *src, char *cmp)
{
  int		i;

  i = 0;
  if (my_strlen(src) != my_strlen(cmp))
    return (-1);
  while (src[i] != '\0')
    {
      if (src[i] != cmp[i])
        return (-1);
      i = i + 1;
    }
  return (1);
}

int		tab_len(char **tab)
{
  int		i;

  i = -1;
  while (tab[++i]);
  return (i);
}
