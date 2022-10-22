/** @file Cjt_Categorias.hh
@brief Especificaci�n de la clase Categoria
*/

#ifndef CJT_MENSAJE_HH
#define CJT_MENSAJE_HH

///\cond
#include <iostream>
#include <map>
#include <utility>
#include <iterator>
///\endcond
#include "Mensaje.hh"
/**
Clase Cjt_Mensaje
*/

using namespace std;

/** @class Cjt_Mensaje
	@brief
*/
class Cjt_Mensaje
{
private:

public:
	Cjt_Mensaje();
	~Cjt_Mensaje();

	/** @brief Consulta de Puntos
		\pre
		\post */
	void conjuntoInicial();

	void addMensaje();

	void borrarMensaje();

	void listarMensajes();
};
#endif