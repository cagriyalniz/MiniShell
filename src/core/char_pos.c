/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_pos.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyalniz <cyalniz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 12:42:39 by cyalniz           #+#    #+#             */
/*   Updated: 2022/11/30 12:43:11 by cyalniz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/header.h"

void	char_pos(int *k, t_rdl *rdl)
{
	int	i;

	i = *k;
	while (rdl->main_str[i] <= 32)
		i++;
	*k = i;
}
