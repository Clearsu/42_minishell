/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_less_token.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junlee2 <junlee2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 19:22:48 by minseok2          #+#    #+#             */
/*   Updated: 2023/01/13 10:05:59 by junlee2          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../includes/lexer.h"

void	make_less_token(t_state *state, t_asset *asset)
{
	t_token	*token;

	token = (t_token *)ft_calloc(1, sizeof(t_token));
	token->type = T_LESS;
	token->value = join_buf(&asset->buf_list);
	list_clear(&asset->buf_list, free);
	list_init(&asset->buf_list);
	list_append(asset->token_list, new_node(token));
	*state = BRANCH;
}
