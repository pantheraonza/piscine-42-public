/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtracking.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maragon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/19 16:44:15 by maragon-          #+#    #+#             */
/*   Updated: 2026/04/19 17:44:51 by maragon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

int	es_seguro(int **g, int i, int j, int n)
{
	int	x;
	x = 0;
	while (x < 4)
	{
	if (g[i][x] == n || g[x][j] == n)
	return (0);
		x++;
	}
	return (1);
}

int	solve(int **g, int pos)
{
	int	i;
	int	j;
	int	n;

	if (pos == 16)
	return (1);

	i = pos / 4;
	j = pos % 4;
	n = 1;
	while (n <= 4)
	{
		if (es_seguro(g, i, j, n))
		{
			g[i][j] = n;
			if (solve(g, pos + 1))
			return (1);
			g[i][j] = 0;
		}
		n++;
	}
	return (0);
}
int	main(void)
{
	int	tamaño;
	int	**tablero;

	tamaño = 4;
	tablero = crear_tablero(tamaño);
	if (!tablero)
		return (1);
	if (solve(tablero, 0))
	{
		imprimir(tablero, tamaño);
	}
	else
	{
		write(1, "Error: No hay solucion\n", 23);
	}
	libera(tablero, tamaño);
	return (0);
}
