
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

#include "DigrafoValorado.h"// propios o los de las estructuras de datos de clase
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
    int numeroCamnios;
    vector<int> formas;

    void relajar(AristaDirigida<int> a) {
        int v = a.desde(), w = a.hasta();
        if (dist[w] > dist[v] + a.valor()) {
            dist[w] = dist[v] + a.valor();
            formas[w] = formas[v];
            pq.update(w, dist[w]);
        }
        else if (dist[w] == dist[v] + a.valor()) {
            formas[w] += formas[v];
        }
        
    }

public:
    Dijkstra(DigrafoValorado<int> const& g, int orig) : origen(orig),
        dist(g.V(), INF), pq(g.V()), formas(g.V(),0){
        dist[origen] = 0;
        formas[origen] = 1;
        pq.push(origen, 0);
        while (!pq.empty()) {
            int v = pq.top().elem; pq.pop();
            for (auto a : g.ady(v))
                relajar(a);
        }
    }

    bool hayCamino(int v) const { return dist[v] != INF; }

    int distancia(int v) const { return dist[v]; }

    int camnios(int v) { return formas[v] ; }
};

bool resuelveCaso() {

    // leer los datos de la entrada
    int V, A;
    cin >> V;
    if (!std::cin)  // fin de la entrada
        return false;
    cin >> A;
    int v, w, c;
    DigrafoValorado<int> caminosCole(V);
    for (int i = 0; i < A; i++) {
        cin >> v >> w >> c;
        caminosCole.ponArista({ v - 1,w - 1,c });
        caminosCole.ponArista({ w - 1,v - 1,c });

    }
    Dijkstra sol(caminosCole,0);

    int caminos = sol.camnios(V - 1);
    cout << caminos << '\n';
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
