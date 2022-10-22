/**
@mainpage 
*/

/** @file program.cc
@brief 
*/

///\cond
#include <iostream>
///\endcond
#include "Cjt_Alfabeto.hh"
#include "Cjt_Mensaje.hh"
#include "Permutacion.hh"
#include "Sustitucion.hh"

using namespace std;

/** @brief Main
    \pre cierto
    \post Ejecuta el codigo principal
*/int main()
{
    Cjt_Alfabeto alfabetos;
    Cjt_Mensaje mensajes;
    Permutacion permuta;
    Sustitucion sustituye;

    alfabetos.conjuntoInicial();
    mensajes.conjuntoInicial();

    string opcion;
    cin >> opcion;
    while (opcion != "fin")
    {
        cout << "#" << opcion;
        if (opcion == "nuevo_mensaje" or opcion == "nm")
        {
            mensajes.addMensaje();
        }
        else if (opcion == "nuevo_alfabeto" or opcion == "na")
        {
            alfabetos.addAlfabeto();
        }
        else if (opcion == "borra_mensaje" or opcion == "bm")
        {
            mensajes.borrarMensaje();
        }
        else if (opcion == "borra_alfabeto" or opcion == "ba")
        {
            alfabetos.borrarAlfabeto();
        }
        else if (opcion == "listar_mensajes" or opcion == "lm")
        {
            mensajes.listarMensajes();
        }
        else if (opcion == "listar_alfabetos" or opcion == "la")
        {
            alfabetos.listarAlfabeto();
        }
        else if (opcion == "codificar_sustitucion_guardado" or opcion == "csg")
        {
            sustituye.codificaGuardado();
        }
        else if (opcion == "codificar_sustitucion" or opcion == "cs")
        {
            sustituye.codificaNoGuardado();
        }
        else if (opcion == "decodificar_sustitución" or opcion == "ds")
        {
            sustituye.decodifica();
        }
        else if (opcion == "codificar_permutacion_guardado" or opcion == "cpg")
        {
            permuta.codificaGuardado();
        }
        else if (opcion == "codificar_permutacion" or opcion == "cp")
        {
            permuta.codificaNoGuardado();
        }
        else if (opcion == "decodificar_permutacion" or opcion == "dp")
        {
            permuta.decodifica();
        }

        cin >> opcion;
    }
}
