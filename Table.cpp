#include "Table.h"
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
//Table function definitions
void Table::read(string s){
	ifstream ifs(s.c_str());
	int cars; //#of cars
	int num_attr;//#of attributes
	string pusher;//string passing the values
	ifs >> cars;
	ifs >> num_attr;
	for (int i = 0; i<num_attr; ++i){//initialization of attr's first level of vectors
		vector<string> s;                //this makes it have the same amount of string vectors as attributes in our input file
		attr.push_back(s);
	}
	for(int i = 0; i<cars+1; ++i){
		vector<string> v_tuples; //a tuple vector to push back as we go
		for(int j = 0; j<num_attr; ++j){
			ifs >> pusher;
			attr[j].push_back(pusher);//attr takes in the attribute
			string s = attr[j][i];//setting s to the string the tuple will take
			v_tuples.push_back(s);
		}
		tuples.push_back(v_tuples);//pushback a portion of the tuples vector of vectors
	}
	ifs.close();
}
void Table::dis_table(){
	for(int i = 0; i<6; ++i){
		for(int j = 0; j<4; ++j){
			cout << attr[j][i] << " ";
		}
		cout << endl;
	}
}
