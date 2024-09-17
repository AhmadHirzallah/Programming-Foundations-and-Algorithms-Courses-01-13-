#include <stdio.h>
#include <stdlib.h>

float	*ft_calculate_triangle_area(float *p_f_base, float *p_f_height);
void    *ft_generic_malloc(int i_elements_count, int i_element_size);
void    ft_read_base_and_height_of_triangle(float *p_f_base, float *p_f_height);

int	main(void)
{
	float	*p_f_area;
	float	*p_f_base;
	float	*p_f_height;

	p_f_area = (float *)ft_generic_malloc(1, sizeof(float));
	p_f_height = (float *)ft_generic_malloc(1, sizeof(float));
	p_f_base= (float *)ft_generic_malloc(1, sizeof(float));
	if (!p_f_area || !p_f_height || !p_f_base)
		return (1);
	ft_read_base_and_height_of_triangle(p_f_base, p_f_height);
	p_f_area = ft_calculate_triangle_area(p_f_base, p_f_height);
	printf("The Triangle Area is: %.2f\n", *p_f_area);
	free(p_f_area);
	free(p_f_base);
	free(p_f_height);

}

void    ft_read_base_and_height_of_triangle(float *p_f_base, float *p_f_height)
{
    printf("Please enter the base of the triangle: ");
    scanf("%f", p_f_base);
    printf("Please enter the hight of the triangle: ");
    scanf("%f", p_f_height);
}

void    *ft_generic_malloc(int i_elements_count, int i_element_size)
{
    void    *p_v;
    p_v = malloc(i_elements_count * i_element_size);
    if (p_v == NULL)
    {
        fprintf(stderr, "Memory allocation failed.\n");
        return (NULL);
    }
    return (p_v);
}

float	*ft_calculate_triangle_area(float *p_f_base, float *p_f_height)
{
	float	*p_f_area;

	p_f_area = (float *)ft_generic_malloc(1, sizeof(float));
	if (p_f_area == NULL)
		return (NULL);
	*p_f_area = (0.5 * (*p_f_base) * (*p_f_height));
	return (p_f_area);
}
