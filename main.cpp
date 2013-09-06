#include <iostream>
#include "Relation.h"
#include "Database.h"
using namespace std;

int main(){
  Database d;

  Relation r;
  r.Insert("Audi", 2013,"R8");
  r.Insert("Chevrolet", 2011,"Cobalt");
  r.Insert("Mercedes",2010,"Benz");
  r.Insert("Dodge",2009,"Charger");
  r.Insert("Nissan", 2006 , "Altima");

  //r.Insert("add",5);
  //r.Insert("sub",6);

  cout << "\nNumber of attributes " << r.getNumAttributes() << endl;

  r.dis_table();



  //d.Show();
  return 0;
}
