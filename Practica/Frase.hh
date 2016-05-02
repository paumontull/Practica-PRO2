/** @file Cjt_text.hh 
 *  @brief classe frase
*/
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
	/** @brief el resultat és una frase buida
		\pre cert
		\post el resultat és una frase buida
	*/
	
	//Destructora
	
	~Frase();
	
	//Modificadores
	
	void write_iesim(int i, string s) const;
	/** @brief el valor de frase[i] és s 
		\pre cert 
		\post el valor de frase[i] és s
		*/
	
	//Consultores
	
	bool es_buit();
	/** @brief retirba cert si p.i. no conté cap element
		\pre cert
		\post retorna cert si p.i. no conté cap element
	*/
	
	string read_iesim(int i);
	/** @brief retorna el valor de l'element i-èsim dle p.i.
		\pre cert
		\post retorna el valor de l'element i-èsim del p.i. 
	*/
	
	int n_paraules();
	/** @brief retorna el nombre d'elements del p.i. 
		\pre cert
		\post retorna el nombre d'elements del p.i. 
	*/
	
	//Lectura i escriptura
	
	void llegir(istringstream iss)
	/** @brief el p.i. és la frase resultant de sperar l'entrada en strings
		\pre el canal estandard d'entrada conté una sola frase no acabada 
		en '.', '!' o '?'
		\post el p.i. és la frase resultant de separar l'entrada 
		en strings 
	*/
	
	void escriure();
	/** @brief sescriuen els elements del p.i- seprats per espais
		\pre cert
		\post s'escriu al canal estandard de sortida els elements del
		p.i. separats per espais i si l'últim és un caràcter de 
		puntuació, aquest s'ajunta al penúltim string 
	*/
};
#endif
