#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
#include <climits>

#include "../include/AlgoritmoFuerzaBruta.h"

ResultadoTSP AlgoritmoFuerzaBruta::calcular(Grafo grafo) {
  ResultadoTSP resultado;
  auto tiempo_inicio = std::chrono::high_resolution_clock::now();  // Iniciar temporizador
  const auto tiempo_maximo = std::chrono::minutes(5);  // Límite de 5 minutos

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
    // Verificar si el tiempo límite ha sido excedido
    auto tiempo_actual = std::chrono::high_resolution_clock::now();
    if (tiempo_actual - tiempo_inicio > tiempo_maximo) {
      std::cerr << "Tiempo límite de 5 minutos excedido. Devolviendo el mejor resultado parcial." << std::endl;
      resultado.SetTiempo(-1);
      resultado.SetCamino(camino_optimo);
      resultado.SetCosto(mejor_costo);
      return resultado;
    }

    int costo_actual = 0;

    // Calcular el costo del camino actual
    for (int i = 0; i < nodos.size() - 1; ++i) {
      int costo = grafo.GetCoste(nodos[i], nodos[i + 1]);
      costo_actual += costo;
    }

    // Volver al nodo de inicio
    int costo_vuelta = grafo.GetCoste(nodos.back(), nodo_inicio); 
    costo_actual += costo_vuelta;

    // Actualizar el mejor costo y camino si es una ruta válida
    if (costo_actual < mejor_costo) {
      mejor_costo = costo_actual;
      camino_optimo = nodos;
    }

  } while (std::next_permutation(nodos.begin() + 1, nodos.end()));  // Permutar los nodos excepto el inicio

  camino_optimo.push_back(nodo_inicio);

  resultado.PararTiempo();
  resultado.SetCamino(camino_optimo);
  resultado.SetCosto(mejor_costo);

  return resultado;
}