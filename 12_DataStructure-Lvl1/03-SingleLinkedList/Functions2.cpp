#include "SingleLinkedList.hpp"
#include <iostream>

void    insertBeforeNodeTests();

void    insertAtEndTests();

void    deleteFirstNodeTests();

void    deleteNodeTest();





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


SingleLinkedList   *findNodeByDataSingleLL(SingleLinkedList *Head, int data)
{
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
    while (Head)
    {
        if (Head->data == data)
            return (1);         // True
        Head = Head->next;
    }

    return 0;       // False Not Exist
    
}


short   insertAfterNodeSingleLL(SingleLinkedList **aNode, int insertData)
{
    if (!(*aNode))
        return 1;

    SingleLinkedList *NewNode = new SingleLinkedList();

    NewNode->data = insertData;
    NewNode->next = (*aNode)->next;
    (*aNode)->next = NewNode;

    return 0;
}


short   insertBeforeNodeSingleLL(SingleLinkedList **Head, SingleLinkedList *Node, int insertData)
{
    if (!(*Head))
        return 1;

    SingleLinkedList *Tmp = *Head;
    SingleLinkedList *Prev = nullptr;
    SingleLinkedList *NewNode = new SingleLinkedList();

    NewNode->data = insertData;

    if (*Head == Node)
    {
        NewNode->next = *Head;
        *Head = NewNode;
        return 0;
    }


    while (Tmp)
    {
        if (Tmp == Node)
        {
            NewNode->next = Tmp;
            Prev->next = NewNode;
            return 0;
        }
        Prev = Tmp;
        Tmp = (Tmp)->next;            // 1 -> 2 -> 3 -> Prev ->XXX(New) --->    Tmp(Searched Node) -> 8 
    }

    return 1;
}


short   insertAtEndOfSingleLL(SingleLinkedList **Head, int to_insert)
{
    SingleLinkedList *NewNode = new SingleLinkedList();

    NewNode->data = to_insert;
    NewNode->next = nullptr;

    if (!(*Head))       //*Head == NULL --> Enter
    {
            *Head = NewNode;
            return 0;
    }

    SingleLinkedList *TmpNode = *Head;

    while (TmpNode->next)       // TmpNode->Next != NULL        // Will Reach Last Node
        TmpNode = TmpNode->next;

    TmpNode->next = NewNode;

    return 0;
}


short   deleteNodeInSingleLL(SingleLinkedList **Head , int to_delete)
{
    SingleLinkedList *Previous = *Head;
    SingleLinkedList *Current = *Head;

    if (*Head == nullptr)
        return 1;

    if (to_delete == (*Head)->data)
    {
        *Head = (*Head)->next;
        delete(Current);
        return 0;
    }   

    while ((Current) && (to_delete != (Current->data)))
    {
        Previous = Current;
        Current = Current->next;
    }

    if (!Current)
        return 1;
    else if (to_delete == Current->data)
    {
        Previous->next = Current->next;
        delete(Current);
    }
    return 0;
}


short   deleteFirstNode(SingleLinkedList **Head)
{
    if (!(*Head))
        return 1;

    SingleLinkedList    *Current;

    Current = *Head;
    *Head = Current->next;
    delete(Current);

    return 0;
}


short   deleteLastNode(SingleLinkedList **Head)
{
    if (!(*Head))
        return 1;

    SingleLinkedList    *Current,  *Previous;
    Current = *Head;
    Previous = nullptr;

    if (!(*Head)->next)     // Head is last Node and after it is nullptr
    {
        delete(*Head);
        *Head = nullptr;
        return 0;
    }
    
    while (Current->next)
    {
        Previous = Current;
        Current = Current->next;
    }

    if (Previous && Current)
    {
        Previous->next = nullptr;
        delete(Current);
    }

    return 0;
}

int main()
{
    system("clear");
    // insertBeforeNodeTests();
    // insertAtEndTests();
    // deleteNodeTest();
    // deleteFirstNodeTests();

    SingleLinkedList *Head;

    insertAtEndOfSingleLL(&Head, 1);
    insertAtEndOfSingleLL(&Head, 2);
    insertAtEndOfSingleLL(&Head, 3);
    insertAtEndOfSingleLL(&Head, 4);
    insertAtEndOfSingleLL(&Head, 5);
    insertAtEndOfSingleLL(&Head, 6);
    printSingleLL(Head);
    
    deleteLastNode(&Head);
    deleteLastNode(&Head);
    deleteLastNode(&Head);


    
    printSingleLL(Head);

    return 0;
}

void    deleteFirstNodeTests()
{
     SingleLinkedList *Head;

    insertAtEndOfSingleLL(&Head, 1);
    insertAtEndOfSingleLL(&Head, 2);
    insertAtEndOfSingleLL(&Head, 3);
    insertAtEndOfSingleLL(&Head, 4);
    insertAtEndOfSingleLL(&Head, 5);
    insertAtEndOfSingleLL(&Head, 6);
    printSingleLL(Head);

    deleteFirstNode(&Head);
    deleteFirstNode(&Head);
    deleteFirstNode(&Head);
    deleteFirstNode(&Head);
    printSingleLL(Head);
}



void    deleteNodeTest()
{
    SingleLinkedList *Head;

    insertAtEndOfSingleLL(&Head, 1);
    insertAtEndOfSingleLL(&Head, 2);
    insertAtEndOfSingleLL(&Head, 3);
    insertAtEndOfSingleLL(&Head, 4);
    insertAtEndOfSingleLL(&Head, 5);
    printSingleLL(Head);

    deleteNodeInSingleLL(&Head, 6);
    printSingleLL(Head);

}


void    insertAtEndTests()
{
    SingleLinkedList *Head = nullptr;

    insertAtEndOfSingleLL(&Head , 1);
    printSingleLL(Head);
    insertAtEndOfSingleLL(&Head , 2);
    insertAtEndOfSingleLL(&Head , 3);
    insertAtEndOfSingleLL(&Head , 4);
    insertAtEndOfSingleLL(&Head , 5);
    insertAtBeginingSingleLL(&Head, 0);
    printSingleLL(Head);

    SingleLinkedList *Node = findNodeByDataSingleLL(Head, 3);

    insertAfterNodeSingleLL(&Node, 33);
    insertBeforeNodeSingleLL(&Head, Node, 33);
    printSingleLL(Head);
}


void    insertBeforeNodeTests()
{
    SingleLinkedList *Head;
    insertAtBeginingSingleLL(&Head, 10);
    insertAtBeginingSingleLL(&Head, 11);
    insertAtBeginingSingleLL(&Head, 12);

    printSingleLL(Head);

    SingleLinkedList *Finded = findNodeByDataSingleLL(Head, 11);
    if (!insertBeforeNodeSingleLL(&Head, Finded, 1))
        printSingleLL(Head);
    else std::cout << "\n Not Found :(\n\n";
}