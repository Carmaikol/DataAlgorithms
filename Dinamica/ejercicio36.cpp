
#include <iostream>
#include <fstream>
#include <vector>
#include "Matriz.h"


bool resolver(int N,std::vector<int> valores_monedas,std::vector<int> cantidad_monedas, int precio);



bool resolver(int N,std::vector<int> valores_monedas,std::vector<int> cantidad_monedas, int precio, std::vector<int> & solucion){
	
	int iteracion_actual, resultado;
	
	Matriz<int> matriz_cantidades(N+1,precio+1,1e9);
	Matriz<int> matriz_tipos(N+1,precio+1,1e9);
	
	for(int i=0; i < N + 1; i++){                         												// i representa el tipo de moneda																		
		for(int j=0; j < precio + 1; j++){																// j  representa el precio del coche
			if(j==0)					matriz_cantidades[i][j] = 0;                                    // Cero dinero, cero monedas
			else if(i > 0){
				for(int k = 0; k <= cantidad_monedas[i-1] && (j - k * valores_monedas[i-1] >= 0); k++){	// FLOYD. Cuantas monedas caben en cada caso.
						iteracion_actual = 
						std::min(matriz_cantidades[i - 1][j - (k*valores_monedas[i-1])] + k,			// Escoger el minimo entre coger la moneda o no
						matriz_cantidades[i - 1][j] );													// Caso recursivo. 
						if(matriz_cantidades[i][j] > iteracion_actual){									// Se busca el minimo
								matriz_cantidades[i][j] = iteracion_actual;								// Se actualiza el resultado
								matriz_tipos[i][j] = k;			
						}
				}
					
			}
		}
	}
	
	
	resultado = matriz_cantidades[N][precio];															// Minimo numero de monedas
	
	if(resultado != 1e9){																				// Si existe resultado
		while(precio > 0){																				// Iteramos por el precio, restandole el valor de las monedas guardadas en la solucion.
				solucion[N-1] = matriz_tipos[N][precio];												// Cogemos solucion guardada
				if(matriz_tipos[N][precio] != 0){														// Si el numero de monedas del tipo es mayor a 0
					precio -= solucion[N-1] * valores_monedas[N-1];										// Restamos el valor de esas monedas al precio.
				}
				N--;
		}
		
		return true;
	}else return false;	
}

// COMPLEJIDAD
//O(N * N * M) donde N es el numero de monedas y M es el precio
bool resuelveCaso() {
	int N, valor, cantidad, precio;//N tipos de moneda distintos
	
	
	std::cin >> N;
	if (std::cin.fail()) return false;
	
	std::vector<int> valores_monedas(N);
	std::vector<int> cantidad_monedas(N);
	std::vector<int> solucion(N, 0);
	
	
	for(int i = 0; i < N; i++){
		std::cin >> valor;
		valores_monedas[i] = valor;
		}
		
	for(int i = 0; i < N; i++){
		std::cin >> cantidad;
		cantidad_monedas[i] = cantidad;
		}
	
	
	std::cin >> precio;																				// Precio a igualar
	
	bool se_puede = resolver(N, valores_monedas, cantidad_monedas, precio, solucion);
	
	if(se_puede){
		std::cout << "SI ";
		int resultado = 0;
		for(size_t i = 0; i < solucion.size(); i++){  												// Recorro la solucion
			resultado += solucion[i];																// Sumo las monedas de cada tipo de moneda
		}
		
		std::cout << resultado << std::endl;
		
	}else std::cout << "NO" << std::endl;
	
	
	
	return true;
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
//	while(){}
	
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
