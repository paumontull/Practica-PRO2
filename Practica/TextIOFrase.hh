#ifndef TEXTIOFRASE_HH
#define TEXTIOFRASE_HH

#include "Text.hh"

vector<Frase> llegir_vec_frases(istringstream& iss);
	/* Pre: iss conté una o més frases. L'últim string d'iss serà sempre el final 
		 d'una frase. Adicionalment, un string acabat en '.', '!' o '?' també marca
		 el final d'una frase.
	/* Post: retorna un vector de frases on cada frase és un vector de strings i
		 si l'ultim string de la frase original acabava en '.', '!', '?', se separa 
		 aquest caràcter marca de l'string i es guarda com a últim element */
       
Frase llegir_frase(istringstream& iss);
	/* Pre: iss conté una sola frase.
	/* Post: retorna la frase */

#endif
