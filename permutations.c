/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   permutations.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wel-safa <wel-safa@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 10:42:01 by wel-safa          #+#    #+#             */
/*   Updated: 2024/11/07 11:42:28 by wel-safa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Assignment name  : permutations
Expected files   : *.c *.h
Allowed functions: puts, malloc, calloc, realloc, free, write
---------------------------------------------------------------

Write a program that will print all the permutations of a string given as argument.

The solutions must be given in alphabetical order.

We will not try your program with strings containing duplicates (eg: 'abccd').

For example this should work:

$> ./permutations a | cat -e
a$

$> ./permutations ab | cat -e
ab$
ba$

$> ./permutations abc | cat -e
abc$
acb$
bac$
bca$
cab$
cba$
*/


#include <stdio.h>
#include <stdlib.h>

void swap(char *str, int i, int j)
{
	char c = (str)[i];
	(str)[i] = (str)[j];
	(str)[j] = c;
}

void permutations(char *str, int start, int end)
{
	if (!str)
		return ;
	if (!(*str))
		return ;
	if (start == end)
	{
		// print permutation & RETURN
		puts(str);
		return ;
	}
	for (int i = start; i < end; i++)
	{
		// swap current character with start character
		swap(str, start, i); 

		// call function recursively for next character
		permutations(str, start + 1, end);

		// Backtrack: swap back to original position
		swap(str, start, i);
	}
}

int ft_strlen(char *s)
{
	int i = 0;
	if (!s)
		return (0);
	while(s[i])
		i++;
	return (i);
}

void sortstring(char *str)
{
	if (!str) return;
	int len = ft_strlen(str);
	for (int i = 0; i < len - 1; i++)
	{
		for (int j = 0; j < len - i - 1; j++)
		{
			if (str[j] > str[j + 1])
			{
				char temp = str[j];
				str[j] = str[j + 1];
				str[j + 1] = temp;
			}
		}
	}
}

int	main(int ac, char **av)
{
	if (ac != 2)
		return (1);
	
	int len = ft_strlen(av[1]);

	char *str = (char *)calloc(sizeof(char), len + 1);
	for (int i = 0; i < len; i++)
		str[i] = av[1][i];
	sortstring(str);
	permutations(str, 0, len);
	free(str);
}
