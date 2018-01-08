/*
** minishell.h for minishell in /home/chenne_a/rendu/PSU_tek1/PSU_2015_minishell1/bootstrap
** 
** Made by Arthur Chennetier
** Login   <chenne_a@epitech.net>
** 
** Started on  Thu Jan 14 16:27:22 2016 Arthur Chennetier
** Last update Sun Jun  5 19:51:38 2016 chauvi_d
*/

#include <dirent.h>

#ifndef MINISHELL_H_
# define MINISHELL_H_

typedef struct		s_check
{
  DIR			*dir;
  struct dirent		*info;
  int			i;
  int			indic;
  int			j;
}			t_check;

typedef struct		s_wtab
{
  char			**arg;
  int			nb;
  int			i;
  int			j;
  int			k;
}			t_wtab;

typedef struct		s_path
{
  int			i;
  int			j;
  int			k;
  int			s_max;
}			t_path;

typedef struct		s_list
{
  struct s_list		*next;
  struct s_list		*prev;
  int			n;
  char			*time;
  char			*name;
}			t_list;

typedef struct          s_dlist
{
  int                   length;
  t_list                *head;
  int                   nb_com;
}                       t_dlist;

typedef struct		s_globb
{
  int			i;
  int			y;
  int			glob_count;
}			t_globb;

typedef struct		s_exec
{
  char			**tmp;
  char			**tab;
  char			**path;
  char			**env;
  char			*new;
  char			*s;
  int			status;
  int			pid;
  int			indic;
  int			direct;
}			t_exec;

typedef struct		s_many
{
  char			**new;
  int			i;
  int			j;
}			t_many;

typedef struct		s_epur
{
  char			*new;
  int			i;
  int			y;
  int			indic;
}			t_epur;

typedef struct		s_pipe
{
  t_exec		exec;
  char			**argv;
  int			*fd;
  int			pid;
  int			s_max;
  int			begin;
  int			second;
  int			end;
  int			i;
}			t_pipe;

typedef struct		s_use
{
  char			**env;
  char			*name;
}			t_use;

typedef struct		s_bin
{
  char			*name;
  struct s_bin		*right;
  struct s_bin		*left;
}			t_bin;

typedef struct		s_cmd
{
  void			(*str)(t_exec, t_exec*);
  char			*cmd;
}			t_cmd;

typedef struct		s_op
{
  char			*str;
  int			size;
  void			(*ptr)(t_exec*, t_bin*);
}			t_op;

typedef struct		s_echo
{
  char			c;
  char			*stop;
  int			nb;
}			t_echo;

typedef struct          s_history
{
  char                  key;
  int                   (*ptr)(char*, char*, int);
}                       t_history;

typedef struct          s_pars
{
  char                  key;
  int                   (*ptr)(char**, int);
}                       t_pars;

t_op            red_tab[9];

t_dlist		*hist;
int		ambig;
int		fail;

char		**str_to_wordtab(char *str, char divide);
char		*my_strcat(char *str1, char *str2);
int             check_double_backslash(char *str, int i);
int             backslash_case(char *str);
int             check_backslash(char *str);
int             in_the_word(char *str);
char            **init_new(char **tab, int begin);
t_check		init_check(t_check exec, int i, int s_max);
char            **prepare_path();
char            *all_path(char *str, char **env, int size);
char            *the_variable(char *str, char c);
char            *my_tilde(char *str, char **env);
int             bad_character(char *str);
char            *my_clean_putstr(char *str, char **env);
void            my_echo(t_exec build, t_exec *var);
void            side_case(t_exec *var, t_bin *node, t_exec exec);
void		double_and_case(t_exec *exec, t_bin *node);
void		double_pipe_case(t_exec *exec, t_bin *node);
void		double_indirect_case(t_exec *exec, t_bin *node);
void            print_tree(t_bin *root);
int             first_check_tree(char *name);
void		simple_exec(t_bin *node, t_exec *exec);
void            check_exec_op(t_bin *node, t_exec *exec);
void            exec_no_fork(t_exec *exec, t_bin *node);
void		setenv_old(char *old, t_exec *var);
char		**prepare_env();
void		first_pipe(int *fd, t_exec *var, t_bin *node);
void		second_pipe(int *fd, t_exec *var, t_bin *node);
t_path		init_path_var(t_path param);
t_epur		norm_epur(t_epur var, char *str);
char		**bad_exit(char **env);
char		**prepare_setenv(char *str);
void		classic_cd(t_exec build, t_exec *var, char *old);
void		change_pwd(t_exec *var, t_exec build);
char		*prepare_old();
char		*change_last(char *pwd);
void		test_siggsev(int status, char **path);
void		change_old(char *old, t_exec *var);
void	        indirect_case(t_exec *var, t_bin *node);
void		double_redirect_case(t_exec *var, t_bin *node);
void		redirect_case(t_exec *var, t_bin *node);
void		pipe_epur(char *right, char *left);
int		check_path(char *right, char *left, char **env);
void		pipe_exec(char **env, char *str);
void		del_env(char **tab, t_list *node);
void		add_env(char **tab, t_list *node);
void		my_unsetenv(t_exec build, t_exec *var);
void		my_setenv(t_exec build, t_exec *var);
void		free_exec(t_exec build, char **env);
int		test_exit(char *str);
int		my_getnbr(char *str);
char		*my_strcpy(char *dest, char *src);
t_epur		space_epur(t_epur var, char *str);
int		my_strcmp(char *src, char *cmp);
int		epur_end(char *str, int i);
t_epur		algo_epur(char *str, t_epur var);
int		my_strlen(char *str);
char		*epur_str(char *str);
char		*prepare_home(t_exec build, int i, char **env);
void		my_cd(t_exec build, t_exec *var);
void		my_env(t_exec build, t_exec *var);
void		my_exit(t_exec build, t_exec *var);
int		check_cmd(char *cmd);
void		build_in(int i, t_exec build, t_exec *var);
void		path_case(t_exec exec, t_exec *var);
void		current_exec(t_exec *var, char **tab, int j);
int		path_exec(t_exec *var, char **tab);
int		direct_exec(char **tab, t_exec *var);
int		my_double_strlen(char **str);
t_exec		exec(char *s, t_exec var);
int		check_exec(char *s, char **PATH, int s_max);
int		find_home(char **env);
char		**init_path(char **env);
char		**write_path(char **path, char *env);
char		*create_path(char *tab, char *path);
t_path		path_nbr(char *env, t_path param);
int		send_j(int i, DIR *dir);
int		space_nbr(char *str);
char		**my_str_to_wordtab(char *str);
int		my_str_compare(char *str1, char *str2);
void		free_path(char **path);
int		check_next(char *str);
int		next_exec(char **tab, int j);
char		**init_exec(char **tab, int j, int y);
t_many		*init_var(char **tab);
t_many		*next_var(char **tab, t_many *var);
int		check_pipe(char *str);
void		pipe_case(t_exec *exec, t_bin *node);
int		check_redirect(t_many *var, char **env);
t_pipe		*second_ctx_init(t_pipe *ctx, char **env);
t_pipe		*init_ctx();
t_pipe		*second_prepare_pipe(t_pipe *ctx, t_many *var);
t_pipe		*first_prepare_pipe(t_pipe *ctx, t_many *var);
char		**prepare_argv_pipe(char **new, int begin, int end);
t_bin		*create_tree(char *str, int pos_op, int n_op);
void		semicolon_case(t_exec *var, t_bin *node);
t_list		*add_new_elem(t_list *node, char **env, int i);
void		print_list(t_list *node);
t_list		*create_list(char **env);
char		**create_env(t_list *node);
int		check_node(t_bin *node, int i);
int		curly(char *str);
int             you_can_curly(char *str);
int		tab_len(char **tab);
char		**my_glob(char **tab);
int             check_right_build_in(char *str);
void            build_in_pipe(t_exec *var, t_bin *node);
void            check_ambiguous(t_bin *node);
t_dlist         *my_init_l();
t_dlist         *add_last_elem(t_dlist *list, t_list *element);
t_dlist         *get_from_history();
t_dlist         *put_in_history(char *str, t_dlist *history);
int             write_history(t_dlist *history, char *file);
t_dlist         *create_history(char *file);
t_dlist         *get_content(t_dlist *history, char **tmp);
char            *my_strcat(char *str1, char *str2);
void            history(t_exec build, t_exec *var);
char            *my_time();
char            *int_to_str(int nb);
t_dlist         *get_from_history(char *str, t_dlist *history);
int             my_strlen2d(char **av);
char            *pars_comm(char *str);
t_dlist         *replace_com(char *str, t_dlist *history);
int             check_flags_history(char **tab);
int             load_history(char *str, char *flag, int j);
int             save_history(char *str, char *flag, int j);
int             reverse_history(char *str, char *flag, int j);
int             simple_history(char *str, char *flag, int j);
int             clear_history(char *str, char *flag, int j);
void            my_free_list(t_dlist **list);
int             is_num(char *str);
void            putn_list(t_dlist *list, int n);
void            putn_list_reverse(t_dlist *list, int n);
int             word_cmp(char *str, char *cmp);
char            *put_in_str(char *str, char *src, int i, int k);
int             alias_history(char **str, int i);
char            *cmd(char *str);
int             nigma(char **str, int i);
int             dash(char **str, int i);
int             excl(char **str, int i);
t_list		*dash_extend(char *cmp);
int		check_error_pars(char **str, int n, int i);
int		flag_str(char **str, int i);
int		check_exit(int i, t_exec *var);
void            putn_list_simple(t_dlist *list, int n);
void            putn_list_simple_r(t_dlist *list, int n);
int		check_np_flag(char *flag, char c, int j, char *str);
int             load_history_extend(char *str, t_dlist *tmp);
t_exec		init_shell(t_exec var, char **env);
t_dlist		*my_del_elem(t_dlist *list, t_list *element);

#endif /* MINISHELL_H_ */
