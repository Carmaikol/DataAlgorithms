#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include "Grafo.h"



std::vector<size_t> _negros;
std::vector<bool> _marked;
std::vector<bool> _esMancha;
//std::vector<bool> _esManchaAux;


void reiniciar(std::vector<bool>& _esMancha, std::vector<size_t> _negros);
bool resuelveCaso();
void calcularTamano(Grafo& grafo, std::vector<bool>& _esMancha, size_t indice, size_t& acumulador, std::vector<size_t>& _resultados);


// COMPLEJIDAD
//O(N * M) donde N es el numero de columnas y M es el numero de filas.
bool resuelveCaso() {
	size_t N, M, resultado = 0; //N es el numero de columnas, M el numero de filas
	
	std::cin >> N >> M;
	if (std::cin.fail()) return false;
	
	
	//size_t vertices = (N+1)*(M+1);
	size_t vertices = (N)*(M)  ;
	Grafo grafo(vertices+1);
//	Grafo grafo(N*M +1);
	
	_negros = std::vector<size_t>();
	//_esMancha = std::vector<bool>(N*M +1,false);
	_esMancha = std::vector<bool>(vertices+1,false);
	//_esManchaAux = std::vector<bool>(vertices,false);
	_marked = std::vector<bool>(vertices,false);
	//_marked = std::vector<bool>(N*M +1,false);
	
	char nodo;
	
	for(size_t i = 0; i < vertices; i++){
		std::cin.get(nodo); if(nodo=='\n') std::cin.get(nodo);
		
		if(nodo=='#'){
			_esMancha[i] = true;
			_negros.push_back(i);
			
			//Elemento superior
				if(i-N >= 0 ){
					size_t indice_superior =  i - N;
					if(_esMancha[indice_superior]){
						grafo.ponArista(i,indice_superior);
					}
				}
				
				//Elemento izquierdo
				if(i%M > 0){
					size_t indice_izquierdo = i - 1;
					
					if(_esMancha[indice_izquierdo]){
						grafo.ponArista(i,indice_izquierdo);
					}
				}
				
				//Diagonal superior izquierda
				if(i%M > 0 && i-N >= 0){
					size_t indice_superior_izquierdo = i - N -  1;
					
					if(_esMancha[indice_superior_izquierdo]){
						grafo.ponArista(i,indice_superior_izquierdo);
					}
				}
			
			
			}
		}

	
		
	

	
	//std::vector<bool> esManchaAux = _esMancha;
	
	for(size_t i = 0; i < _negros.size(); i++){
		size_t local_result = 0;	
		std::vector<size_t> _resultados;
		calcularTamano(grafo,_esMancha, _negros[i],local_result, _resultados);
		resultado = std::max(local_result,resultado);
	}
		
		
		
	
	std::cout << resultado << std::endl;



	//Segunda parte
	size_t numero_casos_nuevos, x, y, _i,_j;
	
	
	std::cin >> numero_casos_nuevos;
		std::cout << "Casos nuevos: " << numero_casos_nuevos<< std::endl;
	
	for(size_t i = 0; i < numero_casos_nuevos; i++){
		std::cin >> _i >> _j;
	//	std::cin >> x >> y;
		
		x = _i - 1;
		y = _j - 1;
		std::cout << "x: " << x << "  y: " << y << std::endl;
		
		size_t indice = x * N + y;
		std::cout << "Indice   " << indice  << std::endl;
		_esMancha[indice] = true;
		_negros.push_back(indice);
				
		//Elemento superior
		if(x-1 >= 0 ){
			size_t indice_superior = (x-1) * N + y;
			std::cout << "Indice Superior: " << indice_superior<< std::endl;
			if(_esMancha[indice_superior]){
					std::cout << "Es mancha: " << std::endl;
				grafo.ponArista(indice,indice_superior);
				
				
				
			}
		}
				
		//Elemento izquierdo
		if(y-1 >= 0){
			size_t indice_izquierdo = x * N + y - 1;
			std::cout << "Indice izquierdo: " << indice_izquierdo<< std::endl;
			if(_esMancha[indice_izquierdo]){
					std::cout << "Es mancha: " << std::endl;
				grafo.ponArista(indice,indice_izquierdo);
			}
		}
		
		//Elemento inferior
		if(x+1 < M){
			size_t indice_inferior= (x+1) * N + y;
						std::cout << "Indice inferior: " << indice_inferior<< std::endl;
			if(_esMancha[indice_inferior]){
					std::cout << "Es mancha: " << std::endl;
				grafo.ponArista(indice,indice_inferior);
			}
		}
		
		
		//Elemento derecho
		if(y+1 < N){
			size_t indice_derecho= x * N + y + 1;
						std::cout << "Indice derecho: " << indice_derecho<< std::endl;
			if(_esMancha[indice_derecho]){
					std::cout << "Es mancha: " << std::endl;
				grafo.ponArista(indice,indice_derecho);
			}
		}
		
		//Diagonal superior izquierda 
		if(y-1 >= 0 && x-1 >= 0 ){
			size_t indice_ds_izq = (x-1) * N + y -1;
					std::cout << "Indice ds izq: " << indice_ds_izq<< std::endl;
			if(_esMancha[indice_ds_izq]){
					std::cout << "Es mancha: " << std::endl;
				grafo.ponArista(indice,indice_ds_izq);
			}
		}
		
			//Diagonal superior derecha 
		if(y+1 < N && x-1 >= 0 ){
			size_t indice_ds_der= (x - 1) * N + y + 1;
					std::cout << "Indice ds der: " << indice_ds_der<< std::endl;
			if(_esMancha[indice_ds_der]){
					std::cout << "Es mancha: " << std::endl;
				grafo.ponArista(indice,indice_ds_der);
			}
		}
		
		
			//Diagonal inferior izquierda 
		if(y-1 >= 0 && x+1 < M ){
			size_t indice_di_izq= (x+1) * N + y - 1;
					std::cout << "Indice di izq: " << indice_di_izq<< std::endl;
			if(_esMancha[indice_di_izq]){
					std::cout << "Es mancha: " << std::endl;
				grafo.ponArista(indice,indice_di_izq);
			}
		}
		
		
			//Diagonal inferior derecha 
		if(y+1 < N && x+1 < M ){
			size_t indice_di_der= (x+1) * N + y + 1;
					std::cout << "Indice di der: " << indice_di_der<< std::endl;
			if(_esMancha[indice_di_der]){
				std::cout << "Es mancha: " << std::endl;
				grafo.ponArista(indice,indice_di_der);
			}
		}
		
		
		
		
		for(size_t i = 0; i < _negros.size(); i++){
			size_t local_result = 0;	

			std::vector<size_t> _resultados;
			calcularTamano(grafo, _esMancha, _negros[i],local_result, _resultados);
			std::cout << "resultado: " << local_result<< std::endl;
			resultado = std::max(local_result,resultado);
		}
		
		std::cout << resultado << std::endl;
		reiniciar(_esMancha, _negros);
			
		
	}


	return true;

}


void calcularTamano(Grafo& grafo, std::vector<bool>& _esMancha, size_t indice, size_t& acumulador, std::vector<size_t>& _resultados){
		_esMancha[indice] = true;
		acumulador++;
		_resultados.push_back(indice);
		
		while(_resultados.size()!=0){
			indice = _resultados.back();
			_resultados.pop_back();
			for(size_t i = 0; i < grafo.adj(indice).size(); i++){
				if(_esMancha[grafo.adj(indice)[i]] && !_esMancha[grafo.adj(indice)[i]]){
						calcularTamano(grafo, _esMancha, grafo.adj(indice)[i], acumulador, _resultados);
				}
			}
			}
}


void reiniciar(std::vector<bool>& _esMancha, std::vector<size_t> _negros){
for(size_t i = 0; i < _negros.size(); i++){
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
