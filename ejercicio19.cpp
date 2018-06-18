#include <iostream>
#include <algorithm>
#include <vector>
#include "PriorityQueue.h"

bool resuelveCaso();


// COMPLEJIDAD
//O(N) donde N es el numero de libros
bool resuelveCaso() {
	int libro,numeroCasos; //N es el numero de personas(vertices), M el numero de pares de amigos(artistas)

	if(std::cin.fail())return false;
	std::cin >> numeroCasos;
	
	//PriorityQueue<int, std::greater<int>> listaLibros;
	std::vector<int> listaLibros(numeroCasos, 0);
	
	for(size_t i = 0; i < numeroCasos; i++){
		std::cin >> libro;
		listalLibros[i] = libro;
		}
		
	
	std::sort(listaLibros.begin(), listaLibros.end(), std::greater<int>());
	
	if(numeroCasos>=3){
	
	int contador = 0;
	size_t suma = 0;
	
	for(int libro: listaLibros){
		contador++;
		if(contador%3==0){
			suma += libro;
			}
		}
	
	std::cout << suma << std::endl;
	
}else{
	
	std::cout << 0 << std::endl;
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
