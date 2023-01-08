/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_great_token.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 19:25:14 by minseok2          #+#    #+#             */
/*   Updated: 2023/01/08 19:52:04 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../includes/lexer.h"

void	make_great_token(t_state *state, t_asset *asset)
{
	t_token	*token;

	token = (t_token *)ft_calloc(1, sizeof(t_token));
	token->type = T_GREAT;
	token->value = join_buf(&asset->buf_list);
	list_clear(&asset->buf_list, free);
	list_init(&asset->buf_list);
	list_append(asset->token_list, new_node(token));
	*state = BRANCH;
}
