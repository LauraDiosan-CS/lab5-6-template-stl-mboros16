#include "produs.h"
#include "monezi.h"
#include "repository.h"
#include "repositoryfile.h"
#include "controller.h"
#include <iostream>
#include <cassert>
#include <string>
#include <stdio.h>

void testProdus()
{
    Produs produs1;
    Produs produs2;
    Produs produs3;
    produs1 = Produs(-1, "apartament2", 15);
    //assert(produs1.getCod()==-1);
    produs2 = Produs(1024, "camera3", 4);
    assert(produs2.getCod() == 1024);
    assert(produs2.getNume().compare("camera3") == 0);
    assert(produs2.getPret() == 4);
    produs3 = Produs(230, "camera56", 40);
    produs3.setCod(450);
    produs3.setNume("camera1");
    produs3.setPret(35);
    std::cout << "Teste succes 1" << std::endl;
}

void testRepository()
{
    Repository <Produs> produs;
    Repository <Monezi> monezi;

    Produs produs1;
    Produs produs2;
    Produs produs3;

    Monezi monezi1;
    Monezi monezi2;
    Monezi monezi3;

    produs1 = Produs(2345, "camera57", 24);
    produs2 = Produs(2414, "camera parter", 2);
    produs3 = Produs(21, "camera58", 100);

    monezi1 = Monezi(50, 20);
    monezi2 = Monezi(10, 14);
    monezi3 = Monezi(5, 4);

    produs.adaugaProdus(produs1);
    produs.adaugaProdus(produs2);
    produs.adaugaProdus(produs3);

    monezi.adaugaProdus(monezi1);
    monezi.adaugaProdus(monezi2);
    monezi.adaugaProdus(monezi3);

    assert(monezi1.compare(monezi.getAll()[0], 0) == true);
    assert(monezi2.compare(monezi.getAll()[1], 0) == true);
    assert(monezi3.compare(monezi.getAll()[2], 0) == true);
    assert(monezi.getAll().size() == 3);
    assert(produs.getAll().size() == 3);

    std::cout << "Teste succes 2" << std::endl;
}

void testController()
{
    Controller controller;
    int v[5];
    int p;
    p = controller.gaseste(5);
    assert(p == 0);

    int k = controller.gaseste(20);
    assert(k == 1);

    int m = controller.gaseste(7);
    assert(m == 2);

    int n = controller.gaseste(75);
    assert(n == 3);

    int o = controller.gaseste(30);
    assert(o == 4);

    int g = controller.gaseste(14);
    assert(g == 5);

    controller.verificarePlata(50, 5, v);

    std::cout << "Teste succes 3" << std::endl;
}

void testeRepositoryFile() {
    RepoFile <Produs> repofile("fisier_intrare.txt");
    Produs produs5;
    produs5 = Produs(5, "Camera1", 5);
    Produs produs6;
    produs6 = Produs(10, "Camera67", 2);
    repofile.adaugaProdus();

    //assert(repofile.getAll()[0].strcmp(produs5,0) == );
    //assert(repofile.getAll()[1].compare(produs6, 0) == true);
    repofile.suprascriere();
    std::cout << "Teste succes 4" << std::endl;
}
