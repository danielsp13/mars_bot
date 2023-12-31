/**
 * @file sensorLinea.h
 * @authors Martin Anaya Quesada, Daniel Perez Ruiz
 * @brief Definicion de la clase SensorLinea
 * @version 0.1.0
 */

#ifndef _SMP_MD_SENSORLINEA_H
#define _SMP_MD_SENSORLINEA_H

/**
 * @brief Esta clase representa el controlador de un dispositivo de deteccion de superficies
 * de linea, utilizado para detectar cambios en la superficie.
 * El sensor emite una señal y detecta la cantidad de luz reflejada desde
 * la superficie, que permitira
 */
class SensorLinea{
    private:
        //Establece un identificador del sensor
        String idSensor;
        //Pin de conexion a la placa Arduino 1 R3.
        uint8_t pin;
        //Modo de conexion de pin con placa Arduino
        const uint8_t MODO_PIN = INPUT;
        //Valor de referencia para superficies negras (HIGH == Blanco; LOW == Negro)
        const uint16_t UMBRAL_NEGRO = 100;
        //Variable para almacenar el ultimo valor leido por el sensor
        uint8_t superficieLeida;

        /**
         * @brief Consulta el sensor, recuperando el valor que muestra
         */
        void obtenerSuperficie();

    public:
        // --- ATRIBUTOS DE CLASE ---

        //Establecer numero de terminal por defecto (depuracion)
        static const uint16_t SERIAL_NUMBER = 9600;
        //Establecer retardo para lecturas
        static const uint16_t DELAY = 200;
        
        /**
         * @brief Constructor del controlador. Recibe como parametro
         * el pin de conexion del dispositivo con la placa Arduino
         * @param idSensor : identificacion del sensor
         * @param nPin : Numero de pin
         */
        SensorLinea(String idSensor, uint8_t nPin);

        /**
         * @brief Comprueba si el lector de linea esta situado sobre el arco
         * negro de la circunferencia del tatami
         * @return 1 si esta sobre la referencia del negro, 0 en otro caso
         */
        int scanBorde();

        /**
         * @brief Imprime la informacion del controlador de sensor de linea
         * Se realizara sobre el terminal especificado
         */
        void printInfo();
};

#include "sensorLinea.cpp"

#endif //_SMP_MD_SENSORLINEA_H
