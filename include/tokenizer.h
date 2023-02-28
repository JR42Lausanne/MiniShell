/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graux <graux@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 15:46:12 by graux             #+#    #+#             */
/*   Updated: 2023/02/28 15:50:56 by graux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKENIZER_H
# define TOKENIZER_H

typedef enum e_token_type
{
	TOK_WORD = 0,
	TOK_SPACE,
	TOK_TAB,
	TOK_SQ,
	TOK_DQ,
	TOK_VAR,
	TOK_PIPE,
	TOK_REDIR_IN,
	TOK_REDIR_OUT,
	TOK_REDIR_APP,
	TOK_HEREDOC,
	TOK_EQ
}			t_token_type;

typedef struct s_token
{
	t_token_type	type;
	char			*content;
	int				content_len;
	int				pos;
}			t_token;

typedef enum e_tokenizer_mode
{
	NORMAL = 0,
	SQ_STRING,
	DQ_STRING,
	DONE
}			t_tok_mode;

typedef struct s_tokenizer
{
	char		*input;
	int			pos;
	t_tok_mode	mode;
}			t_tokenizer;

#endif
