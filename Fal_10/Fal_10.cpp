// Nombre del alumno ......Sandra Wlodkowska
// Usuario del Juez ......FAL-C87


#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;
// función que resuelve el problema
//formalizacion
/*
COMPLEMENTARIO
precondicion n>=0

fun complementario(int n: ent): dev int complem
    cb: 9 - n si n<10

    cr: complementario ([n/10]) * 10 + (9 - (n mod 10)) si n>=10 

poscondicion complementario(n)

coste: 
    cb : O(1)
    cr : T(n) = O(k) siendo k el numero de digitos del numero ~ O(log n)


COMPLEMENTARIO INVERSO
precondicion n>=0

fun complementarioInverso (int n: ent, int resul: salida): dev resul: int
    cb: resul si n==0

    cr: complementarioInverso(n/10 , r*10 + 9 -(n mod 10)) n>0
poscondicion complemenatarioInverso(n)

coste: 
    cb : O(1)
    cr : T(n) = o(k) siendo k el numero de digitos del numero ~O(log n) ya que se recorren los digitos 1 vez

*/



long long int complementario(int n) {

    //caso base: complementario de un digito : n - 9
    if (n < 10) {
        return 9 - n;
    }
    else {
        return complementario(n / 10) * 10 + (9 - n % 10);
    }
    
}
long long int complemenatarioInverso(int n, long long int resul) {
    resul = resul * 10 + (9 - n % 10);
    n /= 10;
    if (n == 0) return resul;     
    return complemenatarioInverso(n, resul);
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    long long int n; cin >> n;
    cout << complementario(n) <<" "<<complemenatarioInverso(n,0)<< '\n';


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