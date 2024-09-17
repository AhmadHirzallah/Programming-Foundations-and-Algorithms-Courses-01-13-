#include <stdio.h>
#include <stdlib.h>

void    *ft_malloc(int i_number_of_elements, int i_element_size);
int	ft_get_count_of_chosen_nbr(int *p_i_entered_nbrs, int *entered_count_of_nbrs, short want_to_check_nbr);
void ft_print_elements(int *p_i_entered_nbrs, int *entered_count_of_nbrs);
int	*ft_read_entered_elemnts(int *p_i_entered_nbrs, int *entered_count_of_nbrs);

int	main(int argc, char **argv)
{
	int	*p_i_entered_nbrs;
	int	*entered_count_of_nbrs;
	short	want_to_check_nbr;

	if (argc != 2)
	{
		printf("Please enter the number of the elements as Command Line Argument after filename.\n");
		return (1);
	}
	entered_count_of_nbrs = (int *)ft_malloc(1, sizeof(int));
	if (!entered_count_of_nbrs)
		return (2);
	*entered_count_of_nbrs = atoi(argv[1]);
	p_i_entered_nbrs = ft_malloc(*entered_count_of_nbrs, sizeof(int));
	if (!p_i_entered_nbrs)
		return (2);
	ft_read_entered_elemnts(p_i_entered_nbrs, entered_count_of_nbrs);
	printf("Please enter the number that you want to check: ");
	scanf("%hd", &want_to_check_nbr);
	ft_print_elements(p_i_entered_nbrs, entered_count_of_nbrs);
	printf("The element: (%d) is repeated: (%d) Times.\n", want_to_check_nbr, ft_get_count_of_chosen_nbr(p_i_entered_nbrs, entered_count_of_nbrs, want_to_check_nbr));
	free(p_i_entered_nbrs);
	free(entered_count_of_nbrs);
	return (0);
}

int	ft_get_count_of_chosen_nbr(int *p_i_entered_nbrs, int *entered_count_of_nbrs, short want_to_check_nbr)
{
	int	i;
	int i_counter;

	i_counter = 0;
	i = 0;
	while (i < *entered_count_of_nbrs)
	{
		if (p_i_entered_nbrs[i] == want_to_check_nbr)
			i_counter++;
		i++;
	}
	return (i_counter);
}


void ft_print_elements(int *p_i_entered_nbrs, int *entered_count_of_nbrs) 
{
	int	c;

	c = 0;
	printf("\nThe original elemnts are:  ");
	while (c < *entered_count_of_nbrs)
	{
		printf("%d ", p_i_entered_nbrs[c]);
		c++;
	}
	printf("\n");
}

int	*ft_read_entered_elemnts(int *p_i_entered_nbrs, int *entered_count_of_nbrs)
{
	short	i;

	i = 0;
	while (i < *entered_count_of_nbrs)
	{
		printf("Enter the element [%i]: ", i + 1);
		scanf("%i", p_i_entered_nbrs + i);
		i++;
	}
	return (p_i_entered_nbrs);
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

