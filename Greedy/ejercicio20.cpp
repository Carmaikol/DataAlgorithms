#include <iostream>
#include <algorithm>
#include <vector>


bool resuelveCaso();


// COMPLEJIDAD
//O(N) donde N es el numero de agujeros
bool resuelveCaso() {
	size_t N,L, agujero; // N numero de agujeros, L longitud de los parches
	

	std::cin >> N >> L;
	if(std::cin.fail())return false;
	
	std::vector<size_t> manguera;
	
	for(size_t i = 0; i < N; i++){
		std::cin >> agujero;
		manguera.push_back(agujero);
		}
		
		
	size_t contador = 1;
	size_t agujero_anterior = manguera[0];
	
	for(size_t i = 1; i < manguera.size(); i++){
			if(agujero_anterior + L < manguera[i]){
				agujero_anterior = manguera[i];
				contador++;
				}
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
