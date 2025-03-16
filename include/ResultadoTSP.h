#pragma once

#include <iostream>
#include <vector>
#include <chrono>

class ResultadoTSP {
 public:
  ResultadoTSP() : camino_({}), costo_(0), tiempo_(0) { }
  ResultadoTSP(std::vector<int> camino, int costo) : camino_(camino), costo_(costo) { }

  void EmpezarTiempo() {
    tiempo_ = clock();
  }
  void PararTiempo() {
    tiempo_ = (double(clock() - tiempo_) / CLOCKS_PER_SEC);
  }

  // Setters
  void SetTiempo(int tiempo) { tiempo_ = tiempo; }
  void SetCamino(std::vector<int> camino) { camino_ = camino; }
  void SetCosto(int costo) { costo_ = costo; }

  void ImprimirResultado() {
    std::cout << "Camino: ";
    for (int i = 0; i < camino_.size(); i++) {
      std::cout << camino_[i] << " ";
    }
    std::cout << std::endl;
    std::cout << "Costo: " << costo_ << std::endl;
    std::cout << "Tiempo: " << tiempo_ << std::endl;
  }
  
 private:
  std::vector<int> camino_;
  int costo_;
  double tiempo_ = 0.0;
};