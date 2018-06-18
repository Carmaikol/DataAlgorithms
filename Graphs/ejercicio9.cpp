#include <iostream>
#include <vector>
#include "Grafo.h"



class Solucion{
public:

	Solucion(Grafo const& grafo): _marked(grafo.V(),false),maximo(0) {
				for (size_t i = 0; i < grafo.V(); i++){
					if(!_marked[i]){
						size_t count = 0;
						dfs(grafo, i,count);
					
						maximo = std::max(count,maximo);
					}
				}
			}
			
	size_t getMaximo() const{
		return maximo;
	}
			
	
private:
	std::vector<bool> _marked;
	size_t maximo;
	
	//Complejidad O(N) donde N es el numero de vertices
	void dfs(Grafo const& grafo, size_t v, size_t& _count){
			++_count;
			_marked[v] = true; // para no repetir vértices
			for (auto w : grafo.adj(v)) { // recorremos todos los adyacentes a v
				if (!_marked[w]) {
					dfs(grafo, w, _count);
				}
			}
	}
			
	
};
				

size_t resuelveCaso();
Grafo construirGrafo(size_t N, size_t M);

// COMPLEJIDAD
//O(N + M) donde N es el numero de vertices y M es el numero de aristas.
size_t resuelveCaso() {
	size_t N, M; //N es el numero de personas(vertices), M el numero de pares de amigos(artistas)
	std::cin >> N >> M;

	Grafo grafo = construirGrafo(N,M);
	Solucion solucion = Solucion(grafo);
	
	
	return solucion.getMaximo();

}


//O(M)
Grafo construirGrafo(size_t N, size_t M){
	Grafo grafo = Grafo(N);
	size_t A, B;
	
	for(size_t i = 0; i < M; i++){
		std::cin >> A >> B;
		grafo.ponArista(A-1,B-1);
		}

	return grafo;
}


int main() {
//   ajustes  para   que cin  extraiga   directamente de un  fichero
//#ifndef DOMJUDGE
//std::ifstream in("casos.txt");
//auto cinbuf = std::cin.rdbuf(in.rdbuf());
//#endif


	size_t numeroCasos = 0;
	
	std::cin >> numeroCasos;
	
	while (numeroCasos > 0) {
		std::cout << resuelveCaso();
		numeroCasos--;
		}

//para dejar  todo  como  estaba  al  principio
//#ifndef  DOMJUDGE
//std::cin.rdbuf(cinbuf);
//system("PAUSE");
//#endif


	return 0;
}
