#include <stdio.h>
#include <stdlib.h>


void    *ft_malloc(int i_number_of_elements, int i_element_size);
int	*ft_p_get_nbr_digits_summation(int *p_i_entered_nbr);

int	main(int argc, char **argv)
{
	int	*p_i_entered_nbr;
	int	*p_i_nbr_digits_summation;

	if (argc != 2)
	{
		printf("Error, please enter the number as command argument line.\n");
		return (1);
	}
	p_i_entered_nbr = ft_malloc(1, sizeof(int));
	if (!p_i_entered_nbr || !p_i_nbr_digits_summation)
		return (2);
	*p_i_entered_nbr = atoi(argv[1]);
	p_i_nbr_digits_summation = ft_p_get_nbr_digits_summation(p_i_entered_nbr);
	printf("The summation of the digits of the number is: (%d)\n", *p_i_nbr_digits_summation);
	free(p_i_nbr_digits_summation);
	free(p_i_entered_nbr);
	return (0);
}

int	*ft_p_get_nbr_digits_summation(int *p_i_entered_nbr)
{
	int	*p_i_nbr_digits_summation;
	
	p_i_nbr_digits_summation = ft_malloc(1, sizeof(int));
	if (!p_i_nbr_digits_summation)
		return (NULL);
	*p_i_nbr_digits_summation = 0;
	if (*p_i_entered_nbr < 0)
	{
		printf("The entered number is - and we sum the digits only\n");
		*p_i_entered_nbr *= -1;
	}
	while (*p_i_entered_nbr > 0)
	{
		*p_i_nbr_digits_summation += *p_i_entered_nbr % 10;
		*p_i_entered_nbr /= 10;
	}
	return (p_i_nbr_digits_summation);
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
