#include <iostream>
#include <algorithm>
#include <vector>


bool resuelveCaso();


// COMPLEJIDAD
//O(N log N) donde N es el numero de partidos
bool resuelveCaso() {
	
	size_t numero_partidos, puntos;
	

	std::cin >> numero_partidos;
	if(std::cin.fail())return false;
	if(numero_partidos == 0 ) return false;
	
	std::vector<size_t> contrarios(numero_partidos,0);
	std::vector<size_t> broncos(numero_partidos,0);
	
	for(size_t i = 0; i < numero_partidos; i++){
		std::cin >> puntos;
		contrarios[i] = puntos;
		}
		
	
	for(size_t i = 0; i < numero_partidos; i++){
		std::cin >> puntos;
		broncos[i] = puntos;
		}
		
	//Como nos da igual cuantos partidos se ganen, ordenamos la lista de los 
	//contrarios de menor a  mayor, asegurandonos la mayor diferencia con los 
	//resultados de los broncos
	std::sort(contrarios.begin(), contrarios.end(), std::less<size_t>());
	std::sort(broncos.begin(), broncos.end(), std::greater<size_t>());
		
	size_t contador = 0, _i = 0, _j = 0;
	
	while(_j < broncos.size() && _i < contrarios.size()){
		if(broncos[_j] > contrarios[_i]) {
			contador += broncos[_j] - contrarios[_i];
			_j++;
			}
			
		_i++;
	}
	
		
		

	std::cout << contador << std::endl;

	
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
std::vector<bool> elegidos_contrarios(numero_partidos,false);
	std::vector<bool> elegidos_broncos(numero_partidos,false);
	
	size_t count = numero_partidos, lastIndex = -1;;
	
	while(count != 0){
		while(elegidos_broncos[_j]){
			_j++;
			}
			
		while(elegidos_contrarios[_i]){
			_i++;
			}
			
		
		
		if(broncos[_j] < contrarios[_i]){
			i++;
		}else{
			
			lastIndex = _j;
			
			while( broncos[_j] > contrarios[_i]){
				_j++
				}
				
			
			maxima_suma =  broncos[_j] - contrarios[_i];
			resultado +=  maxima_suma;
			_j++;
			
			}
		_i++;
		
		}
		* 
		* 
		* 
		* 
		* 
		* 
		* 
		* 
		* 
		* 
		* 
		* 
		* ///otra
		* 
		* 
		* 
		* 	for(size_t _i = 0 ; _i < numero_partidos; _i++){
		suma_maxima_local = 0;
		for(size_t _j = 0 ; _j < numero_partidos; _j++){
					if(broncos[_j] > contrarios[_i]) {
						exito =  std::max(exito, broncos[_j] - contrarios[_i]);
						std::cout << " exito: " << exito << std::endl;
						}
			}
			
			suma_maxima_local += exito;
			suma_maxima_global = std::max(suma_maxima_global, suma_maxima_local);
			std::cout << " SUMA LOCAL: " << suma_maxima_local  << std::endl;
			std::cout << " SUMA GLOBAL: " << suma_maxima_global  << std::endl;
			
			
		}
		
	
	
	
	std::cout << suma_maxima_global << std::endl;
	
	*/
