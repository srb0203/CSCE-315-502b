#include <iostream>
#include <stdlib.h>

using namespace std;

class DBApp {
	//parser p;
	
	public:
		void CreateTable();
		void AddNewCar();
		void DeleteCar(string car_name,string table_name);
		void UpdateCar();
		void SelectCar();
		void ShowTable(string tablename);
};
