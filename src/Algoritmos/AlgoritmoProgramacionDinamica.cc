/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Diseño y Análisis de Algoritmos
 * @author Roberto Báez Herrera, Nailea Fayna Cruz Galván
 * Correo: alu0101497013@ull.edu.es, alu0101477497@ull.edu.es
 * @date 18/03/2025
 */

#include "../include/Algoritmos/AlgoritmoProgramacionDinamica.h"

#include <algorithm>
#include <chrono>
#include <climits>
#include <iostream>
#include <unordered_set>
#include <vector>

ResultadoTSP AlgoritmoProgramacionDinamica::calcular(Grafo grafo, std::vector<std::string> nodos_modi) {
  ResultadoTSP resultado;
  resultado.EmpezarTiempo();  // Iniciar la medición del tiempo de ejecución

  auto tiempo_inicio =
      std::chrono::high_resolution_clock::now();  // Guardamos el tiempo actual
  const auto tiempo_maximo =
      std::chrono::minutes(5);  // Tiempo máximo permitido: 5 minutos

  int numero_nodos =
      grafo.GetNumeroNodos();  // Obtener la cantidad de nodos en el grafo
  const int INF =
      INT_MAX;  // Definir un valor muy alto para representar "infinito"

  // Obtener la lista de nodos y ordenarlos alfabéticamente
  std::vector<std::string> nodos;
  for (const auto& nodo_coste : grafo.GetMatrizCostes()) {
    nodos.push_back(nodo_coste.first);
  }
  std::sort(
      nodos.begin(),
      nodos.end());  // Ordenar los nodos para asegurar que nodos[0] == "A"

  // Definir estructuras de programación dinámica (DP)
  std::vector<std::vector<int>> dp(
      1 << numero_nodos,
      std::vector<int>(numero_nodos, INF));  // dp[mask][i] almacena el costo mínimo de visitar los nodos en "mask" y terminar en "i"
  std::vector<std::vector<int>> prev(1 << numero_nodos, std::vector<int>(numero_nodos, -1));  // prev[mask][i] almacena de dónde venimos para reconstruir el camino

  dp[1][0] = 0;  // Caso base: Desde el nodo inicial "A" (índice 0), con solo
                 // "A" visitado

  // Recorrer todas las combinaciones posibles de nodos visitados (máscaras de bits)
  for (int mask = 1; mask < (1 << numero_nodos); ++mask) {
    for (int u = 0; u < numero_nodos; ++u) {
      if (!(mask & (1 << u)))
        continue;  // Si el nodo "u" no está en la máscara, lo ignoramos

      for (int v = 0; v < numero_nodos; ++v) {
        if (mask & (1 << v))
          continue;  // Si el nodo "v" ya fue visitado, lo ignoramos

        // Verificar si se ha excedido el tiempo límite de 5 minutos
        auto tiempo_actual = std::chrono::high_resolution_clock::now();
        if (tiempo_actual - tiempo_inicio > tiempo_maximo) {
          std::cerr << "Tiempo límite de 5 minutos excedido para prog "
                       "dinámica. Devolviendo el mejor resultado parcial." << std::endl;
          resultado.SetTiempo(-1);  // Indicar que el tiempo fue excedido
          resultado.SetCamino({});  // No hay camino completo
          resultado.SetCosto(-1);   // Indicar error en el costo
          return resultado;
        }

        int newMask =
            mask | (1 << v);  // Agregar el nodo "v" a la máscara actual
        if (dp[mask][u] != INF &&
            grafo.GetCoste(nodos[u], nodos[v]) !=
                INF) {  // Verificar si hay conexión entre "u" y "v"
          int newCost =
              dp[mask][u] +
              grafo.GetCoste(nodos[u], nodos[v]);  // Calcular nuevo costo
          if (newCost < dp[newMask][v]) {  // Si encontramos una mejor ruta, la
                                           // actualizamos
            dp[newMask][v] = newCost;
            prev[newMask][v] = u;  // Guardamos de dónde venimos
          }
        }
      }
    }
  }

  // Determinar la ruta óptima de regreso al nodo inicial "A"
  int finalMask =
      (1 << numero_nodos) - 1;  // Máscara completa (todos los nodos visitados)
  int lastNode = -1;            // Último nodo visitado antes de volver a "A"
  int costoTotal = INF;

  for (int i = 1; i < numero_nodos; ++i) {
    if (grafo.GetCoste(nodos[i], nodos[0]) !=
            INF &&  // Si hay conexión entre "i" y "A"
        dp[finalMask][i] + grafo.GetCoste(nodos[i], nodos[0]) < costoTotal) {
      costoTotal =
          dp[finalMask][i] +
          grafo.GetCoste(nodos[i], nodos[0]);  // Actualizar el costo mínimo
      lastNode = i;  // Guardar el último nodo antes de regresar a "A"
    }
  }

  // Si no se encontró un ciclo válido, devolver un error
  if (lastNode == -1 || costoTotal == INF) {
    std::cerr << "No hay ciclo hamiltoniano válido en el grafo." << std::endl;
    resultado.SetCosto(-1);
    return resultado;
  }

  // Reconstrucción del camino óptimo desde los datos almacenados en "prev"
  std::vector<std::string> camino;
  int mask = finalMask;
  while (lastNode != -1) {
    camino.push_back(nodos[lastNode]);  // Agregar el nodo a la ruta
    int temp = lastNode;
    lastNode = prev[mask][lastNode];  // Retroceder en el camino óptimo
    mask ^= (1 << temp);              // Eliminar el nodo actual de la máscara
  }
  std::reverse(camino.begin(),
               camino.end());  // Ordenar la ruta en el orden correcto
  camino.push_back(nodos[0]);  // Agregar "A" al final para completar el ciclo

  resultado.PararTiempo();         // Detener el temporizador
  resultado.SetCamino(camino);     // Guardar el camino encontrado
  resultado.SetCosto(costoTotal);  // Guardar el costo mínimo encontrado

  return resultado;  // Devolver el resultado óptimo
}