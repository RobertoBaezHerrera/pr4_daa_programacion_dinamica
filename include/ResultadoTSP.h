#pragma once

#include <iostream>
#include <vector>
#include <chrono>

class ResultadoTSP {
 public:
  ResultadoTSP() : camino_({}), costo_(0), tiempo_(0) { }
  ResultadoTSP(std::vector<std::string> camino, int costo) : camino_(camino), costo_(costo) { }

  void EmpezarTiempo();
  void PararTiempo();
  void ImprimirResultado() const;

  // Setters
  void SetTiempo(int tiempo) { tiempo_ = tiempo; }
  void SetCamino(std::vector<std::string> camino) { camino_ = camino; }
  void SetCosto(int costo) { costo_ = costo; }
  
 private:
  std::vector<std::string> camino_;
  int costo_;
  double tiempo_ = 0.0;
};