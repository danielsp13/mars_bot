/**
 * @file motor.cpp
 * @authors Martin Anaya Quesada, Daniel Perez Ruiz
 * @brief Implementacion de metodos de la clase motor
 * @version 0.1.0
 */

// =================================================================

// IMPLEMENTACION DE CONSTRUCTOR

Motor::Motor(String id, uint8_t nPinVelocidad, uint8_t nPinSentido1, uint8_t nPinSentido2){
    // Asignar id de motor
    idMotor = id;
    // Asignar pin de velocidad
    pinVelocidad = nPinVelocidad;
    // Asignar pin de sentido 1
    pinSentido1 = nPinSentido1;
    // Asignar pin de sentido 2
    pinSentido2 = nPinSentido2;

    // Establecer modo de pines (OUTPUT)
    pinMode(pinVelocidad, MODO_PIN);
    pinMode(pinSentido1, MODO_PIN);
    pinMode(pinSentido2, MODO_PIN);

    // Inicializar el estado del motor (apagado)
    encendido = LOW;
    // Inicializar el sentido del motor (adelante)
    sentidoActual = -1;
    setSentido(ADELANTE);
    // Inicializar velocidad del motor (0 rpm)
    setVelocidad(0);
}


// =================================================================

// IMPLEMENTACION DE METODOS DE CONTROL

void Motor::encender(){
    if(!motorEncendido())
        encendido = HIGH;
}

void Motor::apagar(){
    if(motorEncendido()){
        encendido = LOW;
        setVelocidad(0);
    }
}

void Motor::setSentido(uint16_t sentido){
    // -- Se actualiza solo si es diferente el sentido
    if(sentidoActual != sentido){
        // -- Verificamos que son parametros permitidos
        if(sentido == ADELANTE || sentido == ATRAS){
            // -- Almacenar nuevo sentido
            sentidoActual = sentido;

            // -- Modificar valores de pines de sentido
            digitalWrite(pinSentido1, sentidoActual);
	        digitalWrite(pinSentido2, !sentidoActual);
        }
    }
}

void Motor::setVelocidad(uint16_t velocidad){
    if(MIN_RANGE_VELOCIDAD <= velocidad && velocidad <= MAX_RANGE_VELOCIDAD){
        velocidadActual = map(velocidad, MIN_RANGE_VELOCIDAD, MAX_RANGE_VELOCIDAD, MIN_PWM_VALUE, MAX_PWM_VALUE);
	    analogWrite(pinVelocidad, velocidadActual*encendido);
    }
}

uint16_t Motor::getVelocidadActual(){
    return velocidadActual;
}

uint16_t Motor::getSentidoActual(){
    return sentidoActual;
}

int Motor::motorEncendido(){
    return encendido == HIGH;
}

// =================================================================

// IMPLEMENTACION DE METODOS DE DEPURACION

void Motor::printInfo(){
    String info = "MOTOR >> ";
    info.concat("Id: "); info.concat(idMotor);
    info.concat("; Pin Velocidad: "); info.concat(pinVelocidad);
    info.concat("; Pines Sentidos: "); info.concat(pinSentido1);
    info.concat(" || "); info.concat(pinSentido2);
    info.concat("; Encendido: ");
    if(encendido == HIGH)
        info.concat(" SI.");
    else
        info.concat(" NO.");
    info.concat("; Velocidad: "); info.concat(velocidadActual);
    info.concat("; Sentido: ");
    if(sentidoActual == Motor::ADELANTE)
        info.concat(" ADELANTE.");
    else
        info.concat(" ATRAS.");

    Serial.println(info);
}