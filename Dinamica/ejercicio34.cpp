#include <iostream>
#include <vector>
#include <string>
#include "Matriz.h"


bool resuelveCaso();


size_t cantidad_maxima_comida(std::vector<size_t> cubos);



size_t cantidad_maxima_comida(std::vector<size_t> cubos){

		size_t N = cubos.size()-1;
		bool es_mi_turno = true;
		Matriz<size_t> devoradora(N+1,N+1, 0);
		
	
		
		
	
	//cl representa la diagonal
	for(size_t cl = 1; cl <=  N-1; ++cl){
		for(size_t i = 1; i <= N - cl; ++i){
			size_t j = cl + i;
			 if(cubos[i-1] >  cubos[j-1]){
				devoradora[i][j] = std::max( devoradora[i+1][j], devoradora[i][j - 1] + cubos[i-1]);
			} else{
				 devoradora[i][j] =  devoradora[i+1][j-1];;
				 
				 }
				//if(es_mi_turno){
			//	devoradora[i][j] = std::max( devoradora[i][j-1] + cubos[j-1]  , devoradora[i][j - 1] + cubos[i-1]);
			//	es_mi_turno = false;
			//	std::cout << "ES MI TURNO" << std::endl;
			//	}
			//	else{
			//		devoradora[i][j]  = devoradora[i][j-1];
			//		es_mi_turno = true;
			//			std::cout << "NO ES MI TURNO"  << std::endl;
					//j++;
			//	}
			
			//}else{
			//		palindromos[i][j] = palindromos[i+1][j-1];
			//}
		}
	}
		
		
		return devoradora[1][N];	
}



// COMPLEJIDAD
//O(N log N) donde N es el numero de cubos
bool resuelveCaso() {
	size_t N,  cubo; // N numero de cubos
	
	std::cin >> N;
	if(std::cin.fail())return false;
	
	std::vector<size_t> cubos(N+1,0);
	
	for(size_t i = 1; i <= N; i++){
		std::cin >> cubo ;
		cubos[i] = cubo;	
		}
	
	std::cout << cantidad_maxima_comida(cubos) <<  std::endl;
		
	return true;
}



int main() {
//   ajustes  para   que cin  extraiga   directamente de un  fichero
//#ifndef DOMJUDGE
//std::ifstream in("casos.txt");
//auto cinbuf = std::cin.rdbuf(in.rdbuf());
//#endif


while(resuelveCaso()){
	}


//para dejar  todo  como  estaba  al  principio
//#ifndef  DOMJUDGE
//std::cin.rdbuf(cinbuf);
//system("PAUSE");
//#endif


	return 0;
}


/**
 * 	for(size_t i = 1; i <= N; ++i){
			for(size_t j = 1; j <= N; ++j){
				if(j == N-i){
					devoradora[i][j] = devoradora[i-1][j-1] + std::max(cubos[j],cubos[i]);
					
				}else{
					//Si no lo son, coger el maximo del indice superior o izquierdo
					devoradora[i][j] =devoradora[i-1][j] ;
				}
			}
		}
		* 
		* */
