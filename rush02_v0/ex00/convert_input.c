/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_input.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: criredon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/26 16:00:47 by criredon          #+#    #+#             */
/*   Updated: 2026/04/26 16:00:49 by criredon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush-02.h"

int	find_dict_key(t_dict *dict, int dict_size, char *number)
{
	int	i;

	i = dict_size - 1;
	while (i >= 0)
	{
		if (ft_strcmp(dict[i].dict_number, number) <= 0)
		{
			return (i);
		}
		i = i - 1;
	}
	return (-1);
}

void	convert_input(char *number, t_dict *dict, int dict_size)
{
	int		input_index;
	char	quotient[256];
	char	remainder[256];

	if (number[0] == '0' && number[1] == '\0')
	{
		write(1, dict[0].dict_words, ft_strlen(dict[0].dict_words));
		return ;
	}
	while (ft_strcmp(number, "0") > 0)
	{
		input_index = find_dict_key(dict, dict_size, number);
		if (input_index == -1)
		{
			write(1, "Dict Error\n", 11);
			return ;
		}
		if (ft_strlen(dict[input_index].dict_number) > 2)
		{
			ft_strdiv(quotient, number, dict[input_index].dict_number);
			ft_strsub(remainder, number, dict[input_index].dict_number);
			convert_input(quotient, dict, dict_size);
			write(1, " ", 1);
			write(1, dict[input_index].dict_words,
				ft_strlen(dict[input_index].dict_words));
			write(1, " ", 1);
			ft_strcpy(number, remainder);
		}
		else
		{
			write(1, dict[input_index].dict_words,
				ft_strlen(dict[input_index].dict_words));
			ft_strsub(number, number, dict[input_index].dict_number);
			if (ft_strcmp(number, "0") > 0)
				write(1, " ", 1);
		}
	}
}
