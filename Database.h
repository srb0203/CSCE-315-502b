#include <iostream>
#include "Relation.h"

using namespace std;

class Database {
  public:
  Database(){};
    vector<Relation> relation;

    void Create();
    void Insert();
    void Write();
    void Show();
};
