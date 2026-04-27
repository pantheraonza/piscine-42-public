/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: criredon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/19 18:01:47 by criredon          #+#    #+#             */
/*   Updated: 2026/04/19 21:35:55 by criredon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

int		validar(char *str);
int		**crear_tablero(int talla);
void	parsear(char *str, int *pistas);
void	imprimir(int **tablero, int talla);
void	liberar(int **tablero, int talla);
int		solucionar(int **tablero, int posicion, int *pistas);
int		comprueba(int *fuera, int **tablero, int posicion);

int	main(int argc, char **argv)
{
	int	**tablero;
	int	pistas[16];
	int	talla;
	int	i;
	int	j;

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
	talla = 4;
	tablero = crear_tablero(talla);
	i = 0;
	while (i < talla)
	{
		j = 0;
		while (j < talla)
		{
			tablero[i][j] = 0;
			j++;
		}
		i++;
	}
	parsear(argv[1], pistas);
	if (solucionar(tablero, 0, pistas))
		imprimir(tablero, talla);
	else
		write(1, "Error\n", 6);
	liberar(tablero, talla);
	return (0);
}

	/*
	PONER DENTRO DEL MAIN

write(1, "No te puedo contestar. Gracias. :)", 30);
	return (0);
	
	*/