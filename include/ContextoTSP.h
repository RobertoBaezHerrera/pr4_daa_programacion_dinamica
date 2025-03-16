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