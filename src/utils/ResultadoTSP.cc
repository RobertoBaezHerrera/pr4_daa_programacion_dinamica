/**
  * Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Grado en Ingeniería Informática
  * Asignatura: Diseño y Análisis de Algoritmos
  * @author Roberto Báez Herrera, Nailea Fayna Cruz Galván
  * Correo: alu0101497013@ull.edu.es, alu0101477497@ull.edu.es
  * @date 18/03/2025
  */

#include "../include/utils/ResultadoTSP.h"

void ResultadoTSP::EmpezarTiempo() {
  tiempo_ = clock();
}

void ResultadoTSP::PararTiempo() {
  tiempo_ = (double(clock() - tiempo_) / CLOCKS_PER_SEC);
}

void ResultadoTSP::ImprimirResultado() const {
  std::cout << "Camino: ";
  for (int i = 0; i < camino_.size(); i++) {
    std::cout << camino_[i] << " ";
  }
  std::cout << std::endl;
  std::cout << "Costo: " << costo_ << std::endl;
  std::cout << "Tiempo: " << tiempo_ << " segundos" << std::endl;
}