#ifndef CLIENT_STRUCT_H
#define CLIENT_STRUCT_H

#include <string>

struct s_client
{
    std::string str_id_nbr = ""; // Client ID number
    std::string str_pin_nbr = ""; // Client PIN number
    std::string str_name = ""; // Client name
    std::string str_phone_nbr = ""; // Client phone number
    double d_balance = 0.0; // Client balance
    bool request_to_deletion = false; // Deletion request flag
};

#endif // CLIENT_STRUCT_H

