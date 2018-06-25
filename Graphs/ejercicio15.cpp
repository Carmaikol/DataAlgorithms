#include <iostream>
#include <vector>
#include "GrafoValorado.h"
#include "PriorityQueue.h"


//Nuestro cola ordenara los elementos de menor a mayor coste
class ComparadorAristas{
public:
	bool operator()(Arista<size_t> const& a1, Arista<size_t> const& a2)
	{
		if (a1.valor() < a2.valor())
			return true;
		return false;
	}
};


class Solucion{
public:

	Solucion(GrafoValorado<size_t> const& grafo): _marked(grafo.V(),false) {
				_coste = 0;
				count = 0;
				_final = false;
			}
			
			
	void prim(GrafoValorado<size_t> const& grafo, size_t posicion){
			Arista<size_t> arista(0,0,99999999999);
				
				//Comrpuebo si esta marcada
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
					
				//Coger la menor arista no marcada
				while(_queue.size() > 0 && _marked[arista.uno()] && _marked[arista.otro(arista.uno())]){
					//Si se encuentra, quitarla de la cola y utilizarla
					arista = _queue.top();
					_queue.pop();
				}
					
				//Mientras no se llegue al final y no esten marcadas las aristas	
				if(count < grafo.V() && !(_marked[arista.uno()] && _marked[arista.otro(arista.uno())])){
					//Sumar el coste
					_coste  = _coste + arista.valor();
					
					//Elegir desde que posicion empezar la recursion
					if(_marked[arista.uno()]){
						posicion = arista.otro(arista.uno());
					}else{
						posicion = arista.uno();
					}
					
					//Llamada recursiva	
					prim(grafo, posicion);
					}
					
			if(count == grafo.V()) _final = true;
			
		}
		
	
	bool terminado() {
		return _final;
		}
		
	//Resultado almacenado
	size_t coste() {
		return _coste;
		}
		
	

private:

	std::vector<bool> _marked; 									//Marcados
	PriorityQueue<Arista<size_t>, ComparadorAristas> _queue;  	//Cola de prioridad
	bool _final;												//Flag de finalizacion
	size_t posicion, count, _coste;
	
			
};
				
			



bool resuelveCaso();
GrafoValorado<size_t> construirGrafo(size_t N, size_t M);

// COMPLEJIDAD
//O(C log N) donde N es el numero de vertices y C es el numero de aristas.
bool resuelveCaso() {
	size_t N, C; //N es el numero de intersecciones(vertices), C el numero calles entre intersecciones(artistas)
	
	std::cin >> N >> C;
	if (std::cin.fail()) return false;

	GrafoValorado<size_t> grafo = construirGrafo(N,C);
	Solucion solucion = Solucion(grafo);
	solucion.prim(grafo,0);
	
	if(solucion.terminado() && C > 0) {
		std::cout << solucion.coste() << std::endl;
	}else{
		std::cout << "Imposible" << std::endl;
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
//#ifndef DOMJUDGE
//std::ifstream in("casos.txt");
//auto cinbuf = std::cin.rdbuf(in.rdbuf());
//#endif


	//size_t numeroCasos;
	
	//std::cin >> numeroCasos;
	
	while(resuelveCaso()){}
	
	//while (numeroCasos > 0) {
	//	std::cout << resuelveCaso();
	//	numeroCasos--;
	//	}

//para dejar  todo  como  estaba  al  principio
//#ifndef  DOMJUDGE
//std::cin.rdbuf(cinbuf);
//system("PAUSE");
//#endif


	return 0;
}
