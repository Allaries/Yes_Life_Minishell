/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expend.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smedenec <smedenec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 20:51:07 by smedenec          #+#    #+#             */
/*   Updated: 2026/03/20 18:55:13 by smedenec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	expend_word(char *input, t_data *data, t_word *word, int *i)
{
	char	*var;
	char	*expend;
	int		start;

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
	return (add_expend_in_word(word, expend));
}

int	add_expend_in_word(t_word *word, char *expend)
{
	int	y;

	y = 0;
	if (!expend)
		return (1);
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
