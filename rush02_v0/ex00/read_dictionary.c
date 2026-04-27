/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_dictionary.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: criredon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/26 12:10:04 by criredon          #+#    #+#             */
/*   Updated: 2026/04/26 12:11:03 by criredon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush-02.h"

char	*read_file(char *file_path)
{
	int		file_code;
	char	*file;
	int		bytes;

	file = (char *)malloc(8193);
	if (file == 0)
	{
		return (0);
	}
	file_code = open(file_path, O_RDONLY);
	if (file_code < 0)
	{
		free(file);
		return (0);
	}
	bytes = read(file_code, file, 8192);
	file[bytes] = '\0';
	close(file_code);
	return (file);
}

int	process_entry(char *file, char *line, t_dict *dict, int count)
{
	if (fill_struct(line, &dict[count]) == 0)
	{
		free(file);
		return (0);
	}
	return (1);
}

int	create_line(char *file, char *line, int i)
{
	int	j;

	j = 0;
	while (file[i] != '\0' && file[i] != '\n')
	{
		line[j] = file[i];
		j = j + 1;
		i = i + 1;
	}
	line[j] = '\0';
	return (j);
}

int	fill_dictionary(char *file, t_dict *dict)
{
	char	line[256];
	int		i;
	int		j;
	int		count;

	i = 0;
	count = 0;
	while (file[i] != '\0')
	{
		j = create_line(file, line, i);
		i = i + j;
		if (j > 0)
		{
			if (process_entry(file, line, dict, count) == 0)
			{
				return (-1);
			}
			count = count + 1;
		}
		if (file[i] == '\n')
		{
			i = i + 1;
		}
	}
	return (count);
}

int	read_diccionary(char *file_path, t_dict *dict)
{
	char	*file;
	int		count;

	file = read_file(file_path);
	if (file == 0)
	{
		return (-1);
	}
	count = fill_dictionary(file, dict);
	free(file);
	return (count);
}
/*
	Utilitarios:
	count_lines --> hace un recuento de saltos de línea '\n'
	ft_strcpy --> copia el contenido de un string a otro

	Funciones y Notas Importantes:
	file --> donde se guarda el contenido del diccionario
	read_file --> abre el archivo y crea el espacio de
	memoria parar guardar el input (que puede ser ). 
	file_code --> es el identificador del archivo (indexador)
	que la funcion open utiliza para abrirlo y read para leer.
	si open falla al abrir, retorna resultado -1, con lo
	cual necesita vaciar/liberar la memoria con free(file);
	bytes --> el tamaño leido
	read recibe 3 parametros: el identificador del archivo,
	donde va a guardar lo que se lea, y cuantos bytes quiero
	leer. devuelvo cuantos bytes leyo realmente.
	file[bytes] = '\0' --> read no añade el '\0' al final, 
	hay que ponerlo. bytes es un contador como i. si la
	palabra fuera hola, el contador seria = 4 --> file[0] = h
	file[1] = o, file[2] = l, file[3] = a. en la posicion
	file [4] es donde file[bytes] va a poner el '\0'.
	return(file) --> devuelve el string con todo el contenido
	malloc --> para el tamaño esperado multiplico 41 líneas
	por 50 caracteres maximo = 2050. se suelen utilizar bloques
	de potencias de 2 (512, 1024, 2048, 4096, 8192).

*/