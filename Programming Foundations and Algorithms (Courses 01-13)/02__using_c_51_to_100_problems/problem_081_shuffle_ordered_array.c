#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void    *ft_malloc(int i_number_of_elements, int i_element_size);
void	ft_shuffle_array_elements(int i_array[100], short entered_len);
void ft_print_array_elements(int i_array[100], short entered_len);
void	ft_fill_array_from_1_to_n(int i_array[100], short entered_len);
void	ft_swap_2_nbrs(int	*p_nbr1, int *p_nbr2);
int	*ft_p_generate_random_nbr_in_range(int *from, int *to);

int *p_i_generated_random_nbr;
short	*from;
short	*to;


int	main(int argc, char **argv)
{
	int	i_array[100];
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
	ft_fill_array_from_1_to_n(i_array, entered_len);
	printf("The Array elements are:\n");
	ft_print_array_elements(i_array, entered_len);
	ft_shuffle_array_elements(i_array, entered_len);
	printf("The Array elements after shuffling are:\n");
	ft_print_array_elements(i_array, entered_len);
	free(p_i_generated_random_nbr);
	free(from);
	free(to);
	return (0);
}

void	ft_fill_array_from_1_to_n(int i_array[100], short entered_len)
{
	short	c;

	c = 0;
	while (c < entered_len)
	{
		i_array[c] = c + 1;
		c++;
	}
}

void	ft_shuffle_array_elements(int i_array[100], short entered_len)
{
	short	c;
	short	first_random_array_index;
	short	second_random_array_index;

	*from = 0;
	*to = entered_len - 1;
	c = 0;
	while (c++ < entered_len)
	{
		first_random_array_index = *ft_p_generate_random_nbr_in_range((int *)from,(int *)to);
		second_random_array_index = *ft_p_generate_random_nbr_in_range((int *)from, (int *)to);
		ft_swap_2_nbrs(&i_array[first_random_array_index], &i_array[second_random_array_index]);
	}
}

void	ft_swap_2_nbrs(int	*p_nbr1, int *p_nbr2)
{
	int	i_tmp;

	i_tmp = *p_nbr1;
	*p_nbr1 = *p_nbr2;
	*p_nbr2 = i_tmp;
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

int	*ft_p_generate_random_nbr_in_range(int *from, int *to)
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



