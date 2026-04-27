/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: criredon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 19:21:11 by criredon          #+#    #+#             */
/*   Updated: 2026/04/15 21:11:58 by criredon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_swap(int *a, int *b)
{
	int	swap;

	swap = *a;
	*a = *b;
	*b = swap;
}
/*
int	main(void)
{
	int	a;
	int	b;

	a = 24;
	b = 42;
	printf("antes de intercambiar a=%d b=%d\n", a, b);
	ft_swap(&a, &b);
	printf("despues de intercambiar a=%d b=%d\n", a, b);
	return (0);
}
*/
