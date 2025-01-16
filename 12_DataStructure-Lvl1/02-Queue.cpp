#include <iostream>
#include <queue>        //  Queue is part of STL : Standard Template Library

int main()
{
    system("clear");

    std::queue <float>   myQueue;

    myQueue.push(10.1);
    myQueue.push(20.2);
    myQueue.push(30.3);
    myQueue.push(40.4);

    std::cout << "Size of Queue:  " <<  myQueue.size() << std::endl;        //  4
    std::cout << "Front of Queue:  " <<  myQueue.front() << std::endl;      //  10.1
    std::cout << "Back of Queue:  " <<  myQueue.back() << std::endl << std::endl;   //  40.4

    std::cout << "Queue elements:  " << std::endl;
    
    while(!(myQueue.empty()))
    {
        std::cout << myQueue.front() << "  " ; 
        myQueue.pop();
    }

    std::cout << "\n\n";



    std::cout << "\n\n------------\n\nSwapping ! :" << std::endl;


    std::queue <int>    firstQueue;
    std::queue <int>    lastQueue;

    firstQueue.push(10);
    firstQueue.push(20);
    firstQueue.push(30);
    firstQueue.push(40);

    lastQueue.push(60);
    lastQueue.push(70);
    lastQueue.push(80);

    firstQueue.swap(lastQueue);

    std::cout << std::endl << "First Queue:  ";
    while(!(firstQueue.empty()))
    {
        std::cout << firstQueue.front() << "   "; 
        firstQueue.pop();
    }

    std::cout << std::endl << "Last Queue:  ";
    while(!(lastQueue.empty()))
    {
        std::cout << lastQueue.front() << "   "; 
        lastQueue.pop();
    }

    return 0;
}