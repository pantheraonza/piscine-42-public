/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: criredon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/19 18:01:47 by criredon          #+#    #+#             */
/*   Updated: 2026/04/19 18:01:52 by criredon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

int		validar(char *str);
int		**crear_tablero(int talla);
void	llenar(int **tablero, char *str);
void	imprimir(int **tablero, int talla);
void	liberar(int **tablero, int talla);

int	main(int argc, char **argv)
{
	int	**tablero;
	int	talla;

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
	llenar(tablero, argv[1]);
	imprimir(tablero, talla);
	liberar(tablero, talla);
	return (0);
}
