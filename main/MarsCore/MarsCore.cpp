/**
 * @file MarsCore.cpp
 * @authors Martin Anaya Quesada, Daniel Perez Ruiz
 * @brief Implementacion de metodos de la clase sensorUltrasonidos
 * @version 0.1.0
 */

// =================================================================

// IMPLEMENTACION DE CONSTRUCTOR

MarsCore::MarsCore(String nombreBot, int slinea, int sultras, int motores, uint16_t tipoEstrategia){
    nombre = nombreBot;
    sensoresLineaDisponibles = slinea;
    sensoresUltrasonidosDisponibles = sultras;
    motoresDisponibles = motores;
    estrategia = tipoEstrategia;
}

// =================================================================

// IMPLEMENTACION DE METODOS PRIVADOS

void MarsCore::iniciarRobot(){
    // -- Se realizara solo si los motores estan disponibles
    if(motoresDisponibles){
        motorIzda.encender();
        motorDcha.encender();
    }
}

void MarsCore::apagarRobot(){
    // -- Se realizara solo si los motores estan disponibles
    if(motoresDisponibles){
        motorIzda.apagar();
        motorDcha.apagar();
    }
    
}

void MarsCore::obtenerDistancias(){
    // -- Mandar orden de ejecutar sensores de ultrasonidos
    distanciaSensorIzda = sUltrasIzda.scan();
    distanciaSensorCentro = sUltrasCentro.scan();
    distanciaSensorDcha = sUltrasDcha.scan();
}

int MarsCore::escanearSuperficie(){
    int resultado = MarsCore::SUPERFICIE_BLANCA;

    if(sLineaIzda.scanBorde() || sLineaDcha.scanBorde())
        resultado = MarsCore::SUPERFICIE_NEGRA;

    return resultado;
}

void MarsCore::moverRobot(uint8_t direccion){
    // -- Se realizara solo si los motores estan disponibles
    if(motoresDisponibles){
        // -- Definicion de variables para resultado final
        uint8_t velocidadMotorIzda = 0;
        uint8_t velocidadMotorDcha = 0;
        uint8_t sentidoMotorIzda = motorIzda.getSentidoActual();
        uint8_t sentidoMotorDcha = motorDcha.getSentidoActual();

        // -- Decidir la direccion y la velocidad del robot
        switch (direccion){
            case MarsCore::DIRECC_ADELANTE:
                sentidoMotorIzda = Motor::ADELANTE;
                sentidoMotorDcha = Motor::ADELANTE;
                velocidadMotorIzda = VELOCIDAD;
                velocidadMotorDcha = VELOCIDAD;
                break;
            
            case MarsCore::DIRECC_ATRAS:
                sentidoMotorIzda = Motor::ATRAS;
                sentidoMotorDcha = Motor::ATRAS;
                velocidadMotorIzda = VELOCIDAD;
                velocidadMotorDcha = VELOCIDAD;

                break;
            
            case MarsCore::DIRECC_DERECHA:
                sentidoMotorIzda = Motor::ADELANTE;
                sentidoMotorDcha = Motor::ADELANTE;
                velocidadMotorIzda = VELOCIDAD;
                velocidadMotorDcha = 0;

                break;

            case MarsCore::DIRECC_IZQUIERDA:
                sentidoMotorIzda = Motor::ADELANTE;
                sentidoMotorDcha = Motor::ADELANTE;
                velocidadMotorIzda = 0;
                velocidadMotorDcha = VELOCIDAD;

                break;
            
            default:
                break;
        }

        // -- Actualizar motores
        motorIzda.setSentido(sentidoMotorIzda);
        motorDcha.setSentido(sentidoMotorDcha);
        motorIzda.setVelocidad(velocidadMotorIzda);
        motorDcha.setVelocidad(velocidadMotorDcha);
    }
}

void MarsCore::estrategiaPorDefecto(){
    switch (estrategia)
    {
    case MarsCore::BOT_CONSERVADOR:
        moverRobot(DIRECC_NONE);
        break;
    case MarsCore::BOT_AGRESIVO:
        moverRobot(DIRECC_ADELANTE);
        break;

    case MarsCore::BOT_BUSCADOR:
        moverRobot(DIRECC_IZQUIERDA);

    default:
        moverRobot(DIRECC_NONE);
    }
}

// =================================================================

// IMPLEMENTACION DE METODOS PUBLICOS

void MarsCore::encender(){
    iniciarRobot();
}

void MarsCore::apagar(){
    apagarRobot();
}

void MarsCore::esperar(){
    delay(DELAY);
}

int MarsCore::sondearEnemigo(){
    int resultado = 0;

    // -- Se realizara solo si los sensores de ultrasonidos estan disponibles
    if(sensoresUltrasonidosDisponibles){
        // -- Primero: Obtener distancias
        obtenerDistancias();

        // -- Segundo: Comprobar si se ha detectado al enemigo en algun sensor
        if(distanciaSensorIzda <= MAX_RANGO_DISTANCIA)
            resultado = 1;
        else if(distanciaSensorCentro <= MAX_RANGO_DISTANCIA)
            resultado = 2;
        else if(distanciaSensorDcha <= MAX_RANGO_DISTANCIA)
            resultado = 3;
    }

    // -- Tercero: Devolver resultado
    return resultado;
}

int MarsCore::detectaBorde(){
    // -- Se realizara solo si los sensores de linea estan disponibles
    if(sensoresLineaDisponibles){
        uint8_t superficie = escanearSuperficie();

        if(superficie == MarsCore::SUPERFICIE_NEGRA)
            return 1;
        if(superficie == MarsCore::SUPERFICIE_BLANCA)
            return 0;
    }

    return 0;
}


void MarsCore::ataca(){
    // -- Primero: Sondear enemigo
    int enemigoDetectado = sondearEnemigo();
    // -- Segundo: Comprobar por donde se encuentra
    switch (enemigoDetectado)
    {
    case 1:
        moverRobot(DIRECC_IZQUIERDA);
        break;
    case 2:
        moverRobot(DIRECC_ADELANTE);
        break;
    case 3:
        moverRobot(DIRECC_DERECHA);
        break;
    
    default:
        estrategiaPorDefecto();
        break;
    }
}

void MarsCore::retrocede(){
    // -- Mueve simplemente al robot hacia atras
    moverRobot(DIRECC_ATRAS);
}

void MarsCore::printInfo(){
    const String SEPARATOR = "=================================================================";

    // -- Imprimir informacion de los sensores de linea
    Serial.println(SEPARATOR);
    Serial.println(nombre);
    Serial.println(SEPARATOR);
    if(sensoresLineaDisponibles){
        Serial.println(">>> SENSORES DE LINEA <<<");
        sLineaIzda.printInfo();
        sLineaDcha.printInfo();
    }
    Serial.println(SEPARATOR);
    if(sensoresUltrasonidosDisponibles){
        Serial.println(">>> SENSORES DE ULTRASONIDOS <<<");
        sUltrasIzda.printInfo();
        sUltrasCentro.printInfo();
        sUltrasDcha.printInfo();
    }
    Serial.println(SEPARATOR);
    if(motoresDisponibles){
        Serial.println(">>> MOTORES <<<");
        motorIzda.printInfo();
        motorDcha.printInfo();
    }
    Serial.println(SEPARATOR);
}