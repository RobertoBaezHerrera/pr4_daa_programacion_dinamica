#pragma once

#include <iostream>
#include <string>
#include <vector>

#include "InterfazTSP.h"

// Estrategia concreta: resolver el problema TSP por fuerza bruta
class AlgoritmoFuerzaBruta : public InterfazTSP {
 public:
  // Método para resolver el problema TSP por fuerza bruta
  ResultadoTSP calcular(Grafo grafo) override;
};