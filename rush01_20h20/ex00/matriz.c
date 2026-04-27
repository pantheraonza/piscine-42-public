/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matriz.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: criredon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/19 17:38:09 by criredon          #+#    #+#             */
/*   Updated: 2026/04/19 17:44:04 by criredon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

void	liberar(int **tablero, int talla)
{
	int	i;

	i = 0;
	while (i < talla)
	{
		free(tablero[i]);
		i++;
	}
	free (tablero);
}

void	imprimir(int **tablero, int talla)
{
	int		i;
	int		j;
	char	c;

	i = 0;
	j = 0;
	while (i < talla)
	{
		while (j < talla)
		{
			c = tablero[i][j] + '0';
			write(1, &c, 1);
			write(1, " ", 1);
			j++;
		}
		write(1, "\n", 1);
		j = 0;
		i++;
	}
}

void	llenar(int **tablero, int talla)
{
	int	i;
	int	j;
	int	valor;

	i = 0;
	j = 0;
	valor = 1;
	while (i < talla)
	{
		if (valor > 4)
			valor = 1;
		while (j < talla)
		{
			if (valor > 4)
				valor = 1;
			tablero[i][j] = valor;
			valor++;
			j++;
		}
		j = 0;
		i++;
	}
}

int	**crear_tablero(int talla)
{
	int	i;
	int	**tablero;

	i = 0;
	tablero = (int **)malloc(talla * sizeof(int *));
	while (i < talla)
	{
		tablero[i] = (int *)malloc(talla * sizeof(int));
		i++;
	}
	return (tablero);
}

/*
COMENTARIOS
#include <stdlib.h> //for malloc

//llena el tablero con numeros aleatorios para probar
void	llenar(int **tablero, int talla)

	while (i < talla)
		if (valor > 4)//para que no pase de 4
			valor = 1;
		while (j < talla)
			if (valor > 4) //para que no pase de 4

// imprime el tablero solucion
void	imprimir(int **tablero, int talla)

//borra el tablero de la memoria porque no se
puede quedar ahi al final del programa
void	libera(int **tablero, int talla)

//crea en memoria una matriz de 4x4 ints y la devuelve
int	**crear_tablero(int talla)

	tablero = (int **)malloc(talla * sizeof(int *));
	//reservo una columna de int *
	//if error, free y return

	tablero[i] = (int *)malloc(talla * sizeof(int));
	//relleno cada fila con 4 int
	//if error, free y return
*/
/*
int	main(void)
{
	int	talla;
	int	**tablero;

	talla = 4;
	tablero = crear_tablero(talla);
	llenar(tablero, talla);
	imprimir(tablero, talla);
	liberar(tablero, talla);
	return (0);
}
*/