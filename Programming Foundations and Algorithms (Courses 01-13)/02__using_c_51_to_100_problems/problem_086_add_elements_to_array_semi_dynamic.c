#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void    *ft_malloc(int i_number_of_elements, int i_element_size);
int	ft_read_ranged_number(int from, int to, char	*message);
void	ft_add_elements_to_array_dynamically(int i_array[100], int *count);
void	ft_print_array_elements(int i_array[100], short entered_len);

int	i_array[100];
int	count;

int	main(int argc, char **argv)
{
	ft_add_elements_to_array_dynamically(i_array, &count);
	printf("The array length is: (%d)\n", count);
	ft_print_array_elements(i_array, count);
	return (0);
}

void	ft_add_elements_to_array_dynamically(int i_array[100], int *count)
{
	int	i_entered_nbr;
	short	want_more_check;

	*count = 0;
	want_more_check = 1;
	while (want_more_check == 1)
	{
		printf("Please enter a number to add it to the array: ");
		scanf("%d", &i_entered_nbr);
		i_array[*count] = i_entered_nbr;
		(*count)++;
		printf("Do you want to add more number? [1]: Yes, [2]: No: ");
		want_more_check = ft_read_ranged_number(1, 2, "\nYou entered a wrong number; please enter it again: ");
	}
}

int	ft_read_ranged_number(int from, int to, char	*message)
{
	int	i_entered_nbr;

	scanf("%d", &i_entered_nbr);
	while (i_entered_nbr < from || i_entered_nbr > to)
	{
		printf("%s", message);
		scanf("%d", &i_entered_nbr);
	}
	return (i_entered_nbr);
}

void ft_print_array_elements(int i_array[100], short entered_len)
{
    short	c;

    c = 0;
    while (c < entered_len)
    {
        printf("%d ", i_array[c]);
        c++;
    }
    printf("\n");
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
