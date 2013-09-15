#include <iostream>
#include "Relation.h"
#include "Database.h"
#include "Attribute.h"
#include "Token.h"

using namespace std;

Token_stream ts;
bool identifier(Token_stream& ts)
{
	string identifier_name = "";
	Token t = ts.get();
	if(t.kind == ' '){
		t = ts.get();
	}
	if(t.kind != 'a')
	{
		ts.putback(t);
		return false;
	}
	while(t.kind == 'a' || t.kind == '0')
	{
		identifier_name += t.value;
		t = ts.get();
	}
	if(t.kind == ' '){
		t = ts.get();
	}
	ts.putback(t);
	cout << "REL: " << identifier_name << endl;
	return true;
}
bool relation_name(Token_stream& ts)
{
	return identifier(ts);
}
bool expr(Token_stream& ts)
{
	return true;
}
bool atomic_expr(Token_stream& ts){
	return relation_name(ts) || expr(ts);
}
bool name_check(Token_stream& ts, string input){
	string comp = "";
	Token t = ts.get();
	if(t.kind == ' '){
		t = ts.get();
	}
	if(t.kind != 'a')
	{
		ts.putback(t);
		return false;
	}
	vector<Token> tt; //keeps track of tokens that are cycled through
	tt.push_back(t);
	while(t.kind == 'a'){
		comp += t.value;
		t = ts.get();	
		tt.push_back(t);
	}
	if(comp == input){
		cout << "CMD: " << input << endl;
		ts.putback(t);
		return true;
	}
	
	for(int i=tt.size()-1;i>-1;--i){
		ts.putback(tt[i]);
		//cout << ' ' << tt[i] << endl;
	}
	return false;
}

bool check_varchar(Token_stream& ts) {
Token t;
  const string varchar="VARCHAR";
for(size_t i=0;i<varchar.size();++i){
	t=ts.get();
	if(t.kind!='a' || varchar[i]!=t.value){
		ts << varchar.substr(0,i) << t;
		return false;
	}
}
t=ts.get();
if(t.kind!='('){
	ts << varchar << t;
return false;
}
    while(t.kind != ')') {
      t = ts.get();
      if(t.kind == '0') {
        string size = ""; 
        while(t.kind != ' ' && t.kind != ')') {
          size += t.value;
          t = ts.get();
        }		
        cout << size << endl;
		}
		else{
			ts << t;
			return false;
		}
	  }    
    return true;
}

bool check_column_name(Token_stream& ts) {
bool return_value = true;
Token t = ts.get();
if(t.kind == '(') {
	while(t.kind != ')') {
		t = ts.get();
			if(t.kind == 'a' || t.kind == '0') {
				string column_names = "";
				while(t.kind != ' ') {
					column_names += t.value;
					t = ts.get();
					if(t.kind == ')'){
						return false;
					}
					
			}
				if(!name_check(ts,"INTEGER") && !check_varchar(ts)){
					return false;
				}
				cout << column_names << endl;
				while(t.kind ==' ') ts >> t;
				if(t.kind!=',' && t.kind!=')'){
					return false;
				}
			}			
			
		}
		return return_value;
	}
	return false;
}
	



bool create(Token_stream& ts) {
	return name_check(ts, "CREATE") && name_check(ts,"TABLE") && relation_name(ts) && check_column_name(ts) && name_check(ts,"PRIMARY") && name_check(ts,"KEY") ;
}

bool insert(Token_stream& ts){
	return name_check(ts, "INSERT") && name_check(ts, "INTO") && relation_name(ts) && name_check(ts, "VALUES") && name_check(ts, "FROM");
}
bool show(Token_stream& ts){
	return name_check(ts, "SHOW") && atomic_expr(ts);
}
bool exit(Token_stream&ts){
	return name_check(ts, "EXIT");
}
bool write(Token_stream& ts){
	return name_check(ts, "WRITE") && relation_name(ts);
}
bool close(Token_stream& ts){
	return name_check(ts, "CLOSE") && relation_name(ts);
}
bool open(Token_stream& ts){
	return name_check(ts, "OPEN") && relation_name(ts);
}
bool command(Token_stream& ts)
{
	return open(ts) || close(ts) || write(ts) || exit(ts) || show(ts) || insert(ts) || create(ts);
}
bool query(Token_stream& ts)
{
	if(!relation_name(ts))
		return false;
	Token next = ts.get();
	if(next.kind != ':')
	{
		ts.putback(next);
		return false;
	}
	if(!expr(ts))
		return false;
	return true;
}
bool program(Token_stream& ts)
{
	return command(ts) || query(ts);
}
int main(){
  /*d.Create("Table1");
  d.AddColumn("Table1", Header("Str1", STRING));
  d.AddColumn("Table1", Header("Str2", STRING));
  d.AddColumn("Table1", Header("Str3", STRING));
  vector<Cell> cell;
  cell.push_back("1.1");
  cell.push_back("1.2");
  cell.push_back("1.3");
  d.Insert("Table1", cell);
  cell.clear();
  cell.push_back("1.4");
  cell.push_back("1.5");
  cell.push_back("1.6");
  d.Insert("Table1", cell);
  cell.clear();
  cell.push_back("1.7");
  cell.push_back("1.8");
  cell.push_back("1.9");
  d.Insert("Table1", cell);
  
  d.Create("Table2");
  d.AddColumn("Table2", Header("Str1", STRING));
  d.AddColumn("Table2", Header("Str2", STRING));
  d.AddColumn("Table2", Header("Str3", STRING));
  cell.clear();
  cell.push_back("2.1");
  cell.push_back("2.2");
  cell.push_back("2.3");
  d.Insert("Table2", cell);
  cell.clear();
  cell.push_back("2.4");
  cell.push_back("2.5");
  cell.push_back("2.6");
  d.Insert("Table2", cell);
  cell.clear();
  cell.push_back("2.7");
  cell.push_back("2.8");
  cell.push_back("2.9");
  d.Insert("Table2", cell);
  
  d.Create("Table3");
  d.AddColumn("Table3", Header("Str1", STRING));
  d.AddColumn("Table3", Header("Str2", STRING));
  d.AddColumn("Table3", Header("Str3", STRING));
  cell.clear();
  cell.push_back("2.1");
  cell.push_back("2.2");
  cell.push_back("2.3");
  d.Insert("Table3", cell);
  cell.clear();
  cell.push_back("3.4");
  cell.push_back("3.5");
  cell.push_back("3.6");
  d.Insert("Table3", cell);
  cell.clear();
  cell.push_back("2.7");
  cell.push_back("2.8");
  cell.push_back("2.9");
  d.Insert("Table3", cell);
  
  d.Show("Table3");
  d.Update("Table3", "Str2", "6", "Str3", "==", "2.9");
  d.Show("Table3");*/
  Token_stream ts;
  ts.ss.clear();
  ts.ss.str("");
  cout << "Input line: ";
  string line;
  getline(cin, line);
  ts.ss << line;
  bool valid = true;
  {
	Token t = ts.get();
	if(t.kind == ';')
		return 0;
	ts.putback(t);
	if(program(ts)) {
		cout << "Valid Syntax " << endl;
	}
	else 
		cout << "Invalid Syntax " << endl;
  }
  return 0;
}
