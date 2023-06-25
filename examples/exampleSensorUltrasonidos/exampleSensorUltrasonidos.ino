/**
 * @file exampleSensorUltrasonidos.ino
 * @authors Martin Anaya Quesada, Daniel Perez Ruiz
 * @brief Fichero de pruebas del controlador de SensorUltrasonidos
 * @version 0.1.0
 */

#include "sensores/ultrasonidos/sensorUltrasonidos.h"

// Definicion de pines
#define PIN_SENSORULTRA_IZDA_TRIGGER 2 
#define PIN_SENSORULTRA_IZDA_ECHO 3

#define PIN_SENSORULTRA_CENTRO_TRIGGER 4
#define PIN_SENSORULTRA_CENTRO_ECHO 5

#define PIN_SENSORULTRA_DCHA_TRIGGER 6
#define PIN_SENSORULTRA_DCHA_ECHO 7

// Definicion de controladores de sensor
SensorUltrasonidos sensorIzda = SensorUltrasonidos("SULTRAS_IZDA",PIN_SENSORULTRA_IZDA_TRIGGER,PIN_SENSORULTRA_IZDA_ECHO);
SensorUltrasonidos sensorCentro = SensorUltrasonidos("SULTRAS_CENTRO",PIN_SENSORULTRA_CENTRO_TRIGGER,PIN_SENSORULTRA_CENTRO_ECHO);
SensorUltrasonidos sensorDcha = SensorUltrasonidos("SULTRAS_DCHA",PIN_SENSORULTRA_DCHA_TRIGGER,PIN_SENSORULTRA_DCHA_ECHO);

const uint16_t DELAY = 1500;
const String SEPARATOR = "==========================================================";

/**
 * @brief Realiza pruebas sobre el sensor de ultrasonidos especificado como argumento
 * @param s : Sensor de ultrasonidos al que realizar pruebas
 */
void testSensor(const SensorUltrasonidos & s){
    //1. Medir distancia
    s.scan();
    //2. Imprimir informacion
    s.printInfo();
}

// =================================================================================

void setup(){
    Serial.begin(SensorUltrasonidos::SERIAL_NUMBER);
}

void loop(){
    Serial.println(SEPARATOR);
    testSensor(sensorIzda);
    testSensor(sensorCentro);
    testSensor(sensorDcha);
    Serial.println(SEPARATOR);
    Serial.println();
    delay(DELAY);
}
