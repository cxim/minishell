/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnarwhal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/22 17:07:18 by mnarwhal          #+#    #+#             */
/*   Updated: 2020/08/22 17:09:51 by mnarwhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_MINISHELL_H
# define MINISHELL_MINISHELL_H
# include "ft_printf/includes/printf.h"
# include <sys/stat.h>
# include <sys/wait.h>

typedef struct	s_env
{
	char		**my_env;
}				t_env;

void			free_arr(char **arr);
void			shell_loop(t_env *env);
char			**my_split(char *line);
int				todo_cd(char **args, t_env *env);
char			*find_env(char *line, t_env *env);
void			set_env(char *name, char *value, t_env *env);
int				find_poz(char *line, t_env *env);
int				todo_echo(char **array, t_env *env);
int				exec_bin(char **array, t_env *env);
int				todo_set_env(char **args, t_env *env);
int				todo_unset_env(char **array, t_env *env);
char			**realloc_enveron(int new_len, t_env *env);
int				find_start(const char *s1, const char *s2);
#endif
