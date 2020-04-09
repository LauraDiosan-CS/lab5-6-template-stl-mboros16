#ifndef Lab7Mmonezi
#define Lab7Mmonezi
#include <iostream>
#include <string>

class Monezi
{
private:
    int numar;
    int valoare;
public:
    Monezi();
    Monezi(int numar, int valoare);
    ~Monezi();
    int getNumar();
    int getValoare();
    void setNumar(int numar);
    void setValoare(int valoare);
    bool compare(const Monezi& m, int i);
    friend std::ostream& operator<<(std::ostream& os, Monezi& m);
    friend std::istream& operator>>(std::istream& is, Monezi& m);
};
#endif //Lab7M-monezi
