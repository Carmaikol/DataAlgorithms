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
	
	std::cin >> N >> M;
	if (std::cin.fail()) return false;
	

	int vertices = (N+1)*(M+1)  ;

	_negros = std::vector<int>();
	_esPetroleo = std::vector<bool>(vertices,false);
	_marked = std::vector<bool>(vertices,false);
	ConjuntosDisjuntos conjunto(vertices);
	
	
	
	int i,j;
	char nodo;
	std::string linea;
	getline(std::cin,linea);
//	std::cout << "Linea1: " << linea << std::endl;
	for(int _i = 1; _i <= N; _i++){
		getline(std::cin,linea);
	//	std::cout << "_i: " << _i<< std::endl;
	//	std::cout << "Linea: " << linea << std::endl;
		for(int _j = 1; _j <= M; _j++){
			
			i = _i - 1;  //filas
			j = _j - 1;  //columnas
			
	//		std::cout << "i: " << i<< std::endl;
	//		std::cout << "j: " << j<< std::endl;
			nodo = linea[j];
	//		std::cout << "nodo: " << nodo << std::endl;
			int indice = i * M + j;	
	//		std::cout << "indice: " << indice << std::endl;
			int indice_superior =  (i - 1) * M + j;
	//		std::cout << "indice superior: " << indice_superior << std::endl;
			int indice_izquierdo = i * M + j - 1 ;
	//		std::cout << "indice izquierdo: " << indice_izquierdo << std::endl;
			int indice_superior_izquierdo = (i-1) * M + j - 1 ;
		//	std::cout << "indice superior izquierdo: " << indice_superior_izquierdo << std::endl;
			
		if(nodo=='#'){
			
			_esPetroleo[indice] = true;
			_negros.push_back(indice);
		//	std::cout << "pusheo a negros: " << indice << std::endl;
		//	std::cout << "i: " << i<< std::endl;
		//	std::cout << "j: " << j<< std::endl;
			//Elemento superior
				if(i  > 0 ){
					if(_esPetroleo[indice_superior]){
						conjunto.unir(indice,indice_superior);
					}
				}
				
				//Elemento izquierdo
				if(j  > 0){
					if(_esPetroleo[indice_izquierdo]){
						conjunto.unir(indice,indice_izquierdo);
					}
				}
				
					//Elemento superior izquierdo
				if(i  > 0 && j > 0){
					if(_esPetroleo[indice_superior_izquierdo]){
						conjunto.unir(indice,indice_superior_izquierdo);
					}
				}
			
			}
		}
	
	}

	
	
	for(size_t i = 0; i < _negros.size(); i++ ){
	//	std::cout << "buscar: "  << conjunto.buscar(_negros[i]) << std::endl;
		if(!_marked[conjunto.buscar(_negros[i])]){
			size_t max_local = conjunto.size(_negros[i]);
	//		std::cout << "MAX: "  << max_local << std::endl;
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
	//std::cout << "Casos nuevos: " << numero_casos_nuevos<< std::endl;
	
	for(int z = 0; z < numero_casos_nuevos; z++){
		std::cin >> _i >> _j;
		
		i = _i - 1;  //filas
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
		//		std::cout << "Superior" << std::endl;
				conjunto.unir(indice,indice_superior);
			}
		}
				
		//Elemento izquierdo
		if(j > 0){
			if(_esPetroleo[indice_izquierdo]){
				//std::cout << "Izquierdo" << std::endl;
				conjunto.unir(indice,indice_izquierdo);
			}
		}
				
		
		//Elemento derecho
		if(j < M){
			if(_esPetroleo[indice_derecho]){
				
				//std::cout << "Derecho" << std::endl;
				conjunto.unir(indice,indice_derecho);
			}
		}
				
				
		//Elemento inferior
		if(i < N){
			if(_esPetroleo[indice_inferior]){
			//	std::cout << "Inferior" << std::endl;
				conjunto.unir(indice,indice_inferior);
			}
		}
		
		
			//Diagonal superior derecha 
		if(i > 0 && j < M){
			if(_esPetroleo[indice_ds_der]){
			//	std::cout << "Superior derecho" << std::endl;
				conjunto.unir(indice,indice_ds_der);
			}
		}
		
		//Diagonal superior izquierda
		if(i > 0  && j > 0){
				if(_esPetroleo[indice_ds_izq]){
			//		std::cout << "Superior izq" << std::endl;
					conjunto.unir(indice,indice_ds_izq);
				}
		}
		
			//Diagonal inferior izquierda 
		if(i < N   && j > 0){
			if(_esPetroleo[indice_di_izq]){
		//				std::cout << "Inferior izq" << std::endl;
				conjunto.unir(indice,indice_di_izq);
			}
		}
		
			//Diagonal inferior derecha 
		if(i < N  && j < M){
			if(_esPetroleo[indice_di_der]){
		//				std::cout << "Inferior" << std::endl;
				conjunto.unir(indice,indice_di_der);
			}
		}
		
		
		for(size_t i = 0; i < _negros.size(); i++ ){
			if(!_marked[conjunto.buscar(_negros[i])]){
				size_t max_local = conjunto.size(_negros[i]);
				_marked[conjunto.buscar(_negros[i])] = true;
				resultado = std::max(resultado, max_local);
			}
		}
		
		std::cout << resultado << std::endl;
		_marked = std::vector<bool>(vertices,false);
		
	}


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
