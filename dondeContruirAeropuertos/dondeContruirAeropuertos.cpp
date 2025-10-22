
/*@ <answer>
 *
 * Nombre y Apellidos:
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

#include "ConjuntosDisjuntos.h"  // propios o los de las estructuras de datos de clase
#include "GrafoValorado.h"
#include "PriorityQueue.h"
/*@ <answer>

 Escribe aquí un comentario general sobre la solución, explicando cómo
 se resuelve el problema y cuál es el coste de la solución, en función
 del tamaño del problema.

 @ </answer> */


 // ================================================================
 // Escribe el código completo de tu solución aquí debajo
 // ================================================================
 //@ <answer>
class krustal {
private:
    vector<Arista<int>> ARM;
    int coste;
    int numeroComponentesConexas;
    int costeAeropuerto;

    void calculoMenorCoste(GrafoValorado<int> const& g) {
        PriorityQueue<Arista<int>> pq(g.aristas());
        ConjuntosDisjuntos cjtos(g.V());

        while (!pq.empty()) {
            auto a = pq.top(); pq.pop();
            if (a.valor() < costeAeropuerto) {
                int v = a.uno(); int w = a.otro(v);

                if (!cjtos.unidos(v, w)) {
                    cjtos.unir(v, w);
                    ARM.push_back(a);
                    coste += a.valor();

                    if (ARM.size() == g.V() - 1) {
                        break;
                    }
                }
            }

        }
        numeroComponentesConexas = cjtos.num_cjtos();
    }

public:
    krustal(GrafoValorado<int> const& g,int costeAeropuerto) :coste(0),costeAeropuerto(costeAeropuerto), numeroComponentesConexas(0) {
        calculoMenorCoste(g);
    }

    int menorCosteCarreteras() {
        return coste;
    }

    int numroAeropuertos() {
        return numeroComponentesConexas;
    }
};


bool resuelveCaso() {

    // leer los datos de la entrada
    int V, A, costeAeropuerto;
    cin >> V;
    if (!std::cin)  // fin de la entrada
        return false;
    GrafoValorado<int> conexionesIslas(V);
    cin >> A >> costeAeropuerto;
    int v, w, c;
    for (int i = 0; i < A; i++) {
        cin >> v >> w >> c;
        conexionesIslas.ponArista({ v - 1, w - 1, c });
    }
    // resolver el caso posiblemente llamando a otras funciones
    krustal sol(conexionesIslas,costeAeropuerto);
    int numeroAeropuertos = sol.numroAeropuertos();
    int costeCarreteras = sol.menorCosteCarreteras();

    int costeTotal = costeCarreteras + (numeroAeropuertos * costeAeropuerto);

    cout << costeTotal <<" " << numeroAeropuertos << '\n';
    // escribir la solución

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
