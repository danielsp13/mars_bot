/**
 * @file MarsCore.h
 * @authors Martin Anaya Quesada, Daniel Perez Ruiz
 * @brief Definicion de la clase MarsCore
 * @version 0.1.0
 */

#ifndef _SMP_MD_MARSCORE_H
#define _SMP_MD_MARSCORE_H

#include "headerLibs.h"

/**
 * @brief Esta clase representa el controlador de todo el robot. Dispone de todos los drivers de los
 * diferentes dispositivos que lo conforman, y proporciona una capa centralizada y unica para todo el
 * manejo necesario para el combate
 */
class MarsCore{
    private:
        // ----- DEFINICION DE PINES DE DISPOSITIVOS
        // : Pines de sensores de linea
        const uint8_t PIN_SENSORLINEA_IZDA = A5;
        const uint8_t PIN_SENSORLINEA_DCHA = A4;
        // : Pines de sensores de ultrasonidos
        const uint8_t PIN_SENSORULTRA_IZDA_TRIGGER = 2;
        const uint8_t PIN_SENSORULTRA_IZDA_ECHO = 3;

        const uint8_t PIN_SENSORULTRA_CENTRO_TRIGGER = 4;
        const uint8_t PIN_SENSORULTRA_CENTRO_ECHO = 5;

        const uint8_t PIN_SENSORULTRA_DCHA_TRIGGER = 6;
        const uint8_t PIN_SENSORULTRA_DCHA_ECHO = 7;

        // : Pines de motor
        const uint8_t PIN_MOTOR_IZDA_VEL = A1;
        const uint8_t PIN_MOTOR_IZDA_SENTIDO_1 = 10;
        const uint8_t PIN_MOTOR_IZDA_SENTIDO_2 = 11;

        const uint8_t PIN_MOTOR_DCHA_VEL = A0;
        const uint8_t PIN_MOTOR_DCHA_SENTIDO_1 = 12;
        const uint8_t PIN_MOTOR_DCHA_SENTIDO_2 = 13;

        // ----- DEFINICION DE DIRECCIONES
        static const uint8_t DIRECC_NONE = 20;
        static const uint8_t DIRECC_IZQUIERDA = 21;
        static const uint8_t DIRECC_ADELANTE = 22;
        static const uint8_t DIRECC_ATRAS = 23;
        static const uint8_t DIRECC_DERECHA = 24;

        // ----- DEFINICION DE SUPERFICIES
        static const uint8_t SUPERFICIE_BLANCA = 30;
        static const uint8_t SUPERFICIE_NEGRA = 31;

        // ---- DEFINICION DE DISPOSITIVOS
        // : Sensores de linea
        const SensorLinea sLineaIzda = SensorLinea("SLINEA_IZDA",PIN_SENSORLINEA_IZDA);
        const SensorLinea sLineaDcha = SensorLinea("SLINEA_DCHA",PIN_SENSORLINEA_DCHA);
        // : Sensores de ultrasonidos
        const SensorUltrasonidos sUltrasIzda = SensorUltrasonidos("SULTRAS_IZDA",PIN_SENSORULTRA_IZDA_TRIGGER,PIN_SENSORULTRA_IZDA_ECHO);
        const SensorUltrasonidos sUltrasCentro = SensorUltrasonidos("SULTRAS_CENTRO",PIN_SENSORULTRA_CENTRO_TRIGGER,PIN_SENSORULTRA_CENTRO_ECHO);
        const SensorUltrasonidos sUltrasDcha = SensorUltrasonidos("SULTRAS_DCHA",PIN_SENSORULTRA_DCHA_TRIGGER,PIN_SENSORULTRA_DCHA_ECHO);
        // : Motores
        const Motor motorIzda = Motor("MOTOR_IZDA", PIN_MOTOR_IZDA_VEL, PIN_MOTOR_IZDA_SENTIDO_1, PIN_MOTOR_IZDA_SENTIDO_2);
        const Motor motorDcha = Motor("MOTOR_DCHA", PIN_MOTOR_DCHA_VEL, PIN_MOTOR_DCHA_SENTIDO_1, PIN_MOTOR_DCHA_SENTIDO_2);

        // ---- DEFINICION DE CONSTANTES PRIVADAS
        // Define el maximo rango de distancia a la que buscar el enemigo
        const long MAX_RANGO_DISTANCIA = 40;
        // Define la velocidad que tendra el robot en su funcionamiento
        const long VELOCIDAD = Motor::MAX_RANGE_VELOCIDAD;

        // ---- DEFINICION DE ATRIBUTOS PRIVADOS
        // Especifica el nombre del bot
        String nombre;
        // Especifica si los sensores de linea estan disponibles para el bot
        int sensoresLineaDisponibles;
        // Especifica si los sensores de ultrasonidos estan disponibles para el bot
        int sensoresUltrasonidosDisponibles;
        // Especifica si los motores estan disponibles para el bot
        int motoresDisponibles;
        // Especifica la estrategia a seguir por el bot por defecto
        uint16_t estrategia;

        // Almacena la distancia medida por el sensor de ultrasonidos izquierdo
        long distanciaSensorIzda;
        // Almacena la distancia medida por el sensor de ultrasonidos central
        long distanciaSensorCentro;
        // Almacena la distancia medida por el sensor de ultrasonidos derecho
        long distanciaSensorDcha;
        

        // ---- DEFINICION DE METODOS PRIVADOS

        /**
         * @brief Especifica si los dispositivos estan disponibles para el robot
         * @param slinea : Indica si los sensores de linea estaran activos
         * @param sultras : Indica si los sensores de ultasonidos estaran activos
         * @param motores : Indica si los motores estaran activos
         */
        void activarDispositivos(int slinea, int sultras, int motores);

        /**
         * @brief Enciende el robot. Prepara los motores para su funcionamiento.
         */
        void iniciarRobot();

        /**
         * @brief Apaga el robot. Deshabilita los motores
         */
        void apagarRobot();

        /**
         * @brief Consulta los sensores 
         */
        void obtenerDistancias();

        /**
         * @brief Sondea al enemigo en su busqueda
         * @return 0 si no se ha encontrado, 1 si sensor izda, 2 si sensor central, 3 si sensor dcha
         */
        int sondearEnemigo();

        /**
         * @brief Escanea la superficie del tatami. Comprueba si se encuentra en superficie blanca o negra
         * @return SUPERFICIE_BLANCA o SUPERFICIE_NEGRA
         */
        int escanearSuperficie();

        /**
         * @brief Mueve el robot en la direccion indicada
         */
        void moverRobot(uint8_t direccion);

        /**
         * @brief Determina el comportamiento por defecto del robot en la fase de ataque.
         * Indica como se ha de mover
         */
        void estrategiaPorDefecto();

    public:
        // ---- DEFINICION DE ATRIBUTOS DE CLASE
        //Establecer retardo
        static const uint16_t DELAY = 3000;

        //Establecer numero de terminal por defecto (depuracion)
        static const uint16_t SERIAL_NUMBER = 9600;

        // ---- DEFINICION DE ESTRATEGIAS
        // Estrategia1 : Por defecto, el bot esperara hasta tener en la mira a algun enemigo 
        static const uint16_t BOT_CONSERVADOR = 4000;
        static const uint16_t BOT_AGRESIVO = 4001;
        static const uint16_t BOT_BUSCADOR = 4002;

        // ---- DEFINICION DE METODOS

        /**
         * @brief Constructor del controlador
         * @param nombreBot : nombre del bot
         * @param slinea : Indica si los sensores de linea estaran disponibles
         * @param sultras : Indica si los sensores de ultrasonidos estaran disponibles
         * @param motores : Indica si los motores estaran disponibles
         * @param tipoEstrategia : Indica la estrategia a seguir por el bot
         */
        MarsCore(String nombreBot, int slinea, int sultras, int motores, uint16_t tipoEstrategia);

        /**
         * @brief Enciende el robot.
         */
        void encender();

        /**
         * @brief Apaga el robot
         */
        void apagar();

        /**
         * @brief Espera para realizar un movimiento
         */
        void esperar();

        /**
         * @brief Comprueba si el bot se encuentra justo al borde
         * @return 1 si es asi, 0 en caso contrario
         */
        int detectaBorde();

        /**
         * @brief Ataca al enemigo. Primero sondea en su busqueda y a continuacion activa los
         * motores para ir al ataque.
         */
        void ataca();

        /**
         * @brief Hace retroceder al robot. Cambia el sentido de los motores y va en busqueda
         * del robot
         */
        void retrocede();

        /**
         * @brief Imprime la informacion del controlador de sensor de linea
         * Se realizara sobre el terminal especificado
         */
        void printInfo();
};

#include "MarsCore.cpp"

#endif //_SMP_MD_MARSCORE_H
