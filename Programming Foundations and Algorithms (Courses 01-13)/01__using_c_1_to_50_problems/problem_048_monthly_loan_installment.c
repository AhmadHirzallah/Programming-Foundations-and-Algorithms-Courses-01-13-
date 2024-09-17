#include <stdlib.h>
#include <stdio.h>

typedef enum e_datatypes{
    int_type,
    float_type,
    double_type,
    char_type,
    short_type,
    long_type,
    long_long_type,
    unsigned_int_type,
    unsigned_short_type,
    unsigned_long_type,
    unsigned_long_long_type
} t_e_datatypes;

typedef struct s_loan_payment
{
	int	*p_nbr_of_months;
	float	*p_f_loan_amount;
	float	*p_f_monthly_payment;
}	t_s_loan_payment;

void    *ft_malloc(int i_number_of_elements, int i_element_size);
t_s_loan_payment	*ft_read_loan_amount__and__nbr_of_months(t_s_loan_payment    *p_s_about_loan);
t_s_loan_payment	*ft_p_get_monthly_installment(t_s_loan_payment    *p_s_about_loan);
void	ft_print_result(t_s_loan_payment    *p_s_about_loan);
void *ft_read_positive_nbr(char *tell, void *p_entered_nbr, t_e_datatypes type);

int	main(void)
{
	t_s_loan_payment	*p_s_about_loan;

	p_s_about_loan = (t_s_loan_payment *)ft_malloc(1, sizeof(t_s_loan_payment));
	if (!p_s_about_loan)
		return (1);
	p_s_about_loan = ft_read_loan_amount__and__nbr_of_months(p_s_about_loan);
	p_s_about_loan = ft_p_get_monthly_installment(p_s_about_loan);
	ft_print_result(p_s_about_loan);
	free(p_s_about_loan);
	free(p_s_about_loan->p_nbr_of_months);
	free(p_s_about_loan->p_f_loan_amount);
	free(p_s_about_loan->p_f_monthly_payment);
	return (0);
}

void	ft_print_result(t_s_loan_payment    *p_s_about_loan)
{
	printf("\nThe Loan amount to settle the Loan (%.3f $)  in  (%02i $) Months is : (%.3f $)\n", *(p_s_about_loan->p_f_loan_amount), *(p_s_about_loan->p_nbr_of_months), *(p_s_about_loan->p_f_monthly_payment));
}

t_s_loan_payment	*ft_read_loan_amount__and__nbr_of_months(t_s_loan_payment    *p_s_about_loan)
{
	p_s_about_loan->p_nbr_of_months = (int *)ft_malloc(1, sizeof(int));
	p_s_about_loan->p_f_loan_amount = (float *)ft_malloc(1, sizeof(float));
	p_s_about_loan->p_f_monthly_payment = (float *)ft_malloc(1, sizeof(float));
	if (!p_s_about_loan->p_nbr_of_months || !p_s_about_loan->p_f_loan_amount ||  !p_s_about_loan->p_f_monthly_payment)
		return (NULL);
	(p_s_about_loan->p_f_loan_amount) = ft_read_positive_nbr("Enter the loan amount:", p_s_about_loan->p_f_loan_amount, float_type);
	(p_s_about_loan->p_nbr_of_months) = ft_read_positive_nbr("Enter the number of months:", p_s_about_loan->p_nbr_of_months, int_type);
	return (p_s_about_loan);
}

t_s_loan_payment	*ft_p_get_monthly_installment(t_s_loan_payment    *p_s_about_loan)
{
	*(p_s_about_loan->p_f_monthly_payment) = (*(p_s_about_loan->p_f_loan_amount) / *(p_s_about_loan->p_nbr_of_months));
	return (p_s_about_loan);
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

void *ft_read_positive_nbr(char *tell, void *p_entered_nbr, t_e_datatypes type) {
    printf("Please enter a positive number:\n%s\n", tell);

    if (type == int_type) {
        int *p_int = (int *)p_entered_nbr;
        scanf("%d", p_int);
        while (*p_int < 0) {
            printf("Wrong entered number; please enter the number again:\n");
            scanf("%d", p_int);
        }
    } else if (type == float_type) {
        float *p_float = (float *)p_entered_nbr;
        scanf("%f", p_float);
        while (*p_float < 0) {
            printf("Wrong entered number; please enter the number again:\n");
            scanf("%f", p_float);
        }
    } else if (type == double_type) {
        double *p_double = (double *)p_entered_nbr;
        scanf("%lf", p_double);
        while (*p_double < 0) {
            printf("Wrong entered number; please enter the number again:\n");
            scanf("%lf", p_double);
        }
    } else if (type == char_type) {
        char *p_char = (char *)p_entered_nbr;
        scanf("%c", p_char);
        while (*p_char < 0) {
            printf("Wrong entered number; please enter the number again:\n");
            scanf("%c", p_char);
        }
    } else if (type == short_type) {
        short *p_short = (short *)p_entered_nbr;
        scanf("%hd", p_short);
        while (*p_short < 0) {
            printf("Wrong entered number; please enter the number again:\n");
            scanf("%hd", p_short);
        }
    } else if (type == long_type) {
        long *p_long = (long *)p_entered_nbr;
        scanf("%ld", p_long);
        while (*p_long < 0) {
            printf("Wrong entered number; please enter the number again:\n");
            scanf("%ld", p_long);
        }
    } else if (type == long_long_type) {
        long long *p_long_long = (long long *)p_entered_nbr;
        scanf("%lld", p_long_long);
        while (*p_long_long < 0) {
            printf("Wrong entered number; please enter the number again:\n");
            scanf("%lld", p_long_long);
        }
    } else if (type == unsigned_int_type) {
        unsigned int *p_uint = (unsigned int *)p_entered_nbr;
        scanf("%u", p_uint);
        while (*p_uint < 0) {
            printf("Wrong entered number; please enter the number again:\n");
            scanf("%u", p_uint);
        }
    } else if (type == unsigned_short_type) {
        unsigned short *p_ushort = (unsigned short *)p_entered_nbr;
        scanf("%hu", p_ushort);
        while (*p_ushort < 0) {
            printf("Wrong entered number; please enter the number again:\n");
            scanf("%hu", p_ushort);
        }
    } else if (type == unsigned_long_type) {
        unsigned long *p_ulong = (unsigned long *)p_entered_nbr;
        scanf("%lu", p_ulong);
        while (*p_ulong < 0) {
            printf("Wrong entered number; please enter the number again:\n");
            scanf("%lu", p_ulong);
		}
    } else if (type == unsigned_long_long_type) {
        unsigned long long *p_ullong = (unsigned long long *)p_entered_nbr;
        scanf("%llu", p_ullong);
        while (*p_ullong < 0) {
            printf("Wrong entered number; please enter the number again:\n");
            scanf("%llu", p_ullong);
        }
		
	}
    return (p_entered_nbr);
}
