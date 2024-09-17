#include <stdlib.h>
#include <stdio.h>
#include <math.h>

void    *ft_generic_malloc(int i_elements_count, int i_element_size);
float	*ft_calculate_circle_area(float *p_f_radius);
void	ft_read_circle_radius(float *p_f_radius);

int	main(void)
{
	float	*p_f_area;
	float	*p_f_radius;

	p_f_radius = (float *)ft_generic_malloc(1, sizeof(float));
	if (!p_f_radius)
		return (1);
	ft_read_circle_radius(p_f_radius);
	p_f_area = ft_calculate_circle_area(p_f_radius);
	printf("The Area of the circle is: %.3f\n", *p_f_area);
	free(p_f_area);
	free(p_f_radius);
	return (0);
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

float	*ft_calculate_circle_area(float *p_f_radius)
{
	float	*p_f_area;
	p_f_area = (float *)ft_generic_malloc(1, sizeof(float));
	if (!p_f_area)
		return (NULL);
	*p_f_area = pow(*p_f_radius, 2) * M_PI;
	return (p_f_area);
}

void	ft_read_circle_radius(float *p_f_radius)
{
	printf("Please enter the radius of the circle: ");
	scanf("%f", p_f_radius);
}
