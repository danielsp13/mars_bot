/**
 * @file sensorUltrasonidos.cpp
 * @authors Martin Anaya Quesada, Daniel Perez Ruiz
 * @brief Implementacion de metodos de la clase sensorUltrasonidos
 * @version 0.1.0
 */

#include "sensorUltrasonidos.h"

// =================================================================

// IMPLEMENTACION DE CONSTRUCTOR

SensorUltrasonidos::SensorUltrasonidos(String id, uint8_t nPinTrigger, uint8_t nPinEcho){
    // -- Almacenar identificador
    idSensor = id;
    // -- Almacenar valores de pin
    pinTrigger = nPinTrigger;
    pinEcho = nPinEcho;

    // -- Asignar ultimo valor leido
    ultimoValorLeido = -1;

    // -- Activar modos de pin
    pinMode(pinTrigger, MODO_PIN_TRIGGER);
    pinMode(pinEcho, MODO_PIN_ECHO);

    // -- Inicializar pin en estado bajo (0)
    digitalWrite(pinTrigger, LOW);

    // -- Iniciar terminal (solo depuracion)
    Serial.begin(SERIAL_NUMBER);
}

// =================================================================

// IMPLEMENTACION DE METODOS DE CONTROL

void SensorUltrasonidos::leerValor(){
    // -- Enviar pulso de 10us a traves de trigger
    digitalWrite(pinTrigger, HIGH);
    delayMicroseconds(DELAY);
    digitalWrite(pinTrigger, LOW);

    // -- Recibir pulso de respuesta
    long tiempo = pulseIn(pinEcho, HIGH);

    // -- Calcular distancia (y asignar a valor leido)
    ultimoValorLeido = tiempo / VELOCIDAD_CM_US;
}

// =================================================================

// IMPLEMENTACION DE METODOS DE DEPURACION

void SensorUltrasonidos::printInfo(){
    String info = "SENSOR ULTRASONIDOS >> ";
    info.concat("Id: "); info.concat(idSensor);
    info.concat("; Pin: "); info.concat(pin);
    info.concat("; Distancia: "); info.concat(ultimoValorLeido); info.concat(" cm.");

    Serial.println(info);
}