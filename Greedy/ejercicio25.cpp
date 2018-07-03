#include <iostream>
#include <algorithm>
#include <vector>
#include "PriorityQueue.h"


struct Conferencia{
	size_t comienzo;
	size_t fin;
	};	
	
class ComparadorConferencias{
public:
bool operator()(Conferencia const& a1, Conferencia const& a2)
	{
		if (a1.comienzo < a2.comienzo)
			return true;
		return false;
	}
	
};


bool resuelveCaso();


// COMPLEJIDAD
//O(N log N) donde N es el numero de conferencias
bool resuelveCaso() {
	
	size_t numero_conferencias;
	
	std::cin >> numero_conferencias;
	if(std::cin.fail())return false;
	if(numero_conferencias==0) return false;
	
	std::vector<Conferencia> conferencias(numero_conferencias);
	
	
	for(size_t i = 0; i < numero_conferencias; i++){
		Conferencia conferencia;
		std::cin >> conferencia.comienzo >> conferencia.fin;
		conferencias[i] = conferencia;
		}
		
	//Ordenamos las conferencias con preferencia a las que tienen el comienzo anterior
	std::sort(conferencias.begin(), conferencias.end(), ComparadorConferencias());
	
	PriorityQueue<size_t, std::less<size_t>> queue;
	
	for(size_t i = 0; i < numero_conferencias; ++i){
		
		size_t conferencia_comienzo = conferencias[i].comienzo;
		size_t conferencia_fin = conferencias[i].fin;
		
		if(!queue.empty() && queue.top() <= conferencia_comienzo){ 
			//Mientras el comienzo sea posterior al final, utilizar la misma sala
			queue.pop();
			queue.push(conferencia_fin);
		
			
		}else if(queue.empty() || queue.top() > conferencia_comienzo){
			//Si el comienzo es anterior al final, se necesita otra sala
			queue.push(conferencia_fin);
		}
		
	}
		
	std::cout << queue.size() << std::endl;
	
	
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

