/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset_builtin.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyalniz <cyalniz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 10:07:45 by cyalniz           #+#    #+#             */
/*   Updated: 2022/12/12 10:08:11 by cyalniz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/header.h"

int	unset_start(t_command *command)
{
	int	i;
	int	size;

	i = -1;
	size = token_size(command->tokens);
	while (++i < size)
	{
		if (command->tokens->type_id == 10)
			env_delete(command->tokens->context);
		get_next_token(&command->tokens);
	}
	return (0);
}
