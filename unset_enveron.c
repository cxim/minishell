//
// Created by cxim1 on 16.08.2020.
//

#include "minishell.h"

void 	remove_it(int id, t_env *env)
{
	int		i;
	int 	id_count;

	free(env->my_env[id]);
	env->my_env[id] = NULL;
	i = id;
	id_count = id + 1;
	while (env->my_env[i + 1])
	{
		env->my_env[i] = ft_strdup(env->my_env[i + 1]);
		free(env->my_env[i + 1]);
		i++;
		id_count++;
	}
	env->my_env = realloc_enveron(id_count - 1, env);
}

int		todo_unset_env(char **array, t_env *env)
{
	int		i;
	int 	id;

	i = 0;
	id = 0;
	if (!array[0])
	{
		ft_putendl("unsetenv: \033[31mToo few arguments\033[0m");
		return (1);
	}
	while (array[i])
	{
		id = find_poz(array[i], env);
		if (env->my_env[id])
			remove_it(id, env);
		i++;
	}
	return (1);
}