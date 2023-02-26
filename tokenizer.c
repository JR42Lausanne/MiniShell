
typedef struct s_token
{
	void		*type;
	int		pos;
	struct	s_token	*next;
	struct	s_token	*prev;
}		t_token;


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
