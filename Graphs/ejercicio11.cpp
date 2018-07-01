
#include <iostream>
#include <vector>
#include "GrafoDirigido.h"



void dfs(GrafoDirigido const& grafo, size_t v,size_t & _count, std::vector<bool> & _marked, bool & arbol);
bool resuelveCaso();
GrafoDirigido construirGrafo(size_t N, size_t M);


	//Complejidad O(V)
void dfs(GrafoDirigido const& grafo, size_t v,size_t& _count, std::vector<bool> & _marked, bool & arbol){
			++_count;
			_marked[v] = true; // para no repetir vértices
			for (auto w : grafo.adj(v)) { // recorremos todos los adyacentes a v
				if (!_marked[w]) {
					dfs(grafo, w, _count, _marked, arbol);
				}else{
						arbol = false;
						return;
						
				}
			}
	}


// COMPLEJIDAD
//O(N + M) donde N es el numero de vertices y M es el numero de aristas.
bool resuelveCaso() {
	size_t V, A; //V(vertices), A(artistas)
	size_t _count = 0;
	int nodoInicial = -1;
	bool arbol = true;
	
	std::cin >> V ;
	if (std::cin.fail()) return false;
	std::cin >> A;

	GrafoDirigido grafo = construirGrafo(V,A);
	
	
	// if (!esAciclico) : O(1)
	if (A != V - 1){ //Comprueba que el grafo es aciclico sin pasar por el
		std::cout << "NO" << std::endl;
		return true;
	}
	
	
	bool raiz = false;
	

	GrafoDirigido inverso = grafo.reverse();
	
	for (size_t i = 0; i < V && !raiz; i++){
		if(inverso.adj(i).size() == 0){
			nodoInicial = i;
			raiz = true;
			}
	}	
	
	std::vector<bool> _marked(V, false);
	
	if(nodoInicial != -1)
	dfs(grafo, nodoInicial,_count, _marked, arbol);
		
		
	if(!raiz || _count != V) {
		arbol = false;
	}
		

	if(arbol){
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
