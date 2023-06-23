## Mars Rover Creator Bot: Cableado de componentes

*En este documento se especifican las diferentes conexiones entre dispositivos del robot, ya sea al protoboard integrado en el chasis, así como la placa de Arduino UNO R3.*

### :electric_plug: Cableado en protoboard

En la siguiente lista, se indica las conexiones al protoboard:

* Conexión a **GND (tierra)**, desde Arduino. (Cable Negro)
* Conexión a **5V (VCC)**, desde Arduino (Cable Rojo)
* Conexiones de alimentación (GND, 5V) de *Sensores de Linea*: 2.
* Conexiones de alimentación (GND, 5V) de *Sensores de Ultrasonidos*: 3.

****

### :electric_plug: Cableado en Arduino 1 R3: Pines utilizados

En la siguiente lista, se especifican todos los pines ocupados de la placa Arduino, y su conexión:

**CONEXIONES EN PINES DIGITALES:**

- Sensores de linea: 2
  - Sensor Izquierdo: 8
  - Sensor Derecho: 9
- Sensores de Ultrasonidos: 3
  - Sensor Izquierdo: 2 (Trigger), 3 (Echo)
  - Sensor Central: 4 (Trigger), 5 (Echo)
  - Sensor Derecho : 6 (Trigger), 7 (Echo)

**CONEXIONES EN PINES ANALÓGICOS:**

- *Ninguna*.