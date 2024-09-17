#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void    *ft_malloc(int i_number_of_elements, int i_element_size);
int	*ft_p_i_check_a_prime_nbr(int *p_i_nbr);
void	ft_get_prime_nbrs_until_n(int *p_i_nbr);

int	main(int argc, char **argv)
{
	int	*p_i_entered_nbr;

	if (argc != 2)
	{
		printf("Wrong ! Please Enter only one command line argument after file name (Which is the number that you want).\n");
		return (1);
	}
	p_i_entered_nbr = (int *)ft_malloc(1, sizeof(int));
	if (!p_i_entered_nbr)
		return (2);
	*p_i_entered_nbr = atoi(argv[1]);
	ft_get_prime_nbrs_until_n(p_i_entered_nbr);
	free(p_i_entered_nbr);
	return (0);
}

void	ft_get_prime_nbrs_until_n(int *p_i_nbr)
{
	int	*p_i_counter;
	int *p_i_prime_result;

	p_i_counter = (int *)ft_malloc(1, sizeof(int));
	if (!p_i_counter) 
		return ;
	*p_i_counter = 0;
	while (++(*p_i_counter) <= *p_i_nbr)
	{
		p_i_prime_result = ft_p_i_check_a_prime_nbr(p_i_counter);
		if ((*p_i_prime_result))
			printf("%d is included Prime Number.\n", *p_i_counter);
	}
	free(p_i_counter);
}

int	*ft_p_i_check_a_prime_nbr(int *p_i_nbr)
{
	int	*p_i_result;
	short	i;

	p_i_result = (int *)ft_malloc(1, sizeof(int));
	if (!p_i_result)
		return (NULL);
	*p_i_result = 1;
	if (*p_i_nbr == 1)
	{
		*p_i_result = 0;
		return (p_i_result);
	}
	i = 1;
	while (++i < round((*p_i_nbr) / 2))
	{
		if ((*p_i_nbr) % i == 0)
		{
			*p_i_result = 0;
			break ;
		}
	}
	return (p_i_result);
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

