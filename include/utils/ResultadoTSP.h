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
#include <vector>
#include <chrono>

// Clase que almacena el resultado de un problema TSP
class ResultadoTSP {
 public:
  ResultadoTSP() : camino_({}), costo_(0), tiempo_(0) { }
  ResultadoTSP(std::vector<std::string> camino, int costo) : camino_(camino), costo_(costo) { }

  void EmpezarTiempo();
  void PararTiempo();
  void ImprimirResultado() const;

  // Getters
  int GetCosto() const { return costo_; }
  double GetTiempo() const { return tiempo_; }
  std::vector<std::string> GetCamino() const { return camino_; }

  // Setters
  void SetTiempo(int tiempo) { tiempo_ = tiempo; }
  void SetCamino(std::vector<std::string> camino) { camino_ = camino; }
  void SetCosto(int costo) { costo_ = costo; }
  
 private:
  std::vector<std::string> camino_;
  int costo_;
  double tiempo_ = 0.0;
};