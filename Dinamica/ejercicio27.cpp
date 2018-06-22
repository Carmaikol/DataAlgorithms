#include <iostream>
#include <algorithm>
#include <vector>
#include "Matriz.h"


bool resuelveCaso();
size_t formasPosibles(std::vector<size_t> longitudes, size_t L);
size_t minimasCuerdas(std::vector<size_t> longitudes, size_t L);
size_t minimoCoste(std::vector<size_t> longitudes, size_t L,std::vector<size_t> costes);




size_t formasPosibles(std::vector<size_t> longitudes, size_t L){


		size_t resultado = 0;
		Matriz<size_t> formas_posibles(longitudes.size(),L + 1, 0);
		formas_posibles[0][0] = 1;
		
		for(size_t i = 1; i <= longitudes.size()-1; ++i){
			formas_posibles[i][0] = 1;
			for(size_t j = 1; j <= L; ++j){
				if(longitudes[i] > j){
					formas_posibles[i][j] = formas_posibles[i-1][j];
				}else{
					formas_posibles[i][j] = formas_posibles[i-1][j] + formas_posibles[i-1][j - longitudes[i]];
				}
			}
		}
		
		resultado = formas_posibles[longitudes.size()-1][L];
		
		return resultado;	
}




size_t minimasCuerdas(std::vector<size_t> longitudes, size_t L){


		size_t resultado = 0;
		Matriz<size_t> minimas_cuerdas(longitudes.size(),L + 1, 999999999999999);
		minimas_cuerdas[0][0] = 1;
		
		for(size_t i = 1; i <= longitudes.size()-1; ++i){
			minimas_cuerdas[i][0] = 1;
			for(size_t j = 1; j <= L; ++j){
				if(longitudes[i] > j){
					minimas_cuerdas[i][j] = minimas_cuerdas[i-1][j];
				}else{
					minimas_cuerdas[i][j] = std::min(minimas_cuerdas[i-1][j],minimas_cuerdas[i-1][j - longitudes[i]] + 1);
				}
			}
		}
		
		resultado = minimas_cuerdas[longitudes.size()-1][L];
		
		return resultado-1;
}



size_t minimoCoste(std::vector<size_t> longitudes, size_t L,std::vector<size_t> costes){


		size_t resultado = 0;
		Matriz<size_t> minimo_coste(longitudes.size(),L + 1, 999999999999999);
		minimo_coste[0][0] = 1;
		
		for(size_t i = 1; i <= longitudes.size()-1; ++i){
			minimo_coste[i][0] = 1;
			for(size_t j = 1; j <= L; ++j){
				if(longitudes[i] > j){
					minimo_coste[i][j] = minimo_coste[i-1][j];
				}else{
					minimo_coste[i][j] = std::min(minimo_coste[i-1][j],minimo_coste[i-1][j - longitudes[i]] + costes[i]);
				}
			}
		}
		
		resultado = minimo_coste[longitudes.size()-1][L];
		
		return resultado-1;
}



// COMPLEJIDAD
//O(N * L) donde N es el numero de cordeles y L la longitud de la cuerda
bool resuelveCaso() {
	size_t N, L, longitud, coste; // N numero de cordeles, L longitud de la cuerda
	

	std::cin >> N >> L;
	if(std::cin.fail())return false;
	
	std::vector<size_t> longitudes(N+1,0);
	std::vector<size_t> costes(N+1,0);
	
	for(size_t i = 1; i <= N; i++){
		std::cin >> longitud >> coste;
		longitudes[i] = longitud;
		costes[i] = coste;		
		}
		

		
	size_t formas_posibles = formasPosibles(longitudes,L);
	size_t minimo_cuerdas = -1;
	size_t minimo_coste = -1;
	
	if(formas_posibles>0){
		
		minimo_cuerdas = minimasCuerdas(longitudes,L);
		minimo_coste = minimoCoste(longitudes,L,costes);
		
		std::cout << "SI "<< formas_posibles << " " << minimo_cuerdas << " " << minimo_coste <<  std::endl;
		
		
	}else{
		std::cout << "NO" << std::endl;
		
	}
	
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
