/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validar.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: criredon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/19 12:11:08 by criredon          #+#    #+#             */
/*   Updated: 2026/04/19 12:31:04 by criredon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	validar(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (i % 2 == 0)
		{
			if (str[i] < '1' || str [i] > '4')
				return (0);
		}
		if (i % 2 != 0)
		{
			if (str[i] != ' ')
				return (0);
		}
		i++;
	}
	if (i != 31)
	{
		return (0);
	}
	return (1);
}

/*
MUY IMPORTANTE!!!
53 borrar write y sustitur por matriz_problema(argv[1]);

COMENTARIOS POR LINEA:
20 mientras no sea nulo el string
22 si en las posiciones pares son caracteres menores q 1 o mayores q 4
27 si en las posiciones impares los caracteres no son espacios
24 no avanza si no encuentra exactamente 31 posiciones
38 valido y quedo perfecto para la proxima fase
45 > 2 argumentos o si string de entrada es 0, error. argc[0] es la funcion.

MAIN PARA PROBAR ESTE ARCHIVO
int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	if (validar(argv[1]) == 0)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	write(1, "No te puedo contestar. Gracias. :)", 30);
	return (0);
}

PRUEBAS
./validar "4 3 2 1 1 2 2 2 4 3 2 1 1 2 2 2" | cat -e

*/