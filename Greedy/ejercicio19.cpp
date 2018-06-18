#include <iostream>
#include <algorithm>
#include <vector>


bool resuelveCaso();


// COMPLEJIDAD
//O(N) donde N es el numero de libros
bool resuelveCaso() {
	size_t libro,numeroCasos;


	std::cin >> numeroCasos;
	if(std::cin.fail())return false;
	
	//PriorityQueue<int, std::greater<int>> listaLibros;
	std::vector<size_t> listaLibros(numeroCasos, 0);
	
	for(size_t i = 0; i < numeroCasos; i++){
		std::cin >> libro;
		listaLibros[i] = libro;
		}
		
	
	std::sort(listaLibros.begin(), listaLibros.end(), std::greater<size_t>());
	
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
