#include "../include/ImprimirTabla.h"
#include <iomanip>  // Para std::setw

void ImprimirTabla::ImprimirCabecera() {
    // Establecer un ancho fijo para cada columna
    fichero_salida_ << std::left;  // Alinear a la izquierda
    fichero_salida_ << std::setw(20) << "Instancia";
    fichero_salida_ << std::setw(25) << "Valor Fuerza Bruta";
    fichero_salida_ << std::setw(25) << "Tiempo Fuerza Bruta(ms)";
    fichero_salida_ << std::setw(20) << "Valor Voraz";
    fichero_salida_ << std::setw(20) << "Tiempo Voraz(ms)";
    fichero_salida_ << std::setw(30) << "Valor Programación Dinámica";
    fichero_salida_ << std::setw(30) << "Tiempo Programación Dinámica(ms)" << std::endl;
}

void ImprimirTabla::ImprimirResultados(ResultadoTSP resultado_fuerza_bruta, ResultadoTSP resultado_voraz, ResultadoTSP resultado_programacion_dinamica, std::string fichero_entrada) {
    // Quitar la ruta del fichero
    fichero_entrada = fichero_entrada.substr(fichero_entrada.find_last_of("/") + 1);

    // Establecer un ancho fijo para cada columna
    fichero_salida_ << std::left;  // Alinear a la izquierda
    fichero_salida_ << std::setw(20) << fichero_entrada;
    fichero_salida_ << std::setw(25) << resultado_fuerza_bruta.GetCosto();
    if (resultado_fuerza_bruta.GetTiempo() == -1) {
      fichero_salida_ << std::setw(25) << "EXCESIVO";
    } else {
      fichero_salida_ << std::setw(25) << resultado_fuerza_bruta.GetTiempo() * 1000;  // Convertir a ms
    }
    fichero_salida_ << std::setw(20) << resultado_voraz.GetCosto();
    if (resultado_voraz.GetTiempo() == -1) {
      fichero_salida_ << std::setw(20) << "EXCESIVO";
    } else {
      fichero_salida_ << std::setw(20) << resultado_voraz.GetTiempo() * 1000;  // Convertir a ms
    }
    fichero_salida_ << std::setw(30) << resultado_programacion_dinamica.GetCosto();
    if (resultado_programacion_dinamica.GetTiempo() == -1) {
      fichero_salida_ << std::setw(30) << "EXCESIVO";
    } else {
      fichero_salida_ << std::setw(30) << resultado_programacion_dinamica.GetTiempo() * 1000 << std::endl;  // Convertir a ms
    }
}