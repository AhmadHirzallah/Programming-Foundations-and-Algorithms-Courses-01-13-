#include <vector>
#include <iostream>
#include <cctype>

using namespace std;

vector<string>	ft_get_words(string& sentence, short* word_index)
{
	vector<string> words;
	size_t	word_start_index;
	bool	in_word;
	short	c;
	short	word_len;


	word_start_index = 0;
	word_len = 0;
	in_word = false;
	*word_index = -1;
	c = -1;
	while (++c < sentence.length())
	{
        if (sentence[c] >= 9 && sentence[c] <= 13
				|| sentence[c] == 32) 
		{
			if (in_word)
			{
				word_len = c - word_start_index; 
				words.emplace_back(sentence.substr(word_start_index, word_len));
				in_word = 0;
			}
		}
		else if (!in_word)
		{
				word_start_index = c;
				in_word = 1;
		}
	}
	/* Add the last word if the sentence does not end with a space */
    if (in_word) 
	{
		word_len = sentence.length() - word_start_index;
		words.emplace_back(sentence.substr(word_start_index, word_len));
    }
	*word_index = static_cast<short>(words.size() - 1);
	return (words);
}

int	main(void)
{
	string	sentence;
    short	word_index;
    vector<string>	words;
	ssize_t	c;

    printf("Please enter the string: ");
	getline(cin >> ws, sentence);
	words = ft_get_words(sentence, &word_index);
	printf("Last word index: %hd\n", word_index);
	printf("\nEntered string words are:\n");
	c = -1;
	while (++c < words.size())
		printf("%s\n", words[c].c_str());
/*    for (const string &word : words)
        cout << word << endl;	*/
    return (0);
}

