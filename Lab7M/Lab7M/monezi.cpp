#include <iostream>
#include "monezi.h"

Monezi::Monezi()
{
    this->numar = 0;
    this->valoare = 0;
}

Monezi::Monezi(int numar, int valoare)
{
    this->numar = numar;
    this->valoare = valoare;
}

Monezi::~Monezi() {}

int Monezi::getNumar()
{
    return this->numar;
}

int Monezi::getValoare()
{
    return this->valoare;
}

void Monezi::setNumar(int numar)
{
    this->numar = numar;
}

void Monezi::setValoare(int valoare)
{
    this->valoare = valoare;
}

bool Monezi::compare(const Monezi& m, int i)
{
    bool rezultat;
    switch (i) {
    case 0:
        rezultat = (this->valoare == m.valoare) && (this->numar == m.numar);
        break;
    default:
        rezultat = (this->valoare == m.valoare) && (this->numar == m.numar);
        break;
    }
    return rezultat;
}

std::ostream& operator<<(std::ostream& os, Monezi& m)
{
    os << m.numar << " " << m.valoare << std::endl;
    return os;
}

std::istream& operator>>(std::istream& is, Monezi& m)
{
    is >> m.numar >> m.valoare;
    return is;
}