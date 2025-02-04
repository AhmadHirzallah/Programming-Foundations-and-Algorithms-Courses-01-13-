#pragma once

#ifndef CLSSTACKARR_HPP 
# define CLSSTACKARR_HPP

#include <iostream>
#include "clsQueueArr.hpp"

template <class T>
class clsStackArr : public clsQueueArr <T>
{

public:
            short   push(T new_data)
            {
                return (this->DynamicArr.InsertAtBegining(new_data));
            }


            T   top()
            {
                return (clsQueueArr<T>::front());
            }


            T   bottom()
            {
                return (clsQueueArr<T>::back());
            }


            short   InsertAtTop(T insert_val)
            {
                return (push(insert_val));
            }


            short   InsertAtBottom(T insert_val)
            {
                return (clsQueueArr<T>::InsertAtBack(insert_val));
            }
};

#endif