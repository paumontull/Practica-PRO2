#include <sstream>
#include <iostream>
#include <string>
#include <Cjt_Text.hh>
#include <Cjt_Cita.hh>
using namespace std;

int main(){
	//Cridar constructora de Cjt_text i Cjt_cita
	Cjt_text cjt_text;
	Cjt_cita cjt_cita;
	string op;
	istringstream iss;
	while(cin >> op and op != "sortir"){
		if(op == "afegir"){
			getline(cin, op, '"');
			iss.str(op);
			iss >> op;
			if(op == "text"){
				getline(cin, op, '"');         //op conté un string d'el títol sense cometes
				iss.str(op);
				vector<Frase> titol = llegir_vec_frases(iss);
				cin.ignore(256, '"');
				getline(cin, op, '"');         //op conté un string de l'autor sense cometes
				iss.str(op);
				Frase autor = llegir_frase(iss);
				getline(cin, op);              //op conté el contingut del text
				iss.str(op);
				vector<Frase> contingut = llegir_vec_frases(iss);
				cin >> op;                     //op = "****"
				Text text(titol, autor, contingut);
				cjt_text.afegir_text(text);
			}
			else if(op == "cita"){
				int x,y;
				iss >> x >> y;
				cjt_cita.afegir_cita(x,y);
			}
		}
		else if(op == "triar"){
			cin.ignore(256, '{');
			getline(cin, op, '}');              //op conté un string de les paraules a buscar sense brackets
			iss.str(op)
			Frase paraules = llegir_frase(iss);
			cjt_text.triar_text(paraules);
		}
		else if(op == "eliminar"){
			getline(cin, op);                   //op = "text"
			cjt_text.eliminar_text();
		}
		else if(op == "substitueix"){
			string paraula1, paraula2;
			cin.ignore(256, '"');
			getline(cin, paraula1, '"');
			cin.ignore(256, '"');
			getline(cin, paraula2, '"');
			cjt_text.substituir_paraula(paraula1, paraula2);
		}
	}
}
