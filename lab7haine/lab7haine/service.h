#pragma once
#include "repo.h"

template <class T> class Service
{
private:
	RepoFile<T> repo;
public:
	Service() 
	{
	}
	~Service() 
	{
	}
	void load(char* numeFis)
	{
		repo.load(numeFis);
	}
	void save()
	{
		if (repo.is_file())
			repo.save();
	}
	void add(const char* nume, const int pret, const int bucati)
	{
		T ent(nume, pret, bucati);
		repo.add(ent);
	}
	void del(const char* nume)
	{
		T ent(repo.find_by_title(nume));
		if (ent != def)
			repo.del(ent);
	}
	void mod(const char* nume, const char* nume_nou, const int pret_nou, const int bucati_nou)
	{
		T ent(repo.find_by_title(nume));
		if (ent != def)
		{
			T newEnt(nume_nou, pret_nou, bucati_nou);
			if (strcmp(newEnt.getNume(), "-1") == 0)
				newEnt.setNume(ent.getNume());
			if (newEnt.getPret() == -1)
				newEnt.setPret(ent.getPret());
			if (newEnt.getBucati() == -1)
				newEnt.setBucati(ent.getBucati());
			repo.mod(ent, newEnt);
		}
	}
	set<T>& getAll() 
	{ 
		return repo.getAll(); 
	}
	int size() 
	{ 
		return repo.size(); 
	}
};