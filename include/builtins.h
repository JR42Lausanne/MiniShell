/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graux <graux@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 16:03:53 by graux             #+#    #+#             */
/*   Updated: 2023/03/30 14:36:39 by graux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

int		builtin_echo(char **args);
int		builtin_cd(char **args);
int		builtin_pwd(char **args);
int		builtin_export(char **args);
int		builtin_unset(char **args);
int		builtin_env(char **args);
int		builtin_exit(char **args);

int		var_name_len(char *var);
void	export_without_args(void);
#endif
