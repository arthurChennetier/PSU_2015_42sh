/*
** my_strlen.c for my_strlen in /home/chenne_a/rendu/Piscine_C_J04
** 
** Made by Arthur Chennetier
** Login   <chenne_a@epitech.net>
** 
** Started on  Thu Oct  1 16:15:50 2015 Arthur Chennetier
** Last update Sun Jan 24 15:43:24 2016 Arthur Chennetier
*/

#include <stdlib.h>

int		my_strlen(char *str)
{
  int		i;

  i = 0;
  while (str[i] != '\0')
    i = i + 1;
  return (i);
}
