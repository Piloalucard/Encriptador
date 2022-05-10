#include "User.h"

using namespace std;

User::User(){
    brute=3;
}

string User::getName()
{
    return name;
}

string User::getPassHash()
{
    return pass;
}

string User::getInfo()
{
    return info;
}

int User::getBrute()
{
    return brute;
}

void User::decBrute()
{
    brute--;
}


void User::setName(string x)
{
    name=x;
}
void User::setPassword(string x)
{
    Cifrador cfr;
    pass=cfr.encripta(x);
}
void User::setInfo(string x)
{
    info=x;
}

string User::getQS()
{
    return qs;
}

void User::setQS(std::string x)
{
    string aux;
    int i=0;
    char c;
    while (x[i])
    {
        c=x[i];
        aux[i]=tolower(c);
        i++;
    }
    qs=aux;
}

bool User::isValidQS(std::string x)
{
    string aux;
    int i=0;
    char c;
    while (x[i])
    {
        c=x[i];
        aux[i]=tolower(c);
        i++;
    }

    if(aux==qs)
        return true;

    return false;
}
