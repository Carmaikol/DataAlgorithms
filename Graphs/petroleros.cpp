#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include "Grafo.h"
#include "ConjuntosDisjuntos.h"



int calcularTamano(Grafo& grafo, std::vector<bool>& _esPetroleo, int indice, std::vector<bool> &  _marked);
bool resuelveCaso();


// COMPLEJIDAD
//O(N * M) donde N es el numero de filas y M es el numero de columnas.
bool resuelveCaso() {
	int N, M, resultado = 0; //N es el numero de filas, M el numero de columnas
	
	std::vector<bool> _esPetroleo;
	std::vector<bool> _marked;
	std::vector<int> _negros;
	
	
	std::cin >> N >> M;
	if (std::cin.fail()) return false;
	
	
	//size_t vertices = (N+1)*(M+1);
	int vertices = (N+1)*(M)  ;
	Grafo grafo(vertices);

	_negros = std::vector<int>();
	_esPetroleo = std::vector<bool>(vertices,false);
	_marked = std::vector<bool>(vertices,false);
	ConjuntosDisjuntos conjunto(vertices);
	
	
	
	
	char nodo;
	std::string linea;

	for(int i = 0; i < N+1; i++){
		getline(std::cin,linea);
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
						conjunto.unir(indice,indice_superior);
					}
				}
				
				//Elemento izquierdo
				if(i - 1 >= 0){
					if(_esPetroleo[indice_izquierdo]){
						grafo.ponArista(indice,indice_izquierdo);
						conjunto.unir(indice,indice_izquierdo);
					}
				}
				
					//Elemento superior izquierdo
				if(i - 1 >= 0 && j-1 >= 0){
					if(_esPetroleo[indice_superior_izquierdo]){
						grafo.ponArista(indice,indice_superior_izquierdo);
						conjunto.unir(indice,indice_superior_izquierdo);
					}
				}
			
			}
		}
	}

	
		

	for(int i = 0; i < _negros.size(); i++){
		int local_result = 0;	
		local_result = calcularTamano(grafo, _esPetroleo, _negros[i], _marked);
		resultado = std::max(local_result,resultado);
	}
	
	
	//size_t max_l = 0;
	//for(int i = 0; i < conjunto.count(); i++ ){
	//	resultado = std::max(max_l, conjunto.size(i));
	//}
		
		
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
				
		std::cout << "INDICE: " << indice << std::endl;
				
		//Elemento superior
		if(i > 0 ){
			if(_esPetroleo[indice_superior]){
				
				
				std::cout << "Superior" << std::endl;
				grafo.ponArista(indice,indice_superior);
				conjunto.unir(indice,indice_superior);
			}
		}
				
		//Elemento izquierdo
		if(j > 0){
			if(_esPetroleo[indice_izquierdo]){
				std::cout << "Izquierdo" << std::endl;
				grafo.ponArista(indice,indice_izquierdo);
				conjunto.unir(indice,indice_izquierdo);
			}
		}
				
		
		//Elemento derecho
		if(i < M){
			if(_esPetroleo[indice_derecho]){
				
				std::cout << "Derecho" << std::endl;
				grafo.ponArista(indice,indice_derecho);
				conjunto.unir(indice,indice_derecho);
			}
		}
				
				
		//Elemento inferior
		if(j < N){
			if(_esPetroleo[indice_inferior]){
				std::cout << "Inferior" << std::endl;
				grafo.ponArista(indice,indice_inferior);
				conjunto.unir(indice,indice_inferior);
			}
		}
		
		
			//Diagonal superior derecha 
		if(i > 0 && j < N){
			if(_esPetroleo[indice_ds_der]){
				std::cout << "Superior derecho" << std::endl;
				grafo.ponArista(indice,indice_ds_der);
				conjunto.unir(indice,indice_ds_der);
			}
		}
		
		//Diagonal superior izquierda
		if(i > 0  && j > 0){
				if(_esPetroleo[indice_ds_izq]){
					std::cout << "Superior izq" << std::endl;
					grafo.ponArista(indice,indice_ds_izq);
					conjunto.unir(indice,indice_ds_izq);
				}
		}
		
			//Diagonal inferior izquierda 
		if(i < M   && j > 0){
			if(_esPetroleo[indice_di_izq]){
						std::cout << "Inferior izq" << std::endl;
				grafo.ponArista(indice,indice_di_izq);
				conjunto.unir(indice,indice_di_izq);
			}
		}
		
			//Diagonal inferior derecha 
		if(i < M  && j < N){
			if(_esPetroleo[indice_di_der]){
						std::cout << "Inferior" << std::endl;
				grafo.ponArista(indice,indice_di_der);
				conjunto.unir(indice,indice_di_der);
			}
		}
		
		
		
		for(int i = 0; i < _negros.size(); i++){
			int local_result = 0;	
			std::vector<int> _resultados;
			local_result = calcularTamano(grafo,_esPetroleo, _negros[i], _marked);
			//std::cout << "local:  : " << local_result << "   resultado: " <<  resultado << std::endl;
			resultado = std::max(local_result,resultado);
			}
		
		
	//	for(int i = 0; i < conjunto.count(); i++ ){
	//	
		
	//	max_l = 	std::max(max_l, conjunto.size(i));
			
	//	std::cout << "maxl:  : " << max_l  << std::endl;
		
	//	}
		
		
		std::cout << resultado << std::endl;
		_marked = std::vector<bool>(vertices,false);
		
	}


	return true;

}







int calcularTamano(Grafo& grafo, std::vector<bool>& _esPetroleo, int indice, std::vector<bool> & _marked){
		
		int acumulador;
		//_esPetroleo[indice] = false;
		_marked[indice] = true;
		acumulador= 1;
		
		for(int i = 0; i < grafo.adj(indice).size(); i++){
				if(_esPetroleo[grafo.adj(indice)[i]] && !_marked[grafo.adj(indice)[i]])
						acumulador  += calcularTamano(grafo, _esPetroleo, grafo.adj(indice)[i], _marked);
		}
				
	return acumulador;	
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
