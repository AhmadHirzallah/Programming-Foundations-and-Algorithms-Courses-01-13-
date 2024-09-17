#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RESULT_LENGTH 150 


long	ft_get_nbr()
{
    long	entered_nbr;
    printf("%s", "Please enter a Number: ");
    if (scanf("%ld", &entered_nbr) != 1)
    {
        printf("Error: Invalid input\n");
        return -1;
    }
    return entered_nbr;
}

char	*ft_str_get_text_of_nbr(long nbr)
{
	char	*result;
	char	*tmp;

	result = malloc(sizeof(char) * (MAX_RESULT_LENGTH + 1));
	if (!result)
		return (NULL);
	result[0] = '\0'; // Initialize the result string
	if (nbr == 0)
	{
		strcpy(result, "Zero");
		return (result);
	}
	else if (nbr >= 1 && nbr <= 19)
	{
		char	*nbrs_arr[] = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten"
			, "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
		strcpy(result, nbrs_arr[nbr]);
		return (result);
	}
	else if (nbr >= 20 && nbr <= 99)
	{
		char	*nbrs_arr[] = {"", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy" , "Eighty" ,"Ninety"};
		
		strcpy(result, nbrs_arr[nbr / 10]);
		if (nbr % 10 != 0)
		{
			strcat(result, " ");
			tmp = ft_str_get_text_of_nbr(nbr % 10);
		    strcat(result, tmp);
			free (tmp);
		}
		return (result);
	}
	else if (nbr >= 100 && nbr <= 199)
	{
		strcpy(result, "One Hundred");
		if (nbr % 100 != 0)
		{
			strcat(result, " ");
			tmp = ft_str_get_text_of_nbr(nbr % 100);
			strcat(result, tmp);
			free(tmp);
		}
		return (result);
	}
	else if (nbr >= 200 && nbr <= 999)
	{
		tmp = ft_str_get_text_of_nbr(nbr / 100);
		strcpy(result, tmp);
		free (tmp);
		strcat(result, " Hundred");
		if (nbr % 100 != 0)
		{
			strcat(result, " ");
			tmp = ft_str_get_text_of_nbr(nbr % 100);
			strcat(result, tmp);
			free(tmp);
		}
		return (result);
	}
	else if (nbr >= 1000 && nbr <= 1999)
	{
		strcpy(result, "One Thousand");
		if (nbr % 1000 != 0)
		{
			strcat(result, " ");
			tmp = ft_str_get_text_of_nbr(nbr % 1000);
			strcat(result, tmp);
			free(tmp);
		}
		return (result);
	}
	else if (nbr >= 2000 && nbr <= 999999)
	{
		tmp = ft_str_get_text_of_nbr(nbr / 1000);
		strcpy(result, tmp);
		free (tmp);
		strcat(result, " Thousand");
		if (nbr % 1000 != 0)
		{
			strcat(result, " ");
			tmp = ft_str_get_text_of_nbr(nbr % 1000);
			strcat(result, tmp);
			free(tmp);
		}
		return (result);
	}
	else if (nbr >= 1000000 && nbr <= 1999999)
	{

		strcpy(result, "One Million");
		if (nbr % 1000000 != 0)
		{
			strcat(result, " ");
			tmp = ft_str_get_text_of_nbr(nbr % 1000000);
			strcat(result, tmp);
			free(tmp);
		}
		return (result);
	}
	else if (nbr > 1999999 && nbr <= 999999999)
	{
		tmp = ft_str_get_text_of_nbr(nbr / 1000000);
		strcpy(result, tmp);
		free (tmp);
		strcat(result, " Million");
		if (nbr % 1000000 != 0)
		{
			strcat(result, " ");
			tmp = ft_str_get_text_of_nbr(nbr % 1000000);
			strcat(result, tmp);
			free (tmp);
		}
		return (result);
	}
	else if (nbr >= 1000000000 && nbr <= 1999999999)
	{
		strcpy(result, "One Billion");
		if (nbr % 1000000000 != 0)
		{
			strcat(result ," ");
			tmp = ft_str_get_text_of_nbr(nbr % 1000000000);
			strcat(result, tmp);
			free(tmp);
		}
		return (result);
	}
	else if (nbr > 1999999999 && nbr <= 999999999999)
	{
		tmp = ft_str_get_text_of_nbr(nbr / 1000000000);
		strcpy(result, tmp);
		free(tmp);
		strcat(result, " Billion");
		if (nbr % 1000000000 != 0)
		{
			strcat(result, " ");
			tmp = ft_str_get_text_of_nbr(nbr % 1000000000);
			strcat(result, tmp);
			free(tmp);
		}
		return (result);
	}
	else 
	{
		free (result);
		return (NULL);
	}
}


int	main (void)
{
	long	eneterd_nbr;
	char	*str_number_as_text;

	eneterd_nbr = ft_get_nbr();
	str_number_as_text = ft_str_get_text_of_nbr(eneterd_nbr);
	if (str_number_as_text)
		printf("%s\n\n", str_number_as_text);
	else
	    printf("Number out of range or memory allocation failed.\n\n");
	return (0);
}


