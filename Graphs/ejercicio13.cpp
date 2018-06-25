#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include "Grafo.h"



std::stack<size_t> _blancos;
std::vector<bool> _marked;
std::vector<bool> _esBlanco;

bool resuelveCaso();
void dfs(Grafo grafo, size_t indice, size_t N, size_t M);


// COMPLEJIDAD
//O(N * M) donde N es el numero de columnas y M es el numero de filas.
bool resuelveCaso() {
	size_t N, M, resultado = 0; //N es el numero de columnas, M el numero de filas
	
	std::cin >> N >> M;
	if (std::cin.fail()) return false;

	Grafo grafo(N*M);
	
	_esBlanco = std::vector<bool>(N*M,false);
	_marked = std::vector<bool>(N*M,false);
	
	std::string linea;

	for(size_t i = 0; i < M; i++){
		getline(std::cin, linea);
		for(size_t j = 0; j < N; j++){
			//Si el elemento es blanco se le anade una arista
			if(linea[j] == '.'){
				size_t indice = i * N + j;
				_esBlanco[indice] = true;
				_blancos.push(indice);
				
				//Elemento superior
				if(i-1 >= 0){
					size_t indice_superior = (i-1) * N + j;
					if(_esBlanco[indice_superior]){
						grafo.ponArista(indice,indice_superior);
					}
				}
				
				//Elemento izquierdo
				if(j-1 >= 0){
					size_t indice_izquierdo = i * N + j - 1;
					
					if(_esBlanco[indice_izquierdo]){
						grafo.ponArista(indice,indice_izquierdo);
					}
				}
			}
		}
	}
				
			while(_blancos.size() > 0){
				size_t indice  = _blancos.top();
				_blancos.pop();
				if(!_marked[indice]) {
					resultado++;
					dfs(grafo, indice, N, M);
					}
				}
				
	//Se resta el borde al resultado
	std::cout << resultado - 1 << std::endl;

	return true;

}


void dfs(Grafo grafo, size_t indice, size_t N, size_t M){
		_marked[indice] = true;
			for (auto w : grafo.adj(indice)){
				if(!_marked[w] && _esBlanco[w]){
					dfs(grafo, w, N, M);
				}
				
		}
	
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
