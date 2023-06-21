/**
 * @file exampleSensorLinea.ino
 * @authors Martin Anaya Quesada, Daniel Perez Ruiz
 * @brief Fichero de pruebas del controlador de SensorLinea
 * @version 0.1.0
 */

#include <headerLibs.h>

// Definicion de pines
#define PIN_SENSORLINEA_IZDA 0
#define PIN_SENSORLINEA_DCHA 1

// Definicion de controladores de sensor
SensorLinea sensorIzda = SensorLinea("SLINEA_IZDA",PIN_SENSORLINEA_IZDA);
SensorLinea sensorDcha = SensorLinea("SLINEA_DCHA",PIN_SENSORLINEA_DCHA);

const uint16_t DELAY = 1500;
const String SEPARATOR = "=========================================================="

/**
 * @brief Realiza pruebas sobre el sensor de linea especificado como argumento
 * @param s : Sensor de linea al que realizar pruebas
 */
void testSensor(const SensorLinea & s){
    //1. Comprobar superficie
    s.lineaNegra();
    //2. Imprimir informacion
    s.printInfo();
}

// =================================================================================

void setup(){
    Serial.begin(9600);
}

void loop(){
    Serial.println(SEPARATOR);
    // -- Llamada a las funciones de prueba
    testSensor(sensorIzda);
    delay(DELAY);
    testSensor(sensorDcha);
    Serial.println(SEPARATOR);
}