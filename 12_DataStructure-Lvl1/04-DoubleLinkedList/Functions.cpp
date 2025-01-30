#include <iostream>
#include "DoubleLinkedList.hpp"


short   insertAtBegining(DoubleLinkedList **Head, int value)
{
    DoubleLinkedList    *New;

    New = new DoubleLinkedList();
    if (!New)
        return 1;

    (New)->value = value;
    (New)->prev = nullptr;

    if (!(*Head))
        (New)->next = nullptr;
    else
    {
        (New)->next = (*Head);
        (*Head)->prev = New;
    }

    *Head = New;
    return 0;
}


void    printNodeDetails(DoubleLinkedList *Node)
{
    if (!Node)
    {
        std::cout << "NULL";
        return ;
    }

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

    if (!Head)
    {
        std::cout << "(NULL)\n(NO DATA // LINKED LIST IS EMPTY).\n\n";
        return ;
    }
        
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

    if (!Head)
    {
        std::cout << "(NO DATA // LINKED LIST IS EMPTY).\n\n";
        return ;
    }

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


DoubleLinkedList    *FindNodeDoubleLL(DoubleLinkedList **Head, int val)
{
    if (!(*Head))
        return nullptr;

    DoubleLinkedList    *Current;
    Current = *Head;

    while ((Current))
    {
        if (((Current)->value) == val)
            return (Current);
        
        Current = Current->next;
    }
    
    return nullptr;
}


short   isNodeExist(DoubleLinkedList **Head, int val)
{
    DoubleLinkedList    *Node = FindNodeDoubleLL(Head, val);
    return ((Node) ? 1 : 0); 
}


short   insertAfterNodeDoubleLL(DoubleLinkedList **Node, int val)
{
    if (!Node || !(*Node))
        return 1;

    DoubleLinkedList *New = nullptr;

    try
    {
        New = new DoubleLinkedList();
    }
    catch(const std::bad_alloc &)
    {
        return 2;
    }

    New->value = val;
    New->prev = *Node;
    New->next = (*Node)->next;

    if (New->next)
        New->next->prev = New;

    (*Node)->next = New;

    return 0;
}




short   insertBeforeNodeDoubleLL(DoubleLinkedList **Head, DoubleLinkedList *Node, int insertData)
{
    if (!Head || !(*Head) || !(Node))
        return 1;

    if (*Head == Node)
    {
        insertAtBegining(Head, insertData);
        return 0;

        /*
            NewNode->next = *Head;
            NewNode->prev = nullptr;
            (*Head)->prev = NewNode;
            *Head = NewNode;
            return 0;
        */
    }

    DoubleLinkedList *NewNode = new DoubleLinkedList();
    if (!NewNode)
        return 1;

    NewNode->value = insertData;

    DoubleLinkedList *Current = *Head;
    DoubleLinkedList *Prev = Current;

    while (Current)
    {
        if (Current == Node)
        {
            NewNode->next = Current;
            NewNode->prev = Prev;
            Prev->next = NewNode;
            Current->prev = NewNode;
            return 0;
        }
        Prev = Current;
        Current = (Current)->next;            // 1 -> 2 -> 3 -> Prev ->XXX(New) --->    Current(Searched Node) -> 8 
    }

    return 1;
}




short   insertAtEndOfDoubleLL(DoubleLinkedList **Head, int to_insert)
{
    DoubleLinkedList *NewNode = new DoubleLinkedList();

    NewNode->value = to_insert;
    NewNode->next = nullptr;

    if (!(*Head))       //*Head == NULL --> Enter
    {
        NewNode->prev = nullptr;    
        *Head = NewNode;
        return 0;
    }

    DoubleLinkedList *Current = *Head;
    if (!Current)
        return 1;

    while (Current->next)       // Current->Next != NULL        // Will Reach Last Node
        Current = Current->next;

    NewNode->prev = Current;
    Current->next = NewNode;

    return 0;
}





short   deleteNode(DoubleLinkedList **Head , DoubleLinkedList *ToDeleteNode)
{
    if (!(*Head) || !ToDeleteNode)
        return 1;

    if ((*Head) == ToDeleteNode)
    {
        *Head = ToDeleteNode->next;
        if (*Head)
            (*Head)->prev = nullptr;
        delete ToDeleteNode;
        return 0;
    }
    if (ToDeleteNode->next)
        ToDeleteNode->next->prev = ToDeleteNode->prev;
    
    if (ToDeleteNode->prev)
        ToDeleteNode->prev->next = ToDeleteNode->next;

    delete ToDeleteNode;
    return 0;
}




short   deleteFirstNode(DoubleLinkedList **Head)
{
    if (!(*Head))
        return 1;

    DoubleLinkedList    *TempHead;
    TempHead = *Head;
    
    (*Head) = (*Head)->next;
    if ((*Head))
        (*Head)->prev = nullptr;
    delete TempHead;

    return 0;
}



short   deleteLastNode(DoubleLinkedList **Head)
{
    if (!(*Head))
        return 1;

    if (!(*Head)->next)
    {
        delete (*Head);
        (*Head) = nullptr;
        return 0;
    }

    DoubleLinkedList    *BeforeLastNode = *Head;
    while (BeforeLastNode->next->next)             // Inorder to reach the (Previous of the last Node)
        BeforeLastNode =  BeforeLastNode->next;

    DoubleLinkedList    *LastNode = BeforeLastNode->next;

    BeforeLastNode->next = nullptr;
    delete LastNode;

    return 0;
}





int main()
{
    system("clear");


    //      *****************************   My insert At Begining Tests :

    // DoubleLinkedList    *Current;

    // insertAtBegining(&Current, 3);
    // insertAtBegining(&Current, 2);
    // insertAtBegining(&Current, 1);      //  1 <-> 2 <-> 3

    // printList(Current);
    // printListDetails(Current);










    //      *****************************   MY FindNode Tests :

    // DoubleLinkedList    *Current = nullptr;

    // insertAtBegining(&Current, 3);
    // insertAtBegining(&Current, 2);
    // insertAtBegining(&Current, 1);
    // printList(Current);

    // int find = 2;
    // DoubleLinkedList *Node = FindNodeDoubleLL(&Current, find);
    // std::cout << "\nChecking (Finding) Node with value: " << find << std::endl << std::endl;
    // if (Node)
    //     std::cout << "Node is found: " << Node->value << std::endl << std::endl;
    // else
    //     std::cout << "Node isn't found.\n"  << std::endl;



    // find = 8;
    // Node = FindNodeDoubleLL(&Current, find);
    // std::cout << "\nChecking (Finding) Node with value: " << find << std::endl << std::endl;
    // if (Node)
    //     std::cout << "Node is found: " << Node->value << std::endl << std::endl;
    // else
    //     std::cout << "Node isn't found.\n"  << std::endl;



    // insertAtBegining(&Current, 8);
    // find = 8;
    // Node = FindNodeDoubleLL(&Current, find);
    // std::cout << "\nChecking (Finding) Node with value: " << find << std::endl << std::endl;
    // if (Node)
    //     std::cout << "Node is found: " << Node->value << std::endl << std::endl;
    // else
    //     std::cout << "Node isn't found.\n"  << std::endl;







    //      *****************************   MY Insert After Tests:

    // DoubleLinkedList    *Current = nullptr;

    // insertAtBegining(&Current, 3);
    // insertAtBegining(&Current, 2);
    // insertAtBegining(&Current, 1);      //  1 <-> 2 <-> 3


    // printList(Current);
    // printListDetails(Current);

    // DoubleLinkedList *Finded = FindNodeDoubleLL(&Current , 2);
    // std::cout << "----------\n\nInserting After a Node a (22):\n";
    // insertAfterNodeDoubleLL(&Finded, 22);                            //  1 <-> 2 <-> 10 <-> 3

    // printList(Current);
    // printListDetails(Current);


    // Finded = FindNodeDoubleLL(&Current , 1);
    // std::cout << "----------\n\nInserting After a Node (1) a number (11):\n";
    // insertAfterNodeDoubleLL(&Finded, 11);                            //  1 <-> 2 <-> 10 <-> 3

    // printList(Current);
    // printListDetails(Current);


    // Finded = FindNodeDoubleLL(&Current , 3);
    // std::cout << "----------\n\nInserting After a Node (3) a number (33):\n";
    // insertAfterNodeDoubleLL(&Finded, 33);                            //  1 <-> 2 <-> 10 <-> 3

    // printList(Current);
    // printListDetails(Current);






    //      *****************************   MY Insert Before Tests:

    // DoubleLinkedList    *Current;

    // insertAtBegining(&Current, 3);
    // insertAtBegining(&Current, 2);
    // insertAtBegining(&Current, 1);      //  1 <-> 2 <-> 3

    // printList(Current);
    // printListDetails(Current);


    // DoubleLinkedList *Finded = FindNodeDoubleLL(&Current , 1);
    // std::cout << "----------\n\nInserting Before a Node:\n";
    // insertBeforeNodeDoubleLL(&Current, Finded, 11);                            //  1 <-> 2 <-> 10 <-> 3

    // printList(Current);
    // printListDetails(Current);




    // Finded = FindNodeDoubleLL(&Current , 2);
    // std::cout << "----------\n\nInserting Before a Node:\n";
    // insertBeforeNodeDoubleLL(&Current, Finded, 22);                            //  1 <-> 2 <-> 10 <-> 3

    // printList(Current);
    // printListDetails(Current);




    // Finded = FindNodeDoubleLL(&Current , 3);
    // std::cout << "----------\n\nInserting Before a Node:\n";
    // insertBeforeNodeDoubleLL(&Current ,Finded, 33);                            //  1 <-> 2 <-> 10 <-> 3

    // printList(Current);
    // printListDetails(Current);











  //      *****************************   MY Insert At End Tests:

    // DoubleLinkedList    *Current;

    // insertAtBegining(&Current, 3);
    // insertAtBegining(&Current, 2);
    // insertAtBegining(&Current, 1);      //  1 <-> 2 <-> 3

    // printList(Current);
    // printListDetails(Current);
    


    // std::cout << "----------\n\nInserting At End :\n";
    // insertAtEndOfDoubleLL(&Current, 333);

    // printList(Current);
    // printListDetails(Current);



    // std::cout << "----------\n\nInserting At End :\n";
    // insertAtEndOfDoubleLL(&Current, 444);

    // printList(Current);
    // printListDetails(Current);








    //      ***************     Delete Node Tests

    // DoubleLinkedList    *Current;


    // insertAtEndOfDoubleLL(&Current, 1);
    // insertAtEndOfDoubleLL(&Current, 2);
    // insertAtEndOfDoubleLL(&Current, 3);     //  1 <-> 2 <-> 3
    // insertAtEndOfDoubleLL(&Current, 4);     //  1 <-> 2 <-> 3
    // insertAtEndOfDoubleLL(&Current, 5);     //  1 <-> 2 <-> 3
    
    // printList(Current);
    // printListDetails(Current);




    // std::cout << "----------\n\nDeleting a Specific Node:\n";

    // DoubleLinkedList    *Node = FindNodeDoubleLL(&Current, 1);
    // deleteNode(&Current, Node);
    // printList(Current);
    // printListDetails(Current);


    // Node = FindNodeDoubleLL(&Current, 5);
    // deleteNode(&Current, Node);
    // printList(Current);
    // printListDetails(Current);


    // Node = FindNodeDoubleLL(&Current, 3);
    // deleteNode(&Current, Node);
    // printList(Current);
    // printListDetails(Current);








        //      ***************     Delete First Node Tests

    // DoubleLinkedList    *Current;


    // insertAtEndOfDoubleLL(&Current, 1);
    // insertAtEndOfDoubleLL(&Current, 2);
    // insertAtEndOfDoubleLL(&Current, 3);     //  1 <-> 2 <-> 3
    
    // printList(Current);
    // printListDetails(Current);



    // std::cout << "\n\nDeleting First Node:\n";

    // deleteFirstNode(&Current);
    // printList(Current);
    // printListDetails(Current);

    // std::cout << "\n\n----------\n\n";

    // std::cout << "\n\nDeleting First Node:\n";
    // deleteFirstNode(&Current);
    // printList(Current);
    // printListDetails(Current);

    // std::cout << "\n\n----------\n\n";

    // std::cout << "\n\nDeleting First Node:\n";
    // deleteFirstNode(&Current);
    // printList(Current);
    // printListDetails(Current);








        //      ***************     Delete Last Node Tests

    DoubleLinkedList    *Current;


    insertAtEndOfDoubleLL(&Current, 1);
    insertAtEndOfDoubleLL(&Current, 2);
    insertAtEndOfDoubleLL(&Current, 3);     //  1 <-> 2 <-> 3
    
    printList(Current);
    printListDetails(Current);




    std::cout << "\n\nDeleting Last Node:\n";
    deleteLastNode(&Current);
    printList(Current);
    printListDetails(Current);


    std::cout << "\n\n----------\n\n";

    std::cout << "\n\nDeleting Last Node:\n";
    deleteLastNode(&Current);
    printList(Current);
    printListDetails(Current);


    std::cout << "\n\n----------\n\n";

    std::cout << "\n\nDeleting Last Node:\n";
    deleteLastNode(&Current);
    printList(Current);
    printListDetails(Current);


    return (0);   
}