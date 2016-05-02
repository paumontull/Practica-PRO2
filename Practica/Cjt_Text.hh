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
	/** @brief 
		\pre cert
		\post si el p.i. conté un string paraula en i_text.autor,
		i_text.titol o en el seu valor associat retorna cert. Altrament
		retorna fals 
	*/
	
public:
	//Constructora
	
	Cjt_text();
	/** @brief  cre un conjunt buit
		\pre cert 
		\post el resultat és un conjunt buit
	*/
	
	//Destructora
	
	~Cjt_text();
	
	//Modificadores
	
	bool afegir_text(Frase& autor, Text& titol, Text& contingut);
	/** @brief  afegeix un text amb i_text com a clau i contingut com a valor associat
		\pre autor, titol i contingut no són buits
		\post si el p.i. no conté cap element amb i_text.autor = autor i
		i_text.titol = titol retorna cert i n'afegeix un amb aquest
		i_text com a clau i valor associat = contingut. Altrament 
		retorna fals 
	*/
	
	bool triar_text(Frase& paraules);
	/** @brief tria un text que conté unes paraules determinades
		\pre paraules no és buit
		\post si el p.i. conté algun element que contingui els strings de
		paraules en i_text.autor, i_text.titol o en el seu valor
		associat retorna cert, has_selec = true i selec_text apunta
		aquest element del p.i.. Altrament retorna fals 
	*/
	
	bool eliminar_text();
	/** @brief elimina l'últim text selccionat
		\pre cert
		\post si has_selec = true retorna cert, s'elimina l'element apuntat 
		per selec_text i has_selec = false. Altrament retorna fals 
	*/
	
	bool substitueix(paraula1, paraula2);
	/** @brief substituteix totes les paraules = paraula1 per paraula2
		\pre string1 i string2 no són buits
		\post si has_selec = true retorna cert i se substitueixen els
		valors de tots els strings = paraula1 del valor associat a l'
		element apuntat per selec_text per paraula2. Altrament retorna 
		fals 
	*/
	 
	//Consultores
	
	int selec_n_frases();
	/** @brief retorna el nombre de frases del valor associat a l'element
		apuntat per selec_text
		\pre has_selec = true
		\post retorna el nombre de frases del valor associat a l'element
		apuntat per selec_text
	*/
	
	int selec_n_paraules();
	/** @brief  retorna el nombre de paraules d'un element
		\pre has selec = true;
		\post retorna el nombre de paraules del valor associat a l'element
		apuntat per selec_text 
	*/
	
	Text selec_frases(int x, int y);
	/** @brief  retorna un objecte text
		\pre l'interval [x,y] és vàlid per al text seleccionat
		\post retorna un objecte text.
	*/
	
	//Lectura i escriptura
	
	void textos_autor(Frase& autor);
	/** @brief  s'escriuen totes els titols d'un mateix autor ordenats
		\pre autor no és buit
		\post s'han escrit al canal estandard de sortida els valors 
		i_text.titol dels elements del p.i. que tenen i_text.autor = autor 
		en ordre 
	*/
	
	void textos_tots();
	/** @brief s'escriuen totes els titols emmagatzemats, en ordre
		\pre cert
		\post s'han escrit al canal estandard de sortida els valors 
		i_text.titol de tots els elements del p.i. en ordre 
	*/
	
	void autors_tots();
	/** @brief s'escriuen els valors dels elements del p.i. i els seus 
		associats.
		\pre cert
		\post s'han escrit al canal estandard de sortida els diferents
		valors i_text.autor dels elements del p.i. seguits del nombre de
		textos, frases i paraules associats a cada autor de tots els
		elements del p.i. en ordre. 
	*/
	
	bool info(Cjt_Cites cjt_cites);
	/** @brief si has_selec = true escriu diversos atributs de text
		\pre cert
		\post si has selec = true retorna cert i escriu al canal estandard
		de sortida els valors i_text.autor, i_text.titol, el nombre de
		frases, paraules i cites del text seleccionat 
	*/
	
	bool autor();
	/** @brief escriu el valor i_text.autor del text seleccionat
		\pre cert
		\post si has_selec = true retorna true i escriu al canal estandard
		de sortida el valor i_text.autor del text seleccionat. Altrament
		retorna fals 
	*/
	
	bool contingut();
	/** @brief  escriu el contingut del text selccionat separat per frases numerades
		\pre cert
		\post si has_selec = true retorna true i escriu al canal estandard
		de sortida el contingut del text seleccionat separat en frases 
		numerades a partir de 1. Altrament retorna fals 
	*/
	
	bool frases(int x, int y);
	/** @brief escriu les frases entre x-èsima i y-èsima del text seleccionat
		\pre cert
		\post si has_selec = true i [x,y] és un interval vàlid per al text
		seleccionat retorna cert i escriu al canal estandard de sortida les
		frases entre la x-èsima i la y-èsima del text seleccionat.
		Altrament retorna fals 
	*/
	
	bool frequencies();
	/** @brief escriu el contingut del text seleccionat en funció de la freqüència
		\pre cert
		\post si has_selec = true retorna cert i escriu al canal estandard
		de sortida el contingut del text seleccionat ordenat en funció de
		la freqüencia amb que apareix cada paraula, la seva llargada i
		després alfabèticament. 
	*/
	
	bool evaluar(istringstream iss);
	/** @brief escriu les frases que comleixen l'expressió
		\pre iss conté una expressió booleana de paraules
		\post si has_selec = true retorna cert i escriu al canal estandard
		de sortida les frases que compleixen l'expressió del text triat
		altrament retorna fals
	*/
	
	bool consecutives(Frase& paraules);
	/** @brief  escriu les frases on hi apareix la seqüència paraules
		\pre paraules no és buit
		\post si has_selec = true retorna cert i escriu al canal estandard
		de sortida les frases on hi apareix la seqüència paraules.
		Altrament retorna fals 
	*/
};
#endif
