#include "../../include/header.h"

void parser_arg_redir(int *k, t_rdl *rdl)
{
	int i;

	i = *k;
	parser_add_redir(rdl, rdl->main_str[i]);
	i++;
	if (rdl->main_str[i] <= 32)
		while (rdl->main_str[i++] <= 32);
	i -= 2;
    *k = i;
}