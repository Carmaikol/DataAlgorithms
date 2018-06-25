
#include <iostream>
#include <vector>
#include "GrafoDirigido.h"



				
bool resuelveCaso();
GrafoDirigido construirGrafo(size_t N, size_t M);

// COMPLEJIDAD
//O(N + M) donde N es el numero de vertices y M es el numero de aristas.
bool resuelveCaso() {
	size_t V, A; //V(vertices), A(artistas)
	
	
	std::cin >> V >> A;
	if (std::cin.fail()) return false;

	GrafoDirigido grafo = construirGrafo(V,A);
	
	
	// if (!esAciclico) : O(1)
	if (A != V - 1){ //Comprueba que el grafo es aciclico sin pasar por el
		std::cout << "NO" << std::endl;
		return true;
	}
	
	
	
	size_t count = 1;
	size_t arboles = 0;
	size_t nodoInicial = -1;
	
	for (size_t i = 0; i < V; i++){
		DepthFirstDirectedPaths dfp = DepthFirstDirectedPaths(grafo, i);
		size_t j=1;
		count = 1;
			for(j = 1; j < V; j++){
				if (dfp.hasPathTo(j)){
					count++;
				
				if(count==V){
					nodoInicial = i;
					arboles++;
					}
				
				}
		}
	}
	
	
	if(arboles == 1){
		std::cout << "SI " << nodoInicial << std::endl;
	}else{
		std::cout << "NO" << std::endl;
	}
	


	return true;

}


GrafoDirigido construirGrafo(size_t N, size_t M){
	GrafoDirigido grafo = GrafoDirigido(N+1);
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


while(resuelveCaso()){}
	//size_t numeroCasos;
	
	//std::cin >> numeroCasos;
	
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
