#include <string>
#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

class Token
{
public:
	char kind; // what kind of token
	int value;
	Token(char ch = '~') : kind(ch), value(0) {}
	Token(char ch, int val) : kind(ch), value(val) {}
	
};

class Token_stream
{
private:
	vector<Token> buffer; // here is where we keep a Token put back using putback()
public: 
	Token_stream() {}
	Token get(); // get a Token
	Token peek();
	void putback(Token t); // put a Token back
	Token_stream& operator<<(const string& s);
	Token_stream& operator<<(const Token& t);
	Token_stream& operator>>(Token& t);
	stringstream ss;
};

/*
	Type					Kind	
	string literal			"
	alpha					a
	digit					0
	assignment				:
	op						=
	conjunction				&
	condition				|
	,						commas are ommitted
	other					the character itself
*/

void Token_stream::putback(Token t)
{
    buffer.push_back(t);       // copy t to buffer
}

//------------------------------------------------------------------------------

Token Token_stream::get()
{
    if(buffer.size()) // do we already have a Token ready?
	{
        // remove token from buffer
		Token temp = buffer.back();
		buffer.pop_back();
		return temp;
    }

    char ch;
    ss >> noskipws >> ch; 

    switch (ch)
	{
		case ' ':
			return Token(ch);
		case ',':
			return Token(ch,',');
		case '(': case ')': case '+': case '-': case '*': case ';': 
			return Token(ch);        // let each character represent itself
		case'[':case']':
			return get();
		case '0': case '1': case '2': case '3': case '4':
		case '5': case '6': case '7': case '8': case '9':
			{
				return Token('0', ch);   // let '0' represent "digit"
			}
			break;
		case 'a': case 'b': case 'c': case 'd': case 'e': case 'f': case 'g': case 'h': case 'i': case 'j':
		case 'k': case 'l': case 'm': case 'n': case 'o': case 'p': case 'q': case 'r': case 's': case 't':
		case 'u': case 'v': case 'w': case 'x': case 'y': case 'z':
		case 'A': case 'B': case 'C': case 'D': case 'E': case 'F': case 'G': case 'H': case 'I': case 'J':
		case 'K': case 'L': case 'M': case 'N': case 'O': case 'P': case 'Q': case 'R': case 'S': case 'T':
		case 'U': case 'V': case 'W': case 'X': case 'Y': case 'Z':
		case '_':
			{
				return Token('a', ch);   // let 'a' represent "char"
			}
			break;
		case '>': case '!': case '=':
			{
				ss.putback(ch);         // put char back into the input stream
				string val;
				ss >> val;              // read a string
				if(val == "<")
					return Token('=', 'l');
				return Token('=', ch); // let '=' represent "comparison"
			}
			break;
		case '<':
			{
				ss.putback(ch);         // put char back into the input stream
				string val;
				ss >> val;              // read a string
				if(val == "<-")
					return Token(':');   // let ':' represent "assignment"
				else if(val == "<")
					return Token('=', 'g');
				else if(val == "<=")
					return Token('=', ch); // let '=' represent "op"
			}
			break;
		case '&': case '|':
			{
				ss.putback(ch);         // put char back into the input stream
				string val;
				ss >> val;              // read a string
				if(val == "||")
					return Token('|'); // let '|' represent "condition"
				else if(val == "&&")
					return Token('&'); // let '&' represent "conjunction"
			}
			break;
		case '"':
			{
				return Token('"');
			}
			break;
		default:
			cerr << "Bad token" << endl;
			break;
    }
}	
	Token Token_stream::peek(){
		Token t=get();
		putback(t);
		return t;
	}
	Token_stream& Token_stream::operator<<(const string& s){
		for(size_t i=0;i<s.size();++i){
			putback(Token('a',s[i]));
		}
		return *this;
	}
		Token_stream& Token_stream::operator<<(const Token& t){
			putback(t);
		return *this;
	}
	Token_stream& Token_stream::operator>>(Token& t){
		t=get();
		return *this;
	}
	ostream& operator<<(ostream& os, const Token& t){
		return os << '{' << t.kind << ":" << char(t.value) << '}';
	}
