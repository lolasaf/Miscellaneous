/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tsp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wel-safa <wel-safa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 21:06:40 by wel-safa          #+#    #+#             */
/*   Updated: 2024/11/13 01:52:31 by wel-safa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Assignment name  : tsp
Expected files   : *.c *.h
Allowed functions and globals: write, sqrtf, getline, fabsf, memcpy, printf,
malloc, calloc, realloc, free, errno, write, fscanf
*/
/*-----------------------------------------------------------------------------

The first publication referring to this problem as the 
"traveling salesman problem"
is found in the 1949 RAND Corporation report by Julia Robinson,
"On the Hamiltonian game (a traveling salesman problem)."

Here is how she defines the problem:

"The purpose of this note is to give a method for solving a problem related
to the traveling salesman problem. It seems worthwhile to give a description
of the original problem. One formulation is to find the shortest route for a
salesman starting from Washington, visiting all the state capitals and then
returning to Washington.
More generally, to find the shortest CLOSED CURVE
containing n given points in the plane."

For example with the following set of cities:
0, 0
1, 0
2, 0
0, 1
1, 1
2, 1
1, 2
2, 2

which can be represented as follows:
 +  +  +
 +  +  +
    +  +

the shortest path is:
  _____
 |__   |
    |__|

so you should print the length of this path that is:
8.00

Write a program that will read a set of city coordinates under the form
"%f, %f\n" from the standard input and will print the length of the shortest
possible path containing all these cities under the form "%.2f".

Your program will not be tested with more than 11 cities.

You will find in this directory a file tsp.c containing all the boring parts of
this exercise and example files to help you test your program.

hint: In order to use sqrtf, add -lm at the end of your compilation command.

For example this should work:
$> cat square.txt
1, 1
0, 1
1, 0
0, 0
$> ./tsp < square.txt | cat -e
4.00$
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float compute_distance(float **dist_matrix, int *sol, int count)
{
	float total_dist = 0;
	for (int i = 0; i < count; i++)
	{
		if (i == count - 1)
			total_dist += dist_matrix[sol[i]][sol[0]];
		else
			total_dist += dist_matrix[sol[i]][sol[i + 1]];
	}
	return (total_dist);
}

float calculate_distance(float *p1, float *p2)
{
	float distance;

	if (p1 == p2) return 0;
	
	distance = sqrtf((p1[0] - p2[0])*(p1[0] - p2[0]) + (p1[1] - p2[1])*(p1[1] - p2[1]));
	return (distance);
}

float	solve_tsp(float **dist_matrix, int *sol, int start, int count, float min_dist)
{
	if (start == count)
	{
		float curr_dist = compute_distance(dist_matrix, sol, count);
		if (curr_dist < min_dist)
			return (curr_dist);
		else
			return (min_dist);
	}
	else
	{
		for (int j = start; j < count; j++)
		{
			int swap = sol[j];
			sol[j] = sol[start];
			sol[start] = swap;

			min_dist = solve_tsp(dist_matrix, sol, start + 1, count, min_dist);

			swap = sol[j];
			sol[j] = sol[start];
			sol[start] = swap;
		}
	}
}

int	main(void)
{
	float x, y;
	int count = 0;
	float **coords = NULL; // coordinates
	
	while(fscanf(stdin, "%f, %f\n", &x, &y) == 2)
	{
		coords = realloc(coords, sizeof(float *) * (count + 1));
		coords[count] = malloc(sizeof(float) * 2);
		coords[count][0] = x;
		coords[count][1] = y;
		count++;
	}
	
	float **dist_matrix = malloc(sizeof(float *) * count); // distance matrix
	
	for (int j = 0; j < count; j++)
	{
		dist_matrix[j] = malloc (sizeof(float) * count);
		for (int k = 0; k < count; k++)
		{
			dist_matrix[j][k] = calculate_distance(coords[j], coords[k]);
		}
	}
	
	int sol[count];
	for (int i = 0; i < count; i++)
		sol[i] = i;
	float min_dist = solve_tsp(dist_matrix, sol, 0, count, INFINITY);
	
	printf("%.2f\n", min_dist);
	// NEED TO FREE coords + dist_matrix

	
	/*Print coordinates test*/
	/*for(int j = 0; j < i; j++)
	{
		printf("(%.2f, %.2f)\n", coords[j][0], coords[j][1]);
	}*/

}