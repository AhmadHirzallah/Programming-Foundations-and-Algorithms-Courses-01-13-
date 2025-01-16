#include <iostream>
#include "DoubleLinkedList.hpp"


short   insertAtBegining(DoubleLinkedList **Head, int value)
{
    DoubleLinkedList    *New;

    New = new DoubleLinkedList();
    if (!New)
        return 1;

    (New)->prev = nullptr;
    (New)->value = value;


    if (!(*Head))
        (New)->next = nullptr;
    else
        (New)->next = (*Head);

    *Head = New;
    return 0;
}


void    printNodeDetails(DoubleLinkedList *Node)
{
    if (Node->prev)
        std::cout << Node->prev->value;
    else
        std::cout << "NULL";

    std::cout << "  <-->  " << (Node->value) << "  <-->  ";

    if (Node->next)
        std::cout << Node->next->value << "\n";
    else
        std::cout << "NULL\n";
}


void    printListDetails(DoubleLinkedList *Head)
{
    std::cout << "\n\n";
    std::cout << "Printing List (Details):\n\n";

    while (Head)
    {
        printNodeDetails(Head);
        Head = Head->next;
    }

    std::cout << "\n\n";
}


void    printList(DoubleLinkedList *Head)
{
    std::cout << "\n\n";
    std::cout << "Printing List:\n\n";

    if (!Head->prev)
        std::cout << "NULL";
        
    while (Head)
    {
        std::cout << "  <-->  "<< (Head)->value ;
        Head = Head->next;
    }
    if (Head == nullptr)
        std::cout << "  <-->  "<< "NULL";

    std::cout << "\n\n";
}


int main()
{
    system("clear");

    DoubleLinkedList    *Current;

    insertAtBegining(&Current, 3);
    insertAtBegining(&Current, 2);
    insertAtBegining(&Current, 1);

    // while (Current)
    // {
    //     std::cout << (Current)->value << "    ";
    //     Current = (Current)->next;
    // }
    printList(Current);
    printListDetails(Current);

    return (0);   
}