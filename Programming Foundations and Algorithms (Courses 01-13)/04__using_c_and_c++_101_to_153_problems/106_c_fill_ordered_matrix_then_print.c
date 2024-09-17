#/*
Problem:
Write a program to fill a 3x3 matrix with random numbers.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void	ft_fill_2d_array_with_ordered_nbrs(int **array)
{
	short	c1;
	short	c2;
	short	nbr;

	nbr = 0;
	c1 = -1;
	c2 = -1;
	while (++c1 < 3)
	{
		c2 = -1;
		while (++c2 < 3)	
			array[c1][c2] = ++nbr;
	}
}

void	ft_print_2d_array(int **array)
{
	short	c1;
	short	c2;

	c1 = -1;
	while (++c1 < 3)
	{
		c2 = -1;
		while (++c2 < 3)	
			if (c2 != 2)
				printf("%3d\t,", array[c1][c2]);
			else 
				printf("%3d\n", array[c1][c2]);
	}
	printf("\n");
}

int	main(void)
{

	int	**p_2d_array;
	short	c;

	p_2d_array = (int **)malloc(3 * sizeof(int *));
	c = -1;
	while (++c < 3)
		p_2d_array[c] = (int *)malloc(3 * sizeof(int));
	ft_fill_2d_array_with_ordered_nbrs(p_2d_array);
	ft_print_2d_array(p_2d_array);
	free(p_2d_array);
	return (0);
}
