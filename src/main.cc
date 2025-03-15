/**
  * Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Grado en Ingeniería Informática
  * Asignatura: Diseño y Análisis de Algoritmos
  * @file main.cc
  * @author Roberto Báez Herrera, Nailea Fayna Cruz Galván
  * Correo: alu0101497013@ull.edu.es, alu0101477497@ull.edu.es
  * @date 18/03/2025
  * @brief Programa principal
  */

#include <iostream>
#include <string>

#include "../include/GestorArchivos.h"
#include "../include/Grafo.h"

const std::string kTextoAyuda = "Uso: pr4_TCP <ruta_directorio> <fichero_salida.txt>\n\n"
    "Resuelve el TSP de 3 formas diferentes: fuerza bruta, voraz y programación dinámica.\n"
    "Obtiene los grafos de los ficheros de entrada que estánn el la ruta del directorio.\n"
    "Además, imprime los resultados en un fichero de salida.\n"
    "Opciones: \n"
    "  --help \t\t Muestra la ayuda. \n"
    "  <ruta_directorio> <fichero_salida.txt> \t ";

// Según la entrada, muestra la ayuda y comprobar los parametros
void Usage(int argc, char* argv[]) {
    if (argc == 2) {
      std::string parametro{argv[1]};
      if (parametro == "--help") {
        std::cout << kTextoAyuda << std::endl;
        exit(EXIT_SUCCESS);
      } else {
        std::cout << argv[0] << ": Error: Parámetro '" << parametro << "' no reconocido." << std::endl;
        std::cout << "Pruebe '" << argv[0] << " --help' para más información." << std::endl;
        exit(EXIT_SUCCESS);
      }
    } else if (argc != 3) {
      std::cout << argv[0] << ": Error: Numero de parámetros incorrectos." << std::endl;
      std::cout << "Pruebe '" << argv[0] << " --help' para más información." << std::endl;
      exit(EXIT_SUCCESS);
    }
  }

  void Ejecutar(int argc, char* argv[]) {
    std::cout << "Programa ejecutado\n\n";
    if (argc == 3) {
        std::string ruta_directorio{argv[1]};
        std::string fichero_salida{argv[2]};
        GestorArchivos gestor{ruta_directorio, fichero_salida};
        gestor.LeerNombresFicherosEntrada();
        for (auto& fichero : gestor.GetFicherosEntrada()) {
          Grafo grafo{fichero};
        }
        
        
      return;
    }
  }

int main(int argc, char* argv[]) {
    Usage(argc, argv);
    Ejecutar(argc, argv);
    return 0;
}