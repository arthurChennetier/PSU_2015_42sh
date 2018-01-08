/*
** list.c for list in /home/clement/Test_Perso/42
** 
** Made by clement
** Login   <clement@clement-HP-EliteBook-840-G2>
** 
** Started on  Mon May 30 17:02:50 2016 clement
** Last update Sun Jun  5 19:45:51 2016 chauvi_d
*/

#include <stdio.h>
#include <stdlib.h>
#include "minishell.h"

void	my_free_list(t_dlist **list)
{
  t_list	*tmp_elem;
  t_list	*next;
  int		count;

  count = (*list)->length;
  tmp_elem = (*list)->head;
  while (count != 0)
    {
      next = tmp_elem->next;
      free(tmp_elem);
      tmp_elem = next;
      count = count - 1;
    }
  free(*list);
  *list = NULL;
}

t_dlist	*add_last_elem(t_dlist *list, t_list *element)
{
  if (list != NULL)
    {
      if (element != NULL)
      {
	if (list->head == NULL)
	  {
	    list->head = element;
	    element->next = element;
	    element->prev = element;
	    list->length = 1;
	  }
	else
	  {
	    element->prev = list->head->prev;
	    list->head->prev->next = element;
	    list->head->prev = element;
	    element->next = list->head;
	    list->length = list->length + 1;
	  }
      }
    }
  return (list);
}

t_dlist *my_init_l()
{
  t_dlist	*list;

  list = malloc(sizeof (*list));
  if (list == NULL)
    exit(EXIT_FAILURE);
  else
    {
      list->length = 0;
      list->nb_com = 0;
      list->head = NULL;
    }
  return (list);
}

t_dlist *my_del_elem(t_dlist *list, t_list *element)
{
  if (element == list->head)
    {
      list->head = element->next;
      element->prev->next = element->next;
      element->next->prev = element->prev;
    }
  else
    {
      element->prev->next = element->next;
      element->next->prev = element->prev;
    }
  free(element);
  list->length = list->length - 1;
  list->nb_com = list->nb_com -1;
  if (list->length == 0)
      exit(EXIT_SUCCESS);
  return (list);
}
