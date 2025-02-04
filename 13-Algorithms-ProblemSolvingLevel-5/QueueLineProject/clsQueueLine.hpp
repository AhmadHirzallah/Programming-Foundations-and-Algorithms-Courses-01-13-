#pragma once

#ifndef CLSQUEUELINE_HPP
# define CLSQUEUELINE_HPP

# include <iostream>
# include <stack>
# include <queue>

#   include "include/DateUtils.hpp"
#   include "include/StringUtils.hpp"

class clsQueueLine
{

private:

        class   clsTicket
        {
        private:


            std::string                      _Prefix;
            std::string                      _DataTimeStr;
            std::string                      _ClientTicketOrderNbr;
            int             _waiting_clients;
            short           _client_serving_time;




        public:

                clsTicket(std::string Prefix, int ticket_order_nbr ,int waiting_clients, short client_serving_time)
                {
                    _Prefix = Prefix;
                    _DataTimeStr = DateUtils::getSystemDateAndTimeStr();
                    _waiting_clients = waiting_clients;
                    _ClientTicketOrderNbr = _Prefix + std::to_string(ticket_order_nbr);
                    _client_serving_time = client_serving_time;
                }


                std::string getTicketOrderNbr()
                {
                    return (_ClientTicketOrderNbr);
                }


                void    PrintTicket()
                {
                    int cardWidth = 45;
                    int totalWidth = 160;    // Total terminal width (adjust as needed)
                    int padding = (totalWidth - cardWidth) / 2;

                    std::cout << "\n\n";
                    std::cout << std::setw(padding) << std::right << "" 
                            << "Ticket Information:" << std::endl;

                    std::cout << std::setw(padding) << std::right << "" 
                            << "==================================" << std::endl;


                    std::cout << std::setw(padding) << std::right << "" 
                            << "Ticket Order Nbr : " << _ClientTicketOrderNbr << std::endl;

                    std::cout << std::setw(padding) << std::right << "" 
                            << "Date & Time      : " << _DataTimeStr << std::endl;
                            
                    std::cout << std::setw(padding) << std::right << "" 
                            << "Waiting Clients  : " << _waiting_clients << std::endl;

                    std::cout << std::setw(padding) << std::right << "" 
                            << "Serving Time     : " << _client_serving_time << " Minutes" << std::endl;

                    std::cout << std::setw(padding) << std::right << "" 
                            << "==================================" << std::endl;
                    std::cout << std::endl;
                }


        };
        



        int         _total_tickets;
        short                                   _servingExpectedTime; 
        std::string                     _Prefix;
        std::stack  <clsTicket> _Stack;
        std::queue  <clsTicket> _Queue;



        void    _increaseTotalTickets()
        {
            _total_tickets++;
        }


        int _getLastTicketNbr()
        {
            return (_total_tickets);
        }


public:

        clsQueueLine(std::string Prefix , short servingExpectedTime)
        {
            _total_tickets = 0;
            _Prefix = Prefix;
            _servingExpectedTime = servingExpectedTime;
        }


        int getWaitingClientsNbr()
        {
            return (_Queue.size());
        }


        int calcServeredClientsNbr()
        {
            return ((this->_total_tickets) - getWaitingClientsNbr());
        }


        int calcClientServingTime()
        {
            return (_servingExpectedTime * getWaitingClientsNbr());
        }



        void    IssueTicket()
        {
            _increaseTotalTickets();
            clsTicket   Ticket =  clsTicket(this->_Prefix , (this->_total_tickets) , getWaitingClientsNbr() , calcClientServingTime());
            _Queue.push(Ticket);
        }


        std::string WhoIsNext()
        {
            if (this->_Queue.empty())
                return ("*******   No Left Clients.  :(   *******");
            else
                return (_Queue.front().getTicketOrderNbr());
        }

        void    PrintInfo()
        {
            int cardWidth = 45;
            int totalWidth = 160;
            int padding = (totalWidth - cardWidth) / 2;

            std::cout << "\n\n";
            std::cout << std::setw(padding) << std::right << "" 
                    << "Queue Line Information:" << std::endl;

            std::cout << std::setw(padding) << std::right << "" 
                    << "========================================" << std::endl;



            std::cout << std::setw(padding) << std::right << "" 
                    << "Prefix            : " << _Prefix << std::endl;

            std::cout << std::setw(padding) << std::right << "" 
                    << "Total Tickets     : " << _total_tickets << std::endl;

            std::cout << std::setw(padding) << std::right << "" 
                    << "Served Clients    : " << calcServeredClientsNbr() << std::endl;

            std::cout << std::setw(padding) << std::right << "" 
                    << "Waiting Clients   : " << getWaitingClientsNbr() << std::endl;

            std::cout << "\n" << std::setw(padding) << std::right << "" 
                    << "[(Last) Client Serving Time Will Be In: " << calcClientServingTime() << " Minutes]" << std::endl;
                    
            std::cout << std::setw(padding) << std::right << "" 
                    << "========================================" << std::endl;
            std::cout << std::endl;
        }


        void    PrintTicketsRTL()
        {
            int cardWidth = 45;
            int totalWidth = 160;
            int padding = (totalWidth - cardWidth) / 2;

            if (_Queue.empty())
            {
                std::cout << "\n\n";
                std::cout << std::setw(padding) << std::right << "" 
                        << "********    NO TICKETS      ********"  << std::endl;
                return ;
            }

            std::cout << "\n\n";
            std::cout << std::setw(padding) << std::right << "" 
                    << "Tickets Line Order (Right To Left):" << std::endl;

            std::cout << std::setw(padding) << std::right << "" 
                    << "========================================" << std::endl;
            std::cout << "\n\n";

            std::queue <clsTicket>  TempQueue = (this->_Queue);

            std::cout << StringUtils::Tabs(7);
            while (1)
            {
                std::cout << TempQueue.front().getTicketOrderNbr();
                TempQueue.pop(); 
                if (!TempQueue.empty())
                    std::cout << "  <-=-  ";
                else 
                    break;
            }

            std::cout << "\n\n\n\n";
        }


        void    PrintTicketsLTR()
        {
            int cardWidth = 45;
            int totalWidth = 160;
            int padding = (totalWidth - cardWidth) / 2;

            if (_Queue.empty())
            {
                std::cout << "\n\n";
                std::cout << std::setw(padding) << std::right << "" 
                        << "********    NO TICKETS      ********"  << std::endl;
                return ;
            }


            std::cout << "\n\n";
            std::cout << std::setw(padding) << std::right << "" 
                    << "Tickets Line Order (Left To Right):" << std::endl;

            std::cout << std::setw(padding) << std::right << "" 
                    << "========================================" << std::endl;
            std::cout << "\n\n";

            std::stack <clsTicket>  TempStack;
            std::queue <clsTicket>  TempQueue = (this->_Queue);
            while (!TempQueue.empty())
            {
                TempStack.push(TempQueue.front());
                TempQueue.pop();
            }

            std::cout << StringUtils::Tabs(7);
            while (1)
            {
                std::cout << TempStack.top().getTicketOrderNbr();
                TempStack.pop(); 
                if (!TempStack.empty())
                    std::cout << "  -=->  ";
                else 
                    break;
            }

            std::cout << "\n\n\n\n";
        }


        void    PrintAllTickets()
        {
            if (_Queue.empty())
            {
                std::cout << "\n\n";
                std::cout << std::setw((160-45) / 2) << std::right << "" 
                        << "********    NO TICKETS      ********"  << std::endl;
                return ;
            }

            std::queue <clsTicket>  TempQueue = (this->_Queue);

            while (!(TempQueue.empty()))
            {
                TempQueue.front().PrintTicket();
                TempQueue.pop();
            }
        }


        short    ServeNextClient()
        {
            if (_Queue.empty())
                return (1);

            _Queue.pop();
            return (0);
        }




};









#endif