#include "Table.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>

using namespace std;
vector<string> v_tuples;
int cars; //#of cars
int num_attr;//#of attributes

//Table function definitions
void Table::read(string s){
  cout << "opening file " << endl;
  ifstream ifs(s.c_str());
    string pusher;//string passing the values
  ifs >> cars;
  ifs >> num_attr;
  for (int i = 0; i<num_attr; ++i){//initialization of attr's first level of vectors
    vector<string> s; //this makes it have the same amount of string vectors as attributes in our input file
    attr.push_back(s);
  }
  for(int i = 0; i<cars+1; ++i){
    //a tuple vector to push back as we go
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
  cout << "        --------------------------------------------------------" << endl;
  for(int i = 0; i<cars+1; ++i){
    for(int j = 0; j<num_attr; ++j){
      cout << setw(15) << attr[j][i] << " ";
    }
    cout << endl;
  }
  cout << endl;
}

void Table::insert_elements() {
  string tuple;
  cout << "Enter tuple " << endl;
  for(int i =0; i<4 ;i++) {
    cin >> tuple;
    attr[i].push_back(tuple);
  }
  cars++;
}
