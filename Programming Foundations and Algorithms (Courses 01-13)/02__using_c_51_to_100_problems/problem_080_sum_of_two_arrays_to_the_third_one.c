#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void    *ft_malloc(int i_number_of_elements, int i_element_size);
void	ft_fill_i_array_with_random_nbrs_ranged1to100(int i_array[100], short   entered_len);
void ft_print_array_elements(int i_array[100], short entered_len);
int	*ft_p_generate_random_nbr_in_range(int *p_i_generated_random_nbr, int *from, int *to);
int	*ft_sum_two_arrays_to_third_array(int i_array[100], int i_array2[100], int i_3rd_array[100], short entered_len);

int *p_i_generated_random_nbr;
short	*from;
short	*to;


int	main(int argc, char **argv)
{
	int	i_array[100];
	int i_array2[100];
	int	i_3rd_array[100];
	short	entered_len;

	if (argc != 2)
	{
		printf("Please enter the number of elements to generate them randomly as a command line argument.\n");
		return (3);
	}
	srand((unsigned)time(NULL));
	p_i_generated_random_nbr = ft_malloc(1, sizeof(int));
	from = ft_malloc(1, sizeof(short));
	to = ft_malloc(1, sizeof(short));
	if (!p_i_generated_random_nbr || !from || !to)
		return (2);
	entered_len = (short)atoi(argv[1]);
	ft_fill_i_array_with_random_nbrs_ranged1to100(i_array, entered_len);
	printf("The First Array elements are:\n");
	ft_print_array_elements(i_array, entered_len);
	ft_fill_i_array_with_random_nbrs_ranged1to100(i_array2, entered_len);
	printf("\nThe Second Array elements are:\n");
	ft_print_array_elements(i_array2, entered_len);
	ft_sum_two_arrays_to_third_array(i_array, i_array2, i_3rd_array, entered_len);
	printf("\nThe Third array which is summation of first and second array elements:\n");
	ft_print_array_elements(i_3rd_array, entered_len);
	free(p_i_generated_random_nbr);
	free(from);
	free(to);
	return (0);
}

int	*ft_sum_two_arrays_to_third_array(int i_array[100], int i_array2[100], int i_3rd_array[100], short entered_len)
{
	short	c;

	c = 0;
	while (c < entered_len)
	{
		i_3rd_array[c] = i_array[c] + i_array2[c];
		c++;
	}
}

void	ft_print_array_elements(int i_array[100], short entered_len)
{
    short	c;

    c = 0;
    while (c < entered_len)
    {
        printf("%d ", i_array[c]);
        c++;
    }
    printf("\n");
}

void	ft_fill_i_array_with_random_nbrs_ranged1to100(int i_array[100], short entered_len)
{
	short	l;
	*from = 1;
	*to = 100;

	l = 0;
	while (l < entered_len)
	{
		i_array[l++] = *ft_p_generate_random_nbr_in_range(p_i_generated_random_nbr, (int *)from, (int *)to);
	}
}

int	*ft_p_generate_random_nbr_in_range(int *p_i_generated_random_nbr, int *from, int *to)
{	
	*p_i_generated_random_nbr = rand() % (*to - *from + 1) + *from;
	return (p_i_generated_random_nbr);
}

void    *ft_malloc(int i_number_of_elements, int i_element_size)
{
    void    *p_v;

    p_v = (void *)malloc(i_number_of_elements * i_element_size);
    if (!p_v)
    {
        printf("Unfortunatelly; Memory allocation failed.\n");
        return (NULL);
    }
    return (p_v);
}



