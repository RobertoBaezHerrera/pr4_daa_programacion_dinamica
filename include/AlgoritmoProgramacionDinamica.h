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