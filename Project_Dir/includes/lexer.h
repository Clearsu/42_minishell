/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 09:37:32 by minseok2          #+#    #+#             */
/*   Updated: 2023/01/04 10:05:29 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H

# include "data.h"

// define unused type
typedef void	t_unused;

// define state
typedef enum e_state
{
	INIT,
	BRANCH,
	MAKING_WORD,
	MAKING_PIPE,
	MAKING_LESS,
	MAKING_DLESS,
	MAKING_GREAT,
	MAKING_DGREAT,
	QUOTE_BRANCH,
	QUOTE_MAKING_WORD,
	QUOTE_CLOSE,
	DQUOTE_BRANCH,
	DQUOTE_MAKING_WORD,
	DQUOTE_CLOSE,
	EXPAND,
	DQUOTE_EXPAND,
	CLEAR,
	FINISH
}	t_state;

// define total state
# define TOTAL_STATE	19

// define state function pointer
typedef void	(*t_state_fp)(t_state *state, \
								t_data *data, t_list *buf_list, int *idx);

// make_token_list
void	make_token_list(t_data *data);

// make_token_list_utils
void	del_buffer(void **content);
char	*make_buf(char input);
void	make_token(t_list *token_list, t_list *buf_list, t_type type);

// print_token_list
void	print_token_list(t_data *data);

// state functions
void	init(t_state *state, t_data *data, t_list *buf_list, int *idx);
void	branch(t_state *state, t_data *data, t_list *buf_list, int *idx);
void	making_word(t_state *state, t_data *data, t_list *buf_list, int *idx);
void	making_pipe(t_state *state, t_data *data, t_list *buf_list, int *idx);
void	making_less(t_state *state, t_data *data, t_list *buf_list, int *idx);
void	making_dless(t_state *state, t_data *data, t_list *buf_list, int *idx);
void	making_great(t_state *state, t_data *data, t_list *buf_list, int *idx);
void	making_dgreat(t_state *state, t_data *data, t_list *buf_list, int *idx);
void	quote_branch(t_state *state, t_data *data, t_list *buf_list, int *idx);
void	quote_making_word(t_state *state, \
									t_data *data, t_list *buf_list, int *idx);
void	quote_close(t_state *state, t_data *data, t_list *buf_list, int *idx);
void	dquote_branch(t_state *state, t_data *data, t_list *buf_list, int *idx);
void	dquote_making_word(t_state *state, \
									t_data *data, t_list *buf_list, int *idx);
void	dquote_close(t_state *state, t_data *data, t_list *buf_list, int *idx);
void	expand(t_state *state, t_data *data, t_list *buf_list, int *idx);
void	dquote_expand(t_state *state, t_data *data, t_list *buf_list, int *idx);
void	clear(t_state *state, t_data *data, t_list *buf_list, int *idx);

// expand functions
int		get_env_length(char *line);
int		is_expansion(char *line, int idx, t_list *token_list);
char	*make_expanded_line(t_data *data, int idx);

#endif
