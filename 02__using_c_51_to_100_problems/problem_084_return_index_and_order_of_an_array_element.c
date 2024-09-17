#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void    *ft_malloc(int i_number_of_elements, int i_element_size);
short	*ft_get_index_of_nbr_if_is_found(short   entered_len);
void	ft_fill_i_array_with_random_nbrs_ranged1to100(int i_array[100], short   entered_len);
void ft_print_array_elements(int i_array[100], short entered_len);
int	*ft_p_generate_random_nbr_in_range(int *p_i_generated_random_nbr, int *from, int *to);

int *p_i_generated_random_nbr;
int	i_array[100];
short	*searched_for_number;
short	*from;
short	*to;


int	main(int argc, char **argv)
{
	short	entered_len;
	short	*index;

	if (argc != 3)
	{
		printf("Please enter these as Command Argument Line after filename\nNumber of elements of the array; Then the searched number in the array.\n");
		return (1);
	}
	srand((unsigned)time(NULL));
	entered_len = 0;
	p_i_generated_random_nbr = ft_malloc(1, sizeof(int));
	from = ft_malloc(1, sizeof(short));
	to = ft_malloc(1, sizeof(short));
	searched_for_number = ft_malloc(1, sizeof(short));
	if (!p_i_generated_random_nbr || !from || !to || !searched_for_number)
		return (2);
	entered_len = (short)atoi(argv[1]);
	*searched_for_number = (short)atoi(argv[2]);
	ft_fill_i_array_with_random_nbrs_ranged1to100(i_array, entered_len);
	printf("The elements of the array are: \n");
	ft_print_array_elements(i_array, entered_len);
	printf("The element that you are searching for is: (%hd)\n", *searched_for_number);
	index = ft_get_index_of_nbr_if_is_found(entered_len);
	if (*index != -1)
	{
		printf("The element that you are searching for is found in index (Position): (%hd)\n", *index);
		printf("The element that you are searching for is found in order: (%hd)\n", *index + 1);
	}
	else
		printf("The element that you are searching for ISN'T FOUND.\n");
	free(p_i_generated_random_nbr);
	free(searched_for_number);
	free(index);
	free(from);
	free(to);
	return (0);
}

short	*ft_get_index_of_nbr_if_is_found(short   entered_len)
{
	int	c;
	short	*index;
	index = ft_malloc(1, sizeof(short));
	if (!index)
		return (NULL);
	*index = -1;
	c = 0;
	while (c < entered_len)
	{
		if (i_array[c] == *searched_for_number)
		{
			*index = c;
			break;
		}
		c++;
	}
	return (index);
}

void ft_print_array_elements(int i_array[100], short entered_len)
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

void	ft_fill_i_array_with_random_nbrs_ranged1to100(int i_array[100], short   entered_len)
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


