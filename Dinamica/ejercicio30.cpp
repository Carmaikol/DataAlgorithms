#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include "Matriz.h"


bool resuelveCaso();



struct Cofre{
	size_t profundidad;
	size_t oro;
	
};


// COMPLEJIDAD
//O(N * N) donde N es la longitud de la pala bra
bool resuelveCaso() {
	
	std::string palabra;
	
	
	size_t N, resultado; // N longitud de la palabra, T segundos debajo del agua
	

	std::cin >> palabra;
	if(std::cin.fail())return false;
	
	
	N = palabra.length();
		
					
	Matriz<size_t> palindromos(N ,N, 0);
	
	for(size_t i = 0; i < N; ++i){
		palindromos[i][i]  = 0;
	}
	
	
	for(size_t cl = 1; cl < N; ++cl){
		for(size_t i = 0; i < N - cl; ++i){
			size_t j = cl + i;
			if(palabra[i] ==  palabra[j]){
				palindromos[i][j] = palindromos[i+1][j-1];
			}else{
				if()
				palindromos[i][j] = std::min(palindromos[i+1][j] + 1, palindromos[i][j - 1] + 1);
			}
		}
	}
		
	resultado = palindromos[0][N];
		
	std::cout << resultado << std::endl;
	
	
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
