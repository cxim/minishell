//
// Created by cxim1 on 16.08.2020.
//

#include "minishell.h"

int 	exec_this(char *path, char **array, t_env *env)
{
	pid_t	pid;

	pid = fork();
	if (pid == 0)
		execve(path, array, env->my_env);
	else if (pid < 0)
		ft_putendl("\033[31fork failed\033[0m");
	wait(&pid);
	return (1);
}

void 	error_output(char *string)
{
	ft_putstr("minishell: command not found: ");
	ft_putendl(string);
}

int		exec_path(char **array, char **paths, t_env *env)
{
	int				i;
	struct stat		fstat;
	char 			*tmp;
	char 			*tmp2;

	i = -1;
	while (paths[++i])
	{
		tmp = ft_strjoin(paths[i], "/");
		tmp2 = ft_strjoin(tmp, array[0]);
		free(tmp);
		if (lstat(tmp2, &fstat) != -1)
		{
			if (fstat.st_mode & S_IXUSR)
			{
				exec_this(tmp2, array, env);
				free(tmp2);
				return (1);
			}
		}
		free(tmp2);
	}
	return (0);
}

int 	exec_bin(char **array, t_env *env)
{
	int 			catch_res;
	struct stat		fstat;
	char 			**paths;

	catch_res = 0;
	if (lstat(array[0], &fstat) != -1)
	{
		if (fstat.st_mode & S_IXUSR)
		{
			exec_this(array[0], array, env);
			return (1);
		}
	}
	paths = ft_strsplit(find_env("PATH", env), ':');
	if (!paths || paths == NULL)
		error_output(array[0]);
	else
	{
		catch_res = exec_path(array, paths, env);
		if (catch_res == 0)
			error_output(array[0]);
	}
	free_arr(paths);
	return (1);
}