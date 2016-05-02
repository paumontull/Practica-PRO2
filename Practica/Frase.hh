#ifndef FRASE_HH
#define FRASE_HH

#include "Frase.hh"
#include <vector>
#include <string>

using namespace std;

class Frase{

private:

	// Tipus de modul: dades
	// Descripcio del tipus: representa una frase (vector de strings).
	// Una frase conté strings i pot acabar amb un string marca ".", "!",
	// "?" o no (i.e. un nom d'un autor es considera una frase per tenir
	// més d'una paraula però no acaba en caracter marca)
    
	vector<string> frase;
    
public:
	//Constructores
	
	Frase();
	/* Pre: cert */
	/* Post: el resultat és una frase buida */
	
	//Destructora
	
	~Frase();
	
	//Modificadores
	
	void write_iesim(int i, string s) const;
	/* Pre: cert */
	/* Post: el valor de frase[i] és s */
	
	//Consultores
	
	string read_iesim(int i);
	/* Pre: cert */
	/* Post: retorna el valor de l'element i-èsim del p.i. */
	
	int n_paraules();
	/* Pre: cert */
	/* Post: retorna el nombre d'elements del p.i. */
	
	//Lectura i escriptura
	
	void llegir(istringstream iss);
	/* Pre: el canal estandard d'entrada conté una sola frase no acabada 
	   en '.', '!' o '?' */
	/* Post: el p.i. és la frase resultant de separar l'entrada 
	   en strings */
	
	void escriure();
	/* Pre: cert */
	/* Post: s'escriu al canal estandard de sortida els elements del
	   p.i. separats per espais i si l'últim és un caràcter de 
	   puntuació, aquest s'ajunta al penúltim string */
};
#endif
