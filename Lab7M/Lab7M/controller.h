#ifndef Lab7Mcontroller
#define Lab7Mcontroller

#include "produs.h"
#include "monezi.h"
#include "repositoryfile.h"
#include <string>
#include <iostream>

class Controller {
public:
    RepoFile <Produs> p;
    RepoFile <Monezi> monezi;

    Controller();
    ~Controller();
    bool verificarePlata(int x, int y, int v[]);
    int gaseste(int cod);
    void print();
};
#endif //Lab7M-controller
