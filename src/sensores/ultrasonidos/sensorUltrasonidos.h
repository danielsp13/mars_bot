/**
 * @file sensorUltrasonidos.h
 * @authors Martin Anaya Quesada, Daniel Perez Ruiz
 * @brief Definicion de la clase sensorUltrasonidos
 * @version 0.1.0
 */

#ifndef _SMP_MD_SENSORULTRASONIDOS_H
#define _SMP_MD_SENSORULTRASONIDOS_H

/**
 * @brief Esta clase permite interactuar con un sensor de ultrasonidos para medir la distancia entre el sensor y un 
 * objeto cercano. El sensor de ultrasonidos utiliza ondas sonoras de alta frecuencia para determinar la distancia 
 * basándose en el tiempo que tarda en recibir el eco de la señal reflejada por el objeto.
 */
class SensorUltrasonidos{
    private:
        //Establece un identificador del sensor
        String idSensor;
        //Pin de conexion del trigger a la placa Arduino 1 R3.
        uint8_t pinTrigger;
        //Pin de conexion del echo a la placa Arduino 1 R3
        uint8_t pinEcho;
        //Modo de conexion de pines con placa Arduino
        const uint8_t MODO_PIN_TRIGGER = OUTPUT;
        const uint8_t MODO_PIN_ECHO = INPUT;
        //Constante necesaria para el calculo de la distancia (ver documentacion)
        const uint8_t VELOCIDAD_CM_US = 59;
        //Ultimo valor leido por el sensor (distancia)
        long ultimoValorLeido;

    public:
        //Establecer numero de terminal por defecto (depuracion)
        static const uint16_t SERIAL_NUMBER = 9600;
        //Establecer retardo para lecturas (us)
        static const uint16_t DELAY = 10;

        /**
         * @brief Constructor del controlador. Recibe el pin de conexion
         * a la placa de Arduino como argumento
         * @param id : identificador del sensor
         * @param nPinTrigger : pin de conexion con Arduino (trigger)
         * @param nPinEcho : pin de conexion con Arduino (echo)
         */
        SensorUltrasonidos(String id, uint8_t nPinTrigger, uint8_t nPinEcho);

        /**
         * @brief Consulta el sensor, recuperando el valor que muestra
         */
        void leerValor();
        
        /**
         * @brief Imprime la informacion del controlador de sensor de linea
         * Se realizara sobre el terminal especificado
         */
        void printInfo();

};

#include "sensorUltrasonidos.cpp"

#endif //_SMP_MD_SENSORULTRASONIDOS_H