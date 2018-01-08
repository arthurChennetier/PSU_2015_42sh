/*
** my.h for my in /home/chenne_a/rendu/Piscine_C_J09/include
** 
** Made by Arthur Chennetier
** Login   <chenne_a@epitech.net>
** 
** Started on  Thu Oct  8 10:44:13 2015 Arthur Chennetier
** Last update Sun Jan 24 15:35:04 2016 Arthur Chennetier
*/

#ifndef PRINT_H_
# define PRINT_H_

#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>

typedef	struct	s_print
{
  int		(*str)(va_list);
  char		*flags;
}		t_print;

int	long_long(va_list va);
void	my_putstr(char *str);
int	my_put_nbr_base8S(unsigned int nb);
int	my_putstr_S(va_list va);
int	my_put_nbr_base8(va_list va);
int	my_put_nbr_base16maj(va_list va);
int	my_put_nbr_base2(va_list va);
int	my_put_nbr_base16(va_list va);
int	my_put_unva(va_list va);
int	my_printf(const char *str, ...);
void	my_putchar(char c);
int	my_putchar_va(va_list va);
int	my_put_nbr_va(va_list va);
int	my_putstr_va(va_list va);
int	my_strlen(char *str);

#endif /* !PRINT_H_ */
