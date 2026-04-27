/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: criredon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/26 15:40:46 by criredon          #+#    #+#             */
/*   Updated: 2026/04/26 15:40:51 by criredon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush-02.h"

void	free_dict(t_dict *dict, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		free(dict[i].dict_number);
		free(dict[i].dict_words);
		i = i + 1;
	}
}

int	main(int argc, char **argv)
{
	t_dict	dict[50];
	char	*dict_path;
	int		dict_size;

	if (validate_input(argc, argv) == 0)
	{
		write(1, "Error\n", 6);
		return (1);
	}
	if (argc == 3)
		dict_path = argv[1];
	else
		dict_path = "numbers.dict";
	dict_size = read_diccionary(dict_path, dict);
	if (dict_size == -1)
	{
		write(1, "Dict Error\n", 11);
		return (1);
	}
	convert_input(argv[argc - 1], dict, dict_size);
	write(1, "\n", 1);
	free_dict(dict, dict_size);
	return (0);
}
