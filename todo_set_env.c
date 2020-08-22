/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   todo_set_env.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnarwhal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/22 16:55:31 by mnarwhal          #+#    #+#             */
/*   Updated: 2020/08/22 16:55:56 by mnarwhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**realloc_env(int size, t_env *env)
{
	char	**new_env;
	int		i;

	i = -1;
	new_env = (char **)malloc(sizeof(char *) * (size + 1));
	while (env->my_env[++i] && i < size)
	{
		new_env[i] = ft_strdup(env->my_env[i]);
		free(env->my_env[i]);
	}
	free(env->my_env);
	return (new_env);
}

void	set_env(char *name, char *value, t_env *env)
{
	int		poz;
	char	*tmp;

	poz = find_poz(name, env);
	tmp = ft_strjoin("=", value);
	if (env->my_env[poz])
	{
		free(env->my_env[poz]);
		if (value)
			env->my_env[poz] = ft_strjoin(name, tmp);
	}
	else
	{
		env->my_env = realloc_env(poz + 1, env);
		if (value)
			env->my_env[poz] = ft_strjoin(name, tmp);
		env->my_env[poz + 1] = NULL;
	}
	free(tmp);
}
