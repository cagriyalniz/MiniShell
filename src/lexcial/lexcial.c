#include "../../include/header.h"

t_token *lexical_new(char *word)
{
	t_token *tmp;

	tmp = malloc(sizeof(t_token));
	tmp->word = word;
	tmp->next = NULL;
	return (tmp);
}

t_token *lexical_last(t_token *lst)
{
	if (!lst)
		return (lst);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void lexical_append(t_token **lst, t_token *new)
{
	t_token *tmp;

	if (!*lst)
	{
		*lst = new;
		return;
	}
	tmp = lexical_last(*lst);
	tmp->next = new;
}

t_token *lexical_add(char **ptr)
{
	//t_token *lst;
	static t_token *statictmp = 0;
	int i;

	i = 0;
	//lst = NULL;
	while (ptr[i])
	{
		lexical_append(&statictmp, lexical_new(ptr[i]));
		i++;
	}
	// lst = malloc(sizeof(t_token));
	// i = 0;
	// while (ptr[i])
	// {
	// 	lst->word = ptr[i];
	// 	lst->next = statictmp;
	// 	statictmp = lst;
	// 	i++;
	// }

	return (statictmp);
}

int print_lexical(t_token *token)
{
	int size;

	size = 0;
	while (token)
	{
		printf("%s\n", (token)->word);
		token = token->next;
		size++;
	}
	return (size);
	printf("\n");
}
