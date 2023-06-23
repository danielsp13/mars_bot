## Mars Rover Creator Bot: Cálculos de parámetros

*En este documento se especifican algunos cálculos necesarios para el funcionamiento de algunas partes de los controladores de dispositivos del robot.*

#### :heavy_plus_sign: Controlador de Sensores de Ultrasonido

El funcionamiento del sensor de ultrasonido se basa en el cálculo del tiempo que dura en llegar el eco del ultrasonido. tras rebotar en un objeto. Sin embargo, la información que realmente necesitamos es la distancia a dicho objeto. Para ello hay que tener en cuenta:

* Velocidad = Distancia / tiempo
* Velocidad del sonido: 340 m/s = 17/500 cm/us = 0.034 cm/us.

Teniendo en cuenta esto, lo que hacemos es despejar de la fórmula anterior, la distancia:

* *Distancia (cm) = Velocidad (cm/us) · tiempo (us)*

Y además contando el camino de ida y vuelta:

* **Distancia (cm) = Velocidad (cm/us) · tiempo (us) / 2**

Entonces: 0.034 / 2 = 0.017 cm/us = 17 / 1000 cm / us. Y tomando el inverso de este valor: 1000 / 17 = 58.823... = 59 us/cm

Y por tanto, considerar la fórmula final:

*  **DISTANCIA (cm) = TIEMPO (us) / 59 (us/cm)**

Es mejor considerarlo de esta forma para tener un factor de tipo entero, mucho más fácil de manejar que un flotante.