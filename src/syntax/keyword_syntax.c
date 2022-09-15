#include "../../include/header.h"

int keyword_syntax(t_rdl *rdl)
{
	int i;
	t_token *token;

	i = -1;
	token = get_token_id(rdl->token, 0);
	while (token->context[++i])
		ft_tolower(token->context[i]);
	token->context = keyword_trim(token->context);
    if (is_keyword(rdl, token->context))
        return (0);
    return (101);
}