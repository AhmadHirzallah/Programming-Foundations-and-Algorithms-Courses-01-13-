#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void    *ft_malloc(int i_number_of_elements, int i_element_size);
float	ft_sqrt(float *entered_val);

int	main(int argc, char **argv)
{
	float	*entered_val;
	
	if (argc == 1)
	{
		printf("Pleases enter the number after %s\n", argv[0]);
		return (1);
	}
	entered_val = (float *)ft_malloc(1, sizeof(float));
	if (!entered_val)
		return (2);
	*entered_val = atof(argv[1]);
	printf("My sqrt function value is: (%.2f)\n" ,ft_sqrt(entered_val));
	printf("\nC Language's 'math.h' lib sqrt function value is: (%.2f)\n", sqrt(*entered_val));
	free(entered_val);
}

float	ft_sqrt(float *entered_val)
{
	short	c;
	float	nbr;

	if (*entered_val < 0)
		return (-9999);
	c = -1;
	while (++c <= ceil(*entered_val / 2))
	{
		if (c * c == *entered_val)
			return (c);
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


