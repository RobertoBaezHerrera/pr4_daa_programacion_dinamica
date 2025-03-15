#include "../include/Grafo.h"

Grafo::Grafo(std::string fichero_entrada) {
  std::ifstream fichero{fichero_entrada};
  if (!fichero) {
    std::cerr << "Error al abrir el fichero" << std::endl;
    exit(1);
  }
  fichero >> numero_nodos_;
  std::string nodo_origen, nodo_destino;
  int coste;
  while (fichero >> nodo_origen >> nodo_destino >> coste) {
    matriz_costes_[nodo_origen][nodo_destino] = coste;
    matriz_costes_[nodo_destino][nodo_origen] = coste;
  }
  
  for (const auto& fila : matriz_costes_) {
    std::cout << fila.first << " -> ";
    for (const auto& col : fila.second) {
        std::cout << "(" << col.first << ", " << col.second << ") ";
    }
    std::cout << std::endl;
  }
  

}