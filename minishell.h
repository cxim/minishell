//
// Created by cxim1 on 21.06.2020.
//

#ifndef MINISHELL_MINISHELL_H
#define MINISHELL_MINISHELL_H
# include "ft_printf/includes/printf.h"

typedef struct	s_env
{
	char 	**my_env;
}				t_env;

void	free_arr(char **arr);
void	shell_loop(t_env *env);
char	**my_split(char *line);
int 	todo_cd(char **args, t_env *env);
char 	*find_env(char *line, t_env *env);
void	set_env(char *name, char *value, t_env *env);
int 	find_poz(char *line, t_env *env);
#endif //MINISHELL_MINISHELL_H
