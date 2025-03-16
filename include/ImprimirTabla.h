#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <fstream>

#include "ResultadoTSP.h"

class ImprimirTabla {
 public:
  // Constructor
  ImprimirTabla(std::string fichero_salida) : fichero_salida_(fichero_salida) { }

  // Imprime la cabecera de la tabla
  void ImprimirCabecera();

  // Imprime los resultados de los algoritmos
  void ImprimirResultados(ResultadoTSP resultado_fuerza_bruta, ResultadoTSP resultado_voraz, ResultadoTSP resultado_programacion_dinamica);

 private:
  std::string fichero_salida_;
};