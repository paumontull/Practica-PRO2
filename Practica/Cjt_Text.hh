#ifndef CONJ_TEXT_HH
#define CONJ_TEXT_HH

#include "Text.hh"
#include "Cjt_Cites.hh"
#include <map>

struct i_text{
	Frase autor;
	Text titol;
	
	bool operator<(const i_text& i) const{
		if(autor != i.autor) return autor < i.autor;
		else return titol < i.titol;
	}
};

class Cjt_text{
	
private:
	
	// Tipus de modul: dades
	// Descripcio del tipus: representa un conjunt de textos amb autor
	// i títol i ordenat lexicogràficament primer per autor i després
	// per títol
	
	map<i_text, Text> cjt_text;
	map<i_text, Text>::const_iterator selec_text = cjt_text;
	bool has_selec = false;
	
	bool buscar_text(string paraula);
	/* Pre: cert */
	/* Post: si el p.i. conté un string paraula en i_text.autor,
	   i_text.titol o en el seu valor associat retorna cert. Altrament
	   retorna fals */
	
public:
	//Constructora
	
	Cjt_text();
	/* Pre: cert */
	/* Post: el resultat és un conjunt buit */
	
	//Destructora
	
	~Cjt_text();
	
	//Modificadores
	
	bool afegir_text(Frase& autor, Text& titol, Text& contingut);
	/* Pre: autor, titol i contingut no són buits */
	/* Post: si el p.i. no conté cap element amb i_text.autor = autor i
	   i_text.titol = titol retorna cert i n'afegeix un amb aquest
	   i_text com a clau i valor associat = contingut. Altrament 
	   retorna fals */
	
	bool triar_text(Frase& paraules);
	/* Pre: paraules no és buit */
	/* Post: si el p.i. conté algun element que contingui els strings de
	   paraules en i_text.autor, i_text.titol o en el seu valor
	   associat retorna cert, has_selec = true i selec_text apunta
	   aquest element del p.i.. Altrament retorna fals */
	
	bool eliminar_text();
	/* Pre: cert */
	/* Post: si has_selec = true retorna cert, s'elimina l'element apuntat 
	   per selec_text i has_selec = false. Altrament retorna fals */
	
	bool substitueix(paraula1, paraula2);
	/* Pre: string1 i string2 no són buits */
	/* Post: si has_selec = true retorna cert i se substitueixen els
	   valors de tots els strings = paraula1 del valor associat a l'
	   element apuntat per selec_text per paraula2. Altrament retorna 
	   fals */
	 
	//Consultores
	
	int selec_n_frases();
	/* Pre: has_selec = true; */
	/* Post: retorna el nombre de frases del valor associat a l'element
	   apuntat per selec_text */
	
	int selec_n_paraules();
	/* Pre: has_selec = true; */
	/* Post: retorna el nombre de paraules del valor associat a l'element
	   apuntat per selec_text */
	
	Text selec_frases(int x, int y);
	/* Pre: l'interval [x,y] és vàlid per al text seleccionat */
	/* Post: retorna un objecte Text amb les  */
	
	//Lectura i escriptura
	
	void textos_autor(Frase& autor);
	/* Pre: autor no és buit */
	/* Post: s'han escrit al canal estandard de sortida els valors 
	   i_text.titol dels elements del p.i. que tenen i_text.autor = autor 
	   en ordre */
	
	void textos_tots();
	/* Pre: cert */
	/* Post: s'han escrit al canal estandard de sortida els valors 
	   i_text.titol de tots els elements del p.i. en ordre */
	
	void autors_tots();
	/* Pre: cert */
	/* Post: s'han escrit al canal estandard de sortida els diferents
	   valors i_text.autor dels elements del p.i. seguits del nombre de
	   textos, frases i paraules associats a cada autor de tots els
	   elements del p.i. en ordre. */
	
	bool info(Cjt_Cites cjt_cites);
	/* Pre: cert */
	/* Post: si has_selec = true retorna cert i escriu al canal estandard
	   de sortida els valors i_text.autor, i_text.titol, el nombre de
	   frases, paraules i cites del text seleccionat */
	
	bool autor();
	/* Pre: cert */
	/* Post: si has_selec = true retorna true i escriu al canal estandard
	   de sortida el valor i_text.autor del text seleccionat. Altrament
	   retorna fals */
	
	bool contingut();
	/* Pre: cert */
	/* Post: si has_selec = true retorna true i escriu al canal estandard
	   de sortida el contingut del text seleccionat separat en frases 
	   numerades a partir de 1. Altrament retorna fals */
	
	bool frases(int x, int y);
	/* Pre: cert */
	/* Post: si has_selec = true i [x,y] és un interval vàlid per al text
	   seleccionat retorna cert i escriu al canal estandard de sortida les
	   frases entre la x-èsima i la y-èsima del text seleccionat.
	   Altrament retorna fals */
	
	bool frequencies();
	/* Pre: cert */
	/* Post: si has_selec = true retorna cert i escriu al canal estandard
	   de sortida el contingut del text seleccionat ordenat en funció de
	   la freqüencia amb que apareix cada paraula, la seva llargada i
	   després alfabèticament. */
	bool evaluar(istringstream iss);
	/* Pre: iss conté una expressió booleana de paraules */
	/* Post: si has_selec = true retorna cert i escriu al canal estandard
	   de sortida les frases que compleixen l'espressió del text triat.
	   Altrament retorna fals */
	
	bool consecutives(Frase& paraules);
	/* Pre: paraules no és buit */
	/* Post: si has_selec = true retorna cert i escriu al canal estandard
	   de sortida les frases on hi apareix la seqüència paraules.
	   Altrament retorna fals */
};
#endif
