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
	/* Pre: cert */
	/* Post: el resultat és una cita buida */
	
	Cita(Frase& autor, Text& titol, Text& contingut, int x, int y);
	/* Pre: cert */
	/* Post: */
	
	//Destructora
	
	~Cita();
	
	//Modificadores
	
	
	//Consultores
	Frase consultar_autor();
	/* Pre: el p.i. no és buit */
	/* Post: el resultat és l'autor del p.i. */
	
	Text consultar_titol();
	/* Pre: el p.i. no és buit */
	/* Post: el resultat és el títol del p.i.*/
	
	Text consultar_contingut();
	/* Pre: el p.i. no és buit */
	/* Post: el resultat és el contingut del p.i.*/
	
	int consultar_x();
	/* Pre: el p.i. no és buit */
	/* Post: el resutlat és el valor x del p.i.*/
	
	int consultar_y();				
	/* Pre: el p.i. no és buit */
	/* Post: el contingut és el valor y del p.i.*/
	
};

#endif

