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