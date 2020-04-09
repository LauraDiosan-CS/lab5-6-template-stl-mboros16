#include "produs.h"
#include "monezi.h"
#include "repository.h"
#include "controller.h"
#include "teste.h"
#include "repositoryfile.h"
#include "UI.h"
#include <iostream>

/*void UI::rulareRepo()
{
    Controller controller;
    int suma;
    int cod;
    bool stop=false;
    int raspuns;
    int v[4];
    int pret_produs_selectat;
    while(stop==false)
    {
        controller.print();
        std::cout << "Dati valoarea bacnotelor: " << std::endl;
        std::cin >> suma;
        std:: cout << "Introduceti codul produsului: " << std::endl;
        std::cin >> cod;
        if(controller.gaseste(cod) >=0)
        {
            pret_produs_selectat=controller.p.getAll()[controller.gaseste(cod)].getPret();
            if(suma<pret_produs_selectat)
                std::cout<<"Suma introdusa este insuficienta pentru a cumpara produsul dorit." << std::endl;
            else
            {
                if(controller.verificarePlata(suma,pret_produs_selectat,v)==true)
                {
                    std::cout << "Tranzactie aprobata. " << std:: endl;
                    std:: cout << "Rest 50lei: " << v[0] << " Rest 10lei: " << v[1] << " Rest 5lei: " << v[2] << " Rest 1lei: " << v[3] << std::endl;
                    stop=true;
                }
                else
                    std::cout << "Tranzactie refuzata. Nu se poate da rest. " << std::endl;
            }
        }
        else
            std::cout << "Cod invalid. " << std::endl;
    }
}*/

void UI::rulareRepoFile()
{
    Controller controller;
    int suma;
    int cod;
    bool stop = false;
    int v[4];
    int pret_produs_selectat;
    while (stop == false)
    {
        controller.print();
        std::cout << "Dati valoarea bacnotelor: " << std::endl;
        std::cin >> suma;
        std::cout << "Introduceti codul produsului: " << std::endl;
        std::cin >> cod;
        if (controller.gaseste(cod) >= 0)
        {
            pret_produs_selectat = controller.p.getAll()[controller.gaseste(cod)].getPret();
            if (suma < pret_produs_selectat)
                std::cout << "Suma introdusa este insuficienta pentru a cumpara produsul dorit. " << std::endl;
            else {
                if (controller.verificarePlata(suma, pret_produs_selectat, v) == true)
                {
                    std::cout << "Tranzactie aprobata. " << std::endl;
                    std::cout << "Rest 50lei: " << v[0] << " Rest 10lei: " << v[1] << " Rest 5lei: " << v[2]
                        << " Rest 1lei: " << v[3] << std::endl;
                    stop = true;
                }
                else
                    std::cout << "Tranzactie refuzata. Nu se poate da rest. " << std::endl;
            }
        }
        else
            std::cout << "Cod invalid. " << std::endl;
    }
}