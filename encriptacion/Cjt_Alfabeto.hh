/** @file Cjt_Alfabeto.hh
@brief Especificaci�n de la clase Cjt_Alfabeto
*/

#ifndef CJT_ALFABETO_HH
#define CJT_ALFABETO_HH

///\cond
#include <iostream>
#include <map>
#include <utility>
#include <iterator>
#include <string>
///\endcond
#include "Alfabeto.hh"
/**
Clase Cjt_Alfabeto
*/

using namespace std;

/** @class Cjt_Alfabeto
	@brief Representa un conjunto de alfabetos
*/
class Cjt_Alfabeto
{
private:
	map <string, Alfabeto> alfabetos;

public:
	/** @brief Contructora
		\pre Cierto
		\post Se ha creado un objeto*/
	Cjt_Alfabeto();
	/** @brief Destructora
		\pre Cierto
		\post Se ha destruido un objeto*/
	~Cjt_Alfabeto();

	/** @brief Añade un conjunto de alfabetos al iniciar el programa
		\pre Cierto
		\post Se han añadido tantos alfabetos como el usuario ha querido*/
	void conjuntoInicial();

	/** @brief Se añade un unico alfabeto
		\pre Cierto
		\post Se ha añadido un alfabeto*/
	void addAlfabeto();

	/** @brief Se borrara un alfabaeto
		\pre Cierto
		\post Se ha borrado un alfabeto a eleccion del usuario*/
	void borrarAlfabeto();

	/** @brief Se listan todos los alfabetos que haya
		\pre Cierto
		\post Se han mostrado por pantalla la lista de alfabetos*/
	void listarAlfabeto();

	void nuevoMsg(string alf);

	void borrarMsg(string alf);

	string devolverAlf(string id);

	map<string, Alfabeto>::const_iterator findAlfabeto(string nombre);

	map<string, Alfabeto>::const_iterator ultimaPos();
};
#endif