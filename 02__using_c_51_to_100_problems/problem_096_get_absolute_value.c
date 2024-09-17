#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int	ft_abs(int *entered_val);
void    *ft_malloc(int i_number_of_elements, int i_element_size);
int	main(int argc, char **argv)
{
	int	*entered_val;
	
	if (argc == 1)
	{
		printf("Pleases enter the number after %s", argv[0]);
		return (1);
	}
	entered_val = (int *)ft_malloc(1, sizeof(int));
	if (!entered_val)
		return (2);
	*entered_val = atoi(argv[1]);
	printf("My Abs function value is: (%d)\n" ,ft_abs(entered_val));
	printf("\nC Language's 'math.h' lib Abs function value is: (%d)\n", abs(*entered_val));
	free(entered_val);
}

int	ft_abs(int *entered_val)
{
	if (*entered_val < 0)
		*entered_val *= -1;
	return (*entered_val);
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
