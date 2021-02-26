#include "SystemUser.hpp"

SystemUser::SystemUser()
{
    username="empty";
    password="empty";
}
SystemUser::SystemUser(string uName,string pWord)
{
    username=uName;
    password=pWord;
}
string SystemUser::getUsername()
{
    return username;
}
void SystemUser::setUsername(string uName)
{
    username=uName;
}
bool SystemUser::checkPassword(string pass)
{
    return pass==password;
}
bool SystemUser::updatePassword(string pass, string pass2)
{
    if(pass==password)
    {
        password=pass2;
        return true;
    }
    else
        return false;
}
bool SystemUser::operator==(const SystemUser& temp) const
{
    return username==temp.username;
}
bool SystemUser::operator!=(const SystemUser& temp) const
{
    return username!=temp.username;
}
ostream &operator<<(ostream &out, SystemUser &temp)
{
    out << temp.username << " " << temp.password;
    return out;
}
istream &operator>>(istream &in, SystemUser &temp)
{
    in >> temp.username >> temp.password;
    return in;
}
