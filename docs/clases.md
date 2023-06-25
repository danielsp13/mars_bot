## Mars Rover Creator Bot: Clases

*En este documento se especifican brevemente las clases manejadoras de los diferentes componentes del robot. Si se desea consultar de forma más detallada el funcionamiento interno, consultar documentación del código.*



#### :package: Controlador de Sensor de Linea `SensorLinea`:

Este controlador permite utilizar el Sensor de Linea de tal modo que se permite comprobar si la superficie en la que se encuentra el robot es:

* **Blanca** : En ese caso, se encuentra dentro del tatami.
* **Negra** : En ese caso, se encuentra en el borde del tatami.

#### :package: Controlador de Sensor de Ultrasonidos `SensorUltrasonidos`:

Este controlador permite utilizar el Sensor de Ultrasonidos de tal modo que permite comprobar a qué distancia se encuentra el contrincante.

#### :package: Controlador de Motor `Motor`:

Este controlador permite comunicarse con el driver de motores L289N para el manejo de uno de los motores, pudiendo definir:

* **Sentido del motor :** Si va hacia delante, o hacia atrás.
* **Velocidad del motor: **Rpm a la que girará el motor.

#### :package: Controlador conjunto del bot `MarsCore`:

Esta clase permite definir de manera abstracta el núcleo del robot. Contiene todos los controladores para todos los dispositivos básicos del robot, que son lo anteriormente mencionados.