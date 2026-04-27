/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_dictionary.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: criredon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/26 12:10:04 by criredon          #+#    #+#             */
/*   Updated: 2026/04/26 12:11:03 by criredon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush-02.h"

void	ft_strcpy(char *destination, char *source)
{
	int	i;

	i = 0;
	while (source[i] != '\0')
	{
		destination[i] = source[i];
		i = i + 1;
	}
	destination[i] = '\0';
}

int	split_line(char *line, char *dict_number, char *dict_words)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (line[i] != ' ' && line[i] != ':' && line[i] != '\0')
	{
		dict_number[j] = line[i];
		j = j + 1;
		i = i + 1;
	}
	dict_number[j] = '\0';
	while (line[i] == ' ' || line[i] == ':' )
	{
		i = i + 1;
	}
	j = 0;
	while (line[i] != '\0' && line[i] != '\n')
	{
		dict_words[j] = line[i];
		j = j + 1;
		i = i + 1;
	}
	dict_words[j] = '\0';
	return (1);
}

int	fill_struct(char *line, t_dict *dict_entry)
{
	char	dict_number[64];
	char	dict_words[256];

	if (split_line(line, dict_number, dict_words) == 0)
	{
		return (0);
	}
	dict_entry->dict_number = (char *)malloc(64);
	dict_entry->dict_words = (char *)malloc(256);
	if (dict_entry->dict_number == 0 || dict_entry->dict_words == 0)
	{
		return (0);
	}
	ft_strcpy(dict_entry->dict_number, dict_number);
	ft_strcpy(dict_entry->dict_words, dict_words);
	return (1);
}
/*
	Utilitarios:
	ft_strcpy --> copia el contenido de un string a otro

	Atención: Tengo que crear la tabla (struct) en rush-02.h
	typedef struct s_dict
	{
    	char    *dict_number;
    	char    *dict_words;
	}   t_dict;

	Funciones y Notas Importantes:
	split_line -> tiene 2 bucles: uno para sacar el dict_number
	y otro para sacar el dict_words.
	fill_struct --> crea la tabla de datos. entry es un puntero
	a struct/tabla, es como decir "dentro de la tabla entry,
	en el campo/columna dict_number"
*/