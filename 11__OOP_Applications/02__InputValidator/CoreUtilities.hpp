#pragma once

#ifndef	COREUTILITIES_HPP
# define	COREUTILITIES_HPP



# include "iostream"
# include "string"
# include "DateUtils.hpp"
# include "cstdlib"
# include "ctime"
# include "array"

class	CoreUtilities
{
	public:

			enum	e_char_type
			{
				SMALL = 1,
				CAPITAL,
				DIGIT = 3,
				MIX,
				SPECIAL_CHRS = 5
			};





			template <typename... Args>
			// Public method to print multiple arguments with delimiters
			static void	printWithDelimiter(const std::string& delimiter = "[]", const Args&...  args)
			{
					print_Var(delimiter, args...);
			}


			template <typename... Args>
			static auto	sum_Var(const Args&... args) -> decltype((args + ...))
			{
				return (args + ...);  // Fold expression (C++17)
			}




			// Variadic function to check if all arguments are true
			template <typename... Args>
			static bool	allTrue_Var(const Args&... args)
			{
				return (... && args);  // Fold expression for "and"
			}


			// Variadic function to check if any argument is true
			template <typename... Args>
			static bool	anyTrue_Var(const Args&... args)
			{
				return (... || args);  // Fold expression for "or"
			}





			// Variadic function to find the minimum value
			template <typename T, typename... Args>
			static T min_Var(const T& first, const Args&... args) {
				return (args == ... == first) ? first : (std::min)(first, min_Var(args...));
			}


			// Variadic function to find the maximum value
			template <typename T, typename... Args>
			static T max_Var(const T& first, const Args&... args) {
				return (args == ... == first) ? first : (std::max)(first, max_Var(args...));
			}






			static void	sRand()
			{
				srand((unsigned) time(nullptr));
			}



			static int	generateRandomNbr(int from, int to)
			{
				return (rand() % (to - from + 1) + from); 
			}



			static char	generateRandomChr(e_char_type chr_type)
			{
				
				//Capital/Smalll/Digits only (SMALL 1 to DIGIT 3)
				if (chr_type == e_char_type::MIX)
					chr_type = static_cast <e_char_type>(generateRandomNbr(SMALL, DIGIT));

				switch (chr_type)
				{
					case e_char_type::SMALL:
						return (static_cast <char>(generateRandomNbr('a', 'z')));
					case e_char_type::CAPITAL:
						return (static_cast <char>(generateRandomNbr('A', 'Z')));
					case e_char_type::DIGIT :
						return (static_cast <char>(generateRandomNbr('0', '9')));
					case e_char_type::SPECIAL_CHRS:
						return (static_cast <char>(generateRandomNbr(33, 47)));
					default:
						return ('\0');
				}
			}



			static std::string	generateWord(e_char_type chr_type, short word_len)
			{
				std::string	word = "";

				for (int i = 0;	i < word_len;	i++)
					word += generateRandomChr(chr_type);

				return (word);
			}



			static std::string	generateKey(e_char_type chr_type = CAPITAL)
			{
				std::string	key;

				for (int i = 1; i <= 4 ; i++)
					key += generateWord(chr_type, 4) + "-";

				key.pop_back();

				return (key);
			}



			static void	generate_X_Keys(int	keys_nbr, e_char_type chr_type)
			{
				for (int i = 1 ;	i <= keys_nbr;	i++)
					std::cout << "Key[" << i << "]: " << generateKey(chr_type) << Tabs(2);
			}





			static void	fillArrayWithRandomWords(std::string words_arr[100], int arr_len, e_char_type chr_type, short word_len)
			{
				for (int i = 0;	i < arr_len;	i++)
					words_arr[i] = generateWord(chr_type, word_len);
			}


			static void	fillArrayWithRandomWords(std::array <std::string ,100>& words_arr , e_char_type chr_type, short word_len)
			{
				for (auto &word : words_arr)
					word = generateWord(chr_type, word_len);
			}






			static void	fillArrayWithRandomKeys(std::string words_arr[100], int arr_len, e_char_type chr_type)
			{
				for (int i = 0;	i < arr_len;	i++)
					words_arr[i] = generateKey(chr_type);
			}


			static void	fillArrayWithRandomKeys(std::array<std::string, 100>& keys_arr, e_char_type chr_type)
			{
					for (auto& key : keys_arr)
						key = generateKey(chr_type);
			}



			



			static void Swap(int& a, int& b)
			{
				int temp;

				temp = a;
				a = b;
				b = temp;
			}

			static void Swap(double& a, double& b)
			{
				double temp;

				temp = a;
				a = b;
				b = temp;
			}

			static void Swap(bool& a, bool& b)
			{
				bool temp;

				temp = a;
				a = b;
				b = temp;
			}

			static void Swap(char& a, char& b)
			{
				char temp;

				temp = a;
				a = b;
				b = temp;
			}

			static void Swap(std::string& a, std::string& b)
			{
				std::string temp;

				temp = a;
				a = b;
				b = temp;
			}



			static void	Swap(DateUtils Date1, DateUtils Date2)
			{
				DateUtils::swapDates(Date1, Date2);
			}



			static std::string	Tabs(short number_of_tabs)
			{
				std::string t = "";

				for (int i = 1; i <= number_of_tabs; i++)
					t = t + "\t";

				return (t);
			}



			static std::string	encryptText(std::string text, short encryption_key)
			{
				for (int i = 0; i < text.length(); i++)
					text[i] = char((int)text[i] + encryption_key);
					
				return (text);
			}



			static std::string	decryptText(std::string text, short encryption_key)
			{
				return (encryptText(text, -encryption_key));
			}



			// 	WE CREATED BETTER VARIADIC FUNCTION
			// static void	printWithDelimiter(int output, std::string delimiter)
			// {
			// 	std::cout << delimiter[0] << output << delimiter[1] << Tabs(3) << std::endl;
			// }




			void	getArrayShuffled(int my_array[100], int len)
			{
				for (int i = 0; i < len; i++)
					Swap(my_array[i], my_array[(generateRandomNbr(0,  len - 1))]);
			
			}


	private:
				

			template <typename T>
			// Helper function to print a single argument with a delimiter
			static void printSingle(const T& output, const std::string& delimiter)
			{
				std::cout << delimiter[0] << output << delimiter[1] << std::endl;
			}





			// Base case for the variadic template recursion
			static void print_Var(const std::string& delimiter)
			{
				// Base case: do nothing, end recursion
			}

			template <typename T, typename... Args>
			// Variadic function template to print multiple arguments
			static void	print_Var(const std::string& delimiter, const T& first, const Args&... rest)
			{
				// Print the first argument
				printSingle(first, delimiter);

				// Recursively call the function with the remaining arguments
				print_Var(delimiter, rest...);
			}




			// Base case for maxVariadic
			static int max_Var(const int& last)
			{
				return (last);
			}

			// Base case for maxVariadic for other types (generic)
			template <typename T>
			static T max_Var(const T& last)
			{
				return (last);
			}




			// Base case for minVariadic
			static int min_Var(const int& last)
			{
				return (last);
			}

			// Base case for minVariadic for other types (generic)
			template <typename T>
			static T min_Var(const T& last)
			{
				return (last);
			}

};

#endif