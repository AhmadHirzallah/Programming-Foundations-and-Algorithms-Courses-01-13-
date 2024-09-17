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
	printf("Words in the sentence:\n");
    for (short i = 0; i < *word_index; i++)
	{
        printf("Word (%d): (%13s)\tFirst Letter: (%c)\n", i + 1, words[i], words[i][0]);
        free(words[i]);
    }
    free(words);
    free(sentence);
    free(word_index);
	return (0);
}
