/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   permutations.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cadenegr <neo_dgri@hotmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 10:31:25 by cadenegr          #+#    #+#             */
/*   Updated: 2024/11/06 10:59:43 by cadenegr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>

void	swap(int *a, int *b)
{
	int tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	second_step(char *s, int i, int j)
{
	if (i > j)
		swap(&i, &j);
	int	tmp;
	while (j > i)
	{
		tmp = s[i];
		s[i] = s[i + 1];
		s[i + 1] = tmp;
		i++;
	}
}

void	first_step(char *s, int i, int j)
{
	if (i > j)
		swap(&i, &j);
	int	tmp;
	while (j > i)
	{
		tmp = s[j];
		s[j] = s[j - 1];
		s[j - 1] = tmp;
		j--;
	}
}

int	get_min(char *s, int i)
{
	int	min = i;
	while (s[i])
	{
		if (s[i] < s[min])
			min = i;
		i++;
	}
	return min;
}

void	sort(char *s)
{
	int	i = 0, j = 0;
	while(s[i])
	{
		j = get_min(s, i);
		first_step(s, i, j);
		i++;
	}
}

void	permute(char *s, int start, int end)
{
	if (start == end)
		printf("%s\n", s);
	else
	{
		int i = start;
		while (i <= end)
		{
			first_step(s, start, i);
			permute(s, start + 1, end);
			second_step(s, start, i);
			i++;
		}
	}
}

int	main(int ac, char **av)
{
	if (ac != 2)
		return 1;
	char	*arg = av[1];
	int	len = strlen(arg);
	sort(arg);
	permute(arg, 0, len - 1);
	return 0;
}