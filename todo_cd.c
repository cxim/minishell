/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   todo_cd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnarwhal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/22 17:00:39 by mnarwhal          #+#    #+#             */
/*   Updated: 2020/08/22 17:02:02 by mnarwhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	change_path(char *path, t_env *env)
{
	char	*cwd;
	char	buff[4097];

	cwd = getcwd(buff, 4096);
	if (chdir(path) == 0)
		set_env("OLDPWD", cwd, env);
	else
	{
		ft_putstr("cd: ");
		ft_putstr(path);
		if (access(path, F_OK) == 1)
			ft_putendl(": no such file or directory");
		else if (access(path, R_OK) == -1)
			ft_putendl(": permission denidied");
		else
			ft_putendl(": not a directory");
	}
}

char	*string_path(char *str)
{
	str++;
	str++;
	return (str);
}

void	check_home_path(char *home_path, char *path, t_env *env)
{
	char	*tmp;
	char	*tmp2;

	tmp = ft_strjoin(home_path, "/");
	tmp2 = ft_strjoin(tmp, string_path(path));
	change_path(tmp2, env);
	free(tmp);
	free(tmp2);
}

int		todo_cd(char **args, t_env *env)
{
	char	*home_path;

	home_path = find_env("HOME", env);
	if (!args[0] || (args[0][0] == '~' && !args[0][1]))
	{
		change_path(home_path, env);
		return (1);
	}
	else
	{
		if (args[0][0] == '~' && args[0][1] == '/')
		{
			check_home_path(home_path, args[0], env);
			return (1);
		}
		else if (args[0][0] == '-' && !args[0][1])
		{
			change_path(find_env("OLDPWD", env), env);
			return (1);
		}
		change_path(args[0], env);
	}
	return (1);
}
