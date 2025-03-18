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
#include <fstream>

#include "ResultadoTSP.h"

// Clase que imprime los resultados de los algoritmos en una tabla
class ImprimirTabla {
 public:
  // Constructor
  ImprimirTabla(std::string fichero_salida) : fichero_salida_(fichero_salida) { }

  // Imprime la cabecera de la tabla
  void ImprimirCabecera();

  // Imprime los resultados de los algoritmos
  void ImprimirResultados(ResultadoTSP resultado_fuerza_bruta, ResultadoTSP resultado_voraz, ResultadoTSP resultado_programacion_dinamica, std::string fichero_entrada);

 private:
  std::ofstream fichero_salida_;
};