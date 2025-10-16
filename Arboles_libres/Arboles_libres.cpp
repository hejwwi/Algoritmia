
/*@ <answer>
 *
 * Nombre y Apellidos:
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

#include "Grafo.h"  // propios o los de las estructuras de datos de clase

/*@ <answer>

 Escribe aquí un comentario general sobre la solución, explicando cómo
 se resuelve el problema y cuál es el coste de la solución, en función
 del tamaño del problema.

 @ </answer> */


 // ================================================================
 // Escribe el código completo de tu solución aquí debajo
 // ================================================================
 //@ <answer>
class Conexo {
private:
    vector<bool> visitado;
    vector<int> anterior;
    int origen;

    void dfs(Grafo const& g, int v) {
        visitado[v] = true;

        for (int i : g.ady(v)) {
            if (!visitado[i]) {
                anterior[i] = v;
                dfs(g, i);

            }
        }
    }



public:
    Conexo(Grafo const& g, int origen) :visitado(g.V(), false), anterior(g.V()), origen(origen) {
        dfs(g, origen);
    }

    bool conexo(Grafo const& g) {


        for (int i = 0; i < g.V(); i++) {
            if (visitado[i] == false) {
                return false;
            }
        }
        return true;
    }
};


bool resuelveCaso() {

    // leer los datos de la entrada
    int V, A;
    cin >> V;
    if (!std::cin)  // fin de la entrada
        return false;
    cin >> A;
    Grafo arbolesLibre(V);
    int a1, a2;
    for (int i = 0; i < A; i++) {
        cin >> a1 >> a2;
        arbolesLibre.ponArista(a1, a2);
    }
    // resolver el caso posiblemente llamando a otras funciones
    Conexo arbolConexo(arbolesLibre, 1);

    if (arbolConexo.conexo(arbolesLibre) && arbolesLibre.A() < arbolesLibre.V() ) {
        cout << "SI" << '\n';
    }
    else {
        cout << "NO" << '\n';
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
