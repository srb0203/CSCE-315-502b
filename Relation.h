#ifndef RELATION_H
#define RELATION_H
#include <iostream>
#include <vector>
#include "Attribute.h"
#include "iomanip"
using namespace std;
//--------------------------------------------------------------------
//Table class for reading in data
//Input data format:
//First: # of cars Then: # of attributes
//Header: -Attribute Title- -Attribute Title- -Attribute Title- ...etc
//Tuples: -Attribute- -Attribute- -Attribute- ...etc
//--------------------------------------------------------------------

class Relation{
  public:
    vector< Attribute > attr;
    string name;
    Relation() {}
    Relation(const string& name){
      Create(name);
    }
    void add_attr(const Attribute& a) {
      attr.push_back(a);
    }
    void add_attr(string nm, Type t) {
      add_attr(Attribute(t,nm));
    }
    Attribute& operator[](size_t col){
      return attr[col];
    }
    Attribute& getAttribute(int n)
    {
      return (*this)[n];
    }
    int getNumAttributes()
    {
      return attr.size();
    }
    vector<Cell> getRow(int n)
    {
      vector<Cell> tuple;
      for(int i = 0; i < attr.size(); i++)
      {
        tuple.push_back(getAttribute(i).cell[n]);
      }
      return tuple;
    }

    void read(string s);

    void Create(string rel_name){
      name = rel_name;
    }

    void Show() {
      vector<Cell> tuple;
      cout << "\n          ------------------------------------" << endl;
      cout << "                     DATABASE TABLE           " << endl;
      cout << "          ------------------------------------" << endl;
      for(int i = 0; i< attr.size(); i++) {
        cout << setw(15) << getAttribute(i).getName() << setw(15);
      }
      cout << endl;
      cout <<"          ------------------------------------" << endl;

      for(int r=0; r < attr[0].getLength(); ++r) {
        for(int c = 0; c< attr.size(); c++)
          cout << setw(15) << (*this)[c][r];
        cout << endl;
      }
    }

void Rename(string new_name, string old_name) {
  for(int i =0; i < attr.size(); i++) {
    if(old_name == attr[i].name) {
      attr[i].name = new_name;
    }
  }
}

    void Insert(const vector<Cell>& row) { 
      for(int c = 0; c< attr.size(); c++)
        (*this)[c].push_back(row[c]);
    }

    void Write() {
      cout << "Requires File I/O, will be implemented in the next part " << endl;
    }
};
#endif
