#include <iostream>
#include "UI.h"
#include "teste.h"

int main() {
    testProdus();
    testRepository();
    testController();
    testeRepositoryFile();
    UI ui;
    while (true)
    {
        //ui.rulareRepo();
        ui.rulareRepoFile();
    }
}