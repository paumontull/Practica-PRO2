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
	/* Pre: cert */
	/* Post: el resultat és un text buit */
	
	//Destructora
	
	~Text();
	
	//Modificadores
	
	void afegir_salt(Text& t);
	/* Pre: cert */
	/* Post: si el p.i. original era buit ara conté t. Altrament
	   s'afegeix un caracter salt de linia "/n" i el text t a continuació
	   del contingut del p.i. original */
	
	void write_iesim(int i, const Frase& s) const;
	/* Pre: cert */
	/* Post: el valor de frase[i] és s */
	
	//Consultores
	
	bool es_buit();
	/* Pre: cert */
	/* Post: retorna cert si el p.i. no conté cap element */
	
	Frase read_iesim(int i);
	/* Pre: cert */
	/* Post: retorna el valor de l'element i-èsim del p.i. */
	
	int n_frases();
	/* Pre: cert */
	/* Post: retorna el nombre d'elements del p.i. */
	
	//Lectura i escriptura
	
	void llegir(istringstream iss);
	/* Pre: iss conté una o més frases. L'últim string de l'entrada
	   marca sempre el final d'una frase. Adicionalment, un string 
	   acabat en '.', '!' o '?' també marca el final d'una frase. */
	/* Post: el p.i. conté el vector de frases resultant de separar
	   l'entrada en vectors d'string. Si l'últim element de la frase
	   acaba en '.', '!' o '?' se'n separa aquest caràcter marca
	   i es guarda com a últim element de la frase. */
	   
	void escriure();
	/* Pre: cert */
	/* Post: s'escriu al canal estandard de sortida els elements del
	   p.i. separats per espais i amb els caracters de puntuació
	   ajuntats a l'string anterior */
};
#endif
