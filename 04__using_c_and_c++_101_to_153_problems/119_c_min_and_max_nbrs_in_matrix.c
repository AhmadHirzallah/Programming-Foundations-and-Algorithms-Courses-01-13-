#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int	ft_generate_random_nbr_in_range(int from, int to)
{	
	int	i_generated_random_nbr;

	i_generated_random_nbr = rand() % (to - from + 1) + from;
	return (i_generated_random_nbr);
}

void	ft_fill_2d_array_with_random_nbrs(int **array)
{
	short	c1;
	short	c2;

	c1 = -1;
	c2 = -1;
	while (++c1 < 3)
	{
		c2 = -1;
		while (++c2 < 3)	
			array[c1][c2] = ft_generate_random_nbr_in_range(0, 20);
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
				printf("%d\t,", array[c1][c2]);
			else 
				printf("%d\n", array[c1][c2]);
	}
	printf("\n");
}

short	ft_get_max_nbr(int **array)
{
	short	c1;
	short	c2;
	short	max;

	max = array[0][0];
	c1 = -1;
	while (++c1 < 3)
	{
		c2 = -1;
		while (++c2 < 3)
			if (array[c1][c2] > max)
				max = array[c1][c2];
	}
	return (max);
}

short	ft_get_min_nbr(int **array)
{
	short	c1;
	short	c2;
	short	min;

	min = array[0][0];
	c1 = -1;
	while (++c1 < 3)
	{
		c2 = -1;
		while (++c2 < 3)
			if (array[c1][c2] < min)
				min = array[c1][c2];
	}
	return (min);
}

void	ft_print_max_and_min_nbrs_result(short max, short min)
{
	printf("\nThe maxiumum number is: (%d)\n", max);
	printf("\nThe minimum number is: (%d)\n", min);
}

int	main(void)
{
	int	**p_2d_array;
	short	max_nbr;
	short	min_nbr;
	short	c;

	srand((unsigned)time(NULL));
	p_2d_array = (int **)malloc(3 * sizeof(int *));
	c = -1;
	while (++c < 3)
		p_2d_array[c] = (int *)malloc(3 * sizeof(int));
	ft_fill_2d_array_with_random_nbrs(p_2d_array);
	printf("The array:\n");
	ft_print_2d_array(p_2d_array);
	max_nbr = ft_get_max_nbr(p_2d_array);
	min_nbr = ft_get_min_nbr(p_2d_array);
	ft_print_max_and_min_nbrs_result(max_nbr, min_nbr);
	c = -1;
	while (++c < 3)
		free(p_2d_array[c]);
	free(p_2d_array);
	return (0);
}



