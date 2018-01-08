/*
** my_putchar.c for my_putchar in /home/chenne_a/rendu/PSU_2015_my_printf/lib/my
** 
** Made by Arthur Chennetier
** Login   <chenne_a@epitech.net>
** 
** Started on  Mon Nov  9 12:04:11 2015 Arthur Chennetier
** Last update Fri Dec 18 17:12:33 2015 Arthur Chennetier
*/

#include <unistd.h>

void	my_putchar(char c)
{
  write(1, &c, 1);
}
