/**
  * Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Grado en Ingeniería Informática
  * Asignatura: Diseño y Análisis de Algoritmos
  * @file main.cc
  * @author Roberto Báez Herrera, Nailea Fayna Cruz Galván
  * Correo: alu0101497013@ull.edu.es, alu0101477497@ull.edu.es
  * @date 18/03/2025
  * @brief Programa principal
  */

  #pragma once

  #include <iostream>
  #include <string>
  #include <fstream>
  #include <vector>
  #include <map>
  
class Grafo {
 public:
  // Constructor
  Grafo(std::string fichero_entrada);

  // Getters
  int GetNumeroNodos() const { return numero_nodos_; }
  std::map<std::string, std::map<std::string, int>> GetMatrizCostes() const { return matriz_costes_; }
  int GetCoste(std::string nodo_origen, std::string nodo_destino) const;

 private:
  std::map<std::string, std::map<std::string, int>> matriz_costes_;
  int numero_nodos_;
};