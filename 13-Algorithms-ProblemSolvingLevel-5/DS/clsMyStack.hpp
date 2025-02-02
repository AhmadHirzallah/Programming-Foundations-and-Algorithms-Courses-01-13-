#pragma once

#ifndef CLSMYSTACK_HPP 
# define CLSMYSTACK_HPP

#include <iostream>
#include "clsQueue.hpp"

template <class T>
class clsMyStack : public clsQueue<T>
{

public:
            //  overriding the queue push
            short   push(T new_data)
            {
                // clsQueue <T>::_DoubleLinkedList.insertAtBegining(new_data);
                this->_DoubleLinkedList.insertAtBegining(new_data);
                return 0;
            }


            T   top()
            {
                // clsQueue<T>::front();
                return (clsQueue<T>::front());
            }


            T   bottom()
            {
                // return (clsQueue<T>::back());
                return (clsQueue<T>::back());
            }


            short   InsertAtTop(T insert_val)
            {
                return (push(insert_val));
            }


            short   InsertAtBottom(T insert_val)
            {
                return (clsQueue<T>::InsertAtBack(insert_val));
            }
};

#endif