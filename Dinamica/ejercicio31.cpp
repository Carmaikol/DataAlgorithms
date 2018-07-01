#include <iostream>

#include <string>
#include "Matriz.h"


bool resuelveCaso();


size_t subsecuencia_mas_larga(std::string palabra_uno,std::string palabra_dos);



size_t subsecuencia_mas_larga(std::string palabra_uno,std::string palabra_dos){

		size_t N = palabra_uno.length(), M = palabra_dos.length();
		
		Matriz<size_t> subsecuencias(N+1,M+1, 0);
		
		for(size_t i = 1; i <= N; ++i){
			for(size_t j = 1; j <= M; ++j){
				if(palabra_uno[i-1] ==  palabra_dos[j-1]){
					//Si las letras son iguales, anadir uno al resultado anterior
					subsecuencias[i][j] = subsecuencias[i-1][j-1] + 1;
				}else{
					//Si no lo son, coger el maximo del indice superior o izquierdo
					subsecuencias[i][j] = std::max(subsecuencias[i-1][j],subsecuencias[i][j - 1]);
				}
			}
		}
		
		return subsecuencias[N][M];	
}



// COMPLEJIDAD
//O(N * M) donde N es la longitud de la palabra uno y n la longitud de la palabra dos
bool resuelveCaso() {
	
	std::string palabra_uno, palabra_dos;

	std::cin >> palabra_uno >> palabra_dos;
	if(std::cin.fail())return false;
	
	std::cout << subsecuencia_mas_larga(palabra_uno, palabra_dos) <<  std::endl;
		
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
