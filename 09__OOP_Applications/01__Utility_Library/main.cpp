#include "CoreUtilities.hpp"
#include "StringUtils.hpp"

int main() 
{

		int minResult = CoreUtilities::min_Var(10, 2222, -1, 30);
		double maxResult = CoreUtilities::max_Var(3.14, 2333.71, 199.618, 4.5);
		
		std::cout << "Minimum value: " << minResult << std::endl;
		std::cout << "Maximum value: " << maxResult << std::endl;








		bool all = CoreUtilities::allTrue_Var(true, true, false);  // Should return false
		bool any = CoreUtilities::anyTrue_Var(false, false, true); // Should return true
		
		std::cout << "All true: " << all << std::endl;
		std::cout << "Any true: " << any << std::endl;







		// int result = CoreUtilities::sum_Var(1, 2, 3, 4, 5);              // Sums integers
		// double floatResult = CoreUtilities::sum_Var(1.5, 2.0, 3.7);      // Sums floating-point numbers
		// auto mixedResult = CoreUtilities::sum_Var(1, 2.5, 3, 4.0);       // Works with mixed types
		
		// std::cout << "Sum of integers: " << result << std::endl;
		// std::cout << "Sum of floating-point numbers: " << floatResult << std::endl;
		// std::cout << "Sum of mixed types: " << mixedResult << std::endl;








			CoreUtilities::sRand(); // Initialize random seed

			CoreUtilities::printWithDelimiter("{}", 42, "Hello", 3.14, 'A');

			// Test for generateRandomNbr
			std::cout << "Random number between 10 and 20: " 
					<< CoreUtilities::generateRandomNbr(10, 12) << std::endl;

			// Test for generateRandomChr
			std::cout << "Random small character: " 
					<< CoreUtilities::generateRandomChr(CoreUtilities::SMALL) << std::endl;
			std::cout << "Random capital character: " 
					<< CoreUtilities::generateRandomChr(CoreUtilities::CAPITAL) << std::endl;
			std::cout << "Random digit character: " 
					<< CoreUtilities::generateRandomChr(CoreUtilities::DIGIT) << std::endl;
			std::cout << "Random mixed character: " 
					<< CoreUtilities::generateRandomChr(CoreUtilities::MIX) << std::endl;

			// Test for generateWord
			std::cout << "Random word (small letters, length 5): " 
					<< CoreUtilities::generateWord(CoreUtilities::SMALL, 5) << std::endl;

			// Test for generateKey
			std::cout << "Generated key: " 
					<< CoreUtilities::generateKey(CoreUtilities::CAPITAL) << std::endl;

			// Test for generate_X_Keys
			CoreUtilities::generate_X_Keys(4, CoreUtilities::e_char_type::SPECIAL_CHRS);
			std::cout << std::endl;
			
			CoreUtilities::generate_X_Keys(4, CoreUtilities::e_char_type::MIX);
			std::cout << std::endl;

			CoreUtilities::generate_X_Keys(4, CoreUtilities::e_char_type::DIGIT);
			std::cout << std::endl;

			// Test for fillArrayWithRandomWords
			std::string words[100];
			CoreUtilities::fillArrayWithRandomWords(words, 5, CoreUtilities::SMALL, 4);
			std::cout << "Filled array with random words: ";
			for (int i = 0; i < 5; i++)
				std::cout << words[i] << " ";
			std::cout << std::endl;

			// Test for Swap functions
			int a = 5, b = 10;
			CoreUtilities::Swap(a, b);
			std::cout << "Swapped integers: " << a << " " << b << std::endl;

			double x = 1.23, y = 4.56;
			CoreUtilities::Swap(x, y);
			std::cout << "Swapped doubles: " << x << " " << y << std::endl;

			// Test for Tabs
			std::cout << "Tab string with 3 tabs: \"" 
					<< CoreUtilities::Tabs(3) << "Test\"" << std::endl;

			// Test for encryptText and decryptText
			std::string text = "hello";
			std::string encrypted = CoreUtilities::encryptText(text, 3);
			std::string decrypted = CoreUtilities::decryptText(encrypted, 3);
			std::cout << "Original text: " << text << ", Encrypted: " 
					<< encrypted << ", Decrypted: " << decrypted << std::endl;










		// CoreUtilities::sRand(); // Initialize random seed

		// // Test each case for generateRandomChr
		// std::cout << "Random small character: " 
		// 		<< CoreUtilities::generateRandomChr(CoreUtilities::SMALL) << std::endl;
		
		// std::cout << "Random capital character: " 
		// 		<< CoreUtilities::generateRandomChr(CoreUtilities::CAPITAL) << std::endl;
		
		// std::cout << "Random digit character: " 
		// 		<< CoreUtilities::generateRandomChr(CoreUtilities::DIGIT) << std::endl;
		
		// std::cout << "Random special character: " 
		// 		<< CoreUtilities::generateRandomChr(CoreUtilities::SPECIAL_CHRS) << std::endl;
		
		// std::cout << "Random mixed character (small, capital, or digit): " 
		// 		<< CoreUtilities::generateRandomChr(CoreUtilities::MIX) << std::endl;

		// // Edge case: Passing undefined enum value (just for testing, e.g., `10` as invalid enum value)
		// std::cout << "Random undefined character (should return \\0): '" 
		// 		<< CoreUtilities::generateRandomChr(static_cast<CoreUtilities::e_char_type>(10)) << "'" << std::endl;




		// // Create an array of 100 std::string elements
		// std::array<std::string, 100> myWords;

		// // Fill the array with random words
		// CoreUtilities::fillArrayWithRandomWords(myWords, CoreUtilities::CAPITAL, 5);

		// // Output the words (for demonstration purposes)
		// for (const auto& word : myWords)
		// {
		// 	std::cout << word << " ";
		// }


    return 0;
}