#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void	ft_print_array_elements();
void	ft_fill_array_with_random_nbrs();
short	ft_get_positive_count();
int ft_p_generate_random_nbr_in_range(int from, int to);

int	arr[100];
short	arr_len;
short	positive_nbrs_count;

int main(int argc, char *argv[]) 
{
    srand(time(NULL));
    if (argc != 2) 
	{
        printf("Usage: %s <size_of_array>\n", argv[0]);
        return 1;
	}
	positive_nbrs_count = 0; 
	arr_len = atoi(argv[1]);
	ft_fill_array_with_random_nbrs();
	positive_nbrs_count = ft_get_positive_count();
	ft_print_array_elements();
	printf("Positive Numbers count is: (%hd)\n\n", positive_nbrs_count);
	return (0);
}

void	ft_fill_array_with_random_nbrs()
{
	int	c;

	c = -1;
	while (++c < arr_len)
		arr[c] = ft_p_generate_random_nbr_in_range(-10, 10);
}

void	ft_print_array_elements()
{
	short	l;

	l = -1;
	while (++l < arr_len)
		printf("%d  ", arr[l]);
	printf("\n\n");
}

short	ft_get_positive_count()
{
	short	l;

	l = -1;
	while (++l < arr_len)
		if (arr[l] > 0)
			positive_nbrs_count++;
	return positive_nbrs_count;
}


int ft_p_generate_random_nbr_in_range(int from, int to) 
{
    return (from + rand() % (to - from + 1));
}
