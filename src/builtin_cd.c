/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_cd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaiti <jlaiti@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 10:36:04 by jlaiti            #+#    #+#             */
/*   Updated: 2023/03/07 11:25:09 by jlaiti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/builtins.h"
#include "../include/minishell.h"
#include "../include/libft.h"

static int	check_valid_path(char *new_path)
{
	if (access(new_path, 0) == 0)
		return (0);
	else
		return (1);
}

static char	*expand_path(char *new_path, char *arg)
{
	char	*total_path;
	char	*input;
	char	*new_a;
	char	*new_b;
	int		i;
	int		j;

	i = -1;
	if (new_path)
		input = new_path;
	else
		input = ft_strdup(arg);
	if (input[0] != '/')
		input = ft_strjoin(ms_getenv_cont("PWD"), arg);

	return (total_path);
}

int	builtin_cd(char **args)
{
	char	*new_path;
	char	*home_path;
	char	*export_args[2];

	home_path = ms_getenv_cont("HOME");
	if (!args)
		return (1);
	if (!args[1]) // cd only without args
		new_path = home_path;
	else if (args[1][0] == '~') // mettre home + ce qui ya apres dans args[1]
		new_path = ft_strjoin(home_path, args[1] + 1);
	else
		new_path = NULL;
	new_path = expand_path(new_path, args[1]);
	printf("new_path: %s\n", new_path);
	if (!check_valid_path(new_path))
		perror("No valid path");
	export_args[1] = ft_strjoin("PWD=", new_path);
	chdir(new_path);
	builtin_export(export_args);
	return (0);
}
