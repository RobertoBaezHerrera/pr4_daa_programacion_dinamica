#include "../include/ResultadoTSP.h"

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