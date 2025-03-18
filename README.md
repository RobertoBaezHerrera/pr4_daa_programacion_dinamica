# Práctica 4: Diseño y Análisis de Algoritmos - Programación Dinámica

## Descripción de la Práctica

Esta práctica implementa y compara diferentes algoritmos para resolver el **Problema del Viajante de Comercio (TSP)**. El objetivo es encontrar la ruta más corta que visite todos los nodos de un grafo exactamente una vez y regrese al nodo inicial. Los algoritmos implementados son:

1. **Fuerza Bruta**: Genera todas las permutaciones posibles de los nodos y calcula el costo de cada ruta.
2. **Algoritmo Voraz**: Selecciona el nodo más cercano en cada paso, sin considerar soluciones globales.
3. **Programación Dinámica**: Utiliza una técnica de optimización basada en subproblemas para reducir la complejidad computacional.


## Autores

- **Roberto Báez Herrera** - alu0101497013@ull.edu.es
- **Nailea Fayna Cruz Galván** - alu0101477497@ull.edu.es

## Modo de Compilación

Para compilar el proyecto, asegúrate de tener instalado `g++` y sigue estos pasos:

1. Abre una terminal en el directorio raíz del proyecto.
2. Ejecuta el siguiente comando para compilar:
   ```bash
   make

## Modo de ejecución
   ```bash
   ./bin/pr4 grafos_pequenos salida.txt
```

## Estructura del proyecto
### Explicación

1. **`include/`**:
   - Contiene los archivos de cabecera (`.h`) organizados en subcarpetas:
     - `Algoritmos/`: Archivos de cabecera para los algoritmos implementados.
     - `utils/`: Archivos de cabecera para utilidades como gestión de archivos y resultados.

2. **`src/`**:
   - Contiene los archivos fuente (`.cc`) organizados en subcarpetas:
     - `Algoritmos/`: Implementaciones de los algoritmos.
     - `utils/`: Implementaciones de utilidades.

3. **`bin/`**:
   - Carpeta donde se genera el ejecutable (`pr4`).

4. **`build/`**:
   - Carpeta donde se generan los archivos objeto (`.o`).

5. **Otros archivos**:
   - `Makefile`: Archivo para compilar el proyecto.
   - `salida.txt` y `salida_grafos_grandes.txt`: Archivos de salida con los resultados de los algoritmos.
   - `README.md`: Archivo de documentación del proyecto.

Esta estructura es clara y modular, lo que facilita la organización y el mantenimiento del proyecto.### Explicación