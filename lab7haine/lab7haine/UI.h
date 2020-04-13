#pragma once
#include "service.h"

class UI
{
	private:
		Service<Produs> service;
	public:
		UI();
		~UI();
		void load();
		void save();
		void add();
		void del();
		void mod();
		void print();
		void no_command();
		void show();
};
