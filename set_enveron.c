/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_enveron.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnarwhal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/22 16:56:27 by mnarwhal          #+#    #+#             */
/*   Updated: 2020/08/22 16:57:38 by mnarwhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**realloc_enveron(int new_len, t_env *env)
{
	char	**new_env;
	int		i;

	i = -1;
	new_env = (char **)malloc(sizeof(char *) * (new_len + 1));
	while (env->my_env[++i] && i < new_len)
	{
		new_env[i] = ft_strdup(env->my_env[i]);
		free(env->my_env[i]);
	}
	free(env->my_env);
	return (new_env);
}

void	set_this(char *name, char *value, t_env *env)
{
	int		id;
	char	*tmp;

	id = find_poz(name, env);
	tmp = ft_strjoin("=", value);
	if (env->my_env[id])
	{
		free(env->my_env[id]);
		if (value)
			env->my_env[id] = ft_strjoin(name, tmp);
	}
	else
	{
		env->my_env = realloc_enveron(id + 1, env);
		if (value)
			env->my_env[id] = ft_strjoin(name, tmp);
		env->my_env[id + 1] = NULL;
	}
	free(tmp);
}

int		todo_set_env(char **array, t_env *env)
{
	if (!array || (array[0] && !array[1]))
	{
		ft_putendl("setenv: \033[31mToo few arguments.\033[0m");
		return (1);
	}
	if (array[0] && array[1])
	{
		if (array[2])
		{
			ft_putendl("setenv: \033[31mToo few arguments.\033[0m");
			return (1);
		}
		set_this(array[0], array[1], env);
	}
	return (1);
}
