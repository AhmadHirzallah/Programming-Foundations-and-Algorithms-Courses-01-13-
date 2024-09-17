#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef enum e_char_type
{
	small_letter = 1,
	capital_letter,
	digit,
	special_char
}	t_e_char_type;


void    *ft_malloc(int i_number_of_elements, int i_element_size);
char *ft_e_generate_char_types(t_e_char_type *p_e_type, char *p_i_generated_specified_char, int *p_i_generated_random_nbr, int *from, int *to);
int	*ft_p_generate_random_nbr_in_range(int *p_i_generated_random_nbr, int *from, int *to);


int	main(int argc, char **argv)
{
	int	*p_i_generated_random_nbr;
	char	*p_i_generated_specified_char;
	t_e_char_type	*p_e_type;
	int	*from;
	int	*to;
	

	srand((unsigned)time(NULL));
	from = (int *)ft_malloc(1, sizeof(int));
	to = (int *)ft_malloc(1, sizeof(int));
	p_i_generated_random_nbr = (int *)ft_malloc(1, sizeof(int));
	p_e_type = (t_e_char_type *)ft_malloc(1, sizeof(t_e_char_type));
	p_i_generated_specified_char = (char *)ft_malloc(1, sizeof(char));
	if (!p_i_generated_random_nbr || !from || !to || !p_i_generated_specified_char || !p_e_type)
		return (1);
	*p_e_type = small_letter;
	p_i_generated_specified_char = ft_e_generate_char_types(p_e_type, p_i_generated_specified_char, p_i_generated_random_nbr, from, to);
	printf("The Random Small Letter: (%c)\n", *p_i_generated_specified_char);
	*p_e_type = capital_letter;
	p_i_generated_specified_char = ft_e_generate_char_types(p_e_type, p_i_generated_specified_char, p_i_generated_random_nbr, from, to);
	printf("The Random Capital Letter: (%c)\n", *p_i_generated_specified_char);
	*p_e_type = digit;
	p_i_generated_specified_char = ft_e_generate_char_types(p_e_type, p_i_generated_specified_char, p_i_generated_random_nbr, from, to);
	printf("The Random Digit: (%c)\n", *p_i_generated_specified_char);
	*p_e_type = special_char;
	p_i_generated_specified_char = ft_e_generate_char_types(p_e_type, p_i_generated_specified_char, p_i_generated_random_nbr, from, to);
	printf("The Random Special Character: (%c)\n", *p_i_generated_specified_char);
		free(p_i_generated_random_nbr);
		free(from);
		free(to);
		free(p_e_type);
		free(p_i_generated_specified_char);
		return (0);
}

char *ft_e_generate_char_types(t_e_char_type *p_e_type, char *p_i_generated_specified_char, int *p_i_generated_random_nbr, int *from, int *to) 
{
	if (*p_e_type == small_letter)
	{
		*from = (int)('a');
		*to = (int)('z');
		*p_i_generated_specified_char = (char)(*ft_p_generate_random_nbr_in_range(p_i_generated_random_nbr, from, to));
	}
	else if (*p_e_type == capital_letter)
	{

		*from = (int)('A');
		*to = (int)('Z');
		*p_i_generated_specified_char = (char)(*ft_p_generate_random_nbr_in_range(p_i_generated_random_nbr, from, to));
	}
	else if (*p_e_type == digit)
	{
		*from = (int)('0');
		*to = (int)('9');
		*p_i_generated_specified_char = (char)(*ft_p_generate_random_nbr_in_range(p_i_generated_random_nbr, from, to));
	}
	else if (*p_e_type == special_char)
	{
		*from = (int)('!');
		*to = (int)('/');
		*p_i_generated_specified_char = (char)(*ft_p_generate_random_nbr_in_range(p_i_generated_random_nbr, from, to));
	}
	return (p_i_generated_specified_char);
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


