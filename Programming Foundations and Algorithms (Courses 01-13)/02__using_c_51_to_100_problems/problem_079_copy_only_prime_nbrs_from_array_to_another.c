#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

typedef enum	t_e_prime_or_not
{
	prime = 1,
	not_prime = 0
}	t_e_prime_or_not;

void    *ft_malloc(int i_number_of_elements, int i_element_size);
void	ft_copy_array_prime_elements_to_another(int i_array[100], int i_array2[100], short entered_len, short *c_prime_len);
void	ft_fill_i_array_with_random_nbrs_ranged1to100(int i_array[100], short   entered_len);
void ft_print_array_elements(int i_array[100], short entered_len);
int	*ft_p_generate_random_nbr_in_range(int *p_i_generated_random_nbr, int *from, int *to);

int *p_i_generated_random_nbr;
short	*from;
short	*to;
t_e_prime_or_not *p_e_is_prime;

int	main(int argc, char **argv)
{
	int	i_array[100];
	int i_array2[100];
	short	entered_len;
	short	*c_prime_len;

	if (argc != 2)
	{
		printf("Please enter the number of elements to generate them randomly as a command line argument.\n");
		return (3);
	}
	srand((unsigned)time(NULL));
	p_i_generated_random_nbr = ft_malloc(1, sizeof(int));
	from = ft_malloc(1, sizeof(short));
	to = ft_malloc(1, sizeof(short));
	c_prime_len = ft_malloc(1, sizeof(short));
	p_e_is_prime = ft_malloc(1, sizeof(t_e_prime_or_not));
	if (!p_i_generated_random_nbr || !from || !to || !p_e_is_prime)
		return (2);
	entered_len = (short)atoi(argv[1]);
	ft_fill_i_array_with_random_nbrs_ranged1to100(i_array, entered_len);
	printf("The Original Array elements are:\n");
	ft_print_array_elements(i_array, entered_len);
	ft_copy_array_prime_elements_to_another(i_array, i_array2, entered_len, c_prime_len);
	printf("The (Prime) Only Coppied elements to the second array are:\n");
	ft_print_array_elements(i_array2, *c_prime_len);
	free(p_i_generated_random_nbr);
	free(from);
	free(to);
	free(c_prime_len);
	free(p_e_is_prime);
	return (0);
}

t_e_prime_or_not	*ft_e_p_check_is_a_nbr_prime(int *p_i_entered_nbr)
{
	int	i_middle;
	short	j;

	j = 1;
	i_middle = round(*p_i_entered_nbr / 2);
	while (++j <= i_middle)
	{
		if (*p_i_entered_nbr % j == 0)
		{
			*p_e_is_prime = not_prime;
			return (p_e_is_prime);
		}
	}
	*p_e_is_prime = prime;
	return (p_e_is_prime);
}
void	ft_copy_array_prime_elements_to_another(int i_array[100], int i_array2[100], short entered_len, short *c_prime_len)
{
	short	c;

	c = 0;
	*c_prime_len = 0;
	while (c < entered_len)
	{
		p_e_is_prime = ft_e_p_check_is_a_nbr_prime(&i_array[c]);
		if (*p_e_is_prime == prime)
		{
			i_array2[(*c_prime_len)++] = i_array[c];
		}
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



