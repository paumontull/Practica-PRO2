#ifndef TEXT_HH
#define TEXT_HH

#include <vector>

typedef vector<string> Frase;

class Text{

private:

	// Tipus de modul: dades
	// Descripcio del tipus: representa un text (vector de frases)
    
	vector<Frase> titol, contingut;
	Frase autor;
    
public:
	//Constructores
	
	Text();
	/* Pre: cert */
	/* Post: el resultat és un text buit */
	
	Text(vector<Frase>& titol, Frase& autor, vector<frase>& contingut);
	/* Pre: el primer string de titol i autor comença amb '"' i l'ultim acaba amb '"' */
	/* Post: el resultat es un text amb TITOL = titol, AUTOR = autor i CONTINGUT = contingut */
	
	//Destructora
	
	~Text();
	
	//Modificadores
	
	
	
	//Consultores
	
	
};
#endif
