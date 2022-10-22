/** @file Cjt_Categorias.hh
@brief Especificaci�n de la clase Categoria
*/

#ifndef SUSTITUCION_HH
#define SUSTITUCION_HH

#ifndef NO_DIAGRAM
#endif

/**
Clase Sustitucion
*/

using namespace std;

/** @class Sustitucion
	@brief 
*/
class Sustitucion
{
private:

public:
	Sustitucion();
	~Sustitucion();

	/** @brief Consulta de Puntos
		\pre
		\post */
	void codificaGuardado();
	void codificaNoGuardado();
	void decodifica();


};
#endif