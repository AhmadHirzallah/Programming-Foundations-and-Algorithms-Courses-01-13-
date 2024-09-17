#include <stdio.h>
#include <stdlib.h>

void    *ft_malloc(int i_number_of_elements, int i_element_size);
void	ft_print_table_header();
char	*ft_column_seperator_in_table(short nbr);
void	ft_print_1to10_multiplication_table();

int	main(void)
{
	ft_print_1to10_multiplication_table();
	return (0);
}

char	*ft_column_seperator_in_table(short nbr)
{
	char	*p_str;

	p_str = "\t |";
	return (p_str);
}

void	ft_print_table_header()
{
	short   *p_i;
	p_i = (short *)ft_malloc(1, sizeof(short));
	if (!p_i)
		return ;
	*p_i = 0;
	printf("\t\t\t\tMultiplication table from 1 to 10\n\n");
	printf("\t  ");
	while (++(*p_i) <= 10)
		printf("% hd\t", *p_i);
	printf("\n");
	printf("-----------------------------------------------------------------------------------\n");
	free (p_i);
}

void	ft_print_1to10_multiplication_table()
{
	short	*p_i;
	short	*p_j;

	p_j = (short *)ft_malloc(1, sizeof(short));
	p_i = (short *)ft_malloc(1, sizeof(short));
	if (!p_i || !p_j)
		return ;
	ft_print_table_header();
	*p_i = 0;
	*p_j = 0;
	while (++(*p_i) <= 10)
	{
		printf("%hd%s", (*p_i), (ft_column_seperator_in_table(*p_i)));
		while (++(*p_j) <= 10)
			printf(" %hd\t", (*p_j) * (*p_i));
		printf("\n");
		(*p_j) = 0;
	}
	free(p_j);
	free(p_i);
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


