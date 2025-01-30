#pragma once
#ifndef CLSDOUBLYLINKEDLIST_HPP
# define CLSDOUBLYLINKEDLIST_HPP


template <class T>
class clsDoublyLinkedList
{
public:

        class   Node
        {
            public:
                    T       data;
                    Node   *next;
                    Node   *prev;
        };

        Node    *Head = NULL;




//  ************ PRINTING LISTS **************

        void    printListDetails()
        {
            Node    *Current = Head;

            std::cout << "\n\n";
            std::cout << "Printing List (Details):\n\n";

            if (!Current)
            {
                std::cout << "(NULL)\n(NO DATA // LINKED LIST IS EMPTY).\n\n";
                return ;
            }
                
            while (Current)
            {
                _printNodeDetails(Current);
                Current = Current->next;
            }

            std::cout << "\n\n";
        }


        void    printList()
        {
            Node    *Current = Head;

            std::cout << "\n\n";
            std::cout << "Printing List:\n\n";

            if (!Current)
            {
                std::cout << "(NO DATA // LINKED LIST IS EMPTY).\n\n";
                return ;
            }

            if (Current && !Current->prev)
                std::cout << "NULL";
                
            while (Current)
            {
                std::cout << "  <-->  "<< (Current)->data ;
                Current = Current->next;
            }

            if (Current == nullptr)
                std::cout << "  <-->  "<< "NULL";

            std::cout << "\n\n";
        }



//  ************ LIST OPERATIONS **************

        short   insertAtBegining(T data)
        {
            Node    *New;

            New = new Node();
            if (!New)
                return 1;

            (New)->data = data;
            (New)->prev = nullptr;

            if (!(Head))
                (New)->next = nullptr;
            else
            {
                (New)->next = (Head);
                (Head)->prev = New;
            }

            Head = New;
            return 0;
        }


        Node    *FindNode(T val)
        {
            if (!Head)
                return nullptr;

            Node    *Current = Head;

            while ((Current))
            {
                if (((Current)->data) == val)
                    return (Current);
                
                Current = Current->next;
            }
            
            return nullptr;
        }


        short   isNodeExist(T val)
        {
            Node    *Node = FindNode(val);

            return ((Node) ? 1 : 0); 
        }


        short   insertAfter(Node *Node, T val)
        {
            if (!Node)
                return 1;

            typename clsDoublyLinkedList<T>::Node   *New = new typename clsDoublyLinkedList<T>::Node();

            if (!New)
                return 2;

            New->data = val;
            New->prev = Node;
            New->next = Node->next;

            if (New->next)
                New->next->prev = New;

            Node->next = New;

            return 0;
        }


        short   insertBefore(Node *TargetNode, T val)
        {
            if (!TargetNode)
                return 1;

            Node    *NewNode = new Node();
            if (!NewNode)
                return 1;

            NewNode->data = val;
            NewNode->next = TargetNode;
            NewNode->prev = TargetNode->prev;

            if (TargetNode->prev)
                TargetNode->prev->next = NewNode;
            else // So No Prev; Prev = nullptr -> (Target = Head)
                Head = NewNode;

            TargetNode->prev = NewNode;

            return 0;
        }


        short   insertAtEnd(T to_insert)
        {
            Node *NewNode = new Node();
            if (!NewNode)
                return 1;

            NewNode->data = to_insert;
            NewNode->next = nullptr;

            if (!Head)       //*Head == NULL --> Enter
            {
                NewNode->prev = nullptr;    
                Head = NewNode;
                return 0;
            }

            Node    *Current = Head;

            while (Current->next)       // Current->Next != NULL        // Will Reach Last Node
                Current = Current->next;

            NewNode->prev = Current;
            Current->next = NewNode;

            return 0;
        }


        short   deleteFirstNode()
        {
            Node    *TempHead;

            if (!Head)
                return 1;
            TempHead = Head;
            Head = Head->next;
            if (Head)
                Head->prev = nullptr;
            delete TempHead;

            return 0;
        }


        short   deleteNode(Node *ToDeleteNode)
        {
            if (!Head || !ToDeleteNode)
                return 1;

            if (Head == ToDeleteNode)
            {
                deleteFirstNode();
                return 0;
            }
            if (ToDeleteNode->next)
                ToDeleteNode->next->prev = ToDeleteNode->prev;
            
            if (ToDeleteNode->prev)
                ToDeleteNode->prev->next = ToDeleteNode->next;

            delete ToDeleteNode;
            return 0;
        }


        short   deleteLastNode()
        {
            if (!Head)
                return 1;

            if (!Head->next)
            {
                delete Head;
                Head = nullptr;
                return 0;
            }

            Node    *BeforeLastNode = Head;
            while (BeforeLastNode->next->next)             // Inorder to reach the (Previous of the last Node)
                BeforeLastNode =  BeforeLastNode->next;

            Node    *LastNode = BeforeLastNode->next;

            BeforeLastNode->next = nullptr;
            delete LastNode;

            return 0;
        }



private:

        void    _printNodeDetails(Node    *Current)
        {
            if (!Current)
            {
                std::cout << "NULL";
                return ;
            }

            if (Current->prev)
                std::cout << Current->prev->data;
            else
                std::cout << "NULL";

            std::cout << "  <-->  " << (Current->data) << "  <-->  ";

            if (Current->next)
                std::cout << Current->next->data << "\n";
            else
                std::cout << "NULL\n";
        }                                                                                                                                        


};



#endif









/*

     // short   insertAfter(Node *Node, T val)
        // {

        //     // if (!Node || !(*Node))
        //     //     return 1;

        //     // Node *New = nullptr;

        //     // try
        //     // {
        //     //     New = new Node();
        //     // }
        //     // catch(const std::bad_alloc &)
        //     // {
        //     //     return 2;
        //     // }

        //     // New->data = val;
        //     // New->prev = *Node;
        //     // New->next = (*Node)->next;

        //     // if (New->next)
        //     //     New->next->prev = New;

        //     // (*Node)->next = New;

        //     // return 0;
        // }

*/
