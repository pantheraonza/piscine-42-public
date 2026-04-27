/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comprobar_.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: criredon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/19 21:12:30 by criredon          #+#    #+#             */
/*   Updated: 2026/04/19 21:12:36 by criredon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	comprueba_normal1(int **tablero, int linea)
{
	int	i;
	int	maximo;
	int	cuenta;

	i = 0;
	maximo = 0;
	cuenta = 0;
	while (i < 4)
	{
		if (tablero[i][linea] > maximo)
		{
			cuenta++;
			maximo = tablero[i][linea];
		}
		i++;
	}
	return (cuenta);
}

int	comprueba_normal2(int **tablero, int linea)
{
	int	i;
	int	maximo;
	int	cuenta;

	maximo = 0;
	cuenta = 0;
	i = 0;
	while (linea < 4)
	{
		if (tablero[i][linea] > maximo)
		{
			cuenta++;
			maximo = tablero[i][linea];
		}
		linea++;
	}
	return (cuenta);
}

int	comprueba_reverse1(int **tablero, int linea)
{
	int	i;
	int	maximo;
	int	cuenta;

	maximo = 0;
	cuenta = 0;
	i = 3;
	while (i >= 0)
	{
		if (tablero[i][linea] > maximo)
		{
			cuenta++;
			maximo = tablero[i][linea];
		}
		i--;
	}
	return (cuenta);
}

int	comprueba_reverse2(int **tablero, int linea)
{
	int	i;
	int	maximo;
	int	cuenta;

	cuenta = 0;
	maximo = 0;
	i = 3;
	while (linea >= 0)
	{
		if (tablero[i][linea] > maximo)
		{
			cuenta++;
			maximo = tablero[i][linea];
		}
		linea--;
	}
	return (cuenta);
}

int	comprueba(int *fuera, int **tablero, int posicion)
{
	int	cuenta;
	int	linea;

	cuenta = 0;
	linea = posicion % 4;
	if (0 <= posicion && posicion <= 3)
		cuenta = comprueba_normal1(tablero, linea);
	else if (4 <= posicion && posicion <= 7)
		cuenta = comprueba_reverse1(tablero, linea);
	else if (8 <= posicion && posicion <= 11)
		cuenta = comprueba_normal2(tablero, linea);
	else if (12 <= posicion && posicion <= 15)
		cuenta = comprueba_reverse2(tablero, linea);
	return (fuera[posicion] == cuenta);
}

/*
COMENTARIOS

//para los numeros de arriba//
//para los numeros de la izquierda//
//para los numeros de abajo//
//comprueba los de la derecha//

//comprueva los edificios que se ven desde cada posicion
//la posicion se refiere al numero de fuera que estoy
// comprobando.Si es el primero, col1up es == 0, el
// segundo == 2, si es fila1left es == 8
//devuelve 0 si no es correcta la posicion y 1 si es correcta

x 0 1 2 3 x
8         12
9         13
10        14
11        15
x 4 5 6 7 x

*/