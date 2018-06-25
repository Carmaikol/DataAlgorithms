#include <iostream>
#include "Matriz.h"


bool resuelveCaso();



// COMPLEJIDAD
//O(N * N) donde N es la longitud de la palabra
bool resuelveCaso() {
	
	std::string palabra;
	
	
	size_t N, resultado; // N longitud de la palabra
	
	std::cin >> palabra;
	if(std::cin.fail())return false;
	
	N = palabra.length();
			
	Matriz<size_t> palindromos(N+1 ,N+1, 0);
	
	//Rellenamos la diagonal con ceros. Solo utilizaremos la mitad superior de la matriz.
	for(size_t i = 0; i <= N; ++i){
		palindromos[i][i]  = 0;
	}
	
	//cl representa la diagonal
	for(size_t cl = 1; cl <=  N-1; ++cl){
		for(size_t i = 1; i <= N - cl; ++i){
			size_t j = cl + i;
			if(palabra[i-1] ==  palabra[j-1]){
				palindromos[i][j] = palindromos[i+1][j-1];
			}else{
				palindromos[i][j] = std::min(palindromos[i+1][j] + 1, palindromos[i][j - 1] + 1);
			}
		}
	}
		
	resultado = palindromos[1][N];
		
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
