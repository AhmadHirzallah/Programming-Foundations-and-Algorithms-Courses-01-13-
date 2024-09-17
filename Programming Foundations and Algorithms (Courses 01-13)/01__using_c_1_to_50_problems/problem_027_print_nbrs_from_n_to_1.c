#include <stdio.h>
#include <stdlib.h>

void    *ft_p_v_malloc(int i_elements_number, int i_element_size);
void    ft_print_nbrs_from_n_to_1(int i_entered_n);

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        printf("ERROOOOOOOOOOOOOOR !!\nEnter n value after file name (ONLY)\n");
        return (2);
    }
    ft_print_nbrs_from_n_to_1(atoi(argv[1]));
}

void    ft_print_nbrs_from_n_to_1(int i_entered_n)
{
    while (i_entered_n >= 1)
        printf("% i ", i_entered_n--);
    printf("\n");

}
void    *ft_p_v_malloc(int i_elements_number, int i_element_size)
{
    void    *p_v;

    p_v = (void *)malloc(i_elements_number * i_element_size);
    if (p_v == NULL)
    {
        printf("ERROR! Memory allocation failed.\n");
        return (NULL);
    }
    return (p_v);
}  
