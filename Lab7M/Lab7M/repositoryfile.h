#ifndef Lab7MrepFile
#define Lab7MrepFile

#include "repository.h"
#include <iostream>
#include <fstream>
#include <istream>
#include <string.h>
#include <string>

template <class T>
class RepoFile :public Repository<T> {
private:
    std::ifstream in;
    std::ofstream of;
    char* nume_fisier;
public:
    RepoFile() :Repository<T>() {};
    RepoFile(const char* nume_fisier)
    {
        this->nume_fisier = new char[strlen(nume_fisier) + 1];
        strcpy_s(this->nume_fisier, strlen(nume_fisier) + 1, nume_fisier);
        in.open(nume_fisier);
        if (!in)
            std::cerr << "Fiserul nu se poate deschide." << std::endl;
    }
    ~RepoFile()
    {
        in.close();
        of.close();
    }

    void setNume_fisier(const char* nume_fisier)
    {
        this->nume_fisier = new char[strlen(nume_fisier) + 1];
        in.open(nume_fisier);
        if (!in)
            std::cerr << "Fiserul nu se poate deschide." << std::endl;
    }

    void adaugaProdus()
    {
        T produs;
        while (in >> produs)
        {
            Repository <T> ::adaugaProdus(produs);
        }
    }

    void setNumar(int numar, int poz)
    {
        this->listaProduse[poz].setNumar(numar);
    }

    std::vector <T> getAll()
    {
        return Repository <T> ::getAll();
    }

    void suprascriere()
    {
        of.open(this->nume_fisier);
        for (unsigned int i = 0; i < this->listaProduse.size(); i++)
            of << this->listaProduse[i];
    }

    const RepoFile<T>& operator=(const RepoFile<T>& r) {
        in = r.in;
        this->nume_fisier = new char[strlen(r.nume_fisier) + 1];
        strcpy(this->nume_fisier, r.nume_fisier);
        return *this;
    }


};
#endif //Lab7M-repFile
