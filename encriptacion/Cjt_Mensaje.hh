/** @file Cjt_Mensaje.hh
@brief Especificaci�n de la clase Cjt_Mensaje
*/

#ifndef CJT_MENSAJE_HH
#define CJT_MENSAJE_HH

///\cond
#include <iostream>
#include <map>
#include <utility>
#include <iterator>
#include <string>
#include <vector>
///\endcond
#include "BinTree.hh"
#include "Mensaje.hh"
#include "Cjt_Alfabeto.hh"
/**
Clase Cjt_Mensaje
*/

using namespace std;

/** @class Cjt_Mensaje
	@brief Representa un conjunto de mensajes
*/
class Cjt_Mensaje
{
private:
	map<string, Mensaje> mensajes;

	void ecuacionEncriptar(string& mensaje, string& alfabeto, string& clave);

	void ecuacionEncriptarEspecial(string& mensaje, string& alfabeto, string& clave);

	void ecuacionDesEncriptar(string& mensaje, string& alfabeto, string& clave);

	void ecuacionDesEncriptarEspecial(string& mensaje, string& alfabeto, string& clave);

	void permutar(string& mensaje);

	BinTree<char> crear(string mensaje, int inferior, int superior);

	BinTree<char> cambiar(BinTree<char> a, char hermano);
	
	void leer(BinTree<char> a);

public:
	/** @brief Contructora
		\pre Cierto
		\post Se ha creado un objeto*/
	Cjt_Mensaje();

	Cjt_Mensaje(Cjt_Alfabeto& alf);

	/** @brief Destructora
		\pre Cierto
		\post Se ha destruido un objeto*/
	~Cjt_Mensaje();

	/** @brief Se añade un unico mensaje
		\pre Cierto
		\post Se ha añadido un mensaje*/
	void addMensaje(Cjt_Alfabeto& alf);

	/** @brief Se borrara un mensaje
		\pre Cierto
		\post Se ha borrado un mensaje a eleccion del usuario*/
	void borrarMensaje(Cjt_Alfabeto& alf);

	/** @brief Se listan todos los mensajes que haya
		\pre Cierto
		\post Se han mostrado por pantalla la lista de mensajes*/
	void listarMensajes();

	/** @brief Codifica por sustitucion un mensaje guardado
		\pre Cierto
		\post Se ha codificado un mensaje que ya estaba guardado con un alfabeto especifico*/
	void codificaSustGuardado(Cjt_Alfabeto& alf);

	


	/** @brief Codifica por sustitucion un mensaje no guardado
		\pre Cierto
		\post Se ha codificado un mensaje que no estaba guardado con un alfabeto especifico*/
	void codificaSustNoGuardado(Cjt_Alfabeto& alf);

	/** @brief Deodifica por sustitucion
		\pre Cierto
		\post Ha decodificado el mensaje anteriormente codificado por el metodo de sustitucion*/
	void decodificaSust(Cjt_Alfabeto& alf);
	
	/** @brief Codifica por permutacion un mensaje guardado
		\pre Cierto
		\post Se ha codificado un mensaje que ya estaba guardado sin alfabeto*/
	void codificaPermGuardado();

	/** @brief Codifica por permutacion un mensaje no guardado
		\pre Cierto
		\post Se ha codificado un mensaje que no estaba guardado*/
	void codificaPermNoGuardado();

	/** @brief Deodifica por permutacion
		\pre Cierto
		\post Ha decodificado el mensaje anteriormente codificado por el metodo de permutacion*/
	void decodificaPerm();

};
#endif