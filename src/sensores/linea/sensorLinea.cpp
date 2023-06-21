/**
 * @file sensorLinea.cpp
 * @authors Martin Anaya Quesada, Daniel Perez Ruiz
 * @brief Implementacion de metodos de la clase SensorLinea
 * @version 0.1.0
 */

#include "sensorLinea.h"

// =================================================================

// IMPLEMENTACION DE CONSTRUCTOR

SensorLinea::SensorLinea(String id, uint8_t nPin){
    // -- Asignar id de sensor
    idSensor = id;
    // -- Asignar valor de pin
    pin = nPin;
    // -- Asignar valor ultimo leido
    ultimoValorLeido = -1;

    // -- Especificar modo de pin en Arduino
    pinMode(pin, MODO_PIN);
    
    // -- Iniciar terminal (solo depuracion)
    Serial.begin(SERIAL_NUMBER);
}

// =================================================================

// IMPLEMENTACION DE METODOS DE CONTROL

inline void SensorLinea::leerValor(){
    ultimoValorLeido = digitalRead(pin);
}

inline int SensorLinea::lineaNegra(){
    leerValor();

    return ultimoValorLeido == REF_BLANCO;
}

// =================================================================

// IMPLEMENTACION DE METODOS DE DEPURACION

void SensorLinea::printInfo(){
    String info = "SENSOR LINEA >> ";
    info.concat("Id: "); info.concat(idSensor);
    info.concat("Pin: "); info.concat(pin);
    info.concat("; Valor leido: "); info.concat(ultimoValorLeido);

    Serial.println(info);
}