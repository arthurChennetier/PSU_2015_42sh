/*
** my_strcat.c for my_strcat in /home/clement/Test_Perso/42/PSU_2015_42sh
** 
** Made by clement
** Login   <clement@clement-HP-EliteBook-840-G2>
** 
** Started on  Fri Jun  3 11:55:18 2016 clement
** Last update Sun Jun  5 15:50:49 2016 arthur
*/

#include <stdlib.h>
#include "minishell.h"

char	*my_strcat(char *str1, char *str2)
{
  char	*arr;
  int	i;
  int	j;

  j = 0;
  i = 0;
  if ((arr = malloc(sizeof(char) * (my_strlen(str1) + my_strlen(str2) + 2)))
      == NULL)
    return (NULL);
  while (str1[i])
    {
      arr[i] = str1[i];
      i++;
    }
  while (str2[j])
    arr[i++] = str2[j++];
  arr[i] = '\0';
  return (arr);
}
