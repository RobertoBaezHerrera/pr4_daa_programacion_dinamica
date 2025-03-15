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
  
class Grafo {
 public:
  Grafo(std::string fichero_entrada);
  

 private:
  std::vector<std::vector<int>> matriz_costes_;
  std::vector<std::string> nombres_nodos_;
};