#include <iostream>
#include <algorithm>
#include <vector>


bool resuelveCaso();


// COMPLEJIDAD
//O(N) donde N es el numero de usuarios
bool resuelveCaso() {
	size_t peso_maximo, numero_usuarios, peso; 
	

	std::cin >> peso_maximo >> numero_usuarios;
	if(std::cin.fail())return false;
	
	std::vector<size_t> pesos(numero_usuarios,0);
	
	for(size_t i = 0; i < numero_usuarios; i++){
		std::cin >> peso;
		pesos.push_back(peso);
		}
		
	std::sort(pesos.begin(), pesos.end(), std::greater<size_t>());
		
		
	size_t contador = 0;
	size_t ultimo_usuario = numero_usuarios-1; 
	

	
	for(size_t i = 0; i < numero_usuarios && i <= ultimo_usuario; i++){
		if(pesos[i]+pesos[ultimo_usuario]>peso_maximo) {
			if(pesos[i]!=-1){
			contador++;
			pesos[i] = -1;
		}
			}else{
				if(pesos[i]!=-1 && pesos[ultimo_usuario]!=-1){
				contador++;
				pesos[i] = -1;
				pesos[ultimo_usuario] = -1;
				ultimo_usuario -= 1;
				}
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
