#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include "Grafo.h"


std::vector<int> _blancos;
std::vector<bool> _marked;
std::vector<bool> _esBlanco;


void dfs(Grafo& grafo, int indice);
bool resuelveCaso();



void dfs(Grafo& grafo, int indice){
		_marked[indice] = true;
			for (auto w : grafo.adj(indice)){
				if(!_marked[w] && _esBlanco[w]){
					dfs(grafo, w);
				}	
		}	
}

// COMPLEJIDAD
//O(N * M) donde N es el numero de filas y M es el numero de columnas.
bool resuelveCaso() {
	int N, M, resultado = 0; 
	
	std::cin >> M >> N;
	if (std::cin.fail()) return false;
	
	int vertices = (N+1)*(M)  ;
	Grafo grafo(vertices);

	_blancos = std::vector<int>();
	_esBlanco = std::vector<bool>(vertices,false);
	_marked = std::vector<bool>(vertices,false);
	
	
	char nodo;
	std::string linea;

	for(int i = 0; i < N+1; i++){
		getline(std::cin,linea);
		for(int j = 0; j < M; j++){
			nodo = linea[j];
			int indice = i * M + j;
			int indice_superior =  (i - 1)  * M + j;
			int indice_izquierdo = i * M + j - 1 ;
			
		if(nodo=='.'){
			_esBlanco[indice] = true;
			_blancos.push_back(indice);
		
			//Elemento superior
				if(j - 1 >= 0 ){
					if(_esBlanco[indice_superior]){
						grafo.ponArista(indice,indice_superior);
					}
				}
				
				//Elemento izquierdo
				if(i - 1 >= 0){
					if(_esBlanco[indice_izquierdo]){
						grafo.ponArista(indice,indice_izquierdo);
					}
				}
			
			}
		}
	}


	for(int i = 0; i < _blancos.size(); i++){
		int indice  = _blancos[i];

		if(!_marked[indice]) {
			resultado++;
			dfs(grafo, indice);
		}
	}
		
	//Restamos el borde blanco
	std::cout << resultado-1 << std::endl;



	return true;

}




	
	



int main() {
//   ajustes  para   que cin  extraiga   directamente de un  fichero
#ifndef DOMJUDGE
std::ifstream in("casos.txt");
auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif


	//size_t numeroCasos;
	
	//std::cin >> numeroCasos;
	while(resuelveCaso()){}
//	while(){}
	
	//while (numeroCasos > 0) {
	//	std::cout << resuelveCaso();
	//	numeroCasos--;
	//	}

//para dejar  todo  como  estaba  al  principio
#ifndef  DOMJUDGE
std::cin.rdbuf(cinbuf);
system("PAUSE");
#endif

	return 0;
}
