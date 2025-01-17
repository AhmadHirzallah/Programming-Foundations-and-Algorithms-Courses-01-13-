#include "SingleLinkedList.hpp"
#include <iostream>

void    insertBeforeNodeTests();

void    insertAtEndTests();

void    deleteFirstNodeTests();

void    deleteNodeTest();





short   insertAtBeginingSingleLL(SingleLinkedList **Head, int insertData)
{
    SingleLinkedList *Node = new SingleLinkedList();
    if (!Node)
        return 1;

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
    if (!NewNode)
        return 2;

    NewNode->data = insertData;
    NewNode->next = (*aNode)->next;
    (*aNode)->next = NewNode;

    return 0;
}


short   insertBeforeNodeSingleLL(SingleLinkedList **Head, SingleLinkedList *Node, int insertData)
{
    if (!(*Head) || !(Node))
        return 1;

    SingleLinkedList *NewNode = new SingleLinkedList();
    if (!NewNode)
        return 1;

    SingleLinkedList *Current = *Head;
    SingleLinkedList *Prev = nullptr;

    NewNode->data = insertData;

    if (*Head == Node)
    {
        NewNode->next = *Head;
        *Head = NewNode;
        return 0;
    }


    while (Current)
    {
        if (Current == Node)
        {
            NewNode->next = Current;
            Prev->next = NewNode;
            return 0;
        }
        Prev = Current;
        Current = (Current)->next;            // 1 -> 2 -> 3 -> Prev ->XXX(New) --->    Current(Searched Node) -> 8 
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

    SingleLinkedList *Current = *Head;
    if (!Current)
        return 1;

    while (Current->next)       // Current->Next != NULL        // Will Reach Last Node
        Current = Current->next;

    Current->next = NewNode;

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






//      delete Specific Node Tests      ********************

    // SingleLinkedList *Head;

    // insertAtEndOfSingleLL(&Head, 1);
    // insertAtEndOfSingleLL(&Head, 2);
    // insertAtEndOfSingleLL(&Head, 3);
    // insertAtEndOfSingleLL(&Head, 4);
    // insertAtEndOfSingleLL(&Head, 5);
    // printSingleLL(Head);

    // deleteNodeInSingleLL(&Head, 5);
    // printSingleLL(Head);
    // deleteNodeInSingleLL(&Head, 2);
    // printSingleLL(Head);





//      delete First Node Tests     ************************

    // SingleLinkedList *Head;

    // insertAtEndOfSingleLL(&Head, 1);
    // insertAtEndOfSingleLL(&Head, 2);
    // insertAtEndOfSingleLL(&Head, 3);
    // insertAtEndOfSingleLL(&Head, 4);
    // insertAtEndOfSingleLL(&Head, 5);
    // insertAtEndOfSingleLL(&Head, 6);
    // printSingleLL(Head);

    // deleteFirstNode(&Head);
    // printSingleLL(Head);

    // deleteFirstNode(&Head);
    // deleteFirstNode(&Head);
    // deleteFirstNode(&Head);
    // printSingleLL(Head);






//  Delete Last Node Tests  *******************

    SingleLinkedList *Head;

    insertAtEndOfSingleLL(&Head, 1);
    insertAtEndOfSingleLL(&Head, 2);
    insertAtEndOfSingleLL(&Head, 3);
    insertAtEndOfSingleLL(&Head, 4);
    insertAtEndOfSingleLL(&Head, 5);
    insertAtEndOfSingleLL(&Head, 6);

    printSingleLL(Head);
    
    deleteLastNode(&Head);
    printSingleLL(Head);
    deleteLastNode(&Head);
    deleteLastNode(&Head);

    printSingleLL(Head);

    return 0;
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

    SingleLinkedList *Node = findNodeSingleLL(Head, 3);

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

    SingleLinkedList *Finded = findNodeSingleLL(Head, 11);
    if (!insertBeforeNodeSingleLL(&Head, Finded, 1))
        printSingleLL(Head);
    else std::cout << "\n Not Found :(\n\n";
}