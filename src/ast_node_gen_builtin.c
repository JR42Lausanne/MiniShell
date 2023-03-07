/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_node_gen_builtin.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graux <graux@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 18:06:09 by graux             #+#    #+#             */
/*   Updated: 2023/03/07 11:35:08 by graux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ast.h"
#include "../include/builtins.h"

static void	func_from_name(t_builtin_cont *cont, char *name)
{
	if (!ft_strncmp(name, "echo", ft_strlen("echo")))
		cont->func_pointer = builtin_echo;
	else if (!ft_strncmp(name, "cd", ft_strlen("cd")))
		cont->func_pointer = builtin_cd;
	else if (!ft_strncmp(name, "pwd", ft_strlen("pwd")))
		cont->func_pointer = builtin_pwd;
	else if (!ft_strncmp(name, "export", ft_strlen("export")))
		cont->func_pointer = builtin_export;
	else if (!ft_strncmp(name, "unset", ft_strlen("unset")))
		cont->func_pointer = builtin_unset;
	else if (!ft_strncmp(name, "env", ft_strlen("env")))
		cont->func_pointer = builtin_env;
	else if (!ft_strncmp(name, "exit", ft_strlen("exit")))
		cont->func_pointer = builtin_exit;
}

void	ast_node_gen_builtin(t_ast_node *node, t_token **tokens, int start,
		int size)
{
	t_builtin_cont	*content;
	int				pos;
	char			*cmd_name;

	content = malloc(sizeof(t_builtin_cont));
	if (!content)
		return ;
	pos = ast_find_name_pos(tokens, start, size);
	if (pos != -1)
	{
		cmd_name = tokens[pos]->content;
		func_from_name(content, cmd_name);
	}
	content->args = ast_gen_args(tokens, start, size);
	node->content = content;
}
