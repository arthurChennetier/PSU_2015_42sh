/*
** put_simple_list.c for 42sh in /home/chauvi_d/Rendu-2015-Epitech/rendu/Systunix/PSU_2015_42sh
** 
** Made by chauvi_d
** Login   <chauvi_d@epitech.net>
** 
** Started on  Sun Jun  5 18:12:00 2016 chauvi_d
** Last update Sun Jun  5 19:28:56 2016 chauvi_d
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "get_next_line.h"
#include "minishell.h"
#include "print.h"

void            putn_list_simple(t_dlist *list, int n)
{
  t_list        *elem;
  int           num;

  num = list->length;
  elem = list->head;
  while (n != 0 && num >= 0)
    {
      my_printf("   %d  %s\n", elem->n, elem->name);
      elem = elem->next;
      num--;
      n--;
    }
}

void            putn_list_simple_r(t_dlist *list, int n)
{
  t_list        *elem;
  int           num;

  num = list->length;
  elem = list->head->prev;
  while (n != 0 && num >= 0)
    {
      my_printf("   %d  %s\n", elem->n, elem->name);
      elem = elem->prev;
      num--;
      n--;
    }
}
