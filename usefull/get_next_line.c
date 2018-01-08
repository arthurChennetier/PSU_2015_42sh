/*
** get_next_line.c for get_next_line in /home/chenne_a/rendu/CPE_2015_getnextline
** 
** Made by Arthur Chennetier
** Login   <chenne_a@epitech.net>
** 
** Started on  Mon Jan  4 09:34:19 2016 Arthur Chennetier
** Last update Fri Jun  3 18:51:55 2016 arthur
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "get_next_line.h"
#include "minishell.h"

char		*my_realloc(char *str, int size_t)
{
  char		*tmp;
  int		j;

  j = 0;
  if (size_t == 0)
    {
      free(str);
      return (NULL);
    }
  tmp = malloc(sizeof(char) * size_t);
  if (tmp == NULL)
    return (NULL);
  while (j < size_t && str[j] != '\0')
    {
      tmp[j] = str[j];
      j = j + 1;
    }
  free(str);
  tmp[j] = '\0';
  return (tmp);
}

char	*check_read(int *i, int *size, int fd, char *buffer)
{
  if (*i == *size)
    {
      if ((*size = read(fd, buffer, READ_SIZE)) == -1 || *size == 0)
	{
	  free(buffer);
	  return (NULL);
	}
      *i = 0;
    }
  return (buffer);
}

char			get_next_char(const int fd)
{
  char	 		l;
  static int		i = 0;
  static int		size = -42;
  static char		*buffer;

  if (size == -42)
    {
      if ((buffer = malloc(sizeof(char) * READ_SIZE)) == NULL)
	exit(EXIT_FAILURE);
      if ((size = read(fd, buffer, READ_SIZE)) == -1 || size == 0)
	{
	  free(buffer);
	  return (4);
	}
    }
  if ((buffer = check_read(&i, &size, fd, buffer)) == NULL)
    return (4);
  l = buffer[i];
  i = i + 1;
  if (l == '\n')
    return (0);
  return (l);
}

char			*get_next_line(const int fd)
{
  char			*result;
  int			j;
  static int		indic = 0;

  j = 0;
  if (indic == 1 || READ_SIZE < 1)
    return (NULL);
  if ((result = malloc(sizeof(char) * READ_SIZE + 1)) == NULL)
    exit(EXIT_FAILURE);
  result[READ_SIZE] = '\0';
  while ((result[j] = get_next_char(fd)) != 0)
    {
      if (j % READ_SIZE == 0 && j != 0)
	result = my_realloc(result, READ_SIZE + j + 1);
      if (result[j] == 4)
	{
	  free(result);
	  exit(fail);
	}
      j = j + 1;
    }
  return (result);
}
