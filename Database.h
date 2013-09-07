#include <iostream>
#include <map>
#include "Relation.h"

using namespace std;

class Database {
  public:
    typedef map<string,Relation> Table;
    vector<Relation> relation;
  Database(){};
    Table table;
    void Selection(Relation name, string attr_name);
    void Create(string rel_name);
    void AddColumn(const string& rel_name, const Header& h);
    void Insert(string rel_name, const vector<Cell>& row);
    void Write();
    void Show(string rel_name);
    void Rename(string rel_name,string new_name, string old_name);
    Relation& operator[](const string& s);
};
