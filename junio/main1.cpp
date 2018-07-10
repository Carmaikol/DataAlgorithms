#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include "PriorityQueue.h"


struct Paciente{
	std::string nombre;
	int prioridad;
	int extra;
	};	
	
class ComparadorPacientes{
public:
bool operator()(Paciente const& a1, Paciente const& a2)
	{
		if (a1.prioridad > a2.prioridad){
			return true;
		}else if(a1.prioridad == a2.prioridad){
					if(a1.extra <= a2.extra){
							return true;
					}else{
							return false;
						}
			}else
		return false;
	}
	

	
};




bool resuelveCaso();


// COMPLEJIDAD
//O(N) donde N es el numero de libros
bool resuelveCaso() {
	size_t numeroCasos;


	std::cin >> numeroCasos;
	if(std::cin.fail())return false;
	if(numeroCasos==0)return false;
	
	PriorityQueue<Paciente,ComparadorPacientes> queue;
	
	
	
	
	char event_type;
	for(size_t i = 0; i < numeroCasos; i++){
		std::cin >> event_type;
		if(event_type == 'I'){
			Paciente paciente;
			std::cin >> paciente.nombre >> paciente.prioridad;
			paciente.extra = i;
			queue.push(paciente);
		}else{
		//	if(!queue.empty()){
			std::cout<< queue.top().nombre << std::endl;
			queue.pop();	
		//	}
		}
		
		}
		std::cout<< "----" << std::endl;

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
