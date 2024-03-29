/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_builtin.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eozmert <eozmert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 10:03:43 by cyalniz           #+#    #+#             */
/*   Updated: 2022/12/13 13:52:39 by eozmert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/header.h"

int	export_start(t_command *command)
{
	int		i;
	int		size;
	char	*key;
	char	*value;
	char	*tmp_value;
	char	*identifier;

	i = -1;
	key = ft_strdup("");
	value = ft_strdup("");
	tmp_value = ft_strdup("");
	identifier = NULL;
	size = token_size(command->tokens);
	if (size == 0)
	{
		env_asc(g_env.env);
		while (g_env.env[++i])
            printf("declare -x %s\n", g_env.env[i]);
	}
	i = -1;
	while (++i < size)
	{
		if (command->tokens->type_id == 8)
			identifier = ft_strdup(command->tokens->context);
		if (command->tokens->type_id == 10)
		{
			key = ft_strdup(command->tokens->context);
			tmp_value = env_find_value(key);
			if (tmp_value != NULL)
				value = ft_strjoin(value, tmp_value);
		}
		if (command->tokens->type_id == 11)
		{
			value = ft_strjoin(value, command->tokens->context);
			if (ft_strncmp(value, " ", 1) == 0)
				return (206);
		}
		if (command->tokens->type_id == 12 || size == i + 1)
		{
			env_add(identifier, value);
			identifier = NULL;
			key = ft_strdup("");
			value = ft_strdup("");
			tmp_value = ft_strdup("");
		}
		get_next_token(&command->tokens);
	}
	free(key);
	free(value);
	free(identifier);
	free(tmp_value);
	return (0);
}
