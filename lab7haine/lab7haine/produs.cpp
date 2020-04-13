#include "produs.h"

Produs::Produs()
{
	nume = NULL;
	pret = 0;
	bucati = 0;
}

Produs::Produs(const char* nume_nou, const int pret_nou, const int bucati_nou)
{
	setNume(nume_nou);
	setPret(pret_nou);
	setBucati(bucati_nou);

}

Produs::Produs(const Produs& p)
{
	setNume(p.nume);
	setPret(p.pret);
	setBucati(p.bucati);
}

Produs::~Produs()
{
	if (nume)
		delete[] nume;
	nume = NULL;
	pret = 0;
	bucati = 0;
}

Produs& Produs::operator=(const Produs& p)
{
	setNume(p.nume);
	setPret(p.pret);
	setBucati(p.bucati);
	return *this;
}

bool Produs::operator==(const Produs& p) const
{
	if (nume == NULL || p.nume == NULL)
		return false;
	return (strcmp(nume, p.nume) == 0);
}

bool Produs::operator!=(const Produs& p) const
{
	return !(operator==(p));
}

bool Produs::operator<(const Produs& p) const
{
	return (strcmp(nume, p.nume) == -1);
}

bool Produs::operator<=(const Produs& p) const
{
	return ((strcmp(nume, p.nume) == 0) || (strcmp(nume, p.nume) == -1));
}

bool Produs::operator>(const Produs& p) const
{
	return (strcmp(nume, p.nume) == 1);
}

bool Produs::operator>=(const Produs& p) const
{
	return ((strcmp(nume, p.nume) == 0) || (strcmp(nume, p.nume) == 1));
}

ostream& operator<<(ostream& os, Produs& p)
{
	os << p.nume << " " << p.pret << " " << p.bucati << endl;
	return os;
}

istream& operator>>(istream& is, Produs& p)
{
	char* nume = new char[30];
	int pret, bucati;
	is >> nume >> pret >> bucati;
	if (strcmp(nume, "") == 0)
	{
		p = def;
		return is;
	}
	p.setNume(nume);
	p.setPret(pret);
	p.setBucati(bucati);
	delete[] nume;
	return is;
}

char* Produs::getNume() 
{ 
	return nume; 
}

int Produs::getPret() 
{ 
	return pret; 
}

int Produs::getBucati() 
{ 
	return bucati; 
}

void Produs::setNume(const char* nume_nou)
{
	nume = new char[strlen(nume_nou) + 1];
	strcpy_s(nume, strlen(nume_nou) + 1, nume_nou);
}

void Produs::setPret(const int pret_nou)
{
	pret = pret_nou;
}

void Produs::setBucati(const int bucati_nou)
{
	bucati = bucati_nou;
}