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
#include <vector>

#include "InterfazTSP.h"

// Contexo de estrategia
class ContextoTSP {
 public:
  ContextoTSP() { }

  // Setter
  void set_estrategia(InterfazTSP* estrategia);

  // Método para calcular el producto de matrices y devolver la TSP resultado
  ResultadoTSP calcular(Grafo grafo);

 private:
  InterfazTSP* estrategia_ = nullptr;
};