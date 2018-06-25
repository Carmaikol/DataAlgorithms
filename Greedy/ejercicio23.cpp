#include <iostream>
#include <algorithm>
#include <vector>


bool resuelveCaso();


// COMPLEJIDAD
//O(N log N) donde N es el numero de ciudades
bool resuelveCaso() {
	
	size_t numero_ciudades, tropas;
	
	std::cin >> numero_ciudades;
	if(std::cin.fail())return false;
	
	std::vector<size_t> atacantes(numero_ciudades);
	std::vector<size_t> defensores(numero_ciudades);
	
	for(size_t i = 0; i < numero_ciudades; i++){
		std::cin >> tropas;
		atacantes[i] = tropas;
		}
		
	
	for(size_t i = 0; i < numero_ciudades; i++){
		std::cin >> tropas;
		defensores[i] = tropas;
		}
		
		
	//En este caso lo que nos importa es el mayor numero de ciudades defendidas
	// a diferencia del ejercicio de los Broncos, deberemos ordenar ambas colas en
	// orden de mayor a menor.
	std::sort(atacantes.begin(), atacantes.end(), std::greater<size_t>());
	std::sort(defensores.begin(), defensores.end(), std::greater<size_t>());
		 
		
		size_t contador = 0, _i = 0, _j = 0;
		
		while(_j < defensores.size() && _i < atacantes.size()){
			if(defensores[_j] >= atacantes[_i]){
				++contador;
				++_j;
				}
				++_i;
				
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

