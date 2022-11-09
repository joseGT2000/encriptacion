/** @file Mensaje.hh
@brief Especificaci�n de la clase Mensaje
*/

#ifndef MENSAJE_HH
#define MENSAJE_HH

#ifndef NO_DIAGRAM
#endif
/**
Clase Mensaje
*/
#include <iostream>
#include <utility>

using namespace std;

/** @class Mensaje
	@brief Representan un mensaje 
*/
class Mensaje
{
private:
	pair <string, string> msg;

public:
	/** @brief Contructora
		\pre Cierto
		\post Se ha creado un objeto*/
	Mensaje();

	Mensaje(string msg, string alf);

	/** @brief Destructora
		\pre Cierto
		\post Se ha destruido un objeto*/
	~Mensaje();

	void imprimir();
	
};
#endif