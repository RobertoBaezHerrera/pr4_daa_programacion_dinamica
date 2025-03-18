/**
  * Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Grado en Ingeniería Informática
  * Asignatura: Diseño y Análisis de Algoritmos
  * @author Roberto Báez Herrera, Nailea Fayna Cruz Galván
  * Correo: alu0101497013@ull.edu.es, alu0101477497@ull.edu.es
  * @date 18/03/2025
  */

#include "../include/ContextoTSP.h"

void ContextoTSP::set_estrategia(InterfazTSP* estrategia) {
  estrategia_ = estrategia;
}

ResultadoTSP ContextoTSP::calcular(Grafo grafo) {
  if (estrategia_ == nullptr) {
    std::cout << "Error: No se ha establecido ninguna estrategia" << std::endl;
    exit(EXIT_FAILURE);
  }
  return estrategia_->calcular(grafo);
}