#ifndef CONJ_TEXT_HH
#define CONJ_TEXT_HH

#include <string>
#include <map>
#include "Cita.hh"


class Cjt_cita {
	
	
private:
	
	
	// Tipus de modul:dades
	// Descripció del tipus: representa un conjunt de cites ordenades per 
	// referència
	
	map <string, Cita> cjt_cita;
	// La clau és un string que és la referència (ref) de la cita.
	// El valor és la resta d'informació de la cita.
	
	
	
public:
	
	//Modificadores
	
	bool afegir_cita(int x, int y, const Cjt_text& cjt_text);
	/* Pre: cert */
	/* Post: retorna cert si la cita no conté les mateixes frases
	   que una que ja existeix en el p.i., si cjt_text conté un text 
	   triat i si l'interval de frases és valid per aquest text. 
	   Altrament retorna fals. */
	
	bool eliminar_cita(string ref);
	/* Pre: cert */
	/* Post: si la referència (ref) existeix, retorna cert i elimina
	   l'element amb referencia = ref. Altrament retorna fals. */
	
	
	//Consultores
	int n_cites(Frase& autor);
	/* Pre: cert */
	/* Post: retorna el nombre de cites amb autor = autor*/
	
	bool info_cita(string ref);
	/* Pre: cert */
	/* Post: si la referència (ref) existeix, retorna cert, altrament 
	   retorna fals. */
	 
	
	//Lectura i Escriptura
	
	void cites_autor (Frase& autor); 
	/* Pre: autor no és buit. */
	/* Post: escriu pel canal estandard de sortida la següent informació
	   de les cites que compleixen cita.consultar_autor() = autor: 
	   Referencia (ref), cita.consultar_contingut(),
	   cita.consultar_autor() i cita.consultar_titol(). Ordenat per ref. */
	 
	void totes_cites();
	/* Pre: hi ha alguna cita guardada */
	/* Post: Ordeandes per referència mostra totes les cites 
	   emmagatzemades. Mostra: cita.consultar_contingut(), 
	   cita.consultar_autor() cita.consultar_titol() */ 
	 
	void cites(Cjt_text& cjt_text);
	/* Pre: Hi ha un text triat, aquest text triat està associat a 
	   una cita */
	/* Post: escriu pel canal estàndard de sortida, les cites (i info 
	   corresponent) associedes a l'últim text triat, ordeandes per ref. 
	   El contingut, l'autor i el titol del text d'on provenen. 
	   Es consulten mitjançant consultar_contingut, consultar_autor i 
	   consultar_titol.  */
	
	
	};
#endif

