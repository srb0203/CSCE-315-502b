#include <iostream>
#include "Relation.h"
#include "Database.h"
#include "Attribute.h"

using namespace std;

int main(){
  Database d;
  d.Create("Cars");
  d.AddColumn("Cars",Header("Make",STRING));
  d.AddColumn("Cars",Header("Year",INT));
  d.AddColumn("Cars",Header("Model",STRING));
  vector<Cell> cell;
  cell.push_back("Audi");
  cell.push_back("2013");
  cell.push_back("R8");
  d.Insert("Cars", cell);
  cell.clear();
  cell.push_back("Audi2");
  cell.push_back("2013222222");
  cell.push_back("R8222222");
  d.Insert("Cars", cell);

  d.Create("LOL");
  d.AddColumn("LOL",Header("Hello",STRING));
  d.AddColumn("LOL",Header("Bello",STRING));
  d.AddColumn("LOL",Header("haha",STRING));
  
  vector<Cell> cell1;
  vector<Cell> cell2;
  cell1.push_back("lol");
  cell1.push_back("lol2");
  cell1.push_back("lol3");
  cell2.push_back("Audi");
  cell2.push_back("2013");
  cell2.push_back("R0");
  d.Insert("LOL",cell2);
  d.Insert("LOL",cell1);

  d.Show("Cars");
  d.Rename("Cars","sfsd","Model");
  //d.Delete_attr("Cars","Audi");
  d.Delete_attr("Cars","Joinks");
  d.Delete_attr("haha","Audi");
  d.Show("Cars");
  d.Show("LOL");
  d.Union("Cars","LOL");
  //d.AddColumn("CarsLOLUnion",Header("Union",STRING));
  //d.Show("CarsLOLUnion");
  d.Show("kjlk");
  d.Show("Cars");
  d.Write("Cars");
  return 0;
}
