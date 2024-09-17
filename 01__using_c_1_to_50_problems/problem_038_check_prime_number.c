#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef enum	t_e_prime_or_not
{
	prime = 1,
	not_prime = 0
}	t_e_prime_or_not;

void    *ft_malloc(int i_number_of_elements, int i_element_size);
void	ft_print_result(t_e_prime_or_not    *p_e_is_prime, int *p_i_entered_nbr);
t_e_prime_or_not	*ft_e_p_check_is_a_nbr_prime(int *p_i_entered_nbr ,t_e_prime_or_not    *p_e_is_prime);
int	*ft_read_positive_nbr(char *message, int *p_i_entered_nbr);

int	main(void)
{
	int	*p_i_entered_nbr;
	t_e_prime_or_not	*p_e_is_prime;

	p_i_entered_nbr = (int *)ft_malloc(1, sizeof(int));
	p_e_is_prime = (t_e_prime_or_not *)ft_malloc(1, sizeof(t_e_prime_or_not));
	if (!p_i_entered_nbr || !p_e_is_prime)
		return (1);
	p_i_entered_nbr = ft_read_positive_nbr("Please enter a positive number to check if the number is prime: ", p_i_entered_nbr);
	p_e_is_prime = ft_e_p_check_is_a_nbr_prime(p_i_entered_nbr, p_e_is_prime);
	ft_print_result(p_e_is_prime, p_i_entered_nbr);
	free(p_i_entered_nbr);
	free(p_e_is_prime);
	return (0);
}

void	ft_print_result(t_e_prime_or_not    *p_e_is_prime, int *p_i_entered_nbr)
{
	if (*p_e_is_prime == prime)
		printf("\nThe number \'%i\' is Prime. :)\n", *p_i_entered_nbr);
	else if (*p_e_is_prime == not_prime)
			printf("\nThe number \'%i\' is not Prime. :(\n", *p_i_entered_nbr);
}

t_e_prime_or_not	*ft_e_p_check_is_a_nbr_prime(int *p_i_entered_nbr ,t_e_prime_or_not    *p_e_is_prime)
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

int	*ft_read_positive_nbr(char *message, int *p_i_entered_nbr)
{
	*p_i_entered_nbr = -1;
	while(*p_i_entered_nbr <= 0)
	{
		printf("%s\n", message);
		scanf("%i", p_i_entered_nbr);
	}
	return (p_i_entered_nbr);
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
