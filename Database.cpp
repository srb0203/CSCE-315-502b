#include "Database.h"
void Database:: Selection(Relation name, string attr_name) {

}

void Database:: Rename(string rel_name,string new_name, string old_name) {
  for (int i = 0; i < relation.size(); ++i){
    if (rel_name == relation[i].name){
      relation[i].Rename(new_name,old_name);
      return;
    }
  }
  cerr << "I did not find anything called "<< rel_name << endl;
}

void Database::AddColumn(const string& rel_name, const Header& h){
  for (int i = 0; i < relation.size(); ++i){
    if (rel_name == relation[i].name){
      relation[i].add_attr(h.first,h.second);
      return;
    }
  }
  cerr << "I did not find anything called "<< rel_name << endl;
}

void Database:: Insert(string rel_name, const vector<Cell>& row) {
  for (int i = 0; i < relation.size(); ++i){
    if (rel_name == relation[i].name){
      relation[i].Insert(row);
      return;
    }
  }
  cerr << "I did not find anything called "<< rel_name << endl;
}

void Database:: Create(string rel_name) {
  relation.push_back(Relation(rel_name));
}

void Database:: Write() {
}

void Database:: Show(string rel_name) {
  for (int i = 0; i < relation.size(); ++i){
    if (rel_name == relation[i].name){
      relation[i].Show();
      return;
    }
  }
  cerr << "I did not find anything called "<< rel_name << endl;
}
Relation& Database::operator[](const string& s){
  return table[s]; 
}
