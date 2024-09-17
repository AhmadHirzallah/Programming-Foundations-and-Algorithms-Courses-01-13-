#include <stdlib.h>
#include <stdio.h>
#include <math.h>

float	*ft_p_read_circumference(float	*p_f_circumf);
void	*ft_p_v_malloc(int i_items_count, int i_item_size);
float	*ft_calculate_circle_area(float *p_f_circumf);

int	main(void)
{
	float	*p_f_circumf;
	float	*p_f_area;

	p_f_circumf = ft_p_v_malloc(1, sizeof(float));
	if (!p_f_circumf)
		return (1);
	p_f_circumf = ft_p_read_circumference(p_f_circumf);
	p_f_area = ft_calculate_circle_area(p_f_circumf);
	printf("The circle area is: %.3f\n", *p_f_area);
	free(p_f_circumf);
	free(p_f_area);
	return (0);
}

float	*ft_calculate_circle_area(float *p_f_circumf)
{
	float	*p_f_area;

	p_f_area = ft_p_v_malloc(1, sizeof(float));
	if (!p_f_area)
		return (NULL);
	*p_f_area = pow(*p_f_circumf, 2) / (4 * M_PI);
	return (p_f_area);
}

float	*ft_p_read_circumference(float	*p_f_circumf)
{
	printf("Please enter the circumference: ");
	scanf("%f", p_f_circumf);
	return (p_f_circumf);
}

void	*ft_p_v_malloc(int i_items_count, int i_item_size)
{
	void	*p_v;

	p_v = (void *)malloc(i_items_count * i_item_size);
	if (!p_v)
	{
		printf("Memory Allocation Failed.\n");
		return (NULL);
	}
	return (p_v);
}
