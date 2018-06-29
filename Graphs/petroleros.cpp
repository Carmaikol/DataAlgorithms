#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include "Grafo.h"



std::vector<int> _negros;
std::vector<bool> _marked;
std::vector<bool> _esPetroleo;
//std::vector<bool> _esPetroleoAux;



void reiniciar(std::vector<bool>& _esPetroleo, std::vector<int> _negros);
int calcularTamano(Grafo& grafo, std::vector<bool>& _esPetroleo, int indice);
bool resuelveCaso();





// COMPLEJIDAD
//O(N * M) donde N es el numero de filas y M es el numero de columnas.
bool resuelveCaso() {
	int N, M, resultado = 0; //N es el numero de filas, M el numero de columnas
	
	std::cin >> N >> M;
	if (std::cin.fail()) return false;
	
	
	//size_t vertices = (N+1)*(M+1);
	int vertices = (N+1)*(M)  ;
	Grafo grafo(vertices);

	_negros = std::vector<int>();
	_esPetroleo = std::vector<bool>(vertices,false);
	_marked = std::vector<bool>(vertices,false);
	
	
	char nodo;
	std::string linea;

	for(int i = 0; i < N+1; i++){
		getline(std::cin,linea);
		//std::cout << "linea: " << linea << std::endl;
		for(int j = 0; j < M; j++){
			nodo = linea[j];
			int indice = i * M + j;
			int indice_superior =  (i - 1)  * M + j;
			int indice_izquierdo = i * M + j - 1 ;
			int indice_superior_izquierdo = (i-1) * M + j - 1 ;
			
		if(nodo=='#'){
			_esPetroleo[indice] = true;
			_negros.push_back(indice);
		
			//Elemento superior
				if(j - 1 >= 0 ){
					if(_esPetroleo[indice_superior]){
						grafo.ponArista(indice,indice_superior);
					}
				}
				
				//Elemento izquierdo
				if(i - 1 >= 0){
					if(_esPetroleo[indice_izquierdo]){
						grafo.ponArista(indice,indice_izquierdo);
					}
				}
				
					//Elemento superior izquierdo
				if(i - 1 >= 0 && j-1 >= 0){
					if(_esPetroleo[indice_superior_izquierdo]){
						grafo.ponArista(indice,indice_superior_izquierdo);
					}
				}
			
			}
		}
	}

	
		

	for(int i = 0; i < _negros.size(); i++){
		int local_result = 0;	
		local_result = calcularTamano(grafo, _esPetroleo, _negros[i]);
		//std::cout << "local:  : " << local_result << "   resultado: " <<  resultado << std::endl;
		resultado = std::max(local_result,resultado);
	}
		
		
	//Restamos el borde blanco
	std::cout << resultado << std::endl;





	//Segunda parte
	int numero_casos_nuevos, i, j, _i,_j;
	
	
	std::cin >> numero_casos_nuevos;
	//std::cout << "Casos nuevos: " << numero_casos_nuevos<< std::endl;
	
	for(int z = 0; z < numero_casos_nuevos; z++){
		std::cin >> _i >> _j;
	//	std::cin >> x >> y;
		
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
						grafo.ponArista(indice,indice_superior);
					}
				}
				
		//Elemento izquierdo
				if(j > 0){
					if(_esPetroleo[indice_izquierdo]){
						grafo.ponArista(indice,indice_izquierdo);
					}
				}
				
		
		//Elemento derecho
			if(i < M){
					if(_esPetroleo[indice_derecho]){
						grafo.ponArista(indice,indice_derecho);
					}
				}
				
				
			
		//Elemento inferior
			if(j < N){
					if(_esPetroleo[indice_inferior]){
						grafo.ponArista(indice,indice_inferior);
					}
				}
		
		
			//Diagonal superior derecha 
		if(i > 0 && j < N){
			if(_esPetroleo[indice_ds_der]){
				grafo.ponArista(indice,indice_ds_der);
			}
		}
		
		//Diagonal superior izquierda
			if(i > 0  && j > 0){
					if(_esPetroleo[indice_ds_izq]){
						grafo.ponArista(indice,indice_ds_izq);
					}
				}
		
			//Diagonal inferior izquierda 
		if(i > M   && j > 0){
			if(_esPetroleo[indice_di_izq]){
				grafo.ponArista(indice,indice_di_izq);
			}
		}
		
			//Diagonal inferior derecha 
		if(i < M  && j < N){
			if(_esPetroleo[indice_di_der]){
				grafo.ponArista(indice,indice_di_der);
			}
		}
		
		
		
		for(int i = 0; i < _negros.size(); i++){
			int local_result = 0;	
			std::vector<int> _resultados;
				local_result = calcularTamano(grafo,_esPetroleo, _negros[i]);
				//std::cout << "local:  : " << local_result << "   resultado: " <<  resultado << std::endl;
				resultado = std::max(local_result,resultado);
			}
		
		
		
		std::cout << resultado << std::endl;
		reiniciar(_esPetroleo, _negros);
			
		
	}


	return true;

}




int calcularTamano(Grafo& grafo, std::vector<bool>& _esPetroleo, int indice){
		
		int acumulador;
		_esPetroleo[indice] = false;
		acumulador= 1;
		
		for(int i = 0; i < grafo.adj(indice).size(); i++){
				if(_esPetroleo[grafo.adj(indice)[i]])
						acumulador  += calcularTamano(grafo, _esPetroleo, grafo.adj(indice)[i]);
		}
				
	return acumulador;	
}


void reiniciar(std::vector<bool>& _esPetroleo, std::vector<int> _negros){
	for(int i = 0; i < _negros.size(); i++){
		_esPetroleo[_negros[i]] = true;
			
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
