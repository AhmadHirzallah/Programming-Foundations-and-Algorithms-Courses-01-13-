#include <stdio.h>
#include <stdlib.h>

void    *ft_malloc(int i_number_of_elements, int i_element_size);
float	*ft_p_f_get_summation(float   *p_f_entered_nbr, float   *p_f_summation);

int	main(void)
{
	float	*p_f_entered_nbr;
	float	*p_f_summation;

	p_f_entered_nbr = (float *)ft_malloc(1, sizeof(float));
	p_f_summation = (float *)ft_malloc(1, sizeof(float));
	if (!p_f_entered_nbr || !p_f_summation)
		return (1);
	p_f_summation = ft_p_f_get_summation(p_f_entered_nbr, p_f_summation);
	printf("\nThe summation of all numbers is: %.4f\n", *p_f_summation);
	free(p_f_entered_nbr);
	free(p_f_summation);
	return (0);
}

float	*ft_p_f_get_summation(float   *p_f_entered_nbr, float   *p_f_summation)
{
	*p_f_summation = 0;
	*p_f_entered_nbr = 0;
	while (*p_f_entered_nbr != -99)
	{
		printf("Please enter a number:\n");
		scanf("%f", p_f_entered_nbr);
		if (*p_f_entered_nbr != -99)
			*p_f_summation += *p_f_entered_nbr;
	}
	return (p_f_summation);
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
