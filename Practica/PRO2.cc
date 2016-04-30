#include <sstream>
#include <iostream>
#include <string>
using namespace std;

int main(){
	string comanda;
	getline(cin, comanda);
	while(comanda != "sortir"){
		istringstream iss(comanda);
		string op;
		iss >> op;
		if(op == "afegir"){
			iss >> op;
			if(op == "text"){
				
			}
		}
		else if(op == ){
			
		}
	}
}
