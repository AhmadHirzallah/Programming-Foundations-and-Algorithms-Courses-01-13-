#include <iostream>
#include <map>


//  Maps Can be said to be an Associative Array
//  Depends on : 1.Key (Not Index; Can't be repeated; repetition will override) With 2.Value
//  C# , Python : The Map is Called : Dictionary.

//  in c++ ; std::map is a container in the STL (Standard Template Library) that represents an (Associative Arry)
//  It is a Sorted Assciative Container that contains (key-value) pairs ; where each key must be unique
//  Elements are sorted based on the keys!  Which are sorted in ascending order by default & this sorting allows for efficient search, insert , delete of elements
//  

int main()
{
    system("clear");

    // std::map    <std::string , int>     StudentsGradesMap;

                // (Key) Type is (String),   (Value:int)
    std::map    <std::string             ,    int>              StudentsGradesMap;
    
    StudentsGradesMap["Ahmad"] = 100;
    StudentsGradesMap["Yousuf Omar"] = 89;
    StudentsGradesMap["Ali"] = 97;
    StudentsGradesMap["Mahmoud"] = 77;
    StudentsGradesMap["Yousef Khalil"] = 55;

    for (const auto &pair : StudentsGradesMap)
    {                               // key                              //value
        std::cout << "Student:  " << pair.first << "   --> Grade:  " << pair.second  << std::endl;
    }    


    std::cout << "\n\n---------------------\n\nUsing .find Method of (Maps/Dictionaries):\n\n";

    std::string SeachFor = "Ahmad";

    // if (StudentsGradesMap.find("Ahmad") != StudentsGradesMap.end())
    if (StudentsGradesMap.find(SeachFor) != StudentsGradesMap.end())
        std::cout << SeachFor  << "'s Grade is:  " << StudentsGradesMap[SeachFor] << "\n\n";
    else
        std::cout << "Grade isn't found for:  " << SeachFor << "\n\n";


    SeachFor = "Mohammad";
    if (StudentsGradesMap.find(SeachFor) != StudentsGradesMap.end())
        std::cout << SeachFor  << "'s Grade is:  " << StudentsGradesMap[SeachFor] << "\n\n";
    else
        std::cout << "Grade isn't found for:  " << SeachFor << "\n\n";


    return 0;

    //          Even if you do std::map <int , std::string> myMap; 
    //              Which is same as array ! But you take advantage of sorting algorithm for searching and doing operation will be more efficient.
     
}