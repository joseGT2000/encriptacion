/** @file Cjt_Categorias.hh
@brief Especificaci�n de la clase Categoria
*/

#ifndef CJT_ALFABETO_HH
#define CJT_ALFABETO_HH

///\cond
#include <iostream>
#include <map>
#include <utility>
#include <iterator>
///\endcond
#include "Alfabeto.hh"
/**
Clase Cjt_Alfabeto
*/

using namespace std;

/** @class Cjt_Alfabeto
	@brief
*/
class Cjt_Alfabeto
{
private:

public:
	Cjt_Alfabeto();
	~Cjt_Alfabeto();

	/** @brief Consulta de Puntos
		\pre
		\post */
	void conjuntoInicial();

	void addAlfabeto();

	void borrarAlfabeto();

	void listarAlfabeto();
};
#endif