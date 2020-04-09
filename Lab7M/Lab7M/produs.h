#ifndef Lab7Mprodus
#define Lab7Mprodus
#include <iostream>
#include <string>

class Produs
{
private:
    int cod;
    std::string nume;
    int pret;
public:
    Produs();
    Produs(int cod, std::string nume, int pret);
    Produs(const Produs& p);
    ~Produs();

    int getCod();
    std::string getNume();
    int getPret();

    void setCod(int cod);
    void setNume(std::string nume);
    void setPret(int pret);

    Produs& operator=(const Produs& p);
    bool comparareProduse(const Produs& p, int i);
    friend std::ostream& operator<<(std::ostream& os, Produs& c);
    friend std::istream& operator>>(std::istream& is, Produs& c);

};
#endif //Lab7M-produs
