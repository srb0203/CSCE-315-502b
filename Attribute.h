#ifndef ATTRIBUTE_H
#define ATTRIBUTE_H
#include <iostream>
#include <vector>

using namespace std;

enum Type {INT, STRING};
union Value {
  int i;
  char* c;
};
struct Cell {
  Type type;
  Value value;
};

class Attribute{
  public:
    string name;
  public:
    Type type;
    Attribute () {};
    Attribute(Type t, string n) : type(t), name(n) {};
    vector<Cell> cell;
    void push_back(Value& v)
    {
      Cell c;
      c.type = type;
      c.value = v;
      cell.push_back(c);
    }
    vector<Cell> getCells(){
      return cell;
    }
    string getName()
    {
      return name;
    }
    //string getName();
};
#endif
