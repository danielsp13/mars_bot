/**
 * @file mars_bot.ino
 * @authors Martin Anaya Quesada | Daniel Perez Ruiz
 * @brief Fichero principal del robot
 * @version 0.1.0
 */

// ===================================================================

// -- Inclusion de cabeceras
#include "MarsCore/MarsCore.h"

// ===================================================================

// -- Definicion de valores de disponibilidad de dispositivos
#define SENSORES_LINEA_DISPONIBLES 1
#define SENSORES_ULTRASONIDOS_DISPONIBLES 1
#define MOTORES_DISPONIBLES 1

// -- Definicion de estrategia de robot
#define ESTRATEGIA_BOT MarsCore::BOT_AGRESIVO

// ===================================================================

// -- Definicion de directiva de depuracion
//#define VERBOSE

// ===================================================================

// -- Definicion del robot
MarsCore josemiguel = MarsCore(
  "Josemi G",
  SENSORES_LINEA_DISPONIBLES,
  SENSORES_ULTRASONIDOS_DISPONIBLES,
  MOTORES_DISPONIBLES,
  ESTRATEGIA_BOT);

// ===================================================================

// -- Funciones principales

void setup(){
  // -- Depuracion
  #ifdef VERBOSE
    Serial.begin(MarsCore::SERIAL_NUMBER);
  #endif

  // -- Inicializar robot
  josemiguel.encender();
  josemiguel.esperar();
}

void loop(){
  // -- Decision 1: Josemi esta en una superficie valida del tatami
  if(!josemiguel.detectaBorde()){
    josemiguel.ataca();
  }
  // -- Decision 2: Josemi se encuentra en el borde noooooooooo
  else{
    josemiguel.retrocede();
  }


  // -- Imprimir informacion por el puerto serie
  #ifdef VERBOSE
    josemiguel.esperar();
    josemiguel.printInfo();
    Serial.println();
  #endif
}

// ===================================================================



