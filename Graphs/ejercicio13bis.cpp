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
	//	std::cout << N << "   " << M << std::endl;

	//size_t vertices = (N+1)*(M+1);
	size_t vertices = (N+N)*(M)    ;
	Grafo grafo(vertices);
//	Grafo grafo(N*M +1);
	
	_blancos = std::stack<size_t>();
	//_esBlanco = std::vector<bool>(N*M +1,false);
	_esBlanco = std::vector<bool>(vertices,false);
	_marked = std::vector<bool>(vertices,false);
	//_marked = std::vector<bool>(N*M +1,false);
	
	std::string linea;

		std::cout << "N: " << N << "  M: " << M <<  "NxM"<< N*M << "GRAFO V  "<< grafo.V()  << std::endl;


	for(size_t i = 1; i <= M+1; i++){
		getline(std::cin, linea);
		std::cout << "Linea: " << linea << "  i: " << i << std::endl;
		for(size_t j = 1; j < N; j++){
			//Si el elemento es blanco se le anade una arista
			if(linea[j-1] == '.'){
				size_t indice = i * N  + j;
				_esBlanco[indice] = true;
				_blancos.push(indice);
				//std::cout << "Blanco: " << linea << "  i: " << i << std::endl;
				
				//Elemento superior
				if(i-1 >= 0 ){
					size_t indice_superior = (i-1) * N + j;
					if(_esBlanco[indice_superior]){
							std::cout << "pongo arista superior: " << indice_superior << std::endl;
						grafo.ponArista(indice,indice_superior);
						std::cout <<"Lo consigo"<< std::endl;
					}
				}
				
				//Elemento izquierdo
				if(j-1 >= 0){
					size_t indice_izquierdo = i * N + j - 1;
					
					if(_esBlanco[indice_izquierdo]){
						std::cout << "pongo arista superior: " << indice_izquierdo << std::endl;
						grafo.ponArista(indice,indice_izquierdo);
								std::cout <<"Lo consigo"<< std::endl;
					}
				}
			}
		}
	}
	
	std::cout << "salgo del for: " << linea << std::endl;
			while(_blancos.size() > 0){
				
	std::cout << "blancos size: " << _blancos.size() << std::endl;
				size_t indice  = _blancos.top();
				_blancos.pop();
				if(!_marked[indice]) {
					std::cout << "suma a resultado: " << resultado+1 << std::endl;
					resultado++;
					dfs(grafo, indice, N, M);
					}
				}
				
				

	//Se resta el borde al resultado
	std::cout << resultado-1 << std::endl;


	return true;

}


void dfs(Grafo grafo, size_t indice, size_t N, size_t M){
			_marked[indice] = true;
			for (auto w : grafo.adj(indice)){
				if(!_marked[w]){
					dfs(grafo, w, N, M);
				}
				
		}
	
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
