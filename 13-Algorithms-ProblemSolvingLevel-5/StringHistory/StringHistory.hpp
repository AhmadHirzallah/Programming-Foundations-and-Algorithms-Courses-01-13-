#pragma once

#ifndef STRINGHISTORY_HPP
# define STRINGHISTORY_HPP 

#include <iostream>
#include <stack>

class StringHistory
{

private:

        std::stack  <std::string>   _Undo;
        std::stack  <std::string>   _Redo;



        void    _assignValue(const std::string &newValue)
        {
            Value = newValue;
        }





public:


        std::string Value;

        StringHistory(std::string NewValue = "")
        {
            this->Value = NewValue;
        }


        void    SetValue(std::string    NewValue)
        {
            _Undo.push(GetValue());
            _assignValue(NewValue);
        }

        std::string    GetValue()
        {
            return (Value);
        }

        short   Undo()
        {
            if (!(_Undo.empty()))
            {
                (this->_Redo).push(GetValue());
                _assignValue(_Undo.top());
                _Undo.pop();
            }
            return (0);
        }


        short   Redo()
        {
            if (!(_Redo.empty()))
            {
                (this->_Undo).push(GetValue());
                _assignValue(_Redo.top());
                _Redo.pop();
            }
            return (0);
        }


};















#endif