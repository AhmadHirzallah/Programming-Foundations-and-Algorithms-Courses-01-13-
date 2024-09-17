#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void    *ft_malloc(int i_number_of_elements, int i_element_size);
int	*ft_p_generate_random_nbr_in_range(int *p_i_generated_random_nbr, int *from, int *to);

int	main(int argc, char **argv)
{
	int	*p_i_generated_random_nbr;
	int	*from;
	int	*to;

	srand((unsigned)time(NULL));
	from = ft_malloc(1, sizeof(int));
	to = ft_malloc(1, sizeof(int));
	p_i_generated_random_nbr = ft_malloc(1, sizeof(int));
	if (!p_i_generated_random_nbr || !from || !to)
		return (2);
	if (argc == 1)
	{
		printf("You can enter TWO Command Line Arguments; Which are the range \"from\"  \"to\".\nFor Example: \n( ./problem_069_generate_random_number_in_1to10_range.c \"1\"   \"10\" )\n\n\n");
		*from = 1;
		*to = 10;
		p_i_generated_random_nbr = ft_p_generate_random_nbr_in_range(p_i_generated_random_nbr, from, to);
		printf("The Generated Number is: %d\n", *p_i_generated_random_nbr);
		free(p_i_generated_random_nbr);
		free(from);
		free(to);
		return (0);
	}
	else
	{
		*from = atoi(argv[1]);
		*to = atoi(argv[2]);
		p_i_generated_random_nbr = ft_p_generate_random_nbr_in_range(p_i_generated_random_nbr, from, to);
		printf("The Generated Number is: %d\n", *p_i_generated_random_nbr);
		free(p_i_generated_random_nbr);
		free(from);
		free(to);
		return (0);
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

