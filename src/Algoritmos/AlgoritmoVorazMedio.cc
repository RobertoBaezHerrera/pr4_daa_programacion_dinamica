/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Diseño y Análisis de Algoritmos
 * @author Roberto Báez Herrera, Nailea Fayna Cruz Galván
 * Correo: alu0101497013@ull.edu.es, alu0101477497@ull.edu.es
 * @date 18/03/2025
 */

#include "../include/Algoritmos/AlgoritmoVorazMedio.h"

#include <algorithm>
#include <chrono>
#include <climits>
#include <iostream>
#include <unordered_set>
#include <vector>

ResultadoTSP AlgoritmoVorazMedio::calcular(Grafo grafo) {
  ResultadoTSP resultado;
  resultado.EmpezarTiempo();

  auto tiempo_inicio = std::chrono::high_resolution_clock::now();       // Iniciar temporizador
  const auto tiempo_maximo = std::chrono::minutes(5);  // Límite de 5 minutos

  std::vector<std::string> nodos;
  for (const auto& nodo_coste : grafo.GetMatrizCostes()) {
    nodos.push_back(nodo_coste.first);
  }

  std::string nodo_inicio = nodos[0];  // Partimos de la primera ciudad
  std::vector<std::string> camino = {nodo_inicio};
  std::unordered_set<std::string> visitados = {nodo_inicio};
  std::string nodo_actual = nodo_inicio;
  int costo_total = 0;

  while (visitados.size() < nodos.size()) {
    // Verificar si el tiempo límite ha sido excedido
    auto tiempo_actual = std::chrono::high_resolution_clock::now();
    if (tiempo_actual - tiempo_inicio > tiempo_maximo) {
      std::cerr << "Tiempo límite de 5 minutos excedido para voraz. "
                   "Devolviendo el mejor resultado parcial." << std::endl;
      resultado.SetTiempo(-1);
      resultado.SetCamino(camino);
      resultado.SetCosto(costo_total);
      return resultado;
    }

    std::vector<std::pair<int, std::string>> distancias;

    // Buscar todas las ciudades no visitadas y sus distancias
    for (int i = 0; i < nodos.size(); i++) {
      std::string vecino = nodos[i];
      if (visitados.find(vecino) == visitados.end() && grafo.GetMatrizCostes().at(nodo_actual).count(vecino)) {
        int distancia = grafo.GetCoste(nodo_actual, vecino);
        distancias.push_back({distancia, vecino});
      }
    }

    // Si no hay nodo disponible (grafo mal conectado)
    if (distancias.empty()) break;

    // Ordenar las distancias
    std::sort(distancias.begin(), distancias.end());

    // Seleccionar la ciudad en la mitad del orden de distancias
    int indice_medio = distancias.size() / 2;
    std::string siguiente_nodo = distancias[indice_medio].second;
    int menor_distancia = distancias[indice_medio].first;

    // Agregar a la ruta
    camino.push_back(siguiente_nodo);
    visitados.insert(siguiente_nodo);
    costo_total += menor_distancia;
    nodo_actual = siguiente_nodo;
}

// Volver al nodo de inicio
if (grafo.GetMatrizCostes().at(nodo_actual).count(nodo_inicio)) {
  costo_total += grafo.GetCoste(nodo_actual, nodo_inicio);
  camino.push_back(nodo_inicio);
}

resultado.PararTiempo();
resultado.SetCamino(camino);
resultado.SetCosto(costo_total);

return resultado;
}