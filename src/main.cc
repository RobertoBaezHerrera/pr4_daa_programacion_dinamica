/**
  * Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Grado en Ingeniería Informática
  * Asignatura: Diseño y Análisis de Algoritmos
  * @author Roberto Báez Herrera, Nailea Fayna Cruz Galván
  * Correo: alu0101497013@ull.edu.es, alu0101477497@ull.edu.es
  * @date 18/03/2025
  */

#include <iostream>
#include <string>

#include "../include/utils/GestorArchivos.h"
#include "../include/Grafo.h"
#include "../include/Algoritmos/AlgoritmoFuerzaBruta.h"
#include "../include/Algoritmos/AlgoritmoVoraz.h"
#include "../include/Algoritmos/AlgoritmoVorazMedio.h"
#include "../include/Algoritmos/AlgoritmoProgramacionDinamica.h"
#include "../include/ContextoTSP.h"
#include "../include/utils/ImprimirTabla.h"

// Texto de ayuda
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

// Ejecuta los algoritmos y los imprime en la tabla
void EjecutarAlgorimtos(std::string fichero_entrada, ImprimirTabla& tabla) {
  Grafo grafo{fichero_entrada};
  ContextoTSP contexto;
  AlgoritmoFuerzaBruta* fuerza_bruta = new AlgoritmoFuerzaBruta();
  AlgoritmoVoraz* voraz = new AlgoritmoVoraz();
  AlgoritmoProgramacionDinamica* programacion_dinamica = new AlgoritmoProgramacionDinamica();
  AlgoritmoVorazMedio* voraz_medio = new AlgoritmoVorazMedio();

  contexto.set_estrategia(fuerza_bruta);
  ResultadoTSP resultado_fuerza_bruta = contexto.calcular(grafo);
  // resultado_fuerza_bruta.ImprimirResultado();

  contexto.set_estrategia(voraz);
  ResultadoTSP resultado_voraz = contexto.calcular(grafo);
  // resultado_voraz.ImprimirResultado();

  contexto.set_estrategia(programacion_dinamica);
  ResultadoTSP resultado_programacion_dinamica = contexto.calcular(grafo);
  // resultado_programacion_dinamica.ImprimirResultado();

  contexto.set_estrategia(voraz_medio);
  ResultadoTSP resultado_voraz_medio = contexto.calcular(grafo);
  //resultado_voraz_medio.ImprimirResultado();

  tabla.ImprimirResultados(resultado_fuerza_bruta, resultado_voraz, resultado_voraz_medio,
                           resultado_programacion_dinamica, fichero_entrada);

  delete fuerza_bruta;
  delete voraz;
  delete voraz_medio;
  delete programacion_dinamica;
}

// Lee los ficheros de entrada y ejecuta los algoritmos
void LeerFicheros(int argc, char* argv[]) {
  std::string ruta_directorio{argv[1]};
  std::string fichero_salida{argv[2]};
  ImprimirTabla tabla{fichero_salida};
  tabla.ImprimirCabecera();
  GestorArchivos gestor{ruta_directorio, fichero_salida};
  gestor.LeerNombresFicherosEntrada();
  for (auto& fichero : gestor.GetFicherosEntrada()) {
    EjecutarAlgorimtos(fichero, tabla);
  }
  return;
}

// Programa principal
int main(int argc, char* argv[]) {
    Usage(argc, argv);
    LeerFicheros(argc, argv);
    return 0;
}