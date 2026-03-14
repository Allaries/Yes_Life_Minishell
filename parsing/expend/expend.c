/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expend.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smedenec <smedenec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 20:51:07 by smedenec          #+#    #+#             */
/*   Updated: 2026/03/14 05:54:21 by smedenec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	expend_in_word(char *input, t_data *data, t_word *word, int *i)
{
	int		y;
	char	*var;
	char	*expend;
	int		start;
// faut faire l'expension imbriqué aussi
	(*i)++;
	if (!input[*i])
		return (1);
	if (input[*i] == '?')
		return (special_question(data, word, i));
	if (!ft_isalpha(input[*i]) && input[*i] != '_')
		return (1);
	start = *i;
	while (ft_isalnum(input[*i]) || input[*i] == '_')
		(*i)++;
	var = ft_substr(input, start, (*i - start));
	if (!var)
		return (0);
	expend = get_env(data, var);
	free(var);
	if (!expend)
		return (1);
	y = 0;
	while (expend[y])
	{
		if (!add_char_in_word(word, expend[y]))
			return (0);
		y++;
	}
	return (1);
}

int	special_question(t_data *data, t_word *word, int *i)
{
	int		y;
	char	*value;

	y = 0;
	value = ft_itoa(data->exit_code);
	if (!value)
		return (0);
	while (value[y])
	{
		if (!add_char_in_word(word, value[y]))
			return (free(value), 0);
		y++;
	}
	free(value);
	(*i)++;
	return (1);
}

char	*get_env(t_data *data, char *var)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(var);
	while (data->envp[i])
	{
		if (!ft_strncmp(data->envp[i], var, len) && data->envp[i][len] == '=')
			return (data->envp[i] + len + 1);
		i++;
	}
	return (NULL);
}

// int	is_quote(char *input, t_input *new_input, int *i)
// {
// 	int		q;
// 	char	c;

// 	q = 0;
// 	c = 0;
// 	if (char_is_a_quote(input, *i))
// 	{
// 		q = which_quote_inp(new_input);
// 		c = input[*i];
// 		if (!q)
// 			toggle_quote_inp(input, new_input, i);
// 		else if ((q == 1 && input[*i] == '\'') || (q == 2 && input[*i] == '"'))
// 			toggle_quote_inp(input, new_input, i);
// 		else
// 			return (1);
// 	}
// 	if (!input[*i])
// 		return (0);
// 	return (1);
// }

// int	is_expend(char *input, t_input *new_input, int *i)
// {
// 	if (input[*i] == '$')
// 	{
// 		if (new_input->in_squote)
// 			return (1);
// 		else
// 			go_expend(input, new_input, i);
// 		(*i)++;
// 	}
// 	if (input[*i] == '$')
// 		is_expend(input, new_input, i);
// 	if (!input[*i])
// 		return (0);
// 	return (1);
// }

// void	go_expend(char *input, t_input *new_input, int *i)
// {
// 	if (!input)
// 		return ;
// 	if (!new_input) // a enlever sert a rien
// 		return ;
// 	// strduplicate le mot (while !is_space)
// 	// trouver la variable d'env
// 	// strduplicate la varaible d'env
// 	// et add_char_in_word la variable d'env
// }
