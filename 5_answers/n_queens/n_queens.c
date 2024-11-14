/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   n_queens.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cadenegr <neo_dgri@hotmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 11:02:03 by cadenegr          #+#    #+#             */
/*   Updated: 2024/11/06 11:15:42 by cadenegr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void	print_sol(int *a, int n)
{
	for (int i = 0; i < n; i++)
	{
		if (i == 0)
			fprintf(stdout, "%d", a[i]);
		else
			fprintf(stdout, " %d", a[i]);
	}
	fprintf(stdout, "\n");
}

int	safe_q(int *a, int row, int col)
{
	for (int i = 0; i < col; i++)
	{
		if (a[i] == row)
			return 0;
		if (a[i] - i == row - col)
			return 0;
		if (a[i] + i == row + col)
			return 0;
	}
	return 1;
}

void	solve_q(int *a, int n, int col)
{
	if (n == col)
	{
		print_sol(a, n);
		return;
	}
	int i = 0;
	while (i < n)
	{
		if (safe_q(a, i, col))
		{
			a[col] = i;
			solve_q(a, n, col + 1);
		}
		i++;
	}
}

int	main(int ac, char **av)
{
	if (ac != 2)
		return 1;
	int	n = atoi(av[1]);
	if (n < 1)
		return 1;
	int *res = malloc(sizeof(int) * n);
	if (!res)
		return 1;
	int i = 0;
	while (res[i])
	{
		res[i] = -1;
		i++;
	}
	int	col = 0;
	solve_q(res, n, col);
	free(res);
	return 0;
}