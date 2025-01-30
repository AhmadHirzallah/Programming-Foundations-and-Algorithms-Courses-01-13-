#include <iostream>

//  unions has many benifits and also are DANGEROUS; (You should be carefull when using union to avoid the errors from appearing)
//  unions are user defined datatype (like structs and enums) ;;    And as we said before all the datatypes(also primitive like int , array , struct, union) are considered a datastructures.
//  The Main reason of union is to save memory.
//  When you define 3 Datatypes inside union; All will share/have the same memory space. ; so not like struct that will have 3 different memory spaces and location; we will have 1 and 1 < 3 so we save memory.
//  Union space of memory will be for the Largest (Member) Data Type between int , float , class , ... etc

union U_MyUnion
{
    int     intValue;
    float   floatVal;           ///////////// These 3 as 3 people share same room; The size will be the biggest datatype space size float>int>char --> float
    char    charVal;
};

//  Using of union wrong (be carefull of datatypes and assigned values) ; this can lead to undefined behaviour if not used properly
//  When one of the union is accessed; you should be carefull about which union's member was last assigned a value.

int main()
{
    system("clear");

    U_MyUnion   UnionOfTypes;
    
    UnionOfTypes.intValue = 65;
    std::cout << "Interger Value:  " << UnionOfTypes.intValue << std::endl;
    std::cout << "Character Value:  " << UnionOfTypes.charVal << "\n\n\n";

    UnionOfTypes.floatVal = 3.14f;
    std::cout << "Float Value:  " << UnionOfTypes.floatVal << std::endl << "\n\n";
    
    UnionOfTypes.charVal = 'Z';
    std::cout << "Character Value:  " << UnionOfTypes.charVal << std::endl;
    std::cout << "Interger Value:  " << UnionOfTypes.intValue << std::endl << "\n\n";
    
    UnionOfTypes.intValue = 90;
    std::cout << "Interger Value:  " << UnionOfTypes.intValue << std::endl;
    std::cout << "Character Value:  " << UnionOfTypes.charVal << "\n\n\n";

    return 0;
}