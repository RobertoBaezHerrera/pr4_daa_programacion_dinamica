#include "../include/Algoritmos/AlgoritmoMixto.h"
#include "../include/Algoritmos/AlgoritmoVoraz.h"
#include "../include/Algoritmos/AlgoritmoFuerzaBruta.h"

#include <algorithm>
#include <chrono>
#include <climits>
#include <iostream>
#include <unordered_set>
#include <vector>

ResultadoTSP AlgoritmoMixto::calcular(Grafo grafo, std::vector<std::string> nodos_modi) {
  ResultadoTSP resultado;
  resultado.EmpezarTiempo();

  auto tiempo_inicio = std::chrono::high_resolution_clock::now();  // Iniciar temporizador
  const auto tiempo_maximo = std::chrono::minutes(5);  // Límite de 5 minutos

  // Obtener todos los nodos del grafo
  std::vector<std::string> nodos;
  for (const auto& nodo_coste : grafo.GetMatrizCostes()) {
    nodos.push_back(nodo_coste.first);
  }

  // Dividir los nodos en 75% y 25%
  size_t num_nodos_voraz = nodos.size() * 0.75;
  std::vector<std::string> nodos_voraz(nodos.begin(), nodos.begin() + num_nodos_voraz);



  // Resolver los primeros 75% nodos utilizando el algoritmo Voraz
  AlgoritmoVoraz voraz;
  Grafo subgrafo_voraz = grafo.Subgrafo(nodos_voraz);
  ResultadoTSP resultado_voraz = voraz.calcular(subgrafo_voraz, nodos_voraz);

  std::vector<std::string> nodos_fuerza_bruta1(nodos.begin() + num_nodos_voraz, nodos.end());
  std::vector<std::string> nodos_fuerza_bruta2 = resultado_voraz.GetCamino();
  nodos_fuerza_bruta2.insert(nodos_fuerza_bruta2.end(), nodos_fuerza_bruta1.begin(), nodos_fuerza_bruta1.end());

  // Resolver el 25% restante utilizando el algoritmo de Fuerza Bruta
  AlgoritmoFuerzaBruta fuerza_bruta;
  ResultadoTSP resultado_fuerza_bruta = fuerza_bruta.calcular(grafo, nodos_fuerza_bruta2);

  std::vector<std::string> camino_fuerza_bruta = resultado_fuerza_bruta.GetCamino();

  int costo_total = resultado_voraz.GetCosto() + resultado_fuerza_bruta.GetCosto();

  resultado.PararTiempo();
  resultado.SetCamino(camino_fuerza_bruta);
  // Imprimir camino
  for (const auto& nodo : camino_fuerza_bruta) {
    std::cout << nodo << " ";
  }
  std::cout << std::endl;
  resultado.SetCosto(costo_total);

  return resultado;
}