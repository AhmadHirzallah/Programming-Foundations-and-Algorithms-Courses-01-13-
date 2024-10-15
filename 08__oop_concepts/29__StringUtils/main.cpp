#include <iostream>
#include "StringUtils.hpp"




int main(void)
{
 std::string test_str = "Hello World";
    
    std::cout << "Original String: " << test_str << std::endl;

    std::cout << "Length: " << StringUtils::getLength(test_str) << std::endl;

    std::cout << "Uppercase String: " << StringUtils::toUpperAllString(test_str) << std::endl;

    std::cout << "Lowercase String: " << StringUtils::toLowerAllString(test_str) << std::endl;

    std::cout << "Word Count: " << StringUtils::calculateWordsNbr(test_str) << std::endl;

    std::cout << "Count Words with Delim: " << StringUtils::countWordsWithDelim(test_str, " ") << std::endl;

    std::cout << "Invert Case: " << StringUtils::invertAllLettersCases(test_str) << std::endl;

    std::cout << "Count Capital Letters: " << StringUtils::countLetters(test_str, StringUtils::CAPITALS) << std::endl;

    std::cout << "Count Small Letters: " << StringUtils::countLetters(test_str, StringUtils::SMALLS) << std::endl;

    // Test instance methods
    StringUtils strObj("  Hello World ahmad omar ibrahim HIRZALLAH Is good");


    std::cout << "Instance String: " << strObj << std::endl;

    strObj.toUpperAllString();
    std::cout << "Instance Uppercase: " << strObj << std::endl;

    strObj.toLowerAllString();
    std::cout << "Instance Lowercase: " << strObj<< std::endl;

    strObj.upperFirstLetterOfEachWord();
    std::cout << "Uppercase First Letter: " << strObj << std::endl;

    strObj.trimSpaces();
    std::cout << "Trimmed Spaces: " << strObj << std::endl;















	// StringUtils myString("Hello World!");

	// std::vector <std::string>	words = {"This", "is", "a", "test"};
	// myString.setValue(StringUtils::joinStringsVec(words, "-"));
	// std::cout << "After joining strings with '-': " << myString << std::endl;

	// int wordsCount = myString.calculateWordsNbr();
    // std::cout << "Number of words: " << wordsCount << std::endl;

	// std::string trimmed = StringUtils::trimSpaces("   Test String   ");

    // std::cout << "Trimmed string: [" << trimmed << "]" << std::endl;

	// std::string upperCase = StringUtils::toUpperAllString("hello");
	// std::cout << "Uppercase: " << upperCase << std::endl;







	// StringUtils myString("Hello World!");

    // // Test non-static methods
    // std::cout << "Initial value: " << myString.getValue() << std::endl;

    // // Replace word
    // myString.replaceWord("Hello", "Hi");
    // std::cout << "After replacing 'Hello' with 'Hi':\t\t" << myString.getValue() << std::endl;














	// StringUtils	MyString("This is a test string.");
	// int words_count = MyString.calculateWordsNbr();
	// std::cout << words_count << std::endl;
	// MyString = "Ahmad Omar";
	// words_count = MyString.calculateWordsNbr();
	// std::cout << words_count << std::endl;

	// int words_count;
	// std::string testStr = "Another,test;string with|different,delimiters!Ahmad";
    // words_count = StringUtils::calculateWordsNbr(testStr, ",;|!");
    // std::cout << "Static method test, word count: " << words_count << std::endl;
	


 	// StringUtils testStr("Hello World!");
    
    // // Output the original string
    // std::cout << "Original String: " << testStr << std::endl;
    // std::string inverted = StringUtils::invertAllLettersCases(testStr.getValue());
    // std::cout << "Original: " << testStr.getValue() << std::endl;
    // std::cout << "Inverted cases: " << inverted << std::endl;
	return (0);
}