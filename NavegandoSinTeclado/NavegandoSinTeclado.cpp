
/*@ <answer>
 *
 * Nombre y Apellidos:
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <vector>
#include <limits>
using namespace std;

#include "DigrafoValorado.h"  // propios o los de las estructuras de datos de clase
#include "IndexPQ.h"

/*@ <answer>

 Escribe aquí un comentario general sobre la solución, explicando cómo
 se resuelve el problema y cuál es el coste de la solución, en función
 del tamaño del problema.

 @ </answer> */


 // ================================================================
 // Escribe el código completo de tu solución aquí debajo
 // ================================================================
 //@ <answer>
class Dijkstra {
private:
    const int INF = numeric_limits<int>::max();
    int origen;
    vector<int> dist;
    IndexPQ<int> pq;
    void relajar(AristaDirigida<int> a) {
        int v = a.desde(), w = a.hasta();
        if (dist[w] > dist[v] + a.valor()) {
            dist[w] = dist[v] + a.valor(); 
            pq.update(w, dist[w]);
        }
    }

public:
    Dijkstra(DigrafoValorado<int> const& g, int orig) : origen(orig),
        dist(g.V(), INF), pq(g.V()) {
        dist[origen] = 0;
        pq.push(origen, 0);
        while (!pq.empty()) {
            int v = pq.top().elem; pq.pop();
            for (auto a : g.ady(v))
                relajar(a);
        }
    }

    bool hayCamino(int v) const { return dist[v] != INF; }
    int distancia(int v) const { return dist[v]; }
   
};

bool resuelveCaso() {

    // leer los datos de la entrada
    int paginaFinal;
    cin >> paginaFinal;
    if (paginaFinal<1)
        return false;
    vector<int> tiempoCarga;
    int aux;
    for (int i = 0; i < paginaFinal; i++) {
        cin >> aux;
        tiempoCarga.push_back(aux);
    }
    int conexiones;
    cin >> conexiones;
    DigrafoValorado<int> red(paginaFinal);
    int v, w, c;
    for (int i = 0; i < conexiones; i++) {
        cin >> v >> w >> c;
        aux = c + tiempoCarga[v - 1];
        red.ponArista({ v - 1,w - 1,aux });

    }

    Dijkstra sol(red, 0);
    if (sol.hayCamino(paginaFinal - 1)) {
        cout << sol.distancia(paginaFinal - 1) +tiempoCarga[paginaFinal- 1] << '\n';
    }
    else {
        cout << "IMPOSIBLE" << '\n';
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
