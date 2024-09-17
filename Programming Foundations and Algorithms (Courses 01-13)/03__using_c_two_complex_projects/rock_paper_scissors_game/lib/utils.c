#include "game.h"

int	ft_i_read_nbr(char *speak)
{
	int	i_entered_nbr;


	printf("%s\n", speak);
	scanf("%d", &i_entered_nbr);
	return (i_entered_nbr);
}

char	*ft_read_str() 
{
    char	*line;
    size_t	len;
    ssize_t	read;

	line = NULL;
	len = 0;

    printf("Enter a line of text: ");
    read = getline(&line, &len, stdin);
    if (read == -1) 
	{
        printf("Error reading input.\n");
        return (NULL);
    }

    return (line);
}

double	ft_d_read_nbr(char *speak) 
{
    double d_entered_nbr;

    printf("%s\n", speak);
    scanf("%lf", &d_entered_nbr);
    return (d_entered_nbr);
}

void	*ft_malloc(int i_number_of_elements, int i_element_size)
{
    void	*p_v;

    p_v = (void *)malloc(i_number_of_elements * i_element_size);
    if (!p_v)
    {
        printf("Unfortunatelly; Memory allocation failed.\n");
        return (NULL);
    }
    return (p_v);
}

int	ft_i_read_ranged_nbr(char *tell ,int min, int max)
{
    int number;

	printf("%s", tell);
    while (1)
	{
        if (scanf("%d", &number) == 1 && number >= min && number <= max)
		{
            break;
        } 
		else
		{
            printf("Invalid input. Please enter a number between (%d) to(%d):\n", min, max);
            while (getchar() != '\n');
        }
    }
    return (number);
}

char*	ft_put_tabs(short num) 
{
    char	*tab;
    short i;

    if (num < 0)
	{
        return (NULL);
    }
	tab = malloc((size_t)(num + 1) * sizeof(char));
    if (tab == NULL) 
	{
        return (NULL);
    }
	i = 0;
    while (i < num) {
        tab[i] = '\t';
        i++;
    }
    tab[num] = '\0';

    return (tab);
}


int	ft_p_generate_random_nbr_in_range(int from, int to)
{	
	int	i_generated_random_nbr;

	i_generated_random_nbr = rand() % (to - from + 1) + from;
	return (i_generated_random_nbr);
}

