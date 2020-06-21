//
// Created by cxim1 on 21.06.2020.
//

#include "minishell.h"


int		main(int argv, char **argc)
{
	int i;
	char *line;
	ft_putstr("My_minishell $> ");
	while (get_next_line2(0, &line) >= 0)
	{
		if (ft_strcmp(line, "exit") == 0)
		{
			free(line);
			exit(0);
		}
		parce(line);
		ft_putstr("My_minishell $> ");
		free(line);
	}
	return (0);
}