#include "../include/AlgoritmoFuerzaBruta.h"

ResultadoTSP AlgoritmoFuerzaBruta::calcular(Grafo grafo) {
  ResultadoTSP resultado;
  resultado.EmpezarTiempo();
  std::vector<int> camino = {0, 1, 2, 3, 4};
  int coste = 0;
  /* Codigo del algoritmo */
  resultado.PararTiempo();
  resultado.SetCamino(camino);
  resultado.SetCosto(coste);
  return resultado;
}