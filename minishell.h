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
#endif //MINISHELL_MINISHELL_H
