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
	/** @brief
		\pre cert
		\post retorna cert si la cita no conté les mateixes frases
		que una que ja existeix en el p.i., si cjt_text conté un text 
		triat i si l'interval de frases és valid per aquest text. 
		Altrament retorna fals.
	*/
	
	
	bool eliminar_cita(string ref);
	/** @brief
		\pre cert 
		\post si la referència (ref) existeix, retorna cert i elimina 
		l'element amb referència = ref. Altrament retorna fals.
	*/
	
	//Consultores
	int n_cites(Frase& autor);
	/** @brief
		\pre cert
		\post retorna el nombre de cites amb autor = autor
	*/
	
	bool info_cita(string ref);
	/** @brief
		\pre cert
		\post si la referencia (ref) existeix, retorna cert, altrament
		retorna fals.
	*/
	
	//Lectura i Escriptura
	
	void cites_autor (Frase& autor); 
	/** @brief
		\pre autor no és buit
		\post escriu pel canal estàndard de sortida la següent informació
		de les cites que compleixen cita.consultar_autor() = autor: 
		Referencia (ref), cita.consultar_contingut(),
		cita.consultar_autor() i cita.consultar_titol(). Ordenat per ref.
	*/
	 
	void totes_cites();
	/** @brief
		\pre hi ha alguna cita guardada
		\post Ordeandes per referència mostra totes les cites 
		emmagatzemades. Mostra: cita.consultar_contingut(), 
		cita.consultar_autor() cita.consultar_titol() 
	*/ 
	 
	void cites(Cjt_text& cjt_text);
	/** @brief
		\pre Hi ha un text triat, aquest text triat està associat a una
		cita
		\post escriu pel pel canal estàndard de sortida, les cites (i info 
		corresponent) associedes a l'últim text triat, ordeandes per ref. 
		El contingut, l'autor i el titol del text d'on provenen. 
		Es consulten mitjançant consultar_contingut, consultar_autor i 
		consultar_titol.  */
	
	
	};
#endif
