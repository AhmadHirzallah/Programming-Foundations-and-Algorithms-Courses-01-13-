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
			array[c1][c2] = ft_generate_random_nbr_in_range(1, 2);
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

short	ft_check_are_arrays_typical(int **p_2d_array, int **p_2d_array2)
{
	short	c1;
	short	c2;

	c1 = -1;
	while (++c1 < 3)
	{
		c2 = -1;
		while (++c2 < 3)
			if (p_2d_array[c1][c2] != p_2d_array2[c1][c2])
				return (0);
	}
	return (1);
}

void	ft_print_are_arrays_typical_result(short result)
{
	if (result)
		printf("\n\nYes.\nThe arrays are typical.\n\n");
	else
		printf("\n\nNo.\nThe arrays are not typical.\n\n");
}

int	main(void)
{
	int	**p_2d_array;
	int	**p_2d_array2;
	short	check_are_arrays_typical;
	short	c;

	srand((unsigned)time(NULL));
	p_2d_array = (int **)malloc(3 * sizeof(int *));
	p_2d_array2 = (int **)malloc(3 * sizeof(int *));
	c = -1;
	while (++c < 3)
	{
		p_2d_array[c] = (int *)malloc(3 * sizeof(int));
		p_2d_array2[c] = (int *)malloc(3 * sizeof(int));
	}
	ft_fill_2d_array_with_random_nbrs(p_2d_array);
	ft_fill_2d_array_with_random_nbrs(p_2d_array2);
	printf("The 1'st array:\n");
	ft_print_2d_array(p_2d_array);
	printf("The 2'nd array:\n");
	ft_print_2d_array(p_2d_array2);
	check_are_arrays_typical = ft_check_are_arrays_typical(p_2d_array, p_2d_array2);
	ft_print_are_arrays_typical_result(check_are_arrays_typical);
	free(p_2d_array);
	free(p_2d_array2);
	return (0);
}



