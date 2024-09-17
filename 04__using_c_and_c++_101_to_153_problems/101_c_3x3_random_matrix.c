/*
Problem:
Write a program to fill a 3x3 matrix with random numbers.
*/

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
		while (++c2 < 3)	
			if (c1 != 2 || c2 != 2)
				printf("%3d\t,", array[c1][c2]);
			else 
				printf("%3d ", array[c1][c2]);
	}
	printf("\n");
}

int	main(void)
{
	srand((unsigned)time(NULL));

	int	**p_2d_array;
	short	c;

	p_2d_array = (int **)malloc(3 * sizeof(int *));
	c = -1;
	while (++c < 3)
		p_2d_array[c] = (int *)malloc(3 * sizeof(int));
	ft_fill_2d_array_with_random_nbrs(p_2d_array);
	ft_print_2d_array(p_2d_array);
	free(p_2d_array);
	return (0);
}






/* Another Good Way ::::
 * #include <stdio.h>
#include <stdlib.h>
#include <time.h>

void ft_fill_2d_array_with_random_nbrs(int **array) {
    for (short c1 = 0; c1 < 3; ++c1) {
        for (short c2 = 0; c2 < 3; ++c2) {
            array[c1][c2] = rand() % 100 + 1; // Generate random numbers between 1 and 100
        }
    }
}

int main(void) {
    srand((unsigned)time(NULL));

    // Create a 2D array
    int arr[3][3];

    // Create an array of pointers (each pointing to a row of arr)
    int *row_pointers[3];
    for (short c = 0; c < 3; ++c) {
        row_pointers[c] = arr[c];
    }

    // Pass the array of pointers to the function
    ft_fill_2d_array_with_random_nbrs(row_pointers);

    // Now arr contains the random numbers
    // Print arr (optional)
    for (short c1 = 0; c1 < 3; ++c1) {
        for (short c2 = 0; c2 < 3; ++c2) {
            printf("%d ", arr[c1][c2]);
        }
        printf("\n");
    }

    return 0;
}
*/

