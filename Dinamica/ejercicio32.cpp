#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <string>
#include "Matriz.h"


bool resuelveCaso();



struct Relacion{
	std::string amigo1;
	std::string amigo2;
	
};


// COMPLEJIDAD
//O(N * T) donde N es el numero de cofres y T los segundos bajo el agua
bool resuelveCaso() {
	size_t T, N; // N numero de cofres, T segundos debajo del agua
	std::string amigo1, amigo2;

	std::cin >> T >> N;
	if(std::cin.fail())return false;
	
	std::vector<Relacion> amigos(N+1);
	std::stack<Relacion> cofresElegidos;	
	
	for(size_t i = 1; i <= N; i++){
		std::cin >> amigo1 >> amigo2;
		std::cout << "AMIGOS: " << amigo1 << "    " << amigo2 << std::endl;
		Relacion relacion;
		relacion.amigo1 = amigo1;
		relacion.amigo2 = amigo2;
		amigos[i] = relacion;
		}
		
			
	size_t resultado = 0;
	
	Matriz<size_t> busca_relaciones(amigos.size(),T + 1, 0);
	//cazatesoros[0][0] = 1;
		
		for(size_t i = 1; i <= amigos.size()-1; ++i){
			//cazatesoros[i][0] = 1;
			for(size_t j = 1; j <= T; ++j){
				
				if(((amigos[i].amigo2 != amigos[i-1].amigo1) &&  amigos[i].amigo1 == amigos[i-1].amigo2) 	||
				((amigos[i].amigo1 != amigos[i-1].amigo2) &&  amigos[i].amigo2 == amigos[i-1].amigo1)  		|| 
				((amigos[i].amigo1 != amigos[i-1].amigo1) &&  amigos[i].amigo2 == amigos[i-1].amigo2) 		|| 
				((amigos[i].amigo2 != amigos[i-1].amigo2) &&  amigos[i].amigo1 == amigos[i-1].amigo1)){
					busca_relaciones[i][j] = busca_relaciones[i-1][j];
				}else{
					busca_relaciones[i][j] = std::min(busca_relaciones[i-1][j], busca_relaciones[i-1][j - 1] + 1);
				}
				
			}
		}
		
		resultado = busca_relaciones[amigos.size()-1][T];
		

		
		
		if(resultado!=N){
			std::cout << resultado << std::endl;
		}else{
			std::cout << "IMPOSIBLE" << std::endl;
	}
	
	
	//std::cout << "----" << std::endl;
	
	
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
