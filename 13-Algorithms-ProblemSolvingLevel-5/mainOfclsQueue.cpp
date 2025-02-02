#include <iostream>

#include "DS/clsQueue.hpp"

void    EssentialTests()
{
    clsQueue <int> myQueue;

    myQueue.push(10);
    myQueue.push(20);
    myQueue.push(30);
    myQueue.push(40);
    myQueue.push(50);
    std::cout<<"Queue Before:\n";
    myQueue.Print();

    printf("My Queue Size is (%d)\n", myQueue.size());
    printf("My Queue Front is (%d)\n", myQueue.front());
    printf("My Queue Back is (%d)\n", myQueue.back());

    std::cout<<"\n\nQueue After Poping:\n";
    myQueue.pop();
    myQueue.Print();
}


void    Seven_ExtensionsTests()
{
    clsQueue <std::string> MyQueue;

    MyQueue.push("Ahmad");
    MyQueue.push("Basim");
    MyQueue.push("Chicago");
    MyQueue.push("Diab");
    MyQueue.push("Eyad");
    MyQueue.push("Fares");
    std::cout<<"Queue Before:\n";
    MyQueue.Print();

    printf("My Queue Size is (%d)\n", MyQueue.size());
    printf("My Queue Front is (%s)\n", MyQueue.front().c_str());
    printf("My Queue Back is (%s)\n", MyQueue.back().c_str());
    std::cout<<"\n\nQueue After Poping:\n";
    MyQueue.pop();
    MyQueue.Print();

    //  Extension 1
    std::cout << "\n\nItem ((2)) is :  " << MyQueue.GetItem(2) << std::endl;

    //  Extension 2
    MyQueue.Reverse();
    printf("\n\nQueue After Reversing:\n");
    MyQueue.Print();


    //  Extension 3

    MyQueue.UpdateItem(0, "(New) Fares :)");
    MyQueue.UpdateItem(2, "(New) Diab");
    printf("\n\nQueue After Updating items (0 & 2 Indecies):\n");
    MyQueue.Print();


    //  Extension 4
    MyQueue.InsertAfter(0, "Abdelrahman(Inserted)");
    MyQueue.InsertAfter(5, "Fadi(Inserted)");

    printf("\n\nQueue After Inserting items after(0 & 5 Indecies):\n");
    MyQueue.Print();


    //  Extension 5
    MyQueue.InsertAtFront("1'st Inserting");
    MyQueue.InsertAtFront("2nd Insertion");

    printf("\n\nQueue After Inserting items At Front:\n");
    MyQueue.Print();

    std::cout << "\n\nItem ((4)) is :  " << MyQueue.GetItem(4) << std::endl;

    //  Extension 6
    MyQueue.InsertAtBack("End Inserting 1");
    MyQueue.InsertAtBack("End Inserting 2");

    printf("\n\nQueue After Inserting items At End:\n");
    MyQueue.Print();
    std::cout << "\n\nItem ((10)) is :  " << MyQueue.GetItem(10) << std::endl;


    //  Extension 7
    MyQueue.Clear();

    printf("\n\nQueue After Clearing items:\n");
    MyQueue.Print();
}






int main()
{
    system("clear");


    // EssentialTests();

    Seven_ExtensionsTests();


    return 0;
}