#ifndef SYSTEM_USER_STRUCT_H
#define SYSTEM_USER_STRUCT_H

#include <string>

struct s_user
{
    std::string str_username;
    std::string str_password;
    int i_permissions;
    bool b_mark_for_delete = false;

    s_user(const std::string& username = "",
            const std::string& password = "",
            int permissions = 0,
            bool mark_for_delete = false)
        : str_username(username),
          str_password(password),
          i_permissions(permissions),
          b_mark_for_delete(mark_for_delete)
    {}
};

#endif // SYSTEM_USER_STRUCT_H

