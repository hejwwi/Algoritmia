
/*@ <answer>
 *
 * Nombre y Apellidos:
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

#include "GrafoValorado.h"  // propios o los de las estructuras de datos de clase
#include "PriorityQueue.h"
#include "ConjuntosDisjuntos.h"
/*@ <answer>

 Escribe aquí un comentario general sobre la solución, explicando cómo
 se resuelve el problema y cuál es el coste de la solución, en función
 del tamaño del problema.

 @ </answer> */


 // ================================================================
 // Escribe el código completo de tu solución aquí debajo
 // ================================================================
 //@ <answer>
class kruskal {
private:
    vector<Arista<int>> ARM;
    int valorMaximo;
    bool conexo;
    
public:
    kruskal(GrafoValorado<int> const& g) :valorMaximo(0) {
        PriorityQueue<Arista<int>> pq(g.aristas());
        ConjuntosDisjuntos cjtos(g.V());
        while (!pq.empty()) {
            auto a = pq.top(); pq.pop();
            int v = a.uno(), w = a.otro(v);
            if (!cjtos.unidos(v, w)) {
                cjtos.unir(v, w);
                ARM.push_back(a); 
                if (valorMaximo <= a.valor()) {
                    valorMaximo = a.valor();

                }
 
                if (ARM.size() == g.V() - 1) break;
            }
        }
        if (cjtos.num_cjtos() > 1) {
            conexo = false;
        }
        else {
            conexo = true;
        }
    }
    int mayorCoste() {
        return valorMaximo;
    }
    bool arbolConexo() {
        return conexo;
    }
};



bool resuelveCaso() {

    // leer los datos de la entrada
    GrafoValorado<int> arboles(cin, 1);


    if (!std::cin)  // fin de la entrada
        return false;

    kruskal sol(arboles);
    if (!sol.arbolConexo()) {
        cout << "IMPOSIBLE" << '\n';
    }
    else {
        cout << sol.mayorCoste() << '\n';
    }

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
