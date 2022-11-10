/** @file Alfabeto.hh
@brief Especificaci�n de la clase Alfabeto
*/

#ifndef ALFABETO_HH
#define ALFABETO_HH

#ifndef NO_DIAGRAM
#endif

/**
Clase Alfabeto
*/
#include <iostream>
#include <utility>

using namespace std;

/** @class Alfabeto
	@brief Representa un conjunto de caracteres que forman un alfabeto
*/
class Alfabeto
{
private:

	string alfabeto;
	int numMensajes = 0;
	bool special = true;

public:
	/** @brief Contructora
		\pre Cierto
		\post Se ha creado un objeto*/
	Alfabeto();

	Alfabeto(string alf);

	/** @brief Destructora
		\pre Cierto
		\post Se ha destruido un objeto*/
	~Alfabeto();

	void sumarMensaje();

	void restarMensaje();

	int numMensaje();

	string returnAlf();

	void imprimir();

	void esSpecial();
};
#endif