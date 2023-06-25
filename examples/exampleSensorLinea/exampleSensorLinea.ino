/**
 * @file exampleSensorLinea.ino
 * @authors Martin Anaya Quesada, Daniel Perez Ruiz
 * @brief Fichero de pruebas del controlador de SensorLinea
 * @version 0.1.0
 */

#include "sensores/linea/sensorLinea.h"

// Definicion de pines
#define PIN_SENSORLINEA_DCHA A4
#define PIN_SENSORLINEA_IZDA A5

// Definicion de controladores de sensor
SensorLinea sensorDcha = SensorLinea("SLINEA_DCHA",PIN_SENSORLINEA_DCHA);
SensorLinea sensorIzda = SensorLinea("SLINEA_IZDA",PIN_SENSORLINEA_IZDA);

const uint16_t DELAY = 1500;
const String SEPARATOR = "==========================================================";

/**
 * @brief Realiza pruebas sobre el sensor de linea especificado como argumento
 * @param s : Sensor de linea al que realizar pruebas
 */
void testSensor(const SensorLinea & s){
    //1. Comprobar superficie
    s.scanBorde();
    //2. Imprimir informacion
    s.printInfo();
}

// =================================================================================

void setup(){
    Serial.begin(SensorLinea::SERIAL_NUMBER);
}

void loop(){
    Serial.println(SEPARATOR);
    // -- Llamada a las funciones de prueba
    testSensor(sensorIzda);
    testSensor(sensorDcha);
    Serial.println(SEPARATOR);
    Serial.println();
    
    // -- Realizar delay de espera
    delay(DELAY);
}
