/**
 * @file motor.h
 * @authors Martin Anaya Quesada, Daniel Perez Ruiz
 * @brief Definicion de la clase motor
 * @version 0.1.0
 */

#ifndef _SMP_MD_MOTOR_H
#define _SMP_MD_MOTOR_H

/**
 * @brief Esta clase permite interactuar con el driver de los motores L289N, porporcionando metodos
 * para la definicion del sentido y de la velocidad de los mismos
 */
class Motor{
    private:
        //Establece un identificador del sensor
        String idMotor;
        //Pin de conexion a la placa Arduino 1 R3 (velocidad).
        uint8_t pinVelocidad;
        //Pin de conexion a la placa Arduino 1 R3. (sentido 1).
        uint8_t pinSentido1;
        //Pin de conexion a la placa Arduino 1 R3. (sentido 2).
        uint8_t pinSentido2;
        //Modo de conexion de pin con placa Arduino
        const uint8_t MODO_PIN = OUTPUT;

        //Almacena el sentido actual de giro del motor:
        // -- HIGH (Hacia delante)
        // -- LOW (Hacia atras)
        uint16_t sentidoActual;
        //Almacena la velocidad actual a la que se encuentra el motor: (0-100)
        uint16_t velocidadActual;
        //Almacena el estado del motor:
        // -- HIGH (Encendido)
        // -- LOW (Apagado)
        uint16_t encendido;

    public:
        // --- ATRIBUTOS DE CLASE ---
        //Establecer valor para especificar sentido del motor (adelante)
        static const uint16_t ADELANTE = HIGH;
        //Establecer valor para especificar sentido del motor (atras)
        static const uint16_t ATRAS = LOW;

        //Establece el minimo valor de velocidad
        static const uint8_t MIN_RANGE_VELOCIDAD = 0;
        //Establece el maximo valor de velocidad
        static const uint8_t MAX_RANGE_VELOCIDAD = 100;

        //Establece el minimo valor disponible para motor (rpm)
        static const uint8_t MIN_PWM_VALUE = 0;
        //Establece el maximo valor disponible para motor (rpm)
        static const uint8_t MAX_PWM_VALUE = 255;

        //Establecer numero de terminal por defecto (depuracion)
        static const uint16_t SERIAL_NUMBER = 9600;
        //Establecer retardo para lecturas
        static const uint16_t DELAY = 200;

        /**
         * @brief Constructor del driver del motor
         * @param id : Identificador del motor
         * @param nPinVelocidad : Pin de conexion con arduino (velocidad)
         * @param nPinSentido1 : Pin de conexion con arduino (sentido 1)
         * @param nPinSentido2 : Pin de conexion con arduino (sentido 2)
         */
        Motor(String id, uint8_t nPinVelocidad, uint8_t nPinSentido1, uint8_t nPinSentido2);

        /**
         * @brief Enciende el motor
         * @pre Solo actua si el motor no esta encendido
         */
        void encender();

        /**
         * @brief Apaga el motor
         * @pre Solo actua si el motor no esta apagado
         */
        void apagar();

        /**
         * @brief Establece el sentido de giro del motor
         * @param sentido : Indicador de sentido (ADELANTE / ATRAS)
         */
        void setSentido(uint16_t sentido);

        /**
         * @brief Establece la velodidad del motor
         * @param velocidad : Indicador de velocidad del motor
         * @pre velocidad debe valer entre 0 y 100
         */
        void setVelocidad(uint16_t velocidad);

        /**
         * @brief Devuelve la velocidad actual del motor
         * @return velocidadActual
         */
        uint16_t getVelocidadActual();

        /**
         * @brief Devuelve el sentido actual del motor
         * @return sentidoActual
         */
        uint16_t getSentidoActual();

        /**
         * @brief Comprueba si el motor esta encendido o no
         * @return 1 si esta encendido, 0 en caso contrario
         */
        int motorEncendido();

        /**
         * @brief Imprime la informacion del driver del motor
         * Se realizara sobre el terminal especificado
         */
        void printInfo();
};

#include "motor.cpp"

#endif