#include <iostream>

//  Template Functions make we write less code ;
//  We use it when many datatypes of a function with a specific functionllity like : getMax() 
//      So We Create only function without overloading(int, double ,char , string ,, etc) with variable data type will be variable 
//          Called Template Functions.


template <typename T> T getMax(T Var1, T Var2)      //  These types will vary between Integers and Characters and DOUBLES , ETC//
{                                                   //  THIS DEPEND ON THE  USE OF MAIN HOW YOU DEFINED THE TEMPLATE IN THE MAIN
    return (Var1 > Var2) ? Var1 : Var2;
}

int main()
{
    std::cout << getMax<int>(3,7) << std::endl;
    std::cout << getMax<double>(3883.1354,  18534943.123) << std::endl;
    std::cout << getMax<char>('a', 'b') << std::endl; 
    std::cout << getMax<char>('a', 'B') << std::endl; 

    return 0;
}