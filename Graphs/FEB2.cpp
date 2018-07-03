#include <iostream>
#include <vector>
#include "GrafoValorado.h"



class Solucion{
	

private:

	std::vector<bool> _marked;
	bool fin;
	size_t anchura_minima, origen, destino;
	
	//Complejidad O(V)
	void dfs(GrafoValorado<size_t> const& grafo, size_t v){
			//++_count;
			_marked[v] = true; // para no repetir vértices
			
			
			for(size_t i = 0; i < grafo.adj(v).size() && !fin;i++){  // recorremos todos los adyacentes a v
				Arista<size_t> w   = grafo.adj(v)[i];
		
				size_t otro = w.otro(v);
				if(w.valor() >= anchura_minima){
					if (!_marked[otro] && !fin) {
						if(otro==destino) {
							fin = true;
							return;
						}
						dfs(grafo, otro);
					}else{
						if(fin){
							return;
						}
					}
				}
			}
	}	
	
	
	
	
public:

	Solucion(GrafoValorado<size_t> const& grafo, size_t origenE, size_t destinoE, size_t anchura_minimaE): _marked(grafo.V(),false), fin(false) {
			
			origen = origenE;
			destino = destinoE;
			anchura_minima = anchura_minimaE;
		
			dfs(grafo, origen);
			
			}
			
	bool esFin() const{
		return fin;
	}
			
	

			
	
};
				
			
GrafoValorado<size_t>  construirGrafo(size_t N, size_t M);

//O(C log N) donde N es el numero de vertices y C es el numero de aristas.
bool resuelveCaso() {
	size_t V, E; //N es el numero de intersecciones(vertices), V el numero calles entre intersecciones(artistas)
	size_t numero_casos;
	std::cin >> V >> E;
	if (std::cin.fail()) return false;

	GrafoValorado<size_t> grafo = construirGrafo(V,E);
	
	size_t origen, destino, coste;
	std::cin >> numero_casos;
	for(size_t i = 0; i < numero_casos; i++){
	//	std::vector<bool> rechazadas = std::vector<bool>(E+1,false);
		std::cin >> origen >> destino >> coste;
		Solucion solucion = Solucion(grafo, origen-1, destino-1, coste);
	
	
		if(solucion.esFin() && E > 0) {
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
