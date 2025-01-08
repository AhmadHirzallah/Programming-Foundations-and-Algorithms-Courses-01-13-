#pragma once
#ifndef STRINGUTILS_HPP
# define STRINGUTILS_HPP

# include <iostream>
# include <string>
# include <vector>
# include <algorithm> 
# include <cctype>
# include <cstddef>



class	StringUtils
{
	public:
				StringUtils(void)
				{
					_value = "";
				}

				StringUtils(const std::string &value)
				{
					this->_value = value;
				}

				StringUtils(const StringUtils &other)
				{
					this->_value = other._value;
				}

				StringUtils& operator=(const StringUtils &other)
				{
					if (this != &other)
					{
						this->_value = other._value;
					}
					return (*this);
				}

				void	setValue(const std::string &new_value)
				{
					this->_value = new_value;
				}

				const std::string&	getValue(void) const
				{
					return (this->_value);
				}

				// __declspec(property(get = get_value, put = set_value)) string value;

				StringUtils&	operator=(const std::string &value)
				{
					this->_value = value;
					return (*this);
				}

				friend std::ostream&	operator<<(std::ostream &os, const StringUtils& obj)
				{
					os << obj._value;
					return (os);
				}










				/////////////////////////////// MY IMPLEMENTATION OF UTILITISE  ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::

				static int	getLength(const std::string &str)
				{
					return (str.length());
					
					// int len = 0;

					// for (char &c : str)
					// 	len++;
					
					// return (len);
				}

				int	getLength()
				{
					return (getLength(_value));
				}




				static int	countWordsWithDelim(const std::string &str, const std::string &delim = " ")
				{
					int	counter = 0,	pos = 0,	start = 0;

					if (delim.empty())
						return 0;
					
					while((pos = str.find(delim, start)) != std::string::npos)
					{
						if (pos > start)
							counter++;
						start = pos + delim.length();
					}

					if (start < str.length())
						counter++;
					return (counter);
				}

				int	countWordsWithDelim(const std::string &delim = " ")
				{
					return (countWordsWithDelim(_value, delim));
				}




				static int	calculateWordsNbr(const std::string &str, const std::string &delimiters = " \t\n\r|,;.:")
				{
					int					counter = 0;
					bool	in_word = false;

					if (str.empty()) 
						return (0);

					for (size_t i = 0; i < str.length(); i++)
					{
						if ((isspace(str[i])) 
							|| (delimiters.find(str[i]) != std::string::npos))
						{
							if (in_word)
							{
								counter++;
								in_word = false;
							}
						}
						else
							in_word = true;
					}

					if (in_word)
						counter++;

					return (counter);
				}

				int	calculateWordsNbr()
				{
					const std::string	delimiters = " \t\n\r|,;.:-";

					return (calculateWordsNbr(_value,  delimiters));
				}




				static std::string  upperFirstLetterOfEachWord(std::string str, const std::string &delimiters = " \t\n\r|,;.:")
				{
					bool	is_first_letter = true;
					for (size_t i = 0; i < str.size(); i++)
					{
						if ((delimiters.find(str[i]) == std::string::npos)
							&& is_first_letter)
						{
							str[i] = std::toupper(str[i]);
							is_first_letter = false;
						}
						
						is_first_letter = ((delimiters.find(str[i]) != std::string::npos) ? true : false);
					}
					return (str);
				}

				void	upperFirstLetterOfEachWord(const std::string &delimiters = " \t\n\r|,;.:")
				{
					_value = (upperFirstLetterOfEachWord(_value,	delimiters));
				}




				static std::string	lowerFirstLetterOfEachWord(std::string str, const std::string &delimiters = " \t\n\r|,;.:")
				{
					bool	is_first_letter = true;
					for (size_t i = 0; i < str.size(); i++)
					{
						if ((delimiters.find(str[i]) == std::string::npos)
							&& is_first_letter)
						{
							str[i] = std::tolower(str[i]);
							is_first_letter = false;
						}
						
						is_first_letter = ((delimiters.find(str[i]) != std::string::npos) ? true : false);
					}

					return (str);
				}

				void	lowerFirstLetterOfEachWord(const std::string &delimiters = " \t\n\r|,;.:")
				{
					_value = (lowerFirstLetterOfEachWord(_value,	delimiters));
				}




				static std::string	toUpperAllString(std::string str)
				{
					for (char &c : str)
						c = toupper(c);
					
					return (str);
				}

				void	toUpperAllString()
				{
					_value = toUpperAllString(_value);
				}




				static std::string	toLowerAllString(std::string str)
				{
					for (char &c : str)
						c = tolower(c);
					
					return (str);
				}

				void	toLowerAllString()
				{
					_value = toLowerAllString(_value);
				}




				static char	invertLetterCases(char chr)
				{
					return (isupper(chr) ? tolower(chr) : toupper(chr));
				}



				static std::string  invertAllLettersCases(std::string str)
				{
					for (int i = 0 ; i < str.length(); i++)
						str[i] = invertLetterCases(str[i]);

					return (str);
				}

				void	invertAllLettersCases()
				{
					_value = invertAllLettersCases(_value);
				}




				enum	e_letters_cases
				{
					ALL,
					CAPITALS,
					SMALLS
				};


				static int	countLetters(std::string &str, e_letters_cases letters_case = ALL)
				{
					int	counter = 0;

					if (letters_case == ALL)
						return (str.length());

					for (char &chr : str)
					{
						if ((letters_case == CAPITALS) && isupper(chr))
							counter++;
						else if ((letters_case == SMALLS) && islower(chr))
							counter++;
					}

					return (counter);
				}

				int	countLetters(e_letters_cases letter_case = ALL)
				{
					return (countLetters(_value, letter_case));
				}




				static int	countCapitlChrs(std::string &str)
				{
					int	counter = 0;

					for (char &chr : str)
					{
						if (isupper(chr))
							counter++;
					}

					return (counter);
				}

				int	countCapitlChrs()
				{
					return (countCapitlChrs(_value));
				}




				static int	countSmallChrs(std::string &str)
				{
					int	counter = 0;

					for (char &chr : str)
					{
						if (islower(chr))
							counter++;
					}

					return (counter);
				}

				int	countSmallChrs()
				{
					return (countSmallChrs(_value));
				}




				static int	countSpecificChr(char searched_chr,	std::string str,	bool match_case = true)
				{
					int	counter = 0;

					for (char &chr : str)
					{
						if (match_case)
						{
							if (chr == searched_chr)
								counter++;
						}
						else
						{
							if (tolower(chr) == tolower(searched_chr))
								counter++;
						}
					}

					return (counter);
				}

				int	countSpecificChr(char searched_chr,	bool match_case = true)
				{
					return (countSpecificChr(searched_chr, _value, match_case));
				}




				static bool	isVowel(char chr)
				{
					std::string	vowels = "aeiou";
					
					return (vowels.find(tolower(chr)) != std::string::npos); 
				}




				static int	countVowels(const std::string &str)
				{
					int	counter = 0;

					for (const char &chr : str)
						if (isVowel(chr))
							counter++;
				
					return (counter);
				}

				int	countVowels()
				{
					return (countVowels(_value));
				}




				enum	e_split_type {MULTI, SINGLE, DEFAULT};

				static std::vector <std::string>	splitByDelim(const std::string &str, const std::string &delemiters = " \t\n\r|,;.:", e_split_type split_type = e_split_type::DEFAULT)
				{
					if (split_type == e_split_type::SINGLE)
						return (splitSingleChrDelim(str, delemiters));

					else if (split_type == e_split_type::MULTI)
						return (splitMultiChrsDelim(str, delemiters));

					else 
					{
						if (delemiters.length() > 1)
							return (splitMultiChrsDelim(str, delemiters));
						else
							return (splitSingleChrDelim(str, delemiters));
					}
				}




				static std::string	trimLeftSpaces(std::string str)
				{
					for (int i = 0 ; i < str.length() ; i++)
					{
						if (str[i] != ' ')
							return (str.substr(i, (str.length() - i)));
					}

					return "";
				}


				void	trimLeftSpaces()
				{
					_value = (trimLeftSpaces(_value));
				}




				static std::string	trimRightSpaces(std::string str)
				{
					for (int i = (str.length() - 1) ; i >= 0 ; i--)
					{
						if (str[i] != ' ')
							return (str.substr(0, (i + 1)));
					}

					return "";
				}


				void	trimRightSpaces()
				{
					_value = trimRightSpaces(_value);
				}




				static std::string	trimSpaces(std::string str)
				{
					return trimLeftSpaces(trimRightSpaces((str)));
				}


				void	trimSpaces()
				{
					_value = trimSpaces(_value);
				}




				static std::string	trimStringSet(const std::string &str, const std::string &set)
				{
					size_t	start_index = 0	,	end_index = str.length();

					if (str.empty() || set.empty())
						return (str);

					while ((start_index < str.length()) &&
						(set.find(str[start_index]) != std::string::npos))
					{
						start_index++;
					}
					
					while ((end_index > start_index) &&
						(set.find(str[end_index]) != std::string::npos))
					{
						end_index--;
					}

					return (str.substr(start_index, (end_index - start_index + 1)));
				}


				void	trimStringSet(const std::string &set)
				{
					_value = trimStringSet(_value, set);
				}



				static std::string joinStringsVec(const std::vector <std::string> &str_vec, const std::string &delimiter = " ")
				{
					std::string	joined_str = "";

					for (const std::string &str : str_vec)
						joined_str += (str + delimiter); 

					return (joined_str.substr(0, (joined_str.length() - delimiter.length())));
				}


				static std::string joinStringsArr(std::string str_arr[], int len, const std::string &delimiter = " ")
				{
					std::string	joined_str = "";

					for (int i = 0 ; i < len ; i++)
						joined_str += (str_arr[i] + delimiter); 

					return (joined_str.substr(0, (joined_str.length() - delimiter.length())));
				}




				static std::string reverseWordsInString(std::string str, const std::string &delimiter = " ")
				{
					std::vector <std::string>			str_vec;
					std::vector <std::string>::iterator	iter;
					std::string									reversed_words = "";

					str_vec = splitByDelim(str, delimiter);
					iter = str_vec.end();
					
					while (iter != str_vec.begin())
					{
						--iter;
						reversed_words += *iter + delimiter;
					}

					return (reversed_words.substr(0, (reversed_words.length() - delimiter.length())));
				}


				void	reverseWordsInString(const std::string &delimiter = " ")
				{
					_value = reverseWordsInString(_value, delimiter);
				}




				static std::string replaceWord(std::string &str, std::string &replace, std::string &replace_to, const std::string &delimiter = " ", bool match_case = true)
				{
					std::vector <std::string>	str_vec = splitByDelim(str, delimiter);

					for (std::string &tmp : str_vec)
					{
						if (match_case)
						{
							if (tmp == replace)
								tmp = replace_to;
						}
						else
						{
							if (toLowerAllString(tmp) == toLowerAllString((replace)))
								tmp = replace_to;
						}
					}

					return (joinStringsVec(str_vec, delimiter));
				}


				void	replaceWord(std::string replace, std::string replace_to, const std::string &delimiter = " ", bool match_case = true)
				{
					_value = replaceWord(_value, replace, replace_to, delimiter, match_case);
				}




				static std::string removePunctuations(std::string &str)
				{
					std::string	str_after = "";

					for (int i = 0; i < str.length() ; i++)
					{
						if (!ispunct(str[i]))
							str_after += str[i];
					}
					
					return (str_after);
				}


				void	removePunctuations()
				{
					_value = removePunctuations(_value);
				}






				~StringUtils(void) {}



	private:
				std::string	_value;
	

				static std::vector <std::string>	splitMultiChrsDelim(const std::string &str, const std::string &delemiters = " \t\n\r|,;.:")
				{
					size_t							last_pos = 0;
					size_t							delim_pos = 0;
					std::string						word;
					std::vector <std::string>	splitted_v;
					
					// If delimiters contain more than one character, use the delimiter as a whole string
					while ((delim_pos = str.find(delemiters, last_pos)) != std::string::npos)
					{
						word = str.substr(last_pos, delim_pos - last_pos);
						if (!word.empty())
							splitted_v.emplace_back(word);

						last_pos = delim_pos + delemiters.length();
					}

					// Add the last part of the string after the last delimiter
					word = str.substr(last_pos);
					if (!word.empty())
						splitted_v.emplace_back(word);

					return (splitted_v);
				}


				static std::vector <std::string>	splitSingleChrDelim(const std::string &str, const std::string &delemiters = " \t\n\r|,;.:")
				{
					size_t							last_pos = 0;
					size_t							delim_pos = 0;
					std::string						word;
					std::vector <std::string>	splitted_v;
					
					// Single character delimiters (default behavior with find_first_of)
					while ((delim_pos = str.find_first_of(delemiters, last_pos)) != std::string::npos)
					{
						word = str.substr(last_pos, (delim_pos - last_pos));
						if (!word.empty())
							splitted_v.emplace_back(word);

						last_pos = delim_pos + 1;
					}
						
					// Add the last part of the string after the last delimiter
					word = str.substr(last_pos);
					if (!word.empty())
						splitted_v.emplace_back(word);

					return (splitted_v);
				}


};


#endif