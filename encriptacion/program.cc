/**
@mainpage La Criptografía es la ciencia que trata sobre encriptar y desencriptar información.
Desde la edad antigua se han encriptado mensajes diplomáticos, militares o administrativos para conseguir comunicaciones seguras, a salvo de espías.
En la actualidad, la Criptografía desempeña un papel de gran importancia dentro de
la Informática. Su uso es prácticamente cotidiano, ya que elementos tan familiares como
los passwords, los números de tarjetas, etc., se guardan encriptados e incluso hay programas que permiten cifrar y descifrar los mensajes de correo electrónico y, en general,
cualquier documento en soporte digital.
Un mensaje puede encriptarse por permutación o por sustitución de sus caracteres, siguiendo unas reglas predefinidas y quizá introduciendo algún elemento adicional (claves, números aleatorios, ...). Obviamente, si se desea descifrar un mensaje ya encriptado,
resulta esencial que las reglas de cifrado sean reversibles.
En esta práctica proponemos dos métodos de encriptación, uno de cada tipo. Para cada caso solo mostramos el algoritmo de encriptación, el de desencriptación es fácilmente
deducible.
*/

/** @file program.cc
@brief Es el main, esta el selector de opciones
*/

///\cond
#include <iostream>
///\endcond
#include "Cjt_Alfabeto.hh"
#include "Cjt_Mensaje.hh"

using namespace std;

/** @brief Main
    \pre cierto
    \post Ejecuta el codigo principal (solo tiene la selecion de opciones)
*/int main()
{
    Cjt_Alfabeto alfabetos;
    Cjt_Mensaje mensajes(alfabetos);

    //alfabetos.conjuntoInicial();
    //mensajes.conjuntoInicial();

    string opcion;
    cin >> opcion;
    getchar();
    while (opcion != "fin")
    {
        cout << "#" << opcion << endl;
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
            mensajes.codificaSustGuardado();
        }
        else if (opcion == "codificar_sustitucion" or opcion == "cs")
        {
            mensajes.codificaSustNoGuardado();
        }
        else if (opcion == "decodificar_sustitución" or opcion == "ds")
        {
            mensajes.decodificaSust();
        }
        else if (opcion == "codificar_permutacion_guardado" or opcion == "cpg")
        {
            mensajes.codificaPermGuardado();
        }
        else if (opcion == "codificar_permutacion" or opcion == "cp")
        {
            mensajes.codificaPermNoGuardado();
        }
        else if (opcion == "decodificar_permutacion" or opcion == "dp")
        {
            mensajes.decodificaPerm();
        }

        cin >> opcion;
    }
}
