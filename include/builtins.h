/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graux <graux@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 16:03:53 by graux             #+#    #+#             */
/*   Updated: 2023/02/24 16:09:53 by graux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

# define ECHO_OPT_NONE 0
# define ECHO_OPT_NONL 1

void	builtin_echo(int option, char *text);
void	builtin_cd(char *path);
void	builtin_pwd(void);
void	builtin_export(char *var, char *value);
//TODO correct arguments
void	builtin_unset(void);
void	builtin_env(void);
void	builtin_exit(void);

#endif
