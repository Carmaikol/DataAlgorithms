#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include "Grafo.h"



std::vector<int> _negros;
std::vector<bool> _marked;
std::vector<bool> _esMancha;
//std::vector<bool> _esManchaAux;


void reiniciar(std::vector<bool>& _esMancha, std::vector<int> _negros);
bool resuelveCaso();
int calcularTamano(Grafo& grafo, std::vector<bool>& _esMancha, int indice);


// COMPLEJIDAD
//O(N * M) donde N es el numero de filas y M es el numero de columnas.
bool resuelveCaso() {
	int N, M, resultado = 0; //N es el numero de filas, M el numero de columnas
	
	std::cin >> N >> M;
	if (std::cin.fail()) return false;
	
	
	//size_t vertices = (N+1)*(M+1);
	int vertices = (N)*(M)  ;
	Grafo grafo(vertices);

	
	_negros = std::vector<int>();

	_esMancha = std::vector<bool>(vertices,false);

	_marked = std::vector<bool>(vertices,false);
	
	
	char nodo;
		std::cout << "Antes for: " << M*N << std::endl;
	for(int i = 0; i < vertices; i++){
		std::cin.get(nodo); if(nodo=='\n') std::cin.get(nodo);
		std::cout << "for   i: " << i << std::endl;
		if(nodo=='#'){
				std::cout << "es negro: " << i << std::endl;
			_esMancha[i] = true;
			_negros.push_back(i);
		
			//Elemento superior
				if(i-M >= 0 ){
					
					int indice_superior =  i - M;
				//	std::cout << "for   superior: " << indice_superior << std::endl;
					if(_esMancha[indice_superior]){
						grafo.ponArista(i,indice_superior);
					}
				}
				
				//Elemento izquierdo
				if(i%N > 0){
					int indice_izquierdo = i - 1;
				//	std::cout << "for   izquierdo: " << indice_izquierdo << std::endl;
					if(_esMancha[indice_izquierdo]){
						grafo.ponArista(i,indice_izquierdo);
					}
				}
				
				//Diagonal superior izquierda
				if(i%N > 0 && i-M-1 >= 0){
					int indice_superior_izquierdo = i - M -  1;
					//std::cout << "for   superior   izquierdo: " << indice_superior_izquierdo << std::endl;
					if(_esMancha[indice_superior_izquierdo]){
						grafo.ponArista(i,indice_superior_izquierdo);
					}
				}
			
			
			}
		}

	
		
	

	
	//std::vector<bool> esManchaAux = _esMancha;
	
	for(int i = 0; i < _negros.size(); i++){
		int local_result = 0;	
		std::vector<int> _resultados;
		local_result = calcularTamano(grafo,_esMancha, _negros[i]);
		//std::cout << "local:  : " << local_result << "   resultado: " <<  resultado << std::endl;
		resultado = std::max(local_result,resultado);
	}
		
		
		
	
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
		int indice_superior = indice - M;
		int indice_inferior = indice + M;
		int indice_izquierdo = indice - 1;
		int indice_derecho = indice + 1;
		
		
		int indice_ds_der = (i - 1) * M + j + 1;
		int indice_ds_izq = (i - 1) * M + j - 1;
		int indice_di_izq= (i+1) * N + j - 1;
		int indice_di_der= (i+1) * N + j + 1;
		
		
		_esMancha[indice] = true;
		_negros.push_back(indice);
				
		//Elemento superior
				if(i > 0 ){
					if(_esMancha[indice_superior]){
						grafo.ponArista(indice,indice_superior);
					}
				}
				
		//Elemento izquierdo
				if(j > 0){
					if(_esMancha[indice_izquierdo]){
						grafo.ponArista(indice,indice_izquierdo);
					}
				}
				
			
		
		//Elemento derecho
			if( i < M){
					if(_esMancha[indice_derecho]){
						grafo.ponArista(indice,indice_derecho);
					}
				}
				
				
			
		//Elemento inferior
			if(j < N){
					if(_esMancha[indice_inferior]){
						grafo.ponArista(indice,indice_inferior);
					}
				}
		
		
			//Diagonal superior derecha 
		if(i < M && j < N){
		
			
			if(_esMancha[indice_ds_der]){
				//	std::cout << "Es mancha: " << std::endl;
				grafo.ponArista(indice,indice_ds_der);
			}
		}
		
		//Diagonal superior izquierda
			if(i > 0  && j > 0){
					if(_esMancha[indice_ds_izq]){
						grafo.ponArista(indice,indice_ds_izq);
					}
				}
		
			//Diagonal inferior izquierda 
		if(i > 0   && j < N){
			if(_esMancha[indice_di_izq]){
				grafo.ponArista(indice,indice_di_izq);
			}
		}
		
		
			//Diagonal inferior derecha 
		if(i < M  && j < N){
			if(_esMancha[indice_di_der]){
				grafo.ponArista(indice,indice_di_der);
			}
		}
		
		
		
		
		
		
		
			for(int i = 0; i < _negros.size(); i++){
				int local_result = 0;	
				std::vector<int> _resultados;
				local_result = calcularTamano(grafo,_esMancha, _negros[i]);
				std::cout << "local:  : " << local_result << "   resultado: " <<  resultado << std::endl;
				resultado = std::max(local_result,resultado);
			}
		
		
		
		std::cout << resultado << std::endl;
		reiniciar(_esMancha, _negros);
			
		
	}


	return true;

}


int calcularTamano(Grafo& grafo, std::vector<bool>& _esMancha, int indice){
		
		int acumulador;
		_esMancha[indice] = false;
	
		
	//	_resultados.push_back(indice);
		
	//	while(_resultados.size()!=0){
		//	indice = _resultados.back();
		//	_resultados.pop_back();
			acumulador= 1;
			for(int i = 0; i < grafo.adj(indice).size(); i++){
				if(_esMancha[grafo.adj(indice)[i]])
						acumulador  += calcularTamano(grafo, _esMancha, grafo.adj(indice)[i]);
				}
			
				return acumulador;
		//	}
	
}


void reiniciar(std::vector<bool>& _esMancha, std::vector<int> _negros){
for(int i = 0; i < _negros.size(); i++){
	_esMancha[_negros[i]] = true;
		
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
	resuelveCaso();
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
