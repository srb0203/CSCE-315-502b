#include "DBApp.h"

void DBApp:: CreateTable() {
	p.parse("CREATE TABLE cars (carid INTEGER, name VARCHAR(1), model VARCHAR(1), year INTEGER, engine_type INTEGER) PRIMARY KEY (carid);");
	p.parse("INSERT INTO cars VALUES FROM (5,\"Joe\", \"cat\", 4,6);");
	p.parse("CREATE TABLE hello (carid INTEGER, name VARCHAR(1), model VARCHAR(1), year INTEGER, engine_type INTEGER) PRIMARY KEY (carid);");
	p.parse("INSERT INTO cars VALUES FROM (7,\"bob\", \"the builder\", 46,67);");
}

void DBApp:: UpdateCar(string table_name) {
	//cout << "\nUPDATE "+table_name+" SET WHERE (name == "+car_name+");" << endl;
	int n;
	cout << "Choose the information about the  car that you would like to update " << endl;
	cout << "1. Name of the car " << endl;
	cout << "2. Id of the car " << endl;
	cout << "3. Model of the car " << endl;
	cout << "4. Year of the car " << endl;
	cout << "5. Engine type of the car " << endl;
	cin >> n;
	
	if(n == 1) {
		string new_name, old_name;
		cout << "Enter old name of the car " << endl;
		cin >> old_name;
		cout << "Enter new name of the car " << endl;
		cin >> new_name;
		p.parse("UPDATE "+table_name+" SET name = "+new_name+" WHERE name < "+old_name+";");
	}	
	return;
}
void DBApp:: ShowTable(string tablename) {
	p.parse("SHOW " + tablename + ";");
	//parser.parse("SHOW " + tablename+";");
	return;
}

void DBApp:: DeleteCar(string car_name, string table_name) {
	//cout << "\nDELETE FROM "+table_name+" WHERE (name == "+car_name+");" << endl;
	p.parse("DELETE FROM "+table_name+" WHERE (name == "+car_name+");");
	return;
}

void DBApp:: ShowCustomers(string table_name) {
	p.parse("Customers <- project (carid,name) cars;");
	return;
}

void DBApp:: test() {
	//p.parse("UPDATE cars SET name = 0 WHERE name == Joe;");
	p.parse("DELETE FROM cars WHERE (name == Joe);");
}
	
int main() {
int x;


 DBApp d;
 d.CreateTable();
 d.test();
// d.CreateTable();
 // while(true) {
		// cout << "\nThis is a simple Database Application " << endl;
		// cout << "\nPlease choose what you would like to do" << endl;

		// cout << "1. Add Cars the to the warehouse " << endl;
		// cout << "2. Delete a Car from the warehouse " << endl;
		// cout << "3. Show from the warehouse " << endl;
		// cout << "4. Update information about a Car in the warehouse " << endl;
		// cout << "5. Show table of cars " << endl;
		// cout << "6. Exit " << endl;
		// cin >> x;
		
		// if(x == 2) {
			// string car_name,table_name;
			// cout <<"Enter the name of the table from which the car needs to be deleted " << endl;
			// cin >> table_name;
			// cout << "Enter the name of the car to be deleted " << endl;
			// cin >> car_name;
			// d.DeleteCar(car_name,table_name);
			// cout << "\n....Returning to the main menu " << endl;
		// }
		
		// if(x == 3) {
			// string table_name;
			// cout << "Enter the name of the table you want to select from " << endl;
			// cin >> table_name;
			// d.ShowCustomers(table_name);
		// }
		
		// if(x == 4) {
			// string table_name;
			// cout << "Enter the name of the table you wnat to update " << endl;
			// cin >> table_name;
			// d.UpdateCar(table_name);
		// }
		
		// if(x == 5) {
			// string name;
			// cout << "Enter the name of the table to show " << endl;
			// cin >> name;
			// d.ShowTable(name);
			// cout << "\n....Returning to the main menu " << endl;
		// }			
		
		// if(x == 6) {
			// cout << " \n         Good Bye :) " << endl;
			// exit(0);
			//parser.parse("EXIT");
		// }	
		// else {
			// cout << "Invalid Input, Please choose from the list. " << endl;
		// }
	// }
}
