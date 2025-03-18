#pragma once

#include <iostream>
#include <string>
#include <vector>

#include "Grafo.h"
#include "./utils/ResultadoTSP.h"

// Interfaz de estrategia
class InterfazTSP {
 public:
  virtual ResultadoTSP calcular(Grafo grafo) = 0;
  virtual ~InterfazTSP() { }
};