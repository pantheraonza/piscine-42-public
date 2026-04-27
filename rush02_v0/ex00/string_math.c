/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_math.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: criredon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/26 20:29:07 by criredon          #+#    #+#             */
/*   Updated: 2026/04/26 20:29:10 by criredon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush-02.h"

int	ft_strcmp(char *a, char *b)
{
	int	i;

	if (ft_strlen(a) != ft_strlen(b))
		return (ft_strlen(a) - ft_strlen(b));
	i = 0;
	while (a[i] != '\0')
	{
		if (a[i] != b[i])
		{
			return (a[i] - b[i]);
		}
		i = i + 1;
	}
	return (0);
}

void	ft_strsub(char *result, char *a, char *b)
{
	int	i;
	int	j;
	int	carry;
	int	diff;

	i = ft_strlen(a) - 1;
	j = ft_strlen(b) - 1;
	carry = 0;
	while (i >= 0)
	{
		diff = (a[i] - '0') - carry;
		if (j >= 0)
			diff = diff - (b[j] - '0');
		if (diff < 0)
		{
			diff = diff + 10;
			carry = 1;
		}
		else
			carry = 0;
		result[i] = diff + '0';
		i = i - 1;
		j = j - 1;
	}
	result[ft_strlen(a)] = '\0';
}

void	ft_strdiv(char *result, char *a, char *b)
{
	int		count;
	char	temp[256];

	count = 0;
	ft_strcpy(temp, a);
	while (ft_strcmp(temp, b) >= 0)
	{
		ft_strsub(temp, temp, b);
		count = count + 1;
	}
	result[0] = count + '0';
	result[1] = '\0';
}
