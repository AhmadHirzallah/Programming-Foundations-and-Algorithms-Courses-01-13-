#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void    *ft_malloc(int i_number_of_elements, int i_element_size);
int	*ft_i_get_min_array_element(int i_array[100], short entered_len);
void	ft_fill_i_array_with_random_nbrs_ranged1to100(int i_array[100], short   entered_len);
void ft_print_array_elements(int i_array[100], short entered_len);
int	*ft_p_generate_random_nbr_in_range(int *p_i_generated_random_nbr, int *from, int *to);

int *p_i_generated_random_nbr;
int	*i_min_element;
short	*from;
short	*to;


int	main(int argc, char **argv)
{
	int	i_array[100];
	short	entered_len;

	srand((unsigned)time(NULL));
	entered_len = 0;
	p_i_generated_random_nbr = ft_malloc(1, sizeof(int));
	i_min_element = ft_malloc(1, sizeof(int));
	from = ft_malloc(1, sizeof(short));
	to = ft_malloc(1, sizeof(short));
	if (!p_i_generated_random_nbr || !from || !to || !i_min_element)
		return (2);
	printf("Please enter the number of elements of the i_array: ");
	scanf("%hd", &entered_len);
	ft_fill_i_array_with_random_nbrs_ranged1to100(i_array, entered_len);
	i_min_element = ft_i_get_min_array_element(i_array, entered_len);
	ft_print_array_elements(i_array, entered_len);
	printf("The minimum element is: (%d)\n", *i_min_element);
	free(p_i_generated_random_nbr);
	free(i_min_element);
	free(from);
	free(to);
	return (0);
}

int	*ft_i_get_min_array_element(int i_array[100], short entered_len)
{
	short	c;
	*i_min_element = i_array[0];

	c = 0;
	while (c < entered_len)
	{
		if (i_array[c] < *i_min_element)
			*i_min_element = i_array[c];
		c++;
	}
	return (i_min_element);
}

void ft_print_array_elements(int i_array[100], short entered_len)
{
    short	c;

    c = 0;
    printf("\nThe original elemnts are:  ");
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
	while (l <= entered_len)
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


