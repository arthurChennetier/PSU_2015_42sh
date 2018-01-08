/*
** time.c for 42sh in /home/chauvi_d/Rendu-2015-Epitech/rendu/Systunix/for42/history
** 
** Made by chauvi_d
** Login   <chauvi_d@epitech.net>
** 
** Started on  Sun Jun  5 14:41:52 2016 chauvi_d
** Last update Sun Jun  5 14:43:54 2016 chauvi_d
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include <string.h>

char		*parse_time(char *time)
{
  int		j;
  int		i;
  int		space;
  char		*new_time;

  i = 0;
  space = 0;
  j = 0;
  if ((new_time = malloc(sizeof(char) * (strlen(time) + 1))) == NULL)
    return (NULL);
  while (time[i] && space != 4)
    {
      if (time[i] == ' ')
	space++;
      i++;
    }
  while (time[i] != ' ' && time[i])
    new_time[j++] = time[i++];
  new_time[j - 3] = 0;
  return (new_time);
}

char		*my_time()
{
  time_t        timer;
  char		*tim;
  char		*new_time;

  timer = time(NULL);
  tim = asctime(localtime(&timer));
  new_time = parse_time(tim);
  return (new_time);
}
