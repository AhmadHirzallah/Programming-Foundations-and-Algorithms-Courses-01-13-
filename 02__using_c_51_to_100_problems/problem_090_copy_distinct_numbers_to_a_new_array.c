#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef enum	t_e_distinct_or_not
{
	distinct = 1,
	not_distinct = 0
}	t_e_distinct_or_not;	

void	ft_add_array_element(int i_entered_nbr, int i_array[10], short *i_len);
void ft_print_array_elements(int i_array[10], short entered_len);
void	ft_copy_array_distinct_elements_to_another(int i_array[10], int i_array2[10], short array1_len, short *array2_len);
void    *ft_malloc(int i_number_of_elements, int i_element_size);
t_e_distinct_or_not	*ft_e_p_check_is_a_nbr_distinct(int *p_i_entered_nbr, int i_array[10], short *len);

int	i_array2[10];
short	i_array_len;
short	i_array2_len;
t_e_distinct_or_not	*p_e_distinct_or_not;

int	i_array[] = {10, 10, 10, 50, 50, 70, 70, 70, 70, 90};

int	main(int argc, char **argv)
{
	srand((unsigned)time(NULL));
	p_e_distinct_or_not = (t_e_distinct_or_not *)ft_malloc(1, sizeof(t_e_distinct_or_not));
	i_array_len = sizeof(i_array) / sizeof(i_array[0]);
	printf("The 1'st array elements:\n");
	ft_print_array_elements(i_array, i_array_len);
	printf("\n");
	ft_copy_array_distinct_elements_to_another(i_array, i_array2, i_array_len, &i_array2_len);
	printf("The 2'nd array elements (Distinct elements):\n");
	ft_print_array_elements(i_array2, i_array2_len);
	free(p_e_distinct_or_not);
	return (0);
}

t_e_distinct_or_not	*ft_e_p_check_is_a_nbr_distinct(int *p_i_entered_nbr, int i_array[10], short *len)
{

	short	j;

	j = -1;
	while (++j < *len)
	{
		if (*p_i_entered_nbr == i_array[j])
		{
			*p_e_distinct_or_not = not_distinct;
			return (p_e_distinct_or_not);
		}
	}
	*p_e_distinct_or_not = distinct;
	return (p_e_distinct_or_not);
}

void	ft_add_array_element(int i_entered_nbr, int i_array[10], short *i_len)
{
	i_array[*i_len] = i_entered_nbr;
	(*i_len)++;
}

void	ft_copy_array_distinct_elements_to_another(int i_array[10], int i_array2[10], short array1_len, short *array2_len)
{
	short	c;

	*array2_len = 0;
	c = 0;
	while (c < array1_len)
	{
		p_e_distinct_or_not = ft_e_p_check_is_a_nbr_distinct(&i_array[c], i_array2, &array1_len);
		if (*p_e_distinct_or_not == distinct)
				ft_add_array_element(i_array[c], i_array2, array2_len);
		c++;
	}
}

void ft_print_array_elements(int i_array[10], short entered_len)
{
    short	c;

    c = 0;
    while (c < entered_len)
    {
        printf("%d  ", i_array[c]);
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
