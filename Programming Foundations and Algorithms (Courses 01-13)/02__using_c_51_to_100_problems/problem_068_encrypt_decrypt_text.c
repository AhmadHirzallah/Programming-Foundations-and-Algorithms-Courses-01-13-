#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void    *ft_malloc(int i_number_of_elements, int i_element_size);
char	*ft_p_decrypt_text(char *p_encrypted_text);
char	*ft_p_encrypt_text(char *p_encrypted_text);

const short	ENCRYPTION_KEY = 2;

int	main(int argc, char **argv)
{
	char	*p_entered_text;
	char	*p_encrypted_text;
	
	if (argc != 2)
	{
		printf("Error, please enter the number as command argument line.\n");
		return (1);
	}
	p_entered_text = argv[1];
	p_encrypted_text = (char *)ft_malloc((strlen(p_entered_text) + 1), sizeof(char));
	if (!p_encrypted_text)
		return (2);
	strcpy(p_encrypted_text, p_entered_text);
	printf("The text before Encryption: (%s)\n", p_entered_text);
	p_encrypted_text = ft_p_encrypt_text(p_encrypted_text);
	printf("The text after Encryption: (%s)\n", p_encrypted_text);
	p_encrypted_text = ft_p_decrypt_text(p_encrypted_text);
	printf("The text after Decryption: (%s)\n", p_encrypted_text);
	free(p_encrypted_text);
	return (0);
}

char	*ft_p_encrypt_text(char *p_encrypted_text)
{
	char	*p_tmp;

	p_tmp = p_encrypted_text;
	while (*p_tmp)
		(*p_tmp++) += ENCRYPTION_KEY;
	return (p_encrypted_text);
}

char	*ft_p_decrypt_text(char *p_encrypted_text)
{
	char	*p_tmp;

	p_tmp = p_encrypted_text;
	while (*p_tmp)
		(*p_tmp++) -= ENCRYPTION_KEY;
	return (p_encrypted_text);
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

