/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   n_queens.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wel-safa <wel-safa@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 22:36:03 by wel-safa          #+#    #+#             */
/*   Updated: 2024/11/12 13:20:03 by wel-safa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* TASK:
Given a number n, you have to place n queens on a chess board with the size n*n
while the queens cannot attack each other.

You have to print all the different solutions in the following format:
1 3 0 2
2 0 3 1
*/

#include <stdio.h>
#include <stdlib.h>

int	arequeensok(int *arr, int row, int col)
{
	int i = 0;

	while (i < col)
	{
		if (arr[i] == row)
			return (0);
		if (arr[i] == row - (col - i))
			return (0);
		if (arr[i] == row + (col - i))
			return (0);
		i++;
	}
	return (1);
}

void	printsol(int *arr, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d", arr[i]);
		if (i < n - 1)
			printf(" ");	
	}
	printf("\n");
}

void	n_queens(int *arr, int n, int col)
{
	int row = 0;
	while (row < n)
	{
		arr[col] = row;
		if (arequeensok(arr, row, col))
		{
			if (col == n - 1)
				printsol(arr, n);
			else
				n_queens(arr, n, col + 1);
		}
		row++;
	}
}

int main(int ac, char **av)
{
	if (ac != 2)
		return (0);
	int n = atoi(av[1]); // number of queens
	int arr[n]; // array to save result [col1 col2 col3 ... coln]
	n_queens(arr, n, 0);
	return (0);
}
