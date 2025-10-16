/*@ <answer>
 *
 * Nombre y Apellidos:
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
 //#include <...>
using namespace std;

#include "TreeSet_AVL.h"  // propios o los de las estructuras de datos de clase

/*@ <answer>

 Escribe aquí un comentario general sobre la solución, explicando cómo
 Escribe aquí un comentario general sobre la solución, explicando cómo
 se resuelve el problema y cuál es el coste de la solución, en función
 del tamaño del problema.

 @ </answer> */


 // ================================================================
 // Escribe el código completo de tu solución aquí debajo
 // ================================================================
 //@ <answer>

bool resuelveCaso() {

    // leer los datos de la entrada
    int num;
    cin >> num;
    if (num < 1)  // fin de la entrada
        return false;
    else {
        Set<int> arbol;
        int elem;

        for (int i = 0; i < num; i++) {
            cin >> elem;
            arbol.insert(elem);
        }

        int casos;
        cin >> casos;
        int kesimo;
        for (int i = 0; i < casos; i++) {
            cin >> kesimo;
            try {
                cout << arbol.kesimo(kesimo) << '\n';
            }
            catch (std::out_of_range const&) {
                cout << "??\n";
            }


        }
        cout << "---\n";
    }
        // resolver el caso posiblemente llamando a otras funciones

        // escribir la solución

        return true;
    
}

//@ </answer>
//  Lo que se escriba dejado de esta línea ya no forma parte de la solución.

int main() {
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("casos.in");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

    while (resuelveCaso());

    // para dejar todo como estaba al principio
#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif
    return 0;
}