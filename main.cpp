#include <iostream>
#include "Relation.h"
#include "Database.h"
using namespace std;

int main(){
  Database d;

  Relation r;
  r.Insert('q', 58,'a');
  r.Insert('f', 48,'t');
  r.Insert('a',67,'b');
  r.Insert('z',54,'c'); 
  cout << "number of attributes " << r.getNumAttributes() << endl;

  r.dis_table();



  d.Show();
  return 0;
}
