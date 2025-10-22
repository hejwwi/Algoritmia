// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;
// función que resuelve el problema
int resolver(int ini, int fin, vector<int> priosioneros) {
    if (ini == fin) {
        if (priosioneros[ini] == ini) {
            return ini + 1;
        }
        else {
            return ini;
        }
    }
    else {
        int m = (ini + fin) / 2;
        if (priosioneros[m] == m) {
            return resolver(m + 1, fin, priosioneros);
        }
        else {
            return resolver(ini, m, priosioneros);
        }
    }

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    char ini, fin;
    cin >> ini >> fin;

    int inicio, final;
    inicio = (ini-'0') - (ini-'0');
    final = (fin-'0') - (ini - '0');
    vector<int> prisioneros(final);
    char aux;
    for (int i = 0; i < final; i++) {
        cin >> aux;
        prisioneros[i] = (aux - '0') - (ini - '0');
    }
    int resul = resolver(inicio, final - 1, prisioneros);
    int aux2 = resul + (ini);
    cout << (char)aux2 << '\n';
    // escribir sol



}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("1.in");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 


    int numCasos;
    std::cin >> numCasos;
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();


    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}