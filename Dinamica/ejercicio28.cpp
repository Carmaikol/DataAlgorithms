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
//O(N * T) donde N es el numero de cofres y T los segundos bajo el agua
bool resuelveCaso() {
	size_t T, N, profundidad, oro; // N numero de cofres, T segundos debajo del agua
	

	std::cin >> T >> N;
	if(std::cin.fail())return false;
	
	std::vector<Cofre> cofres(N+1);
	std::stack<Cofre> cofresElegidos;	
	
	for(size_t i = 1; i <= N; i++){
		std::cin >> profundidad >> oro;
		Cofre cofre;
		cofre.profundidad = profundidad;
		cofre.oro = oro;
		cofres[i] = cofre;
		}
		
			
	size_t valor_maximo_oro = 0;
	size_t numero_cofres = 0;
	Matriz<size_t> cazatesoros(cofres.size(),T + 1, 0);
	//cazatesoros[0][0] = 1;
		
		for(size_t i = 1; i <= cofres.size()-1; ++i){
			//cazatesoros[i][0] = 1;
			for(size_t j = 1; j <= T; ++j){
				if((cofres[i].profundidad * 3) > j){
					cazatesoros[i][j] = cazatesoros[i-1][j];
				}else{
					cazatesoros[i][j] = std::max(cazatesoros[i-1][j], cazatesoros[i-1][j - (cofres[i].profundidad*3)] + cofres[i].oro);
				}
			}
		}
		
		valor_maximo_oro = cazatesoros[cofres.size()-1][T];
		
		size_t resto = T;
		for(size_t i = cofres.size()-1; i >= 1; --i){
			if(cazatesoros[i][resto] != cazatesoros[i-1][resto]){
				++numero_cofres;
				cofresElegidos.push(cofres[i]);
				resto = resto - (cofres[i].profundidad*3);
				
				}
			}	
		
		
		
	if(numero_cofres > 0){
		std::cout << valor_maximo_oro << std::endl;
		std::cout << numero_cofres << std::endl;
		for(size_t i = 0; i < numero_cofres; i++ ){
				std::cout << cofresElegidos.top().profundidad << " " << cofresElegidos.top().oro << std::endl;
				cofresElegidos.pop();
			};
				
			
	}else{
		std::cout << 0 << std::endl;
		std::cout << 0 << std::endl;
		
	}
	
	std::cout << "----" << std::endl;
	
	
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
