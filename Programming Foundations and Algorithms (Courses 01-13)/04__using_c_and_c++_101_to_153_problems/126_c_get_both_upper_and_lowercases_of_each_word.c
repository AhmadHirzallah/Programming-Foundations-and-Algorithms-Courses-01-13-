#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int ft_count_words(char *sentence) 
{
    int count = 0;
    int in_word = 0;

    while (*sentence) 
	{
        if (*sentence >= 9 && *sentence <= 13
				|| *sentence == 32) 
            in_word = 0;
		else if (!in_word)
		{
            in_word = 1;
            count++;
        }
        sentence++;
    }
    return (count);
}

char	**ft_get_words(char *sentence, short *word_index)
{
	char	**words;
	char	*word_start;
	short	in_word;
	short	c;
	short	word_len;

	words = (char **) malloc((1 + ft_count_words(sentence)) * sizeof(char *));
	word_start = NULL;
	in_word = 0;
	*word_index = -1;
	c = -1;
	while (sentence[++c])
	{
        if (sentence[c] >= 9 && sentence[c] <= 13
				|| sentence[c] == 32) 
		{
			if (in_word)
			{
				word_len = &sentence[c] - word_start;
				words[++(*word_index)] = (char *) malloc((word_len + 1) * sizeof(char));
				strncpy(words[*word_index], word_start, word_len);
				words[*word_index][word_len] = '\0';
				in_word = 0;
			}
		}
		else
		{
			if (!in_word)
			{
				word_start = &sentence[c];
				in_word = 1;
			}
		}
	}
	/* Add the last word if the sentence does not end with a space */
    if (in_word) 
	{
        word_len = &sentence[c] - word_start;
		words[++(*word_index)] = (char *) malloc((word_len + 1) * sizeof(char));
        strncpy(words[*word_index], word_start, word_len);
        words[*word_index][word_len] = '\0';
    }
	words[++(*word_index)] = NULL;
	return (words);
}

char	**ft_convert_each_word_to_uppercase(char **words, short *word_index)
{
	short	c1;
	short	c2;

	c1 = -1;
	while (++c1 < *word_index)
	{
		c2 = -1;
		while (words[c1][++c2])
			if (words[c1][c2] >= 'a' && words[c1][c2] <= 'z')
				words[c1][c2] -= 32;
	}
	return (words);
}

char	**ft_convert_each_word_to_lowercase(char **words, short *word_index)
{

	short	c1;
	short	c2;

	c1 = -1;
	while (++c1 < *word_index)
	{
		c2 = -1;
		while (words[c1][++c2])
			if (words[c1][c2] >= 'A' && words[c1][c2] <= 'Z')
				words[c1][c2] += 32;
	}
	return (words);
}

int	main(void)
{
	short	*word_index;
	char	*sentence;
	char	**words;
	size_t	len;
	ssize_t	read;

	len = 0;
	word_index = (short *) malloc(sizeof(short));
	printf("Please enter the string: ");
	read = getline(&sentence, &len, stdin);
	if (read != -1)
    {
        if (sentence[read - 1] == '\n')
            sentence[read - 1] = '\0';
    }
	words = ft_get_words(sentence, word_index);
	words =	ft_convert_each_word_to_uppercase(words, word_index);
	printf("\nWords in the sentence which converted to uppercase:\n");
    for (short i = 0; i < *word_index; i++)
	{
        printf("Word (%d): (%13s)\n", i + 1, words[i]);
    }
	words =	ft_convert_each_word_to_lowercase(words, word_index);
	printf("\n\nWords in the sentence converted to lowercase:\n");
    for (short i = 0; i < *word_index; i++)
	{
        printf("\nWord (%d): (%13s)\n", i + 1, words[i]);
        free(words[i]);
    }
    free(words);
    free(sentence);
    free(word_index);
	return (0);
}


