## Mars Rover Creator Bot: Estructura del proyecto

*En este documento se especifica la estructura de directorios del proyecto para el robot de combate.*

#### :package: Estructura

El esquema es el siguiente:

~~~bash
mars_bot
├── docs
│   ├── cableado.md
│   ├── calculos.md
│   ├── clases.md
│   ├── estructura_proyecto.md
│   ├── inventario.md
│   └── referencias.md
├── examples
│   ├── exampleMotor
│   │   └── exampleMotor.ino
│   ├── exampleSensorLinea
│   │   └── exampleSensorLinea.ino
│   └── exampleSensorUltrasonidos
│       └── exampleSensorUltrasonidos.ino
├── LICENSE
├── main
│   ├── mars_bot.ino
│   └── MarsCore
│       ├── MarsCore.cpp
│       └── MarsCore.h
├── Makefile
├── README.md
└── src
    ├── headerLibs.h
    ├── motor
    │   ├── motor.cpp
    │   └── motor.h
    └── sensores
        ├── linea
        │   ├── sensorLinea.cpp
        │   └── sensorLinea.h
        └── ultrasonidos
            ├── sensorUltrasonidos.cpp
            └── sensorUltrasonidos.h
~~~

### :open_file_folder: Directorios:

La lista de directorios más importantes son:

* `docs`: Directorio de documentación del proyecto, así como documentación del código.
* `examples`: Directorio de sketchs de Arduino para pruebas.
* `main`: Directorio del sketch final del proyecto.
* `src`: Contiene las cabeceras y los fuentes del proyecto.