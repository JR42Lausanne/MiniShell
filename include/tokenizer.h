/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graux <graux@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 15:46:12 by graux             #+#    #+#             */
/*   Updated: 2023/03/01 17:16:53 by graux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKENIZER_H
# define TOKENIZER_H

# include "libft.h"

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

const static char	*g_tokens_str[] = {
[TOK_WORD] = "TOK_WORD",
[TOK_SPACE] = "TOK_SPACE",
[TOK_TAB] = "TOK_TAB",
[TOK_SQ] = "TOK_SQ",
[TOK_DQ] = "TOK_DQ",
[TOK_VAR] = "TOK_VAR",
[TOK_PIPE] = "TOK_PIPE",
[TOK_REDIR_IN] = "TOK_REDIR_IN",
[TOK_REDIR_OUT] = "TOK_REDIR_OUT",
[TOK_REDIR_APP] = "TOK_REDIR_APP",
[TOK_HEREDOC] = "TOK_HEREDOC",
[TOK_EQ] = "TOK_EQ"
};

typedef struct s_token
{
	t_token_type	type;
	char			*content;
	int				tok_num;
}			t_token;

typedef enum e_tokenizer_mode
{
	MODE_NORMAL = 0,
	MODE_SQ,
	MODE_DQ
}			t_tok_mode;

typedef struct s_tokenizer
{
	t_list		*tokens;
	char		*input;
	int			pos;
	t_tok_mode	mode;
}			t_tokenizer;

t_token		*token_create(t_token_type type, char *cont, int num);
void		token_void_dest(void *tok);
void		token_destroy(t_token *tok);

t_tokenizer	*tokenizer_create(char *input);
void		tokenizer_destroy(t_tokenizer *toker);
t_token		*tokenizer_next_token(t_tokenizer *toker);
t_token		**tokenizer_as_array(t_tokenizer *toker);
t_token		**tokenizer_parse(t_tokenizer *toker);

void		tokens_print(t_token **tokens);

#endif
