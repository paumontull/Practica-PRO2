#ifndef FRASE_HH
#define FRASE_HH

#include "Frase.hh"
#include <vector>
#include <string>

class Frase{

private:

	// Tipus de modul: dades
	// Descripcio del tipus: representa una frase (vector de strings).
	// Una frase conté strings i pot acabar amb un string marca ".", "!",
	// "?" o no (i.e. un nom d'un autor es considera una frase per tenir
	// més d'una paraula però no acaba en caracter marca)
    
	vector<string> Frase;
    
public:
	//Constructores
	
	Frase();
	/* Pre: cert */
	/* Post: el resultat és una frase buida */
	
	//Destructora
	
	~Text();
	
	//Modificadores
	
	
	
	//Consultores
	
	
	
	//Lectura i escriptura
	
	void llegir();
	/* Pre: el canal estandard d'entrada conté una sola frase no acabada 
	   en '.', '!' o '?' */
	/* Post: el p.i. és la frase resultant de separar l'entrada 
	   en strings */
};
#endif
