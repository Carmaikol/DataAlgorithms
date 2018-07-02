#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include "PriorityQueue.h"


struct Pelicula{
	size_t comienzo;
	size_t fin;
	};	
	
class ComparadorPeliculas{
public:
bool operator()(Pelicula const& a1, Pelicula const& a2)
	{
		if (a1.fin < a2.fin)
			return true;
		else
		return false;
	}
	

	
};

Pelicula leerPelicula();
bool resuelveCaso();


Pelicula leerPelicula(){
	char aux;
	int hora, minutos, duracion;
	Pelicula pelicula;
	std::cin >> hora >> aux >> minutos >> duracion;
	
	pelicula.comienzo = (hora * 60) + minutos;
	pelicula.fin = pelicula.comienzo + duracion + 10 ;
	
	return pelicula;
}

// COMPLEJIDAD
//O(N log N) donde N es el numero de peliculas
bool resuelveCaso() {
	
	size_t HORA_MAXIMA = 23 * 60 + 59;
	
	size_t numero_peliculas;
	
	std::cin >> numero_peliculas;
	if(std::cin.fail())return false;
	if(numero_peliculas==0) return false;
	
	PriorityQueue<Pelicula, ComparadorPeliculas> queue;
	
	for(size_t i = 0; i < numero_peliculas; i++){
		Pelicula pelicula = leerPelicula();
		queue.push(pelicula);
		}
		
	int numPeliculas = 1;			//Contamos que siempre vemos la primera
		
	size_t fin_anterior = -1 ;   	//Flag que controla el fin de la ultima pelicula que hemos visto
	
	while(!queue.empty()){
		Pelicula pelicula_actual = queue.top();
		queue.pop();
		
		size_t pelicula_comienzo = pelicula_actual.comienzo;
		size_t pelicula_fin = pelicula_actual.fin;
		
		if(fin_anterior == -1) fin_anterior = pelicula_fin;	
			
		//Recorremos la cola
		if(!queue.empty()) {
			if(queue.top().comienzo >= fin_anterior &&  queue.top().fin <= HORA_MAXIMA){
					//Puedo ver la pelicula
					fin_anterior = queue.top().fin;
					numPeliculas++;
					
			}
			//Quitamos el elemento de la cola
			queue.pop();
			
			
			 	
			}else{
			//Comprobamos si podemos anadir el ultimo elemento
			if(pelicula_comienzo >= fin_anterior &&  pelicula_fin <= HORA_MAXIMA){
					numPeliculas++;
			}	
		}
		
	}
		
	std::cout << numPeliculas << std::endl;
	
	
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

