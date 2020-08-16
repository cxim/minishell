//
// Created by cxim1 on 16.08.2020.
//

#include "minishell.h"

void 	output_path(char *string, t_env *env)
{
	char 	*path;

	path = find_env(string + 1, env);
	ft_putstr(path);
}

void 	echo_string(char *string, t_env *env)
{
	int 	start;
	int 	end;

	start = 0;
	end = (int)ft_strlen(string) - 1;
	if (string[0] == '$')
		output_path(string, env);
	else
	{
		while (string[start] == '\'' || string[start] == '"')
			start++;
		while (string[end] == '\'' || string[end] == '"')
			end--;
		while (start <= end)
			write(1, &string[start++], 1);
	}
}

int 	todo_echo(char **array, t_env *env)
{
	int		i;

	i = 0;
	if (!array[0])
	{
		ft_putchar('\n');
		return (1);
	}
	while (array[i])
	{
		echo_string(array[i], env);
		ft_putchar(' ');
		i++;
	}
	ft_putchar('\n');
	return (1);
}