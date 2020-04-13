#include "teste.h"

void ProdusTeste()
{
	Produs p;
	Produs p1;
	Produs p2("camasi", 50, 5);
	Produs p3(p2);
	p = p2;
	assert(p2 == p3);
	assert(p == p2);
	p.setNume("maieuri");
	p.setPret(10);
	p.setBucati(5);
	assert(strcmp(p.getNume(), "maieuri") == 0 && p.getPret() == 10 && p.getBucati() == 5);
}

void RepoTeste()
{
	Produs p1("camasi", 50, 5);
	Produs p2("tricouri", 30, 10);
	Produs p3("maieuri", 10, 5);
	Repo<Produs> produs;
	produs.add(p1);
	produs.add(p2);
	produs.add(p3);
	assert(produs.size() == 3);
	Produs p4("pantaloni scurti", 40, 100);
	produs.del(p3);
	assert(produs.size() == 2);
	produs.mod(p1, p4);
	assert(*(produs.getAll().begin()) == p4);
	produs.add(p3);
	assert(produs.find_by_title("maieuri") == p3);
}

void ServiceTeste()
{
	Service<Produs> service;
	Produs p1("camasi", 50, 5);
	service.add("maieuri", 10, 100);
	//assert(*(service.getAll().begin()) == p1);
	service.add("ochelari", 15, 50);
	assert(service.size() == 2);
	service.del("ochelari");
	assert(service.size() == 1);
	Produs p3("pantaloni scurti", 30, 100);
	service.mod("camasi", "maieuri", 50, 100);
	//assert(*(service.getAll().begin()) == p3);
}

void teste()
{
	ProdusTeste();
	RepoTeste();
	ServiceTeste();
}