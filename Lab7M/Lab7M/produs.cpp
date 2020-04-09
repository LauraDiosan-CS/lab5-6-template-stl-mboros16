#include "produs.h"
#include <iostream>
#include<string>

Produs::Produs()
{
    this->cod = 0;
    this->nume = "";
    this->pret = 0;
};
Produs::Produs(int cod, std::string nume, int pret)
{
    this->cod = cod;
    this->nume = nume;
    this->pret = pret;
};

Produs::Produs(const Produs& p)
{
    this->cod = p.cod;
    this->nume = p.nume;
    this->pret = p.pret;
}

Produs::~Produs() {}

int Produs::getCod()
{
    return this->cod;
}
std::string Produs::getNume()
{
    return this->nume;
}

int Produs::getPret()
{
    return this->pret;
}

void Produs::setCod(int cod)
{
    this->cod = cod;
}

void Produs::setNume(std::string nume)
{
    this->nume = nume;
}

void Produs::setPret(int pret)
{
    this->pret = pret;
}

Produs& Produs::operator=(const Produs& p)
{
    if (this != &p)
    {
        this->setCod(p.cod);
        this->setNume(p.nume);
        this->setPret(p.pret);
    }
    return *this;
}

bool Produs::comparareProduse(const Produs& p, int i)
{
    bool rezultat;
    switch (i)
    {
    case 0:
        rezultat = (this->pret == p.pret) && (this->cod == p.cod) && (this->nume.compare(p.nume) == 0);
        break;
    case 1:
        rezultat = (this->pret == p.pret);
        break;
    case 2:
        rezultat = (this->cod == p.cod);
        break;
    case 3:
        rezultat = (this->nume.compare(p.nume) == 0);
        break;
    default:
        rezultat = (this->pret == p.pret) && (this->cod == p.cod) && (this->nume.compare(p.nume) == 0);
        break;
    }
    return rezultat;
}

std::ostream& operator<<(std::ostream& os, Produs& c)
{
    os << c.cod << " " << c.nume << " " << c.pret << std::endl;
    return os;
}

std::istream& operator>>(std::istream& is, Produs& c)
{
    is >> c.cod >> c.nume >> c.pret;
    return is;
}
