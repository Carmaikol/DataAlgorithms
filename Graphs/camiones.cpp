#include <iostream>
#include <vector>
#include "GrafoValorado.h"
#include "PriorityQueue.h"


/**
 * 
	 * Somos una empresa de transporte y hemos decidido renovar parte de nuestra
	flota de camiones de reparto.  A nosotros nos conviene que los camiones sean anchos,
	porque as ́ı se puede repartir y colocar mejor la mercancia.  Pero claro, hay ciudades
	con calles muy estrechas, por donde no todos los camiones pueden pasar.
	Tenemos mapas actualizados de las ciudades donde trabajamos, donde hemos
	se nalado  para  cada  calle  cu al  es  la  anchura  maxima  que  puede  tener  un  camion
	para poder transitar por ella.
	¿Nos ayudas a decidir si un cami on de una anchura determinada puede circular
	por una ciudad para llegar desde un punto concreto a otro?

 * */





//Nuestro cola ordenara los elementos de menor a mayor coste
class ComparadorAristas{
	
public:
	bool operator()(Arista<size_t> const& a1, Arista<size_t> const& a2)
	{
		if (a1.valor() > a2.valor())
			return true;
		return false;
	}
};


class Solucion{
	
public:

	Solucion(GrafoValorado<size_t> const& grafo): _marked(grafo.V(),false) {
				count = 0;
				_final = false;
			}
			
			
	void prim(GrafoValorado<size_t> const& grafo, size_t posicion,size_t destino, size_t anchura_minima , std::vector<std::vector<bool>> rechazadas){
			Arista<size_t> arista(0,0,99999999999);
				
				//Compruebo si esta marcada
				if(!_marked[posicion]){
					count++;
					_marked[posicion] = true;
				}
	
				//Recorro los adjuntos
				for(size_t i = 0; i < grafo.adj(posicion).size();i++){
					size_t otro = grafo.adj(posicion)[i].otro(posicion);
					if(!_marked[otro]){
						_queue.push(grafo.adj(posicion)[i]);
						}
					}
					
				//Coger la menor arista no marcada y no rechazada
				while((_queue.size() > 0 && _marked[arista.uno()] && _marked[arista.otro(arista.uno())] ) ||  ((rechazadas[arista.uno()][arista.otro(arista.uno())]) && count < grafo.V()-1)){
					//Si se encuentra, quitarla de la cola y utilizarla
					if(!_queue.empty()){
						arista = _queue.top();
						_queue.pop();
					
						//Si la anchura de la calle es menor a la anchura del camion
						if(arista.valor() < anchura_minima){
							//Rechazar
							rechazadas[arista.uno()][arista.otro(arista.uno())] = true;
							rechazadas[arista.otro(arista.uno())][arista.uno()] = true;
							//rechazadas[arista.otro(arista.uno())] = true;
						}
					}
				}
					
					
				//Mientras no se llegue al final y no esten marcadas las aristas	
				if(!_final && count < grafo.V() && !(_marked[arista.uno()] && _marked[arista.otro(arista.uno())])){

					//Elegir desde que posicion empezar la recursion
					if(_marked[arista.uno()] || destino == arista.otro(arista.uno())){
						posicion = arista.otro(arista.uno());
					}else{
						posicion = arista.uno();
					}
					//Si se llega al destino y no esta rechazada
					if(posicion == destino && !rechazadas[posicion][arista.otro(posicion)]){						
						_final = true; 
					}
					
					//Llamada recursiva	
					prim(grafo, posicion, destino, anchura_minima, rechazadas);
				}
		}
		
	
	bool terminado() {
		return _final;
		}
		

		
	

private:

	std::vector<bool> _marked; 									//Marcados
	PriorityQueue<Arista<size_t>, ComparadorAristas> _queue;  	//Cola de prioridad
	bool _final;												//Flag de finalizacion
	std::vector<size_t> rechazadas;
	size_t posicion, destino, count;
	
	
			
};
				
			



bool resuelveCaso();
GrafoValorado<size_t> construirGrafo(size_t N, size_t M);

// COMPLEJIDAD
//O(C log N) donde N es el numero de vertices y C es el numero de aristas.
bool resuelveCaso() {
	size_t V, E; //N es el numero de intersecciones(vertices), V el numero calles entre intersecciones(artistas)
	size_t numero_casos;
	std::cin >> V >> E;
	if (std::cin.fail()) return false;

	GrafoValorado<size_t> grafo = construirGrafo(V,E);
	//Solucion solucion = Solucion(grafo);
	
	size_t origen, destino, coste;
	std::cin >> numero_casos;
	for(size_t i = 0; i < numero_casos; i++){
		std::vector<bool> columnas_rechazadas(E+1,false);
		std::vector<std::vector<bool>> rechazadas(E+1,columnas_rechazadas);
		std::cin >> origen >> destino >> coste;
		Solucion solucion = Solucion(grafo);
		solucion.prim(grafo,origen-1, destino-1, coste, rechazadas );
	
		if(solucion.terminado() && E > 0) {
			std::cout << "SI" << std::endl;
		}else{
			std::cout << "NO" << std::endl;
		}
		
	}
	
	
	
	
	return true;

}


GrafoValorado<size_t>  construirGrafo(size_t N, size_t M){
	GrafoValorado<size_t> grafo = GrafoValorado<size_t>(N);
	size_t origen, destino, coste;
	
	for(size_t i = 0; i < M; i++){
		std::cin >> origen >> destino >> coste;
		Arista<size_t> arista = Arista<size_t>(origen-1, destino-1, coste);
		grafo.ponArista(arista);
		}

	return grafo;
}


int main() {
//   ajustes  para   que cin  extraiga   directamente de un  fichero
#ifndef DOMJUDGE
std::ifstream in("casos.txt");
auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif


	//size_t numeroCasos;
	
	//std::cin >> numeroCasos;
	
	while(resuelveCaso()){}
	
	//while (numeroCasos > 0) {
	//	std::cout << resuelveCaso();
	//	numeroCasos--;
	//	}

//para dejar  todo  como  estaba  al  principio
#ifndef  DOMJUDGE
std::cin.rdbuf(cinbuf);
system("PAUSE");
#endif


	return 0;
}
