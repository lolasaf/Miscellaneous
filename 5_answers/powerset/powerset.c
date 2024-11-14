/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   powerset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cadenegr <neo_dgri@hotmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 11:17:21 by cadenegr          #+#    #+#             */
/*   Updated: 2024/11/06 11:38:04 by cadenegr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

void	printsubset(int *arr, int n, int mask)
{
	int start = 1, i = 0;
	while (i < n)
	{
		if (mask & 1 << i)
		{
			if (start)
			{
				fprintf(stdout, "%d", arr[i]);
				start = 0;
			}
			else
				fprintf(stdout, " %d", arr[i]);
		}
		i++;
	}
	fprintf(stdout, "\n");
}

int	sumsubset(int *arr, int n, int mask)
{
	int sum = 0, i = 0;
	while (i < n)
	{
		if (mask & 1 << i)
			sum += arr[i];
		i++;
	}
	return sum;
}


void	powerset(int *arr, int n, int base)
{
	int total_combo = 1 << n;

	int	mask = 0;
	while (mask < total_combo)
	{
		if ((sumsubset(arr, n, mask)) == base)
			printsubset(arr, n, mask);
		mask++;
	}
}


int	main(int ac, char **av)
{
	if (ac < 3)
		return 1;
	int base = atoi(av[1]);
	int	n = ac - 2;
	int	*args = malloc(sizeof(int) * n);
	if (!args)
		return 1;
	int i = 0;
	while (i < n)
	{
		args[i] = atoi(av[i + 2]);
		i++;
	}
	powerset(args, n, base);
	free(args);
	return 0;
}