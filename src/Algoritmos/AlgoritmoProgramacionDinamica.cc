#include "../include/Algoritmos/AlgoritmoProgramacionDinamica.h"

#include <algorithm>
#include <chrono>
#include <climits>
#include <iostream>
#include <unordered_set>
#include <vector>

ResultadoTSP AlgoritmoProgramacionDinamica::calcular(Grafo grafo) {
  ResultadoTSP resultado;
  resultado.EmpezarTiempo();

  auto tiempo_inicio =
      std::chrono::high_resolution_clock::now();       // Iniciar temporizador
  const auto tiempo_maximo = std::chrono::minutes(5);  // Límite de 5 minutos

  int numero_nodos = grafo.GetNumeroNodos();
  const int INF = INT_MAX;

  // Obtener nodos y ordenarlos
  std::vector<std::string> nodos;
  for (const auto& nodo_coste : grafo.GetMatrizCostes()) {
    nodos.push_back(nodo_coste.first);
  }
  std::sort(nodos.begin(), nodos.end());  // Asegurar que nodos[0] == "A"

  std::vector<std::vector<int>> dp(1 << numero_nodos, std::vector<int>(numero_nodos, INF));
  std::vector<std::vector<int>> prev(1 << numero_nodos, std::vector<int>(numero_nodos, -1));

  dp[1][0] = 0;  // Partimos de A

  for (int mask = 1; mask < (1 << numero_nodos); ++mask) {
    for (int u = 0; u < numero_nodos; ++u) {
      if (!(mask & (1 << u))) continue;

      for (int v = 0; v < numero_nodos; ++v) {
        if (mask & (1 << v)) continue;

        // Verificar si el tiempo límite ha sido excedido
        auto tiempo_actual = std::chrono::high_resolution_clock::now();
        if (tiempo_actual - tiempo_inicio > tiempo_maximo) {
          std::cerr << "Tiempo límite de 5 minutos excedido para prog dinamica. Devolviendo el mejor resultado parcial."
                    << std::endl;
          resultado.SetTiempo(-1);
          resultado.SetCamino({});
          resultado.SetCosto(-1);
          return resultado;
        }

        int newMask = mask | (1 << v);
        if (dp[mask][u] != INF && grafo.GetCoste(nodos[u], nodos[v]) != INF) {
          int newCost = dp[mask][u] + grafo.GetCoste(nodos[u], nodos[v]);
          if (newCost < dp[newMask][v]) {
            dp[newMask][v] = newCost;
            prev[newMask][v] = u;
          }
        }
      }
    }
  }

  int finalMask = (1 << numero_nodos) - 1;
  int lastNode = -1;
  int costoTotal = INF;

  for (int i = 1; i < numero_nodos; ++i) {
    if (grafo.GetCoste(nodos[i], nodos[0]) != INF &&
        dp[finalMask][i] + grafo.GetCoste(nodos[i], nodos[0]) < costoTotal) {
      costoTotal = dp[finalMask][i] + grafo.GetCoste(nodos[i], nodos[0]);
      lastNode = i;
    }
  }

  // Si no encontramos un ciclo válido, devolver error
  if (lastNode == -1 || costoTotal == INF) {
    std::cerr << "No hay ciclo hamiltoniano válido en el grafo." << std::endl;
    resultado.SetCosto(-1);
    return resultado;
  }

  // Reconstrucción del camino
  std::vector<std::string> camino;
  int mask = finalMask;
  while (lastNode != -1) {
    camino.push_back(nodos[lastNode]);
    int temp = lastNode;
    lastNode = prev[mask][lastNode];
    mask ^= (1 << temp);
  }
  std::reverse(camino.begin(), camino.end());
  camino.push_back(nodos[0]);

  resultado.PararTiempo();
  resultado.SetCamino(camino);
  resultado.SetCosto(costoTotal);

  return resultado;
}