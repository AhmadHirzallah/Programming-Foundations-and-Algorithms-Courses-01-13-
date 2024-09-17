#include <stdlib.h>
#include <stdio.h>


void    *ft_malloc(int i_number_of_elements, int i_element_size);
void	ft_print_letters_from_a_to_z();

int	main(void)
{
	ft_print_letters_from_a_to_z();
	return (0);
}


void	ft_print_letters_from_a_to_z()
{
	int	*i_az_letters;

	i_az_letters = (int *)ft_malloc(1, sizeof(int));
	if (!i_az_letters)
		return;
	*i_az_letters = 'A';
	while (*i_az_letters <= 'Z')
	{
		printf("%c", *i_az_letters);
		(*i_az_letters)++;
	}
	printf("\n");
	free(i_az_letters);
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
