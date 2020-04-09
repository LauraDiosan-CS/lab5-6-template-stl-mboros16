#ifndef Lab7Mrepository
#define Lab7Mrepository
#include <vector>
#include <iostream>
#include <string>

template <class T>
class Repository {
protected:
    std::vector <T> listaProduse;
public:
    Repository() {}
    ~Repository() {}
    void adaugaProdus(T produs)
    {
        this->listaProduse.push_back(produs);
    }

    std::vector <T> getAll()
    {
        return this->listaProduse;
    }

    void setNumar(int numar, int poz)
    {
        this->listaProduse[poz].setNumar(numar);
    }

};
#endif //Lab7Mrepository

