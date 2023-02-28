/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaiti <jlaiti@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 10:48:19 by jlaiti            #+#    #+#             */
/*   Updated: 2023/02/27 11:06:09 by jlaiti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

typedef enum e_token_type
{
	WORD = 0,
	SPACE,
	TAB
}			t_token_type;

typedef struct s_token
{
	t_token_type	type;
	char			*content;
	int				content_len;
	int				pos;
}			t_token;

typedef	enum e_tokenizer_mode
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


void	check_is_word(char **prompt, t_token *token)
{
	int	i;
	
	i = 0;
	while (prompt[i] != '\0')
	{
		if (prompt[i] == ' ' || prompt[i] == '\t')
			i++;
		is_string;
		else if (prompt[i] == ':'
			TODO
		else if (prompt

	}

}

void	read_line(char	**prompt)
{
	t_token	*token;

	token = malloc(sizeof(t_token));
	check_word(&prompt, &token);
	
}
