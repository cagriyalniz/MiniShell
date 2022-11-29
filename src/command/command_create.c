/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_create.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eozmert <eozmert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 14:48:35 by cyalniz           #+#    #+#             */
/*   Updated: 2022/11/29 14:51:09 by eozmert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../../include/header.h"

int command(t_rdl *rdl)
{
    int i;

	i = -1;
    command_malloc(rdl);
	while (++i < token_size(rdl->token))
	{
        if (command_create(rdl) == -1)
            break ;
		get_next_token(&rdl->token);
	}
    command_run(rdl);
    token_clear(&rdl->command_list[8].tokens);
    return (0);
}

int command_malloc(t_rdl *rdl)
{
    int command_id;

    rdl->token->context = keyword_trim(rdl->token->context);
    command_id = command_find(rdl, rdl->token->context);
    if (rdl->token->type_id == 0)
    {
        command_id = command_find(rdl, rdl->token->context);
        if (rdl->command_list[command_id].count == 0)
        {
           rdl->command_list[command_id].fd[0] = dup(0);
        }
        rdl->command_list[command_id].count++;
        rdl->command_list[command_id].pipe_count = rdl->pipe_prop->count;
    }
    return (0);
}

int command_create(t_rdl *rdl)
{
    t_token *token;
    int is_token_type;
    int command_id;
     
    token = get_token_type_id(rdl->token, 0);
    token->context = keyword_trim(token->context);
    command_id = command_find(rdl, token->context);
    if (rdl->token->type_id == 0)
        command_id = command_find(rdl, token->context);
    is_token_type = command_in_token_type(rdl, command_id, rdl->token->id);
    if (is_token_type == 1)
        rdl->command_list[command_id].tokens = token_add_copy(rdl->command_list[command_id].tokens, rdl->token);
    if (rdl->token->type_id == 6)
        return (-1);
    return (0);
}
