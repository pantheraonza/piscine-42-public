/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush-02.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: criredon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/26 15:30:57 by criredon          #+#    #+#             */
/*   Updated: 2026/04/26 15:31:00 by criredon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

typedef struct s_dict
{
	char	*dict_number;
	char	*dict_words;
}	t_dict;

int		ft_strlen(char *str);
void	ft_strcpy(char *destination, char *source);
int		ft_strcmp(char *a, char *b);
void	ft_strsub(char *result, char *a, char *b);
void	ft_strdiv(char *result, char *a, char *b);
int		validate_input(int argc, char **argv);
int		split_line(char *line, char *dict_number, char *dict_words);
int		fill_struct(char *line, t_dict *dict_entry);
char	*read_file(char *file_path);
int		read_diccionary(char *file_path, t_dict *dict);
int		find_dict_key(t_dict *dict, int dict_size, char *number);
void	convert_input(char *number, t_dict *dict, int dict_size);

/*
	Librerias:
	<fcnt1.h> para utilizar open
	<stdlib.h> para utilizar mallon y free
*/