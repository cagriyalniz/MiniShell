/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_double_str.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyalniz <cyalniz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 14:48:24 by cyalniz           #+#    #+#             */
/*   Updated: 2022/11/30 13:06:19 by cyalniz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/header.h"

void	ft_free_dbl_str(char **str)
{
	int	i;

	if (!str[0])
		return ;
	i = -1;
	while (str[++i])
		free(str[i]);
	free(str);
	str = NULL;
}
