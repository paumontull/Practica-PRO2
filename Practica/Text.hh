#ifndef TEXT_HH
#define TEXT_HH

#include "Frase.hh"
#include <vector>

class Text{

private:

	// Tipus de modul: dades
	// Descripcio del tipus: representa un text (vector de frases)
    
	vector<Frase> Text;
    
public:
	//Constructores
	
	Text();
	/* Pre: cert */
	/* Post: el resultat és un text buit */
	
	//Destructora
	
	~Text();
	
	//Modificadores
	
	
	
	//Consultores
	
	
	
	//Lectura i escriptura
	
	void llegir();
	/* Pre: el canal estandard d'entrada conté una o més frases. 
	   L'últim string de l'entrada marca sempre el final d'una frase.
	   Adicionalment, un string acabat en '.', '!' o '?' també marca
		 el final d'una frase. */
	/* Post: el p.i. conté el vector de frases resultant de separar
	   l'entrada en vectors d'string. Si l'últim element de la frase
	   acaba en '.', '!' o '?' se'n separa aquest caràcter marca
	   i es guarda com a últim element de la frase. */
};
#endif
