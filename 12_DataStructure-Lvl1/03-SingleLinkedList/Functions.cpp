#include "SingleLinkedList.hpp"
#include <iostream>

void    insertAtBeginingAndFindAndIsExistTests(); 





short   insertAtBeginingSingleLL(SingleLinkedList **Head, int insertData)
{
    SingleLinkedList *Node = new SingleLinkedList();

    Node->data = insertData;

    if (*Head)                  // If the Linked List Not Empty ()
        Node->next = *Head;         //  Node --> Head --->
    else 
        Node->next = nullptr;

    *Head = Node;
    return 0;       //  Succeed
}


void    printSingleLL(SingleLinkedList *Head)
{
    while((Head))
    {
        std::cout << (Head)->data  << "   ";
        (Head) = (Head)->next;
    }

    std::cout <<"\n\n\n";
}


SingleLinkedList   *findNodeSingleLL(SingleLinkedList *Head, int data)
{
    if (!Head)
        return nullptr;

    while (Head)
    {
        if (Head->data == data)
            return (Head);
        Head = Head->next;
    }

    return nullptr;       // False Not Exist
}


short   isNodeExistByDataSingleLL(SingleLinkedList *Head, int data)
{
    SingleLinkedList *Node = findNodeSingleLL(Head, data);
    return ((Node == nullptr) ? 0 : 1);
    
    /*
    if (!Head)
        return 0;

    while (Head)
    {
        if (Head->data == data)
            return (1);         // True
        Head = Head->next;
    }

    return 0;       // False Not Exist
    */    
}


short   insertAfterNodeSingleLL(SingleLinkedList **aNode, int insertData)
{
    if (!(*aNode))
        return 1;

    SingleLinkedList *NewNode = new SingleLinkedList();
    if (!NewNode)
        return 2;

    NewNode->data = insertData;
    NewNode->next = (*aNode)->next;
    (*aNode)->next = NewNode;

    return 0;
}



int main()
{
    system("clear");


    // insertAtBeginingAndFindAndIsExistTests();







    //  ****************** Insert After Node Tests Are Below

    // SingleLinkedList *Head;
    // insertAtBeginingSingleLL(&Head, 1);
    // insertAtBeginingSingleLL(&Head, 2);
    // insertAtBeginingSingleLL(&Head, 5);
    // insertAtBeginingSingleLL(&Head, 10);
    // printSingleLL(Head);
    
    
    // SingleLinkedList *Finded = findNodeSingleLL(Head, 5);
    // insertAfterNodeSingleLL(&Finded , 6);
    // printSingleLL(Head);
    // insertAfterNodeSingleLL(&Finded , 7);
    // printSingleLL(Head);

    // Finded = findNodeSingleLL(Head, 6);
    // insertAfterNodeSingleLL(&Finded , 7);
    // printSingleLL(Head);


    // Finded = findNodeSingleLL(Head, 1);
    // insertAfterNodeSingleLL(&Finded , 100);
    // printSingleLL(Head);


    // Finded = findNodeSingleLL(Head, 10);
    // insertAfterNodeSingleLL(&Finded , 1111);
    // printSingleLL(Head);


    // Finded = findNodeSingleLL(Head, 22);
    // insertAfterNodeSingleLL(&Finded , 10000);
    // printSingleLL(Head);
    return 0;
}











void    insertAtBeginingAndFindAndIsExistTests()
{
    SingleLinkedList    *Node1;
    SingleLinkedList    *Node2;

    Node1 = new SingleLinkedList();
    Node2 = new SingleLinkedList();

    Node1->data = 1;
    Node2->data = 2;

    Node1->next = Node2;
    Node2->next = nullptr;


    std::cout <<"Adding Before Insert (Hard Coded):\n\n";

    printSingleLL(Node1);


    std::cout <<"Adding After Insterting Using (insertAtBeginning) [1 then 2 then 3]:\n\n";
    insertAtBeginingSingleLL(&Node1 , 1);
    insertAtBeginingSingleLL(&Node1 , 2);
    insertAtBeginingSingleLL(&Node1 , 3);

    printSingleLL(Node1);

    std::cout <<"\n\n\n";


    std::cout <<"Finding Node By Data:\n\n";
    SingleLinkedList *Head = Node1;
    SingleLinkedList *NewNode;
    if ((NewNode = findNodeSingleLL(Head, 1)))
        std::cout << "The Node is Exist and the Data : (" << NewNode->data << ")  is Found Successfully.\n";
    else
        std::cout << "The Node is'nt Exist and the Data ISNOT Found .\n";

    std::cout <<"\n\n\n";
    int x = 7;
    if ((NewNode = findNodeSingleLL(Head, x)))
        std::cout << "The Node is Exist and the Data : (" << NewNode->data << ")  is Found Successfully. :)\n";
    else
        std::cout << "The Node is'nt Exist and the Data:  (" << x << ") ISNOT Found. :( \n";

    std::cout <<"\n\n\n";

    std::cout <<"Checking if Node is Exist By Data:\n\n";
    if (isNodeExistByDataSingleLL(Head, 1))
        std::cout << "The Node is Exist.\n";
    else
        std::cout << "The Node isn't Exist.\n";


    std::cout <<"\n\n\nChecking if Node is Exist By Data:\n\n";
    if (isNodeExistByDataSingleLL(Head, x))
        std::cout << "The Node is Exist and Found Successfully. :)\n";
    else
        std::cout << "The Node isn't Exist. :(\n";

    std::cout <<"\n\n\n";

    insertAtBeginingSingleLL(&Head, 7);
    std::cout <<"\n\n\nChecking if Node is Exist By Data after inserting 7:\n\n";
    if (isNodeExistByDataSingleLL(Head, x))
        std::cout << "The Node is Exist and Found Successfully. :)\n";
    else
        std::cout << "The Node isn't Exist and ISNOT Found. :(\n";
}