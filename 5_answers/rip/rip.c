/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rip.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cadenegr <neo_dgri@hotmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 10:10:26 by cadenegr          #+#    #+#             */
/*   Updated: 2024/11/06 10:29:08 by cadenegr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	is_balance(char *res)
{
	int	balance = 0;
	int i = 0;
	while (res[i])
	{
		if (res[i] == '(')
			balance++;
		if (res[i] == ')')
			balance--;
		if (balance < 0)
			return 0;
		i++;
	}
	return (balance == 0);
}


void	rip(char *arg, int start, int open, int close, char *res, int i_res)
{
	if (open < 0 || close < 0)
		return;
	if (arg[start] == '\0')
	{
		res[i_res] = '\0';
		if (is_balance(res))
			puts(res);
		return;
	}
	res[i_res] = arg[start];
	rip(arg, start + 1, open, close, res, i_res + 1);
	if (arg[start] == '(')
	{
		res[i_res] = ' ';
		rip(arg, start + 1, open - 1, close, res, i_res + 1);
	}
	else if (arg[start] == ')')
	{
		res[i_res] = ' ';
		rip(arg, start + 1, open, close - 1, res, i_res + 1);
	}
}


int	main(int ac, char **av)
{
	if (ac != 2)
		return 1;

	char *arg = av[1];
	int	open_paraenthesis = 0, close_parenthesis = 0, i = 0;
	while (arg[i])
	{
		if (arg[i] == '(')
			open_paraenthesis++;
		else if (arg[i] == ')')
		{
			if (open_paraenthesis > 0)
				open_paraenthesis--;
			else
				close_parenthesis++;
		}
		i++;
	}
	char *result = malloc(sizeof(char) * (i + 1));
	if (!result)
		return 1;
	rip(arg, 0, open_paraenthesis, close_parenthesis, result, 0);
	free(result);
	return 0;
}