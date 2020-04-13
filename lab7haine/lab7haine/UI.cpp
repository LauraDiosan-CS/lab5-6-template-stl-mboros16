#include "UI.h"

UI::UI() 
{
}
UI::~UI() 
{
}
void UI::load()
{
	char* numeFis = new char[sizeof "produse.txt" + 1];
	strcpy_s(numeFis, sizeof "produse.txt" + 1, "produse.txt");
	service.load(numeFis);
	print();
}
void UI::save()
{
	service.save();
	cout << "Salvat!" << endl << endl;
}

void UI::add()
{
	char* nume = new char[30];
	int pret, bucati;
	cout << "Introduceti numele: ";
	cin >> nume;
	cout << "Introduceti pret: ";
	cin >> pret;
	cout << "Introduceti numar de bucati: ";
	cin >> bucati;
	service.add(nume, pret, bucati);
	cout << "Adaugat!" << endl << endl;
	delete[] nume;
}

void UI::del()
{
	char* nume = new char[30];
	cout << "Introduceti numele: ";
	cin >> nume;
	service.del(nume);
	cout << "Sters!" << endl << endl;
	delete[] nume;
}

void UI::mod()
{
	char* nume = new char[30];
	char* nume_nou = new char[30];
	int pret_nou, bucati_nou;
	cout << "Introduceti numele: ";
	cin >> nume;
	cout << "Introduceti noile date, daca doriti sa nu modificati, introduceti -1!" << endl << "Introduceti noul nume: ";
	cin >> nume_nou;
	cout << "Introduceti noul pret: ";
	cin >> pret_nou;
	cout << "Introduceti noul numar de bucati: ";
	cin >> bucati_nou;
	service.mod(nume, nume_nou, pret_nou, bucati_nou);
	cout << "Modificat!" << endl << endl;
	delete[] nume;
	delete[] nume_nou;
}

void UI::print()
{
	cout << "Produse: " << endl;
	for (auto it = service.getAll().begin(); it != service.getAll().end(); ++it)
	{
		Produs crt = *it;
		cout << crt;
	}
	cout << endl;
}

void UI::no_command()
{
	cout << "Comanda invalida" << endl << endl;
}

void UI::show()
{
	char op;
	cout << "Doriti sa incarcati din fisier? 1-DA  2-NU" << endl << "Introduceti: ";
	cin >> op;
	if (op == '1')
		load();
	do
	{
		cout << "1.Adaugare (RETURNARE);" << endl
			<< "2.Stergere (CUMPARARE);" << endl
			<< "3.Modificare;" << endl
			<< "4.Afisare;" << endl
			<< "5.Incarcare din fisier;" << endl
			<< "6.Salvare;" << endl
			<< "7.Inchidere." << endl
			<< "Introduceti: ";
		cin >> op;
		switch (op)
		{
		default:
		{
			no_command(); break;
		}
		case '1':
		{
			add(); break;
		}
		case '2':
		{
			del(); break;
		}
		case '3':
		{
			mod(); break;
		}
		case '4':
		{
			print(); break;
		}
		case '5':
		{
			load(); break;
		}
		case '6':
		{
			save(); break;
		}
		case '7':
		{
			return;
		}
		}
	} while (op);
}