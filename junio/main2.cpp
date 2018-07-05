
#include <iostream>
#include <vector>
#include "Grafo.h"



void dfs(Grafo const& grafo, size_t v,size_t & _count, std::vector<bool> & _marked, bool & arbol);
bool resuelveCaso();
Grafo construirGrafo(size_t N, size_t M, size_t& nodo_inicial);


	//Complejidad O(V)
void dfs(Grafo const& grafo, size_t v,size_t& _count, std::vector<bool> & _marked, bool & arbol){
			++_count;
			_marked[v] = true; // para no repetir vértices
			for (auto w : grafo.adj(v)) { // recorremos todos los adyacentes a v
				if (!_marked[w]) {
					
					dfs(grafo, w, _count, _marked, arbol);
				}
			}
	}


// COMPLEJIDAD
//O(N + M) donde N es el numero de vertices y M es el numero de aristas.
bool resuelveCaso() {
	size_t V, A; //V(vertices), A(artistas)
	size_t _count = 0;
	size_t nodo_inicial = -1;
	bool arbol = true;
	
	std::cin >> V ;
	if (std::cin.fail()) return false;
	std::cin >> A;

	Grafo grafo = construirGrafo(V,A, nodo_inicial);
	
	
	// if (!esAciclico) : O(1)
	if (A != V - 1){ //Comprueba que el grafo es aciclico sin pasar por el
		std::cout << "NO" << std::endl;
		return true;
	}
	
	
	
	
	std::vector<bool> _marked(V, false);
	
	if(nodo_inicial != -1)
	dfs(grafo, nodo_inicial,_count, _marked, arbol);
		
		
		
	//std::cout << "Nodo inicial: " << nodo_inicial << std::endl;
//	std::cout << "Count: " << _count << std::endl;
	if(_count != V) {
		arbol = false;
	}
		

	if(arbol){
		std::cout << "SI "  << std::endl;
	}else{
		std::cout << "NO" << std::endl;
	}
	


	return true;

}


Grafo construirGrafo(size_t N, size_t M, size_t & nodo_inicial){
	Grafo grafo = Grafo (N+1);
	size_t A, B;
	
	for(size_t i = 0; i < M; i++){
		std::cin >> A >> B;
		grafo.ponArista(A,B);
		if(i==0) nodo_inicial = A;
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
