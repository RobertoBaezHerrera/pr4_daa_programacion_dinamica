#pragma once

#include <iostream>
#include <string>
#include <vector>

#include "InterfazTSP.h"

// Estrategia concreta: resolver el problema TSP por algortimo voraz
class AlgoritmoVoraz : public InterfazTSP {
 public:
  // Método para resolver el problema TSP por algortimo voraz
  ResultadoTSP calcular(Grafo grafo) override;
};