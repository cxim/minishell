//
// Created by cxim1 on 23.06.2020.
//

#include "minishell.h"

int 	find_start(const char *s1, const char *s2)
{
	int 	i;

	i = -1;
	while (s2[++i])
		if (s1[i] != s2[i])
			return (0);
	return (1);
}

char 	*find_env(char *line, t_env *env)
{
	int		i;
	char	*tmp;

	i = 0;
	while (env->my_env[i])
	{
		tmp = ft_strjoin(line, "=");
		if (find_start(env->my_env[i], tmp))
		{
			free(tmp);
			return (ft_strchr(env->my_env[i], '=') + 1);
		}
		free(tmp);
		i++;
	}
	return (NULL);
}

int 	find_poz(char *line, t_env *env)
{
	int		i;
	char	*tmp;

	i = 0;
	while (env->my_env[i])
	{
		tmp = ft_strjoin(line, "=");
		if (find_start(env->my_env[i], tmp))
		{
			free(tmp);
			return (i);
		}
		free(tmp);
		i++;
	}
	return (i);
}

int 	exec_oper(char **args, t_env *env)
{
	if (!args || args[0] == NULL)
		return (1);
	else if (ft_strcmp(args[0], "exit") == 0)
		return (0);
	else if (ft_strcmp(args[0], "cd") == 0)
		return (todo_cd(args + 1, env));
//	else if (ft_strcmp(args[0], "echo") == 0)
//		return (todo_echo(args + 1));
//	else if (ft_strcmp(args[0], "setenv") == 0)
//		return (todo_set(args + 1));
//	else if (ft_strcmp(args[0], "unsetenv") == 0)
//		return (todo_unset(args + 1));
//	else if (ft_strcmp(args[0], "env") == 0)
//	{
//		print_env();
//		return (1);
//	}
//	else (exec_bin(args));
	return 1;
}

void	shell_loop(t_env *env)
{
	char 	*get_cmd;
	char 	**args;
	int 	cycle;

	cycle = 1;
	while (cycle)
	{
		ft_putstr("My_Minishell_$>");
		get_next_line2(0, &get_cmd);
		//free(get_cmd);
//		if (ft_strcmp(get_cmd, "exit") == 0) {
//			free(get_cmd);
//			break;
//		}
		args = my_split(get_cmd);
		free(get_cmd);
		cycle = exec_oper(args, env);
		free_arr(args);
	}
}