#include <iostream>
#include <vector>
#include <fstream>
#include "Grafo.h"



class Solucion{
public:

	Solucion(Grafo const& grafo): _marked(grafo.V(),false),_colores(grafo.V(),false),bipartito(true) {
				for (size_t i = 0; i < grafo.V() && bipartito; i++){
					if(!_marked[i]){
						dfs(grafo, i,bipartito);
					}
				}
			}
			
	bool esBipartito() const{
		return bipartito;
	}
			
	
private:

	std::vector<bool> _marked;
	std::vector<bool> _colores;
	bool bipartito;
	
	//Complejidad O(V)
	void dfs(Grafo const& grafo, size_t v, bool& bipartito){
			//++_count;
			_marked[v] = true; // para no repetir vértices
			for (auto w : grafo.adj(v)) { // recorremos todos los adyacentes a v
				if (!_marked[w]) {
					_colores[w] = !_colores[v];
					dfs(grafo, w, bipartito);
				}else{
					if(_colores[w] == _colores[v]){
						bipartito = false;
						}
				}
			}
	}
			
	
};
				
			



bool resuelveCaso();
Grafo construirGrafo(size_t N, size_t M);

// COMPLEJIDAD
//O(N + M) donde N es el numero de vertices y M es el numero de aristas.
bool resuelveCaso() {
	size_t N, M; //N es el numero de personas(vertices), M el numero de pares de amigos(artistas)
	
	if (std::cin.fail()) return false;
	std::cin >> N >> M;

	Grafo grafo = construirGrafo(N,M);
	Solucion solucion = Solucion(grafo);
	
	if(solucion.esBipartito()){
		std::cout << "SI" << std::endl;
	}else{
		std::cout << "NO" << std::endl;
	}
	
	
	return true;

}


Grafo construirGrafo(size_t N, size_t M){
	Grafo grafo = Grafo(N+1);
	size_t A, B;
	
	for(size_t i = 0; i < M; i++){
		std::cin >> A >> B;
		grafo.ponArista(A,B);
		}

	return grafo;
}


int main() {
//   ajustes  para   que cin  extraiga   directamente de un  fichero
//#ifndef DOMJUDGE
//std::ifstream in("casos.txt");
//auto cinbuf = std::cin.rdbuf(in.rdbuf());
//#endif


	//size_t numeroCasos;
	
	//std::cin >> numeroCasos;
	
	while(resuelveCaso()){}
	
	//while (numeroCasos > 0) {
	//	std::cout << resuelveCaso();
	//	numeroCasos--;
	//	}

//para dejar  todo  como  estaba  al  principio
//#ifndef  DOMJUDGE
//std::cin.rdbuf(cinbuf);
//system("PAUSE");
//#endif


	return 0;
}
