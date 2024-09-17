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
			array[c1][c2] = ft_generate_random_nbr_in_range(1, 100);
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
		printf("\n");
		while (++c2 < 3)
			if (c2 != 2)
				printf("%3d\t,", array[c1][c2]);
			else
				printf("%3d ", array[c1][c2]);
	}
	printf("\n");
}

int	ft_get_sum_of_2d_array_column(int **array, short column_index)
{
	int	sum;
	short	c;
	
	sum = 0;
	c = -1;
	while (++c < 3)
		sum += array[c][column_index];
	return (sum);
}

void	ft_fill_1d_arr_with_sum_of_2d_array_columns(int **array, int *p_each_row_sum)
{
	short	c;

	c = -1;
	while (++c < 3)
		p_each_row_sum[c] = ft_get_sum_of_2d_array_column(array, c);	
}

void	ft_print_sum_of_2d_array_columns_from_1d_arr_of_sums(int *column)
{
	short	c;

	c = -1;
	while (++c < 3)
		printf("Column %hd summation: %d\n", c + 1, column[c]);
}

int	main(void)
{
	srand((unsigned)time(NULL));
	int	**p_2d_array;
	int	*p_each_row_sum;
	short	c;

	p_2d_array = (int **)malloc(3 * sizeof(int *));
	p_each_row_sum = (int *)malloc(3 * sizeof(int));
	c = -1;
	while (++c < 3)
		p_2d_array[c] = (int *)malloc(3 * sizeof(int));
	ft_fill_2d_array_with_random_nbrs(p_2d_array);
	ft_print_2d_array(p_2d_array);
	printf("______\n");
	ft_fill_1d_arr_with_sum_of_2d_array_columns(p_2d_array, p_each_row_sum);
	ft_print_sum_of_2d_array_columns_from_1d_arr_of_sums(p_each_row_sum);
	free(p_each_row_sum);
	free(p_2d_array);
	return (0);
}



