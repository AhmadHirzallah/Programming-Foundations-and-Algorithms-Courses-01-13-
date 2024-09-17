#include <stdio.h>
#include <stdlib.h>


void    *ft_malloc(int i_number_of_elements, int i_element_size);
void	ft_print_nbr_digit_by_digit_reversly(int *p_i_entered_nbr);

int	main(int argc, char **argv)
{
	int	*p_i_entered_nbr;

	if (argc != 2)
	{
		printf("Please enter command line argument after filename which is the number that you want.\n");
		return (1);
	}
	p_i_entered_nbr = (int *)ft_malloc(1, sizeof(int));
	if (!p_i_entered_nbr)
		return (2);
	*p_i_entered_nbr = atoi(argv[1]);
	ft_print_nbr_digit_by_digit_reversly(p_i_entered_nbr);
	free(p_i_entered_nbr);
	return (0);
}

void	ft_print_nbr_digit_by_digit_reversly(int *p_i_entered_nbr)
{
	short	digit;
	if (*p_i_entered_nbr < 0)
	{
		printf("-\n");
		*p_i_entered_nbr *= -1;
	}
	while (*p_i_entered_nbr > 0)
	{
		digit = *p_i_entered_nbr % 10;
		printf("%hd\n", digit);
		*p_i_entered_nbr /= 10;
	}
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
