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

    void Create(string name, int year , string model) {
          }

    void dis_table() {
      vector<Cell> tuple;
      Attribute intsecho = getAttribute(0);
      Attribute charsecho = getAttribute(1);
      Attribute char2echo = getAttribute(2);
      cout << "\n--------------------------------" << endl;
      cout <<"         DATABASE TABLE           " << endl;
      cout <<"--------------------------------" << endl;
      cout << intsecho.getName() << setw(12) << charsecho.getName() << setw(13) << char2echo.getName() << endl;
      cout <<"--------------------------------" << endl;
      int s = 0;
      int s2 = 1;
      int s3 = 2;

      for(int i=0; i < attr.size()/3; ++i) {
        tuple = getTuple(0);
        cout << tuple[s].value.i << setw(12) << tuple[s2].value.c << setw(12) << tuple[s3].value.c << endl;
        s = s+3;
        s2 = s2+3;
        s3 = s3+3;
      }
    }

    void Insert(char* s1, int i1 , char* s2) { 
      Attribute ints(INT, "Year");
        Attribute chars2(STRING, "Model");
        Attribute chars(STRING, "Car");
      Value v1, v2 , v3;
      v1.i = i1;
      v2.c = s1;
      v3.c = s2;
      ints.push_back(v1);
      chars.push_back(v2);
      chars2.push_back(v3);

      add_attr(ints);
      add_attr(chars);
      add_attr(chars2);
    }

    void Write() {
      cout << "Requires File I/O, will be implemented in the next part " << endl;
    }
};
#endif
