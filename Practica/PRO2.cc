/** @mainpage Gestor de textos i cites
	Aquesta és una aplicació que permet manipular textos i cites de diverses maneres.

*/

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
	bool e = false;
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
				Text titol;
				titol.llegir(iss);
				cin.ignore(256, '"');
				getline(cin, op, '"');         //op conté un string de l'autor sense cometes
				iss.str(op);
				Frase autor;
				autor.llegir(iss);
				getline(cin, op);              //op conté el contingut del text
				Text contingut;
				while(op != "****"){
					iss.str(op);
					Text linia;
					linia.llegir(iss);
					contingut.afegir_salt(linia);
					getline(cin, op);
				}
				e = cjt_text.afegir_text(autor, titol, contingut);
			}
			else if(op == "cita"){
				int x,y;
				iss >> x >> y;
				e = cjt_cita.afegir_cita(x,y, cjt_text);
			}
		}
		else if(op == "triar"){
			cin.ignore(256, '{');
			getline(cin, op, '}');              //op conté un string de les paraules a buscar sense brackets
			iss.str(op);
			Frase paraules;
			paraules.llegir(iss);
			e = cjt_text.triar_text(paraules);
		}
		else if(op == "eliminar"){
			getline(cin, op);                   //op = "text"
			e = cjt_text.eliminar_text();
		}
		else if(op == "substitueix"){
			string paraula1, paraula2;
			cin.ignore(256, '"');
			getline(cin, paraula1, '"');
			cin.ignore(256, '"');
			getline(cin, paraula2, '"');
			e = cjt_text.substitueix(paraula1, paraula2);
		}
		else if(op == "textos"){
			cin.ignore(256, '"');
			getline(cin, op, '"');
			iss.str(op);
			Frase autor;
			autor.llegir(iss);
			cjt_text.textos_autor(autor);
			cin.ignore(256, '?')
		}
		else if(op == "tots"){
			getline(cin, op, '?');
			iss.str(op);
			iss >> op;
			if(op == "textos") cjt_text.textos_tots();
			else cjt_text.autors_tots();
		}
		else if(op == "info"){
			getline(cin, op, '"');
			iss.str(op);
			ws(iss);
			char p = iss.peek();
			if(p == '?') e = cjt_text.info(cjt_cita);
			else{
				getline(cin, op, '"');
				e = cjt_cita.info_cita(op);
			}
		}
		else if(op == "autor"){
			cin.ignore(256, '?');
			e = cjt_text.autor();
		}
		else if(op == "contingut"){
			cin.ignore(256, '?');
			e = cjt_text.contingut();
		}
		else if(op == "frases"){
			getline(cin, op, '?');
			iss.str(op);
			char p = iss.peek;
			if(p >= '0' and p <= '9'){
				int x,y;
				iss >> x >> y;
				e = cjt_text.frases(x,y);
			}
			else if(p == '"'){
				cin.ignore(256, '"');
				getline(cin, op, '"');
				iss.str(op);
				Frase paraules;
				paraules.llegir(iss);
				e = consecutives(paraules);
			}
			else{
				getline(cin, op, '?');
				iss.str(op);
				e = evaluar(iss);
			}
		}
		else if(op == "nombre"){
			cin.ignore(4);
			getline(cin, op, '?');
			iss.str(op);
			iss >> op;
			e = cjt_text.has_selec();
			if(op == "frases" and not e){
				cout << cjt_text.selec_n_frases();
			}
			else if(not e){
				cout << cjt_text.selec_n_paraules();
			}
		}
		else if(op == "cites"){
			getline(cin, op, '"');
			iss.str(op);
			char p = iss.peek();
			if(p == 'a'){
				getline(cin, op, '"');
				Frase autor;
				autor.llegir(iss);
				cjt_cita.cites_autor(autor);
				cin.ignore(256, '?');
			}
			else cjt_cita.cites(cjt_text);
		}
		else if(op == "totes"){
			cjt_cita.totes_cites();
		}
		if(e) cout << "error" << endl;
	}
}
