#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void	ft_fill_i_array_with_random_nbrs_ranged1to100(int i_array[100], short   *i_entered_len, short *from, short *to);
void	ft_add_array_element(int i_entered_nbr, int i_array[100], short *i_len);
int	*ft_p_generate_random_nbr_in_range(int *p_i_generated_random_nbr, int *from, int *to);
void	ft_copy_array_elements_to_another(int i_array[100], int i_array2[100], short array1_len, short *array2_len);
void    *ft_malloc(int i_number_of_elements, int i_element_size);
void	ft_print_array_elements(int i_array[100], short entered_len);

int	i_array[100];
int	i_array2[100];
short	i_entered_len;
short	i_array2_len;
int *p_i_generated_random_nbr;


int	main(int argc, char **argv)
{
	short	*from;
	short	*to;

	srand((unsigned)time(NULL));
	i_array2_len = 0;
	i_entered_len = 0;
	p_i_generated_random_nbr = ft_malloc(1, sizeof(int));
	from = ft_malloc(1, sizeof(short));
	to = ft_malloc(1, sizeof(short));
	if (!p_i_generated_random_nbr || !from || !to)
		return (2);
	printf("Please enter the number of elements of the i_array: ");
	scanf("%hd", &i_entered_len);
	ft_fill_i_array_with_random_nbrs_ranged1to100(i_array, &i_entered_len, from, to);
	ft_print_array_elements(i_array, i_entered_len);
	printf("\n");
	ft_copy_array_elements_to_another(i_array, i_array2, i_entered_len, &i_array2_len);
	ft_print_array_elements(i_array2, i_array2_len);
	return (0);
}

void	ft_add_array_element(int i_entered_nbr, int i_array[100], short *i_len)
{
	i_array[*i_len] = i_entered_nbr;
	(*i_len)++;
}

void	ft_copy_array_elements_to_another(int i_array[100], int i_array2[100], short array1_len, short *array2_len)
{
	short	c;

	*array2_len = 0;
	c = 0;
	while (c < array1_len)
	{
		ft_add_array_element(i_array[c], i_array2, array2_len);
		c++;
	}
}

void	ft_fill_i_array_with_random_nbrs_ranged1to100(int i_array[100], short   *i_entered_len, short *from, short *to)
{
	short	l;
	*from = 1;
	*to = 100;

	l = 0;
	while (l < *i_entered_len)
	{
		i_array[l++] = *ft_p_generate_random_nbr_in_range(p_i_generated_random_nbr, (int *)from, (int *)to);
	}
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

