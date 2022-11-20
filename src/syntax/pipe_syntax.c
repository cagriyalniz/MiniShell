#include "../../include/header.h"

int pipe_syntax(t_rdl *rdl)
{
    if (rdl->token->id == 0)
        return (0);
    if (rdl->token->len == 1)
    {
        if (rdl->token->context[0] == '|')
            rdl->pipe->count++;
    }
    if (rdl->pipe->count > 2)
        return (105);
    if (rdl->token->next->context[0] != '|')
        rdl->pipe->count = 0;
    return (0);
}