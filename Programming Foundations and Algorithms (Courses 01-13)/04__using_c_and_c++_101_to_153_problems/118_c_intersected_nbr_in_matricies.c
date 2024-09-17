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
			array[c1][c2] = ft_generate_random_nbr_in_range(0, 7);
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

short	ft_check_is_nbr_in_matrix(int **p_2d_array, int search_nbr)
{
	short	c1;
	short	c2;


	c1 = -1;
	while (++c1 < 3)
	{
		c2 = -1;
		while (++c2 < 3)
			if (p_2d_array[c1][c2] == search_nbr)
				return (1);
	}
	return (0);

}

short	ft_check_is_nbr_added_to_prevent_duplicate(int *p_exist_nbrs, int search_nbr, short count_of_intersected_nbrs)
{
	short	c;

	c = -1;
	while (++c < count_of_intersected_nbrs)
		if (p_exist_nbrs[c] == search_nbr)
			return (1);
	return (0);
}

short	ft_count_intersected_nbrs_in_matrices(int **p_2d_array, int **p_2d_array2)
{
	short	c1;
	short	c2;
	short	count;
	short	searched_nbr;

	count = 0;
	c1 = -1;
	while (++c1 < 3)
	{
		c2 = -1;
		while (++c2 < 3)
		{
			searched_nbr = p_2d_array[c1][c2];
			if (ft_check_is_nbr_in_matrix(p_2d_array2, searched_nbr))
				count++;
		}
	}
	return (count);
}

int	*ft_get_intersected_nbr_in_matrices(int **p_2d_array, int **p_2d_array2, short *count_of_intersected_nbrs)
{
	short	c1;
	short	c2;
	short	c3;
	short	checked_nbr;
	int *p_exist_nbrs;

	p_exist_nbrs = (int *)malloc(*count_of_intersected_nbrs * sizeof(int));
	c3 = 0;
	c1 = -1;
	while (++c1 < 3)
	{
		c2 = -1;
		while (++c2 < 3)
		{
			checked_nbr = p_2d_array[c1][c2];
			if (ft_check_is_nbr_in_matrix(p_2d_array2, checked_nbr) && !ft_check_is_nbr_added_to_prevent_duplicate(p_exist_nbrs, checked_nbr, c3))
				p_exist_nbrs[c3++] = checked_nbr;
		}
	}
	*count_of_intersected_nbrs = c3++;
	return (p_exist_nbrs);
}

void	ft_print_intersected_nbrs_result(int *p_exist_nbrs, short len)
{
	short	c;

	printf("The intersected numbers are: ");
	c = -1;
	while(++c < len)
		printf("(%d)   ", p_exist_nbrs[c]);
	printf("\n");
}

int	main(void)
{
	int	**p_2d_array;
	int	**p_2d_array2;
	int *intersected_nbrs;
	short	count_of_intersected_nbrs;
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
	count_of_intersected_nbrs = ft_count_intersected_nbrs_in_matrices(p_2d_array, p_2d_array2);
	intersected_nbrs = ft_get_intersected_nbr_in_matrices(p_2d_array, p_2d_array2, &count_of_intersected_nbrs);
	ft_print_intersected_nbrs_result(intersected_nbrs, count_of_intersected_nbrs);
	c = -1;
	while (++c < 3)
	{
		free(p_2d_array[c]);
		free(p_2d_array2[c]);
	}
	free(p_2d_array);
	free(p_2d_array2);
	free(intersected_nbrs);
	return (0);
}




