
/*@ <answer>
 *
 * Nombre y Apellidos: Sandra Wlodkowska
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

#include "Digrafo.h"  // propios o los de las estructuras de datos de clase

/*@ <answer>

 Escribe aquí un comentario general sobre la solución, explicando cómo
 se resuelve el problema y cuál es el coste de la solución, en función
 del tamaño del problema.

 @ </answer> */


 // ================================================================
 // Escribe el código completo de tu solución aquí debajo
 // ================================================================
 //@ <answer>

class deteccionCicloDirigido {
private:
    vector<bool> visit;
    vector<bool> apilado;
    bool hayCiclo;

    void dfs(Digrafo const& g, int v) {
        apilado[v] = true;
        visit[v] = true;

        for (int w : g.ady(v)) {

            if (!visit[w]) { // encontrado un nuevo vértice, seguimos
                dfs(g, w);
            }
            else if (apilado[w]) { // hemos detectado un ciclo
                // se recupera retrocediendo
                hayCiclo = true;
            }
        }
        apilado[v] = false;
    }

public:
    deteccionCicloDirigido(Digrafo const& g) : visit(g.V(), false), apilado(g.V(), false), hayCiclo(false) {
        dfs(g, 0);
    }

    bool ciclo() { 
        return hayCiclo;
    }
    bool alcanzable(int v) {
        return visit[v];
    }
};

bool resuelveCaso() {

    // leer los datos de la entrada
    int V;
    cin >> V;
    if (!std::cin)  // fin de la entrada
        return false;
    Digrafo instrucciones(V + 1);
    // resolver el caso posiblemente llamando a otras funciones
    char c;
    int n;
    for (int i = 0; i < V; i++) {
        cin >> c;
        if (c == 'A') {
            instrucciones.ponArista(i, i + 1);
        }
        else if (c == 'J') {
            cin >> n;
            instrucciones.ponArista(i, n - 1);
        }
        else if (c=='C') {
            cin >> n;
            instrucciones.ponArista(i, n - 1);
            instrucciones.ponArista(i, i + 1);
        }
    }

    //fnalAlcanzableDesdeOrigen alcanzable(instrucciones, 0);
    deteccionCicloDirigido ciclo(instrucciones);
    if (ciclo.alcanzable(V)) {


        if (ciclo.ciclo()) {
            cout << "A VECES" << '\n';
        }
        else {
            cout << "SIEMPRE" << '\n';
        }
    }
    else {
        cout << "NUNCA" << '\n';
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
