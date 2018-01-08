/*
** prepare_functions.c for minishell2 in /home/arthur/rendu/semestre2/PSU_2016/PSU_2015_minishell2/redirect
** 
** Made by arthur
** Login   <chenne_a@epitech.net>
** 
** Started on  Mon Apr  4 15:25:37 2016 arthur
** Last update Mon Apr  4 15:28:38 2016 arthur
*/

#include <dirent.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "minishell.h"
#include "get_next_line.h"
#include "print.h"

char		**prepare_argv_pipe(char **new, int begin, int end)
{
  char		**argv;
  int		i;

  i = 0;
  argv = malloc(sizeof(char*) * (end - begin + 1));
  while (begin < end)
    {
      argv[i] = malloc(sizeof(char) * (my_strlen(new[begin]) + 1));
      my_strcpy(argv[i], new[begin]);
      i = i + 1;
      begin = begin + 1;
    }
  argv[i] = NULL;
  return (argv);
}

t_pipe		*first_prepare_pipe(t_pipe *ctx, t_many *var)
{
  ctx->exec.indic = check_exec(var->new[ctx->begin],
			       ctx->exec.path, ctx->s_max);
  ctx->exec.new = create_path(var->new[ctx->begin],
			      ctx->exec.path[ctx->exec.indic]);
  ctx->argv = prepare_argv_pipe(var->new, ctx->begin, ctx->second);
  return (ctx);
}

t_pipe		*second_prepare_pipe(t_pipe *ctx, t_many *var)
{
  ctx->exec.indic = check_exec(var->new[ctx->second + 1],
			       ctx->exec.path, ctx->s_max);
  ctx->exec.new = create_path(var->new[ctx->second + 1],
			      ctx->exec.path[ctx->exec.indic]);
  ctx->argv = prepare_argv_pipe(var->new, ctx->second + 1, ctx->end);
  return (ctx);
}

t_pipe		*second_ctx_init(t_pipe *ctx, char **env)
{
  ctx->exec.path = init_path(env);
  ctx->s_max = my_double_strlen(ctx->exec.path);
  if ((ctx->fd = malloc(sizeof(int) * 2)) == NULL)
    return (NULL);
  return (ctx);
}

t_pipe		*init_ctx()
{
  t_pipe	*ctx;

  if ((ctx = malloc(sizeof(t_pipe))) == NULL)
    return (NULL);
  ctx->i = 0;
  ctx->begin = 0;
  ctx->second = 0;
  return (ctx);
}
