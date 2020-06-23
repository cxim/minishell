//
// Created by cxim1 on 23.06.2020.
//

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

int 	todo_cd(char **args, t_env *env)
{
	char	*home_path;

	home_path = find_env("HOME", env);
	if (!args[0] || (args[0][0] == '~' && !args[0][1]))
	{
		change_path(home_path, env);
		return (1);
	}
//	else
//	{
//
//	}
	return (1);
}