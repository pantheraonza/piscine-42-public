/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solucionar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maragon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/19 16:44:15 by maragon-          #+#    #+#             */
/*   Updated: 2026/04/19 17:44:51 by maragon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

int comprueba(int *fuera, int **tablero, int posicion);

int	posicionar(int **tablero, int i, int j, int num)
{
	int	x;

	x = 0;
	while (x < 4)
	{
		if (tablero[i][x] == num || tablero[x][j] == num)
			return (0);
		x++;
	}
	return (1);
}

int	solucionar(int **tablero, int posicion, int *pistas)
{
	int	i;
	int	j;
	int	n;
	int	p;

	if (posicion == 16)
	{
		p = 0;
		while (p < 16)
		{
			if (!comprueba(pistas, tablero, p))
        		return (0);
    		p++;
		}
		return (1);
	}
	i = posicion / 4;
	j = posicion % 4;
	n = 1;
	while (n <= 4)
	{
		if (posicionar(tablero, i, j, n))
		{
			tablero[i][j] = n;
			if (solucionar(tablero, posicion + 1, pistas))
				return (1);
			tablero[i][j] = 0;
		}
		n++;
	}
	return (0);
}
