/**
@mainpage El programa principal empezará leyendo el número de categorías C ≥ 1 y el número máximo de niveles K ≥ 4, ambos constantes. A continuación se leerá una secuencia de C strings con los nombres asociados a las categorías identificadas por los valores entre 1 y C en orden creciente (de identificador, no de nombre). Luego se leerán C × K enteros mayores o iguales que 0, que serán los puntos por categoría y nivel, ordenados crecientemente por categorías y dentro de cada categoría ordenados crecientemente por nivel. Seguidamente se leerá un número inicial de torneos T ≥ 0 y una secuencia de T pares de string t y entero c, donde t será el nombre que identifica al torneo (sin repeticiones) y c la categoría entre 1 y C a la que pertenece el torneo. Por último se leerá un número inicial de jugadores P ≥ 0 y una secuencia de P strings con los nombres que identifican a los jugadores (sin repeticiones). El orden en que se lean los jugadores determinará el orden de ranking inicial (el i-ésimo jugador leído será el número i del ranking, para todo i entre 1 y P). Excepto dicho valor de ranking inicial, el resto de estadísticas de los jugadores se inicializarán a cero, incluidos sus puntos.
Hayquenotar que las magnitudes T y P noserán constantes ya que podrán aumentar o disminuir al añadir posteriormente nuevos torneos o jugadores y al dar de baja torneos o jugadores registrados previamente. Terminadas las inicializaciones, se procesará una serie de comandos acabados en un comando fin.
1. nuevo_jugador p: lee y añade un nuevo jugador con identificador p (si éste es válido). El comando admite la forma abreviada nj. Si ya existe un jugador en el circuito con el mismo identificador se imprime un mensaje de error. En caso contrario se añade el jugador con estadísticas a cero y última posición en el ranking y se imprime el número de jugadores P en el circuito después de añadirlo.
2. nuevo_torneo t c: lee un nuevo torneo con identificador t y categoría c y lo añade al circuito (si los datos son válidos). El comando admite la forma abreviada nt. Si la categoría c no está entre 1 y C se imprime un mensaje de error. Si lo está, pero ya existe un torneo en el circuito con el nombre t, se imprime otro mensaje de error. En caso contrario se imprime el número de torneos T en el circuito después de añadirlo.
3. baja_jugador p: da de baja en el circuito al jugador con identificador p. El comando admite la forma abreviada bj. Si no existe un jugador con identificador p se imprime un mensaje de error. En caso contrario se actualiza el ranking (desplazando una posición hacia arriba los jugadores siguientes en el ranking) y se imprime el número de jugadores P en el circuito después de darlo de baja. Si más tarde se añade otro jugador con el mismo nombreescomosielanterior no hubiera existido.
4. baja_torneo t:dadebajaenelcircuitoaltorneoconidentificadort.Elcomando admitela formaabreviadabt.Sinoexisteuntorneoconidentificadortseimprime unmensaje deerror. En caso contrario se actualiza el ranking después de restar los puntos conseguidos por los jugadores en la última edición del torneo (si se hubiera jugado alguna) y se imprime el número de torneos T en el circuito después de darlo de baja. Si más tarde se añade otro torneo con el mismo nombre es como si el anterior no hubiera existido.
5. iniciar_torneo t:seleelainscripcióneneltorneotyseconfeccionaeimprime el cuadro deemparejamientosdelosjugadoresinscritos. Se garantiza que el torneo t existe en el circuito. El comando admite la forma abreviada it. Primero se lee el número n de jugadores inscritos y luego se leen n enteros con sus posiciones en el ranking actual ordenadas crecientemente. El formato de escritura del cuadro de emparejamientos se deducirá del juego de pruebas público.
6. finalizar_torneo t: se leen los resultados del torneo t, se produce e imprime el cuadro oficial de resultados, y se listan los puntos para el ranking ganados por cada uno de los participantes; también se actualiza el ranking y las estadísticas de los jugadores. Se garantiza que el torneo t existe en el circuito y que previamente se ha ejecutado el comando iniciar_torneo t correspondiente†. El comando admite la forma abreviada ft. Los resultados del torneo se leen como un árbol binario de strings en preorden siguiendo la estructura del cuadro de emparejamientos. El formato de escritura del cuadro de resultados se deducirá del juego de pruebas público. La lista de jugadores y puntos ganados por cada uno se escribe por orden de ranking de los jugadores en el momento de iniciar el torneo. La actualización del ranking ha de tener en cuenta, además de los puntos ganados en la presente edición que se suman, los puntos ganados en la edición anterior del torneo, si la hubiera, que se restan.
7. listar_ranking: se listan, por orden creciente de ranking actual, la posición, el nombre y los puntos de cada jugador del circuito. El comando admite la forma abreviada lr.
8. listar_jugadores: se listan, por orden creciente de identificador (nombre), el nombre, la posición en el ranking, los puntos y el resto de las estadísticas de cada jugador del circuito. El comando admite la forma abreviada lj.
9. consultar_jugador p: lo mismo que la anterior, pero solamente para el jugador con identificador p. Si no existe un jugador con identificador p se imprime un mensaje de error. El comando admite la forma abreviada cj.
10. listar_torneos: se listan, por orden creciente de identificador (nombre), el nombre y la categoría de cada torneo del circuito. El comando admite la forma abreviada lt.
11. listar_categorías: se listan, por orden creciente de identificador, el nombre y la tabla de puntos por niveles (en orden creciente de nivel) de cada categoría del circuito. El comando admite la forma abreviada lc.
12. fin: termina la ejecución del programa
*/

/** @file program.cc
@brief Especificación de la clase Jugador
*/

///\cond
#include <iostream>
///\endcond

#include "Categorias.hh"
#include "Cjt_Torneos.hh"
#include "Cjt_Jugadores.hh"


using namespace std;

/** @brief Main
    \pre cierto
    \post Ejecuta el codigo principal
*/int main()
{
    Categorias categorias;

    Cjt_Torneos conjuntoTorneos;

    Cjt_Jugadores conjuntoJugadores;

    conjuntoJugadores.rank.sortRanking();
    conjuntoJugadores.actualizarPuntuaciones();

    string opcion;
    cin >> opcion;
    while (opcion != "fin")
    {
        cout << "#" << opcion;
        if (opcion == "nuevo_jugador" or opcion == "nj")
        {
            conjuntoJugadores.nuevoJugador();
        }
        else if (opcion == "nuevo_torneo" or opcion == "nt")
        {
            conjuntoTorneos.nuevoTorneo(categorias.numCategorias());
        }
        else if (opcion == "baja_jugador" or opcion == "bj")
        {
            string nombre;
            cin >> nombre;
            cout << " " << nombre << endl;
            if (conjuntoJugadores.eliminarJugador(nombre))
                conjuntoTorneos.eliminarJugador(nombre);
        }
        else if (opcion == "baja_torneo" or opcion == "bt")
        {
            conjuntoTorneos.bajaTorneo(conjuntoJugadores);
        }
        else if (opcion == "iniciar_torneo" or opcion == "it")
        {
            conjuntoTorneos.iniciarTorneo(conjuntoJugadores.rank);
        }
        else if (opcion == "finalizar_torneo" or opcion == "ft")
        {
            conjuntoTorneos.finalizarTorneo(conjuntoJugadores, categorias);
        }
        else if (opcion == "listar_ranking" or opcion == "lr")
        {
            cout << endl;
            conjuntoJugadores.listarRanking();
        }
        else if (opcion == "listar_jugadores" or opcion == "lj")
        {
            cout << endl;
            conjuntoJugadores.listarJugadores();
        }
        else if (opcion == "consultar_jugador" or opcion == "cj")
        {
            conjuntoJugadores.consultarJugador();
        }
        else if (opcion == "listar_torneos" or opcion == "lt")
        {
            cout << endl;
            conjuntoTorneos.listarTorneos(categorias);
        }
        else if (opcion == "listar_categorias" or opcion == "lc")
        {
            cout << endl;
            categorias.listarCategorias();
        }

        cin >> opcion;
    }
}
// encriptacion.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>

int main()
{
    std::cout << "Hello World!\n";
}

// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
