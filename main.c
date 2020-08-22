/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnarwhal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/22 16:51:53 by mnarwhal          #+#    #+#             */
/*   Updated: 2020/08/22 16:53:10 by mnarwhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <stdio.h>
#include <sys/types.h>

int		find_start(const char *s1, const char *s2)
{
	int		i;

	i = -1;
	while (s2[++i])
		if (s1[i] != s2[i])
			return (0);
	return (1);
}

int		env_len(char **env)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (env[i])
	{
		count++;
		i++;
	}
	return (count);
}

void	copy_env(int ac, char **av, char **env, t_env *my_env)
{
	int		i;

	(void)ac;
	(void)av;
	if (!(my_env->my_env = (char**)malloc(sizeof(char*) * (env_len(env) + 1))))
		return ;
	i = 0;
	while (env[i])
	{
		if (!(my_env->my_env[i] = ft_strdup(env[i])))
		{
			free_arr(my_env->my_env);
			write(1, "\n", 1);
			exit(1);
		}
		i++;
	}
	my_env->my_env[i] = NULL;
}

int		main(int ac, char **av, char **environ)
{
	t_env *env;

	if (!(env = (t_env*)ft_memalloc(sizeof(t_env))))
		exit(1);
	copy_env(ac, av, environ, env);
	shell_loop(env);
	free_arr(env->my_env);
	free(env);
	return (0);
}
