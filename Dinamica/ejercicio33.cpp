#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>

#include "Matriz.h"


bool resuelveCaso();




// COMPLEJIDAD
//O(N * T) donde N es el numero de cofres y T los segundos bajo el agua
bool resuelveCaso() {
	int L, N, corte; // L longitud del tablon, N numero de cortes
	

	std::cin >> L >> N;
	if(std::cin.fail())return false;
	
	std::vector<int> cortes(N+1);
		
	
	for(int i = 0; i < N; i++){
		std::cin >> corte;
		cortes[i] = corte;
		}
		
			
	int valor_minimo_esfuerzo = 999999999;
	//int maximo_local = 0;
	Matriz<int> esfuerzo(cortes.size()+1,L + 1, valor_minimo_esfuerzo);
	
	//cazatesoros[0][0] = 1;
		int longitud_actual = L;
		for(int i = 1; i <= N; ++i){
	//	size_t aux_i = i;
		esfuerzo[i][0] = 0;
			//cazatesoros[i][0] = 1;
			for(int j = 1; j <= L; ++j){
				std::cout << " i:  " << i << "   j: " << j << std::endl; 
				if(cortes[i-1] <= j ){
					
					//Cortar
					longitud_actual = std::abs(longitud_actual - j);	
					esfuerzo[i][j] = std::min(esfuerzo[i-1][j],esfuerzo[i][j- cortes[i-1]] +  2*(longitud_actual));
					std::cout << "esfuerzo: " << esfuerzo[i][j] << std::endl;
					std::cout << "longitud_actual: " << longitud_actual << std::endl;	
				
								 
				}else{
					esfuerzo[i][j] = esfuerzo[i-1][j];
					std::cout << "esfuerzo: " << esfuerzo[i][j] << std::endl;
				}
				

			}
		}
		
		
		//cl representa la diagonal
	for(size_t cl = 1; cl <=  N-1; ++cl){
		for(size_t i = 1; i <= N - cl; ++i){
			size_t j = cl + i;
			
			
			if(corte[i-1]  ){
				esfuerzo[i][j] = esfuerzo[i+1][j-1];
			}else{
				esfuerzo[i][j] = std::min(esfuerzo[i+1][j] + (2*(L-corte[i]), esfuerzo[i][j - 1] + (2*(L-corte[j])));
			}
		}
	}
			
		
		
	valor_minimo_esfuerzo = esfuerzo[N][L];
	
	
	std::cout << valor_minimo_esfuerzo << std::endl;
	
	
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
