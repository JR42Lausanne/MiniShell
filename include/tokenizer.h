/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graux <graux@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 15:46:12 by graux             #+#    #+#             */
/*   Updated: 2023/03/21 13:23:14 by graux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKENIZER_H
# define TOKENIZER_H

# include "libft.h"

typedef enum e_token_type
{
	TOK_WORD = 0,
	TOK_SQ,
	TOK_DQ,
	TOK_VAR,
	TOK_PIPE,
	TOK_OR,
	TOK_AND,
	TOK_WILDCARD,
	TOK_REDIR_IN,
	TOK_REDIR_OUT,
	TOK_REDIR_APP,
	TOK_HEREDOC,
	TOK_SPACE,
	TOK_INVALID
}			t_token_type;

typedef struct s_token
{
	t_token_type	type;
	char			*content;
	int				tok_num;
	int				to_be_removed;
}			t_token;

typedef struct s_tokenizer
{
	t_list		*tokens;
	char		*input;
	int			pos;
}			t_tokenizer;

t_token		*token_create(t_token_type type, char *cont, int num);
void		token_void_dest(void *tok);
void		token_destroy(t_token *tok);
void		token_gen_content(t_token *tok, char *src, int size);
//handlers for next token generation
void		token_handle_pipe(t_tokenizer *toker, t_token *tok);
void		token_handle_word(t_tokenizer *toker, t_token *tok);
void		token_handle_and(t_tokenizer *toker, t_token *tok);
void		token_handle_redir_i(t_tokenizer *toker, t_token *tok);
void		token_handle_redir_o(t_tokenizer *toker, t_token *tok);
void		token_handle_var(t_tokenizer *toker, t_token *tok);
int			token_var_len(t_tokenizer *toker);
void		token_handle_tilde(t_tokenizer *toker, t_token *tok);
void		token_handle_space(t_tokenizer *toker, t_token *tok);
void		dq_mode(t_tokenizer *toker, t_token *tok);

t_token		**agregate_spaces(t_token **tokens, int size);
void		agregate_redirs(t_token ***tokens, int size);
t_token		**expand_wildcards(t_token **tokens);
int			is_redir(t_token *tok);

t_tokenizer	*tokenizer_create(char *input);
void		tokenizer_destroy(t_tokenizer *toker);
t_token		*tokenizer_next_token(t_tokenizer *toker);
t_token		**tokenizer_as_array(t_tokenizer *toker);
t_token		**tokenizer_parse(t_tokenizer *toker);
t_token		**tokenize_input(char *input);

void		tokens_print(t_token **tokens);
int			tokens_size(t_token **tokens);

//TODO tilde expansion maybe ????

#endif
