#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float ft_round(float *entered_val);
void    *ft_malloc(int i_number_of_elements, int i_element_size);
float	ft_round(float *entered_val);

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
	printf("My round function value is: (%f)\n" ,ft_round(entered_val));
	printf("\nC Language's 'math.h' lib round function value is: (%f)\n", round(*entered_val));
	free(entered_val);
}

float	ft_round(float *entered_val)
{
	short	flag;
	float	round_result;

	round_result = 0;
	flag = 0;
	if (*entered_val < 0)
	{
		flag = 1;
		*entered_val *= -1;
	}

	if (*entered_val >= ((int)*entered_val + 0.5))
		round_result = (int)*entered_val + 1;
	else
		round_result = (int)*entered_val;
	if (flag == 1)
		return (round_result * -1);
	else
		return (round_result);
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
