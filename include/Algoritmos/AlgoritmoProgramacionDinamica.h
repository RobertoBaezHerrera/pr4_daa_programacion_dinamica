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

// Estrategia concreta: resolver el problema TSP por programación dinámica
class AlgoritmoProgramacionDinamica : public InterfazTSP {
 public:
  // Método para resolver el problema TSP por programación dinámica
  ResultadoTSP calcular(Grafo grafo) override;
};