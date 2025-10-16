
/*@ <answer>
 *
 * Nombre y Apellidos: Sandra Wlodkowska
 *
 *@ </answer> */

#include <iostream>
#include <fstream>

using namespace std;

#include "PriorityQueue.h"  // propios o los de las estructuras de datos de clase

/*@ <answer>

 Escribe aquí un comentario general sobre la solución, explicando cómo
 se resuelve el problema y cuál es el coste de la solución, en función
 del tamaño del problema.

 @ </answer> */

struct tMusicos {
    int numeroMusicos;
    int numPartituras;
};

// ================================================================
// Escribe el código completo de tu solución aquí debajo
// ================================================================
//@ <answer>

bool operator<(const tMusicos& m1, const tMusicos& m2) {

    return((m1.numeroMusicos * m2.numPartituras) > (m2.numeroMusicos * m1.numPartituras));
}

bool resuelveCaso() {

    // leer los datos de la entrada
    int numAtriles, numInstrumentos;
    cin >> numAtriles;
    if (!std::cin)  // fin de la entrada
        return false;
    cin >> numInstrumentos;
    PriorityQueue<tMusicos, less<tMusicos>> atriles_musicos;
    tMusicos musicoAux;
    int n;
    for (int i = 0; i < numInstrumentos; i++) {
        cin >> n;
        atriles_musicos.push({ n,1 });
    }
    // resolver el caso posiblemente llamando a otras funciones
    if (numAtriles == numInstrumentos) {
        musicoAux = atriles_musicos.top();
        cout << musicoAux.numeroMusicos << endl;
    }
    else {

        for (int i = 0; i < numAtriles - numInstrumentos; i++) {
            musicoAux = atriles_musicos.top();
            atriles_musicos.pop();
            musicoAux.numPartituras++;
            atriles_musicos.push(musicoAux);


        }
        musicoAux = atriles_musicos.top();
        int m = (musicoAux.numeroMusicos / musicoAux.numPartituras) + (musicoAux.numeroMusicos % musicoAux.numPartituras>0);
        cout << m << endl;
    }

    return true;
}

//@ </answer>
//  Lo que se escriba dejado de esta línea ya no forma parte de la solución.

int main() {
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("1.in");
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
