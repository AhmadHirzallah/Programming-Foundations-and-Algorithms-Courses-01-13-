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
			array[c1][c2] = ft_generate_random_nbr_in_range(1, 5);
	}
}

int	ft_get_sum_of_matrix_numbers(int **p_2d_array)
{
	int	sum;
	short	c1;
	short	c2;

	c1 = -1;
	sum = 0;
	while (++c1 < 3)
	{
		c2 = -1;
		while (++c2 < 3)
			sum += p_2d_array[c1][c2];
	}
	return (sum);
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

short	ft_check_arrays_equality_by_summation(int **p_2d_array, int **p_2d_array2)
{
	return (ft_get_sum_of_matrix_numbers(p_2d_array) == ft_get_sum_of_matrix_numbers(p_2d_array2));
}

void	ft_print_array_equality_result(short result)
{
	if (result)
		printf("\n\nYes.\nThe arrays are equal.\n\n");
	else
		printf("\n\nNo.\nThe arrays are not equal.\n\n");
}

int	main(void)
{
	int	**p_2d_array;
	int	**p_2d_array2;
	int	sum;
	short	check_are_arrays_equal;
	short	c;

	srand((unsigned)time(NULL));
	p_2d_array = (int **)malloc(3 * sizeof(int *));
	p_2d_array2 = (int **)malloc(3 * sizeof(int *));
	sum = 0;
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
	sum = ft_get_sum_of_matrix_numbers(p_2d_array);
	printf("\n\nThe sum of numbers of the 1'st array: (%d)\n", sum);
	sum = ft_get_sum_of_matrix_numbers(p_2d_array2);
	printf("\nThe sum of numbers of the 2'nd array: (%d)\n", sum);
	check_are_arrays_equal = ft_check_arrays_equality_by_summation(p_2d_array, p_2d_array2);
	ft_print_array_equality_result(check_are_arrays_equal);
	free(p_2d_array);
	free(p_2d_array2);
	return (0);
}


