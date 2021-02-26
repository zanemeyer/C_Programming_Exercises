#include <iostream>
#include <cmath>
#include <math.h>
# ifndef SYSTEMUSER_HPP
# define SYSTEMUSER_HPP

using namespace std;

class SystemUser
{
    public:
    SystemUser();
    SystemUser(string uName,string pWord);

    string getUsername();
    void setUsername(string);
    bool checkPassword(string);
    bool updatePassword(string, string);

    bool operator==(const SystemUser&) const;
    bool operator!=(const SystemUser&) const;
    friend ostream &operator <<(ostream &out, SystemUser &temp);
    friend istream &operator >>(istream &in, SystemUser &temp);

    private:
    string username, password;
};

#endif
