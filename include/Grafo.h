/**
  * Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Grado en Ingeniería Informática
  * Asignatura: Diseño y Análisis de Algoritmos
  * @author Roberto Báez Herrera, Nailea Fayna Cruz Galván
  * Correo: alu0101497013@ull.edu.es, alu0101477497@ull.edu.es
  * @date 18/03/2025
  */

#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <map>
  
// Clase que representa un grafo
class Grafo {
 public:
  // Constructor
  Grafo() = default;
  Grafo(std::string fichero_entrada);

  // Getters
  int GetNumeroNodos() const { return numero_nodos_; }
  std::map<std::string, std::map<std::string, int>> GetMatrizCostes() const { return matriz_costes_; }
  int GetCoste(std::string nodo_origen, std::string nodo_destino) const;

  // Setters
  void SetMatrizCostes(std::map<std::string, std::map<std::string, int>> matriz_costes) { matriz_costes_ = matriz_costes; }
  void SetNumeroNodos(int numero_nodos) { numero_nodos_ = numero_nodos; }

  // Devuelve un subgrafo con los nodos indicados
  Grafo Subgrafo(std::vector<std::string> nodos) const;

 private:
  std::map<std::string, std::map<std::string, int>> matriz_costes_;
  int numero_nodos_;
};