#include <iostream>
#include <vector>
#include "Grafo.h"


std::vector<std::vector<bool>> _marked;
std::vector<std::pair<size_t,size_t>> direcciones[4];



bool resuelveCaso();
void dfs(std::vector<std::string> foto,std::pair<size_t,size_t> posicion, size_t N, size_t M);
Grafo construirGrafo(size_t N, size_t M);

// COMPLEJIDAD
//O(N + M) donde N es el numero de vertices y M es el numero de aristas.
bool resuelveCaso() {
	size_t N, M, resultado = 0; //N es el numero de columnas, M el numero de filas
	

	std::pair<size_t,size_t> posicion;
	
	
	std::cin >> N >> M;
	if (std::cin.fail()) return false;

	Grafo grafo = construirGrafo(N,M);


	std::vector<std::string> foto(M,".");
	//Eliminar el salto de linea
	std::cin.get(); 

	for(int i = 0; i < M; i++){
		getline(std::cin, foto[i]);
	}

	
	 _marked(N, std::vector<bool>(M,false)) ;
	
	for(size_t i = 0; i < N; i++){
		for(size_t j = 0; i < M; j++){
			//Encuentro posicion blanca
			if(!_marked[i][j] && foto[i][j] != 'X'){ 
					resultado++;
					std::pair<size_t,size_t> posicion = std::pair<size_t,size_t>(i,j);
					dfs(foto, posicion,N,M);
			}
				
				
			
		}
	}
	

		std::cout << resultado << std::endl;

	
	
	
	return true;

}


void dfs(std::vector<std::string> foto,std::pair<size_t,size_t> posicion, size_t N, size_t M){
	_marked[posicion.first][posicion.second];
	//Recorremos los vecinos
	for(int i = 0; i < 4; i++){
		std::pair<size_t,size_t> vecino(posicion.first + direcciones[i].first, posicion.second + direcciones[i].second);
		if(vecino.first >= 0 && vecino.first < N && vecino.second >= 0 && vecino.second < M && foto[vecino.first][vecino.second] != 'X' && !_marked[vecino.first][vecino.second]){
			dfs(foto,vecino,N,M);
			}
		}
	
	
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
	direcciones[4] = {
		std::pair<size_t,size_t>(0,1),
		std::pair<size_t,size_t>(0,-1),
		std::pair<size_t,size_t>(1,1),
		std::pair<size_t,size_t>(1,-1)
	};
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
