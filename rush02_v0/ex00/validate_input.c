/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: criredon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/26 12:10:04 by criredon          #+#    #+#             */
/*   Updated: 2026/04/26 12:11:03 by criredon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush-02.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i = i + 1;
	}
	return (i);
}

int	validate_input(int argc, char **argv)

{
	char	*user_input;
	int		i;

	if (argc < 2 || argc > 3)
	{
		return (0);
	}
	user_input = argv[argc - 1];
	if (ft_strlen(user_input) == 0)
	{
		return (0);
	}
	i = 0;
	while (user_input[i] != '\0')
	{
		if (user_input[i] < '0' || user_input[i] > '9')
		{
			return (0);
		}
		i = i + 1;
	}
	return (1);
}

/*
Utilitarios:
ft_strlen --> cuenta caracteres del string hasta el '\0'

Funciones y Notas Importantes:
key_number = argv[argc - 1] --> la clave a convertir es siempre
la ultima, si argc=3 entonces 3-1=2, la clave es el argv[2]
validate_input --> prueba la casuisticas de error

Casuisticas de Error:
1. Si tiene más que 3 argumentos --> (argc < 2 || argc > 3)
2. Si no es un numero entero --> (key[i] < '0' || key[i] > '9')
*/