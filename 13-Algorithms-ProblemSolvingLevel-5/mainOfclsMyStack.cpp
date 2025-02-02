#include <iostream>

#include "DS/clsMyStack.hpp"

void    EssentialTests()
{
    clsMyStack <int> myStack;

    myStack.push(10);
    myStack.push(20);
    myStack.push(30);
    myStack.push(40);
    myStack.push(50);
    std::cout<<"Stack Before:\n";
    myStack.Print();

    printf("My Stack Size is (%d)\n", myStack.size());
    printf("My Stack Front is (%d)\n", myStack.top());
    printf("My Stack Back is (%d)\n", myStack.bottom());

    std::cout<<"\n\nStack After Poping:\n";
    myStack.pop();
    myStack.Print();
}


void    ExtensionsTests()
{
    clsMyStack <int> MyStack;

    MyStack.push(1);
    MyStack.push(2);
    MyStack.push(3);
    MyStack.push(4);
    MyStack.push(5);
    MyStack.push(6);
    std::cout<<"Stack Before:\n";
    MyStack.Print();

    printf("My Stack Size is (%d)\n", MyStack.size());
    printf("My Stack top is (%i)\n", MyStack.top());
    printf("My Stack bottom is (%i)\n", MyStack.bottom());


    std::cout<<"\n\nStack After Poping:\n";
    MyStack.pop();
    MyStack.Print();


    //  Extension 1
    std::cout << "\n\nItem ((2)) is :  " << MyStack.GetItem(2) << std::endl;
    std::cout << "\n\nItem ((4)) is :  " << MyStack.GetItem(4) << std::endl;


    //  Extension 2
    MyStack.Reverse();
    printf("\n\nStack After Reversing:\n");
    MyStack.Print();


    //  Extension 3

    MyStack.UpdateItem(0, 11);
    MyStack.UpdateItem(2, 33);
    printf("\n\nStack After Updating items (0 & 2 Indecies):\n");
    MyStack.Print();


    //  Extension 4
    MyStack.InsertAfter(0, 111);
    MyStack.InsertAfter(5, 222);

    printf("\n\nStack After Inserting items after(0 & 5 Indecies):\n");
    MyStack.Print();


    //  Extension 5
    MyStack.InsertAtFront(101);
    MyStack.InsertAtTop(202);

    printf("\n\nStack After Inserting items At Front (Called Top of Stack Also):\n");
    MyStack.Print();

    std::cout << "\n\nItem ((4)) is :  " << MyStack.GetItem(4) << std::endl;

    //  Extension 6
    MyStack.InsertAtBack(808);
    MyStack.InsertAtBottom(909);

    printf("\n\nStack After Inserting items At End (Back ; Called Bottom Also):\n");
    MyStack.Print();


    std::cout << "\n\nItem ((10)) is :  " << MyStack.GetItem(10) << std::endl;


    //  Extension 7
    MyStack.Clear();

    printf("\n\nStack After Clearing items:\n");
    MyStack.Print();
}


int main()
{
    system("clear");


    // EssentialTests();

    ExtensionsTests();


    return 0;
}