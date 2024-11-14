/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tsp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cadenegr <neo_dgri@hotmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 11:47:20 by cadenegr          #+#    #+#             */
/*   Updated: 2024/11/06 12:05:57 by cadenegr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <math.h>
#include <float.h>

float	dis(double x0, double y0,double x1, double y1)
{
	float	dx, dy;
	dx = x1 - x0;
	dy = y1 - y0;
	return (sqrt(dx * dx + dy * dy));
}

void	swap(int *a, int *b)
{
	int tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	tsp(int *p, int start, int end, double x[], double y[], double *min)
{
	int i, total_distance = 0;
	if (start == end)
	{
		i = 0;
		while (i < end)
		{
			total_distance += dis(x[p[i]], y[p[i]], x[p[i + 1]], y[p[i + 1]]);
			i++;
		}
		total_distance += dis(x[p[end]], y[p[end]], x[p[0]], y[p[0]]);
		if (*min > total_distance)
			*min = total_distance;
	}
	i = start;
	while (i < end)
	{
		swap(&p[start], &p[i]);
		tsp(p, start + 1, end, x, y, min);
		swap(&p[start], &p[i]);
		i++;
	}
}


int	main ()
{
	double	x[11];
	double	y[11];
	double	min;
	int		p[11];

	int	i = 0;
	while (fscanf(stdin, "%lf, %lf", &x[i], &y[i]) == 2)
	{
		p[i] = i;
		i++;
	}
	min = DBL_MAX;
	tsp(p, 0, i - 1, x, y, &min);
	printf("%.2lf\n", min);
	return 0;
}