## Mars Rover Creator Bot : Sumo warrior

### :bust_in_silhouette: Autores:

* :star2: Martín Anaya Quesada
* :star2: Daniel Pérez Ruiz

****

### :dart: Descripción:

En este repositorio, se dispone el código para el robot **[Mars Rover Creator Bot](https://www.kickstarter.com/projects/1760629603/mars-rover-creator-bot?lang=es)**, donde el objetivo principal será convertirlo en un guerrero de sumo, de acuerdo a una serie de normas.

****

### :white_check_mark: Requisitos previos:

Este proyecto se ha desarrollado utilizando **[Arduino IDE](https://support.arduino.cc/hc/en-us/articles/360019833020-Download-and-install-Arduino-IDE)**. Por lo que se requiere su instalación en el sistema operativo para poder ejecutar y enviar el código a la placa.

****

### :books: Documentación:

La documentación del proyecto puede encontrarse en los siguientes ficheros:

* :package: **[Estructura del proyecto](docs/estructura_proyecto.md)**: Se especifica el esquema de directorios y ficheros del proyecto.
* :computer: **[Clases](docs/clases.md)**: Se especifican las clases desarrolladas para el control de los dispositivos del robot.
* :page_facing_up: **[Inventario](docs/inventario.md)**: Se especifica el listado de componentes esenciales para el funcionamiento del robot.
* :bookmark: **[Referencias](docs/referencias.md)**: Se especifican las referencias consultadas para el desarrollo del código del robot.
* :heavy_plus_sign: **[Cálculos](docs/calculos.md)**: Se especifican algunos cálculos utilizados para los métodos de controladores.

****

### :shell: Órdenes de construcción y configuración de proyectos:

Para poder cargar adecuadamente el proyecto final al robot de combate, hay que hacer los siguientes pasos:

1. Conectar la placa Arduino UNO vía USB al ordenador.

2. Habilitar permisos de control del puerto de conexión, esto se puede hacer utilizando la orden (requiere sudo):

   ~~~bash
   $ make detectTTY
   ~~~

3. Construir proyecto Arduino IDE para su volcado. Esto se puede hacer con la siguiente orden, que creará el proyecto de arduino en `arduino_projects/mars_bot`:

   ~~~bash
   $ make mars
   ~~~

4. Abrir Arduino IDE, y abrir el sketch del proyecto final  `mars_bot.ino`.

5. Enviar a la placa.

6. Si se quieren obtener además los proyectos referentes a los tests, simplemente ejecutar:

   ~~~bash
   $ make
   ~~~

7. Si se quieren obtener sólo los proyectos referentes a los tests, simplemente ejecutar:

   ~~~bash
   $ make examples
   ~~~

****

