#ifndef CONJ_TEXT_HH
#define CONJ_TEXT_HH

#include "Text.hh"
#include <map>

struct info_text{
	Frase autor;
	Text titol;
	
	bool operator<(const info_text& i) const{
		if(autor != i.autor) return autor < i.autor;
		else return titol < i.titol;
	}
};

class Cjt_text{

private:

	// Tipus de modul: dades
	// Descripcio del tipus: representa un conjunt de textos
	
	map<info_text, Text> cjt_text;
	map<info_text, Text>::const_iterator selec_text = cjt_text.begin();
	bool has_selec = false;
	
	bool buscar_text
	
public:
	//Modificadores
	
	bool afegir_text(Frase& autor, Text& titol, Text& contingut);
	/* Pre: autor, titol i contingut no són buits */
	/* Post: si el p.i. no conté cap element amb info_text.autor = autor i
	   info_text.titol = titol, retorna cert i n'afegeix un amb aquest
	   info_text com a clau i valor associat = contingut. Altrament 
	   retorna fals */
	
	bool triar_text(Frase& paraules);
	/* Pre: paraules no és buit */
	/* Post: si el p.i. conté algun */
	
	bool eliminar_text();
	/* Pre: */
	/* Post: */
	
	
};
#endif
