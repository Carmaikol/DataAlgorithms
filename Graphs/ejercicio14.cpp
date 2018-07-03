#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include "Grafo.h"
#include "ConjuntosDisjuntos.h"



bool resuelveCaso();


// COMPLEJIDAD
//O(N * M) donde N es el numero de filas y M es el numero de columnas.
bool resuelveCaso() {
	int N, M; //N es el numero de filas, M el numero de columnas
	size_t resultado = 0;
	std::vector<bool> _esPetroleo;
	std::vector<bool> _marked;
	std::vector<int> _negros;
	
	std::cin >> N;
	if (std::cin.fail()) return false;
	std::cin >> M;

	int vertices = (N+1)*(M)  ;

	_negros = std::vector<int>();
	_esPetroleo = std::vector<bool>(vertices,false);
	_marked = std::vector<bool>(vertices,false);
	ConjuntosDisjuntos conjunto(vertices);
	
	
	
	int i,j;
	char nodo;
	std::string linea;
	for(int _i = 0; _i < N+1; _i++){
		getline(std::cin,linea);
		for(int _j = 0; _j <  M; _j++){
			
			i = _i ;  //filas
			j = _j ;  //columnas
			
			nodo = linea[j];
			int indice = i * M + j;
			int indice_superior =  (i - 1)  * M + j;
			int indice_inferior =  (i + 1)  * M + j;
			int indice_izquierdo = i * M + j - 1 ;
			int indice_derecho = i * M + j + 1;
			int indice_ds_izq = (i - 1) * M + j - 1 ;
			int indice_ds_der = (i - 1) * M + j + 1;
			int indice_di_izq= (i+1) * M + j - 1;
			int indice_di_der= (i+1) * M + j + 1;
			
		if(nodo=='#'){
			
			_esPetroleo[indice] = true;
			_negros.push_back(indice);
		//Elemento superior
		if(i > 0 ){
			if(_esPetroleo[indice_superior]){
				conjunto.unir(indice,indice_superior);
			}
		}
				
		//Elemento izquierdo
		if(j > 0){
			if(_esPetroleo[indice_izquierdo]){
				conjunto.unir(indice,indice_izquierdo);
			}
		}
				
		
		//Elemento derecho
		if(j < M-1){
			if(_esPetroleo[indice_derecho]){
				conjunto.unir(indice,indice_derecho);
			}
		}
				
				
		//Elemento inferior
		if(i < N){
			if(_esPetroleo[indice_inferior]){
				conjunto.unir(indice,indice_inferior);
			}
		}
		
		
			//Diagonal superior derecha 
		if(i > 0 && j < M-1){
			if(_esPetroleo[indice_ds_der]){
				conjunto.unir(indice,indice_ds_der);
			}
		}
		
		//Diagonal superior izquierda
		if(i > 0  && j > 0){
				if(_esPetroleo[indice_ds_izq]){
					conjunto.unir(indice,indice_ds_izq);
				}
		}
		
			//Diagonal inferior izquierda 
		if(i < N   && j > 0){
			if(_esPetroleo[indice_di_izq]){
				conjunto.unir(indice,indice_di_izq);
			}
		}
		
			//Diagonal inferior derecha 
		if(i < N  && j < M-1){
			if(_esPetroleo[indice_di_der]){
				conjunto.unir(indice,indice_di_der);
			}
		}
			
			}
		}
	
	}

	
	
	for(size_t i = 0; i < _negros.size(); i++ ){
		if(!_marked[conjunto.buscar(_negros[i])]){
			size_t max_local = conjunto.size(_negros[i]);
			_marked[conjunto.buscar(_negros[i])] = true;
			resultado = std::max(resultado, max_local );
		}
	}
		
		
	//Restamos el borde blanco
	std::cout << resultado << std::endl;
	_marked = std::vector<bool>(vertices,false);




	//Segunda parte
	int numero_casos_nuevos, _i,_j;
	
	
	std::cin >> numero_casos_nuevos;
	
	for(int z = 0; z < numero_casos_nuevos; z++){
		std::cin >> _i >> _j;
		
		i = _i;  //filas
		j = _j - 1;  //columnas

		int indice = i * M + j;
		int indice_superior =  (i - 1)  * M + j;
		int indice_inferior =  (i + 1)  * M + j;
		int indice_izquierdo = i * M + j - 1 ;
		int indice_derecho = i * M + j + 1;
		int indice_ds_izq = (i - 1) * M + j - 1 ;
		int indice_ds_der = (i - 1) * M + j + 1;
		int indice_di_izq= (i+1) * M + j - 1;
		int indice_di_der= (i+1) * M + j + 1;
		
		
		_esPetroleo[indice] = true;
		_negros.push_back(indice);
				
		//Elemento superior
		if(i > 0 ){
			if(_esPetroleo[indice_superior]){
				conjunto.unir(indice,indice_superior);
			}
		}
				
		//Elemento izquierdo
		if(j > 0){
			if(_esPetroleo[indice_izquierdo]){
				conjunto.unir(indice,indice_izquierdo);
			}
		}
				
		
		//Elemento derecho
		if(j < M-1){
			if(_esPetroleo[indice_derecho]){
				conjunto.unir(indice,indice_derecho);
			}
		}
				
				
		//Elemento inferior
		if(i < N){
			if(_esPetroleo[indice_inferior]){
				conjunto.unir(indice,indice_inferior);
			}
		}
		
		
			//Diagonal superior derecha 
		if(i > 0 && j < M-1){
			if(_esPetroleo[indice_ds_der]){
				conjunto.unir(indice,indice_ds_der);
			}
		}
		
		//Diagonal superior izquierda
		if(i > 0  && j > 0){
				if(_esPetroleo[indice_ds_izq]){
					conjunto.unir(indice,indice_ds_izq);
				}
		}
		
			//Diagonal inferior izquierda 
		if(i < N   && j > 0){
			if(_esPetroleo[indice_di_izq]){
				conjunto.unir(indice,indice_di_izq);
			}
		}
		
			//Diagonal inferior derecha 
		if(i < N  && j < M-1){
			if(_esPetroleo[indice_di_der]){
				conjunto.unir(indice,indice_di_der);
			}
		}
		
		
		
		size_t max_local = conjunto.size(indice);
		resultado = std::max(resultado, max_local);
		
		
		std::cout << resultado << std::endl;
		
	}


	return true;

}



int main() {
//   ajustes  para   que cin  extraiga   directamente de un  fichero
#ifndef DOMJUDGE
std::ifstream in("casos_petrolero.txt");
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
