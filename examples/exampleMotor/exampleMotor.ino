/**
 * @file exampleMotores.ino
 * @authors Martin Anaya Quesada, Daniel Perez Ruiz
 * @brief Fichero de pruebas del controlador de los Motores
 * @version 0.1.0
 */

#include "motor/motor.h"

// Definicion de pines
#define PIN_MOTOR_IZDA_VEL A1
#define PIN_MOTOR_IZDA_SENTIDO_1 10
#define PIN_MOTOR_IZDA_SENTIDO_2 11

#define PIN_MOTOR_DCHA_VEL A0
#define PIN_MOTOR_DCHA_SENTIDO_1 12
#define PIN_MOTOR_DCHA_SENTIDO_2 13

// Definicion de controladores de motor
Motor motorIzda = Motor("MOTOR_IZDA",PIN_MOTOR_IZDA_VEL,PIN_MOTOR_IZDA_SENTIDO_1,PIN_MOTOR_IZDA_SENTIDO_2);
Motor motorDcha = Motor("MOTOR_DCHA",PIN_MOTOR_DCHA_VEL,PIN_MOTOR_DCHA_SENTIDO_1,PIN_MOTOR_DCHA_SENTIDO_2);

const uint16_t DELAY = 2000;
const String SEPARATOR = "==========================================================";

const uint8_t MAX_VELOCIDAD_ENCENDIDO = 70;
const uint8_t MIN_VELOCIDAD_ENCENDIDO = 0;

/**
 * @brief Realiza pruebas sobre el motor especificado como argumento
 * @param m : Motor al que realizar pruebas
 */
void testMotor(const Motor & m){
    delay(DELAY);

    //1. Encender motor
    m.encender();
    //2. Imprimir informacion
    m.printInfo();

    //realizar espera
    delay(DELAY);

    //3. Set velocidad (50)
    m.setVelocidad(MAX_VELOCIDAD_ENCENDIDO);
    //4. Imprimir informacion
    m.printInfo();

    //realizar espera
    delay(DELAY);

    //3. Set velocidad (0)
    m.setVelocidad(MIN_VELOCIDAD_ENCENDIDO);
    //4. Imprimir informacion
    m.printInfo();

    //realizar espera
    delay(DELAY);

    //5. Set sentido (atras)
    m.setSentido(Motor::ATRAS);
    //6. Set velocidad (100)
    m.setVelocidad(MAX_VELOCIDAD_ENCENDIDO);
    //7. Imprimir informacion
    m.printInfo();

    //realizar espera
    delay(DELAY);

    //8. Apagar motor
    m.apagar();
    //9. Imprimir informacion
    m.printInfo();
}

// =================================================================================

void setup(){
    Serial.begin(Motor::SERIAL_NUMBER);

    Serial.println(SEPARATOR);
    // -- Llamada a las funciones de prueba
    testMotor(motorIzda);
    testMotor(motorDcha);
    Serial.println(SEPARATOR);
    Serial.println();
}

void loop(){
    
}