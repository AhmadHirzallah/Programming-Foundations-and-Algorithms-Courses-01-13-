#include <iostream>
#include <stack>        //  Stack is part of STL : Standard Template Library

int main()
{
    system("clear");

    std::stack <int> stkNumbers;

    stkNumbers.push(10);
    stkNumbers.push(20);
    stkNumbers.push(30);
    stkNumbers.push(40);
    stkNumbers.push(50);

    std::cout << "\nSize of (Count) the Stack of Numbers is:  " << stkNumbers.size() << std::endl << std::endl;

    while (!(stkNumbers.empty()))
    {
        std::cout << stkNumbers.top() << "\n" << std::endl;
        stkNumbers.pop();       // 50 40 30 20 10
    }



    std::cout << "\n\n------------\n\n Swapping ! :" << std::endl;

    std::stack  <float> S1;
    std::stack  <float> S2;

    S1.push(10.1);
    S1.push(20.2);
    S1.push(30.3);
    S1.push(40.4);
    S1.push(50.5);
    std::cout << std::endl << "Stack (1) Size Before:   " << S1.size();     //  5 


    S2.push(60.6);
    S2.push(70.7);
    S2.push(80.8);
    S2.push(90.9);
    S2.push(100.111);
    S2.push(100.112);
    std::cout << std::endl << "Stack (2) Size Before:   " << S2.size();     //  6


    S1.swap(S2);


    std::cout << std::endl << std::endl << "Stack (1) Size After:   " << S1.size();
    std::cout << std::endl << "Stack (1) After:   " ;
    while (!(S1.empty()))
    {
        std::cout << S1.top() << "   ";
        S1.pop();
    }

    std::cout << std::endl << std::endl << "Stack (2) Size After:   " << S2.size();
    std::cout << std::endl << "Stack (2) After:   " ;
    while (!(S2.empty()))
    {
        std::cout << S2.top() << "   ";
        S2.pop();
    }
    std::cout << "\n\n------------\n\n";

    return 0;
}