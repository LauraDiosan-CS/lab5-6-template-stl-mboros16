#pragma once
#include <stdlib.h>
#include <string>
#include <iostream>

using namespace std;

class Produs
{
	private:
		char* nume;
		int pret;
		int bucati;
	public:
		Produs();
		Produs(const char*, const int, const int);
		Produs(const Produs&);
		~Produs();
		Produs& operator=(const Produs&);
		bool operator==(const Produs&) const;
		bool operator!=(const Produs&) const;
		bool operator<(const Produs&) const;
		bool operator<=(const Produs&) const;
		bool operator>(const Produs&) const;
		bool operator>=(const Produs&) const;
		friend ostream& operator<<(ostream&, Produs&);
		friend istream& operator>>(istream&, Produs&);
		char* getNume();
		int getPret();
		int getBucati();
		void setNume(const char*);
		void setPret(const int);
		void setBucati(const int);
};



const Produs def("", 0, 0);