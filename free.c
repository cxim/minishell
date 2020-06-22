//
// Created by cxim1 on 21.06.2020.
//

#include "minishell.h"

void	free_arr(char **arr)
{
	int		i;

	if (!arr)
		return ;
	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
	arr = NULL;
}