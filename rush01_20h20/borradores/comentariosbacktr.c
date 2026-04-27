#include <stdlib.h>
#include <unistd.h>

int	es_seguro(int **g, int i, int j, int n)
{
	int	x;
	x = 0; //Valor número
	while (x < 4)
	{
		if (g[i][x] == n || g[x][j] == n) // Comprueba si el número ya esta en la fila.
				return (0);			// Comprueba si el número ya está en la columna.
			x++;
	}
	return (1); //Si llega aqui, es seguro ponerlo.
}

int	solve(int **g, int pos)
{
	int i; //Fila
	int j; //Columna
	int n; //Número

	if (pos == 16)
			return (1);

	i = pos / 4;
	j = pos % 4;
	n = 1;

	while (n <= 4)
	{
		if (es_seguro(g, i, j, n))
		{
			g[i][j] = n; //Probamos el número.
			if (solve(g, pos + 1)) // Intentamos resolver el resto
					return (1);
			g[i][j] = 0; // Si falló, borramos.
		}
		n++;
	}
	return (0); //No hay solución por este camino
}
