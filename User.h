#ifndef USER_H_INCLUDED
#define USER_H_INCLUDED
#include <iostream>
#include "cifrador.h"

class User{
private:
    std::string name;
    std::string pass;
    std::string info;
    int brute;
    std::string qs;
public:
    User();
    std::string getName();
    std::string getPassHash();
    std::string getInfo();
    std::string getQS();
    int getBrute();
    void setName(std::string);
    void setPassword(std::string);
    void setInfo(std::string);
    void setQS(std::string);
    void decBrute();
    bool isValidQS(std::string);


};

#endif // USER_H_INCLUDED
