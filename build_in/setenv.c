/*
** setenv.c for minishell2 in /home/arthur/rendu/semestre2/PSU_2016/PSU_2015_minishell2
** 
** Made by arthur
** Login   <chenne_a@epitech.net>
** 
** Started on  Tue Apr 12 13:39:31 2016 arthur
** Last update Sat Jun  4 15:28:50 2016 arthur
*/

#include <stdlib.h>
#include "get_next_line.h"
#include "minishell.h"
#include "print.h"

t_list		*empty_node(char **tab)
{
  t_list	*node;
  int		i;
  int		j;

  j = 0;
  i = 0;
  if ((node = malloc(sizeof(t_list))) == NULL)
    exit(EXIT_FAILURE);
  if ((node->name = malloc(sizeof(char) * (my_strlen(tab[1]) + 1))) == NULL)
    exit(EXIT_FAILURE);
  while (tab[1][i] != '\0')
    {
      node->name[i] = tab[1][i];
      i = i + 1;
    }
  node->name[i++] = '=';
  if (tab[2] != NULL)
    while (tab[2][j] != '\0')
      node->name[i++] = tab[2][j++];
  node->name[i] = '\0';
  node->next = NULL;
  node->prev = NULL;
  return (node);
}

void		my_setenv(t_exec build, t_exec *var)
{
  t_list	*node;
  int		i;
  char		**tab;

  tab = prepare_setenv(build.tab[1]);
  i = 0;
  if (var->env[0] == NULL)
    var->env = prepare_env();
  node = create_list(var->env);
  del_env(tab, node);
  while (build.tab[i] != NULL)
    i = i + 1;
  if (i > 3)
    {
      var->indic = 0;
      fail = 1;
      my_putstr("setenv: Too many arguments.\n");
    }
  else if (i == 1)
    my_env(build, var);
  else if (node != NULL)
    add_env(build.tab, node);
  else
    node = empty_node(tab);
  var->env = create_env(node);
}

char		**prepare_setenv(char *str)
{
  char		**tab;

  if ((tab = malloc(sizeof(char**) * 3)) == NULL)
    exit(EXIT_FAILURE);
  if ((tab[0] = malloc(sizeof(char*) * (my_strlen("unsetenv") + 1))) == NULL)
    exit(EXIT_FAILURE);
  if ((tab[1] = malloc(sizeof(char*) * (my_strlen(str) + 1))) == NULL)
    exit(EXIT_FAILURE);
  tab[0] = my_strcpy(tab[0], "unsetenv");
  tab[1] = my_strcpy(tab[1], str);
  tab[2] = NULL;
  return (tab);
}
