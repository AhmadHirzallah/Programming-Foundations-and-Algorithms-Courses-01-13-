#include <stdio.h>
#include <stdlib.h>


void    *ft_malloc(int i_number_of_elements, int i_element_size);
short	*ft_p_get_digit_frequency(int *p_i_entered_nbr, short   *p_chosen_digit);

int	main(int argc, char **argv)
{
	int	*p_i_entered_nbr;
	short	*p_chosen_digit;
	short	*p_digit_frequency;

	if (argc != 3)
	{
		printf("Error, please enter the number as command line argument then add the chosen digit to get frequence.\nFor Example\".FileName 5555 5\"\nAnswer will be: (4)\n");
		return (1);
	}
	p_i_entered_nbr = ft_malloc(1, sizeof(int));
	p_chosen_digit = ft_malloc(1, sizeof(short));
	if (!p_i_entered_nbr || !p_chosen_digit)
		return (2);
	*p_i_entered_nbr = atoi(argv[1]);
	*p_chosen_digit = (short)atoi(argv[2]);
	p_digit_frequency = ft_p_get_digit_frequency(p_i_entered_nbr, p_chosen_digit);
	printf("The frequency of the digit: (%hd) in the number (%d) is: (%hd)\n", *p_chosen_digit, atoi(argv[1]), *p_digit_frequency);
	free(p_digit_frequency);
	free(p_chosen_digit);
	free(p_i_entered_nbr);
	return (0);
}

short	*ft_p_get_digit_frequency(int *p_i_entered_nbr, short   *p_chosen_digit)
{
	short   *p_digit_frequency;
	
	p_digit_frequency = ft_malloc(1, sizeof(short));
	if (!p_digit_frequency)
		return (NULL);
	if (*p_i_entered_nbr < 0)
		*p_i_entered_nbr *= -1;
	*p_digit_frequency = 0;
	while (*p_i_entered_nbr > 0)
	{
		if (*p_i_entered_nbr % 10 == *p_chosen_digit)
			++(*p_digit_frequency);
		*p_i_entered_nbr /= 10;
	}
	return (p_digit_frequency);
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

