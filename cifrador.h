#ifndef CIFRADOR_H_INCLUDED
#define CIFRADOR_H_INCLUDED

#include <iostream>
#include <cmath>
#include <sstream>

class Cifrador
{
private :
    std::string quitarTildes(std::string aux);
    std::string ascii(std::string aux);
    std::string toBinaryRev(int n);
    int binarioToDecimal(std::string aux);
public:
    Cifrador();
    std::string encripta(std::string data);
    std::string desencripta(std::string data);
};

#endif // CIFRADOR_H_INCLUDED
