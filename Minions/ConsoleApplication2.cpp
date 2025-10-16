
/*@ <answer>
 *
 * Nombre y Apellidos:
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

#include "Grafo.h"// propios o los de las estructuras de datos de clase

/*@ <answer>

 Escribe aquí un comentario general sobre la solución, explicando cómo
 se resuelve el problema y cuál es el coste de la solución, en función
 del tamaño del problema.

 @ </answer> */


 // ================================================================
 // Escribe el código completo de tu solución aquí debajo
 // ================================================================
 //@ <answer>

class maximaComponenteConexa {
private:
    vector<bool> visitado;
    int maximaComponente;

    int dfs(Grafo const& g, int v) {
        visitado[v] = true;
        int tamanio = 1;
        for (int i : g.ady(v)) {
            if (!visitado[i]) {
                tamanio = tamanio + dfs(g, i);
                
            }
           
        }
        return tamanio;
    }

    

public:
    maximaComponenteConexa(Grafo const& g) : visitado(g.V(), false), maximaComponente(0) {

        for (int i = 0; i < g.V(); i++) {
            if (!visitado[i]) {
                maximaComponente = max(dfs(g, i), maximaComponente);
            }
        }

    }
    int maximo() {
        return maximaComponente;
    }
    

   
};

void resuelveCaso() {

    // leer los datos de la entrada
    int V, A;
    cin >> V >> A;
    Grafo amigos(V);
    int a1, a2;
    for (int i = 0; i < A; i++) {
        cin >> a1 >> a2;
        amigos.ponArista(a1 - 1, a2 - 1);
    }
    maximaComponenteConexa conexa(amigos);

    cout << conexa.maximo() << '\n';
    // resolver el caso posiblemente llamando a otras funciones

    // escribir la solución
}

//@ </answer>
//  Lo que se escriba dejado de esta línea ya no forma parte de la solución.

int main() {
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("1.in");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

    int numCasos;
    std::cin >> numCasos;
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();

    // para dejar todo como estaba al principio
#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif
    return 0;
}
