/** @file Cita.hh 
 *  @brief classe cita
*/

#ifndef CITA_HH
#define CITA_HH

#include vector;
#include "Text.hh"


class Cita{

private:

	// Tipus de modul: dades
	// Descripcio del tipus: representa un text (vector de frases)
    
    Frase autor;
	Text titol;
	Text contingut;
	int x;
	int y; 
    
public:
	//Constructores
	
	Cita();
	/** @brief Afegeix una cita buida
		\pre cert
		\post el resultat és una cita buida 
	*/
	
	Cita(Frase& autor, Text& titol, Text& contingut, int x, int y);
	/** @brief Afegeix una cita completa
		\pre cert
		\post el resultat és una cita amb tots els paràmetres corresponents
	*/
	
	//Destructora
	
	~Cita();
	
	//Modificadores
	
	
	//Consultores
	Frase consultar_autor();
	/** @brief consulta l'autor d'una cita
		\pre el p.i. no és buit
		\post el resultat és l'autor del p.i.
	*/
		
	Text consultar_titol();
	/** @brief consulta el titol del text d'on prové una cita
		\pre el p.i. no és buit
		\post el resultat és el títol del p.i.
	*/
	
	Text consultar_contingut();
	/** @brief consulta el contingut de la cita
		\pre el p.i. no és buit
		\post el resultat és el contingut del p.i.
	*/
	
	int consultar_x();
	/** @brief consulta el valor x de la cita
		\pre el p.i. no és buit
		\post el resultat és el valor x del p.i.
	*/

	int consultar_y();				
	/** @brief consulta el valor y de la cita cita
		\pre el p.i. no és buit
		\post el resultat és el valor y del p.i.
	*/
	
};

#endif

