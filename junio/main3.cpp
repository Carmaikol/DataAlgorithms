#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include "PriorityQueue.h"


struct Edificio{
	int comienzo;
	int fin;
	};	
	
class ComparadorEdificios{
public:
bool operator()(Edificio const& a1, Edificio const& a2)
	{
		if (a1.comienzo < a2.comienzo)
			return true;
		else if(a1.comienzo == a2.comienzo){
			if(a1.fin <= a2.fin)
						return true;
			else return false;
			
			}
		else
		return false;
	}
	

	
};

Edificio leerEdificio();
bool resuelveCaso();


Edificio leerEdificio(){
	
	Edificio edificio;
	std::cin >> edificio.comienzo >> edificio.fin;
	
	
	return edificio;
}

// COMPLEJIDAD
//O(N log N) donde N es el numero de edificios
bool resuelveCaso() {
	int numero_edificios;
	
	std::cin >> numero_edificios;
	if(std::cin.fail())return false;
	if(numero_edificios==0) return false;
	
	PriorityQueue<Edificio, ComparadorEdificios> queue;
	
	for(int i = 0; i < numero_edificios; i++){
		Edificio edificio = leerEdificio();
		queue.push(edificio);
		}
		
	int numero_tuneles = 1;									//Contamos que siempre vemos la primera
		
	int fin_anterior = -1 ;   								//Flag que controla el fin de la ultima pelicula que hemos visto
	int fin_anterior_valido = -1 ;   								//Flag que controla el fin de la ultima pelicula que hemos visto
	
	
	Edificio edificio = queue.top();
	
	queue.pop();
	
	
	fin_anterior = edificio.fin;
	
	
	
	
	while(!queue.empty()){
		Edificio edificio_actual = queue.top();
		queue.pop();
		
		if((edificio_actual.comienzo + 1 > fin_anterior) || 
		(fin_anterior_valido != -1 &&  fin_anterior_valido < edificio_actual.comienzo + 1 )  ){
				numero_tuneles++;
				fin_anterior = edificio_actual.fin;
				fin_anterior_valido = -1;
				
		}else {
			if(fin_anterior_valido == -1){
					fin_anterior_valido = edificio_actual.fin;
			}else{
				if((fin_anterior_valido + 1  < edificio_actual.comienzo)){
					numero_tuneles++;
					fin_anterior = edificio_actual.fin;
					fin_anterior_valido = -1;
				}					
			}				
		}
		
	}
		
	std::cout << numero_tuneles << std::endl;
	
	
	return true;

}



int main() {
//   ajustes  para   que cin  extraiga   directamente de un  fichero
#ifndef DOMJUDGE
std::ifstream in("casos.txt");
auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif


while(resuelveCaso()){
	}


//para dejar  todo  como  estaba  al  principio
#ifndef  DOMJUDGE
std::cin.rdbuf(cinbuf);
system("PAUSE");
#endif


	return 0;
}

