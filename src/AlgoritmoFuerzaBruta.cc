#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
#include <climits>

#include "../include/AlgoritmoFuerzaBruta.h"

ResultadoTSP AlgoritmoFuerzaBruta::calcular(Grafo grafo) {
  ResultadoTSP resultado;
  resultado.EmpezarTiempo();

  std::vector<std::string> nodos;
  for (const auto& nodo_coste : grafo.GetMatrizCostes()) {
    nodos.push_back(nodo_coste.first);
  }

  std::string nodo_inicio = nodos[0];  // Empezamos desde el primer nodo
  std::vector<std::string> camino_optimo;
  int mejor_costo = INT_MAX;

  // Generar todas las permutaciones de nodos
  do {
    int costo_actual = 0;

    // Calcular el costo del camino actual
    for (int i = 0; i < nodos.size() - 1; ++i) {
      int costo = grafo.GetCoste(nodos[i], nodos[i + 1]);
      costo_actual += costo;
    }

    // Volver al nodo de inicio
    int costo_vuelta = grafo.GetCoste(nodos.back(), nodo_inicio); 
    // si no fuera desde A, nodo_inicio = nodos.front(), y next permutation empiezaría en nodos.begin()
    costo_actual += costo_vuelta;

    // Actualizar el mejor costo y camino si es una ruta válida
    if (costo_actual < mejor_costo) {
      mejor_costo = costo_actual;
      camino_optimo = nodos;
    }

  } while (std::next_permutation(nodos.begin() + 1, nodos.end()));  // Permutar los nodos excepto el inicio

  resultado.PararTiempo();
  resultado.SetCamino(camino_optimo);
  resultado.SetCosto(mejor_costo);

  return resultado;
}

