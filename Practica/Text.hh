/** @file Cjt_text.hh 
 *  @brief classe text
*/
#ifndef TEXT_HH
#define TEXT_HH

#include "Frase.hh"

class Text{

private:

	// Tipus de modul: dades
	// Descripcio del tipus: representa un text (vector de frases)
    
	vector<Frase> text;
    
public:
	//Constructores
	
	Text();
	/** @brief el restultat és un text buit
		\pre cert
		\post el resultat és un text buit 
	*/
	
	//Destructora
	
	~Text();
	
	//Modificadores
	
	void afegir_salt(Text& t);
	/** @brief afegeix un salt de linia si p.i. no era buit
		\pre cert
		\post si el p.i. original era buit ara conté t. Altrament
		s'afegeix un caracter salt de linia "/n" i el text t a continuació
		del contingut del p.i. original ç
	*/
	
	void write_iesim(int i, const Frase& s) const;
	/** @brief el valor de frase[i] és s
		\pre cert
		\post el valor de frase[i] és s 
	*/
	
	//Consultores
	
	bool es_buit();
	/** @brief retorna cert si el p.i. no conté cap element
		\pre cert 
		\post retorna cert si el p.i. no conté cap element 
	*/
	
	Frase read_iesim(int i);
	/** @brief retirba el valor de l'element i-èsim del p.i.
		\pre cert 
		\post retorna el valor de l'element i-èsim del p.i. 
	*/
	
	int n_frases();
	/** @brief reforma el nombre d'elements del p.i.
		\pre cert 
		\post retorna el nombre d'elements del p.i.
	*/
	
	//Lectura i escriptura
	
	void llegir(istringstream iss);
	/** @brief el p.i. conté el vector de frases resultant de seprara l'entrada en vectors d'estring.
		\pre conté una o més frases. L'últim string de l'entrada marca
		sempre el final d'una frase. Adicionalment, un string acabat en
		'.', '!' o '?' també marca el final d'una frase
		\post el p.i. conté el vector de frases resultant de separar
		l'entrada en vectors d'string. Si l'últim element de la frase
		acaba en '.', '!' o '?' se'n separa aquest caràcter marca
		i es guarda com a últim element de la frase. 
	*/
	   
	void escriure();
	/** @brief s'escriuen eles elemnts de p.i. seperats per espais
		\pre cert
		\post s'escriu al canal estandard de sortida els elements del
		p.i. separats per espais i amb els caracters de puntuació
		ajuntats a l'string anterior 
	*/
};
#endif
