#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

typedef enum	t_e_odd_or_even
{
	odd = 1,
	even = 0
}	t_e_odd_or_even;	

void	ft_add_array_element(int i_entered_nbr, int i_array[100], short *i_len);
int	*ft_p_generate_random_nbr_in_range(int *p_i_generated_random_nbr, int *from, int *to);
void	ft_copy_array_odd_elements_to_another(int i_array[100], int i_array2[100], short array1_len, short *array2_len);
void    *ft_malloc(int i_number_of_elements, int i_element_size);
void	ft_print_array_elements(int i_array[100], short entered_len);
void	ft_print_result(char *message, short *result);
short	*ft_count_odd_nbrs_in_array(int i_array[100], short   *i_entered_len);
t_e_odd_or_even	*ft_e_p_check_nbr_odd_or_even(int *p_i_entered_nbr);
void	ft_fill_i_array_with_random_nbrs_ranged1to100(int i_array[100], short   *i_entered_len, short *from, short *to);

int	i_array[100];
short	i_entered_len;
int *p_i_generated_random_nbr;
t_e_odd_or_even	*p_e_odd_or_not;
short	*p_odd_count;

int	main(int argc, char **argv)
{
	short	*from;
	short	*to;

	srand((unsigned)time(NULL));
	p_e_odd_or_not = (t_e_odd_or_even *)ft_malloc(1, sizeof(t_e_odd_or_even));
	i_entered_len = 0;
	p_i_generated_random_nbr = ft_malloc(1, sizeof(int));
	p_odd_count = ft_malloc(1, sizeof(short));
	from = ft_malloc(1, sizeof(short));
	to = ft_malloc(1, sizeof(short));
	if (!p_i_generated_random_nbr || !from || !to)
		return (2);
	i_entered_len = (short)atoi(argv[1]);
	ft_fill_i_array_with_random_nbrs_ranged1to100(i_array, &i_entered_len, from, to);
	printf("The array elements:\n");
	ft_print_array_elements(i_array, i_entered_len);
	printf("\n");
	p_odd_count = ft_count_odd_nbrs_in_array(i_array, &i_entered_len);
	ft_print_result("The count of odd numbers is: ", p_odd_count);
	free(p_i_generated_random_nbr);
	free(p_e_odd_or_not);
	free(p_odd_count);
	free(from);
	free(to);
	return (0);
}

void	ft_print_result(char *message, short *result)
{
	printf("%s(%hd)\n", message, *result);
}

short	*ft_count_odd_nbrs_in_array(int i_array[100], short   *i_entered_len)
{
	short	index;

	*p_odd_count = 0;
	index = -1;
	while (++index < *i_entered_len)
	{
		p_e_odd_or_not = ft_e_p_check_nbr_odd_or_even(&i_array[index]);
		if (*p_e_odd_or_not == odd)
			(*p_odd_count)++;
	}
	return (p_odd_count);
}

t_e_odd_or_even	*ft_e_p_check_nbr_odd_or_even(int *p_i_entered_nbr)
{
	if (*p_i_entered_nbr % 2 != 0)
	{
		*p_e_odd_or_not = odd;
		return (p_e_odd_or_not);
	}
	*p_e_odd_or_not = even;
	return (p_e_odd_or_not);
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
