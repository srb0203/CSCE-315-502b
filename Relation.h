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
  private:
    vector< vector<string> > tuples;
  public:
    vector< Attribute > attr;
    Relation() {}
    void add_attr(Attribute& a) {
      attr.push_back(a);
    }

    Attribute getAttribute(int n)
    {
      return attr[n];
    }
    int getNumAttributes()
    {
      return attr.size();
    }
    vector<Cell> getTuple(int n)
    {
      vector<Cell> tuple;
      for(int i = 0; i < attr.size(); i++)
      {
        tuple.push_back(getAttribute(i).cell[n]);
      }
      return tuple;
    }

    void read(string s);

    void dis_table() {
      vector<Cell> tuple;
      Attribute intsecho = getAttribute(0);
      Attribute charsecho = getAttribute(1);
      Attribute char2echo = getAttribute(2);
      cout << "\n--------------------------------" << endl;
      cout <<"         DATABASE TABLE           " << endl;
      cout <<"--------------------------------" << endl;
      cout << intsecho.getName() << " " << charsecho.getName() << " " << char2echo.getName() << endl;
      cout <<"--------------------------------" << endl;
      for(int i=0; i<attr.size()/3; ++i) {
        tuple = getTuple(i);
        cout << tuple[0].value.i << setw(12) << tuple[1].value.c << setw(12) << tuple[2].value.c2 << endl;
      }
    }

    void Insert(char s1, int i1 , char s2) { 
      Attribute ints(INT, "Integers");
      Attribute chars(CHAR, "Characters1");
      Attribute chars2(CHAR, "Characters2");
      Value v1, v2 , v3;
      v1.i = i1;
      v2.c = s1;
      v3.c2 = s2;
      ints.push_back(v1);
      chars.push_back(v2);
      chars2.push_back(v3);

      add_attr(ints);
      add_attr(chars);
      add_attr(chars2);
    }
};
#endif
