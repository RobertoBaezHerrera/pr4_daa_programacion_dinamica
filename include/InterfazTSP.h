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

#include "Grafo.h"
#include "./utils/ResultadoTSP.h"

// Interfaz de estrategia
class InterfazTSP {
 public:
  virtual ResultadoTSP calcular(Grafo grafo, std::vector<std::string> nodos_modi = std::vector<std::string>()) = 0;
  virtual ~InterfazTSP() { }
};;