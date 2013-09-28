#ifndef DBAPP_H
#define DBAPP_H

#include <iostream>
#include <stdlib.h>
#include "Parser.h"

using namespace std;

class DBApp {
	Parser p;
	
	public:
		void CreateTable();
		void AddNewCar();
		void DeleteCar(string car_name, string table_name);
		void UpdateCar(string table_name);
		void ShowCarWithID(string table_name);
		void ShowTable(string tablename);
		void test();
		void AddCar(string table_name);
		void Exit();
		void Diff();
};

#endif
