/**
  * Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Grado en Ingeniería Informática
  * Asignatura: Diseño y Análisis de Algoritmos
  * @author Roberto Báez Herrera, Nailea Fayna Cruz Galván
  * Correo: alu0101497013@ull.edu.es, alu0101477497@ull.edu.es
  * @date 18/03/2025
  */

#include "../include/Grafo.h"

Grafo::Grafo(std::string fichero_entrada) {
  std::ifstream fichero{fichero_entrada};
  if (!fichero) {
    std::cerr << "Error al abrir el fichero" << std::endl;
    exit(1);
  }
  fichero >> numero_nodos_;
  int aristas_no_repetidas = (numero_nodos_ * (numero_nodos_ + 1)) / 2 - numero_nodos_;
  int contador_aristas_declaradas = 0;
  std::string nodo_origen, nodo_destino;
  int coste;
  while (fichero >> nodo_origen >> nodo_destino >> coste) {
    // Comprobar que la aristas no haya sido declarada antes
    if (matriz_costes_[nodo_origen][nodo_destino] != 0) {
      std::cerr << "Error: Arista repetida" << std::endl;
      exit(EXIT_FAILURE);
    }
    matriz_costes_[nodo_origen][nodo_destino] = coste;
    matriz_costes_[nodo_destino][nodo_origen] = coste;
    contador_aristas_declaradas++;
  }
  fichero.close();

  // Comprobar que el número de aristas declaradas es correcto
  if (contador_aristas_declaradas != aristas_no_repetidas) {
    std::cerr << "Error: El número de aristas declaradas no coincide con el número de aristas no repetidas" << std::endl;
    exit(EXIT_FAILURE);
  }
}

int Grafo::GetCoste(std::string nodo_origen, std::string nodo_destino) const {
  auto it = matriz_costes_.find(nodo_origen);
  if (it != matriz_costes_.end()) {
      auto it2 = it->second.find(nodo_destino);
      if (it2 != it->second.end()) {
          return it2->second;
      }
  }
  std::cerr << "Error: No se ha encontrado la arista:" << nodo_origen << "->" << nodo_destino << std::endl;
  exit(EXIT_FAILURE);
}