#include <iostream>
#include "repository.h"
#include "controller.h"

Controller::Controller()
{
    p.setNume_fisier("fisier_intrare.txt");
    p.adaugaProdus();
    monezi.setNume_fisier("fisier_intrare2.txt");
    monezi.adaugaProdus();
}

Controller::~Controller() {}

bool Controller::verificarePlata(int x, int y, int v[])
{
    int suma_bani = this->monezi.getAll().size();
    int rest = x - y;
    int m;
    int n;
    if (rest >= 0)
    {
        for (int i = 0; i < suma_bani; i++)
        {
            m = 0;
            n = this->monezi.getAll()[i].getNumar();
            while (rest >= this->monezi.getAll()[i].getValoare() && n > 0)
            {
                m = m++;
                rest -= this->monezi.getAll()[i].getValoare();
                n--;
                this->monezi.setNumar(n, i);
            }
            v[i] = m;
        }
    }
    if (rest == 0)
    {
        for (int j = 0; j < suma_bani; j++)
        {
            n = this->monezi.getAll()[j].getNumar();
            while (y >= this->monezi.getAll()[j].getValoare())
            {
                y = y - this->monezi.getAll()[j].getValoare();
                n = n + 1;
                this->monezi.setNumar(n, j);
            }
        }
        return true;
    }
    return false;
}

void Controller::print()
{
    std::cout << "Bacnote disponibile: 50lei, 10lei, 5lei, 1lei" << std::endl;
    std::cout << "Camere disponibile: " << std::endl;
    for (unsigned int i = 0; i < p.getAll().size(); i++)
        std::cout << p.getAll()[i] << std::endl;
}

int Controller::gaseste(int cod)
{
    for (unsigned int i = 0; i < p.getAll().size(); i++)
    {
        if (p.getAll()[i].getCod() == cod)
            return i;
    }
    return -1;
}