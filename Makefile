# ===================================================================================
#   SISTEMAS CON MICROPROCESADORES : UNIVERSIDAD DE GRANADA
# ===================================================================================
#   Autores:
#     - Martin Anaya Quesada
#     - Daniel Perez Ruiz
# ===================================================================================
# Makefile para construccion de proyecto de Mars Rover Mini-Creator Bot
# ===================================================================================
#    MANUAL DE OPCIONES DISPONIBLES PARA EL MAKEFILE
#  - all: Construye el proyecto final, y los examples de testeo
#  - mars: Construye el proyecto final
#  - examples: Construye los proyectos de testeo de dispositivos
#  - detectTTY: Permite configurar el puerto de la placa para el volcado de codigo
#  - clean: Elimina los proyectos Arduino construidos
# ===================================================================================

# ============================= VARIABLES

# -- Prefijos
A = @ #Eliminar @ para ver órdenes de makefile explicitamente
EXAMPLE_PREFIJ = example
SLINEA_PREFIJ = SensorLinea
SULTRAS_PREFIJ = SensorUltrasonidos
MOTOR_PREFIJ = Motor
MARSBOT_PREFIJ = mars_bot

# -- Extensiones
INO_EXT = .ino
HEADER_EXT = .h
SOURCE_EXT = .cpp

# -- Directorios
EXAMPLES_DIR = $(EXAMPLE_PREFIJ)s
SRC_DIR = src
SENSORES_DIR = sensores
SLINEA_DIR = linea
SULTRAS_DIR = ultrasonidos
MOTOR_DIR = motor
MARSBOT_DIR = $(MARSBOT_PREFIJ)
MAIN_DIR = main
CORE_DIR = MarsCore
BUILD_DIR = arduino_projects

EXAMPLE_SLINEA_DIR = $(EXAMPLE_PREFIJ)$(SLINEA_PREFIJ)
EXAMPLE_SULTRAS_DIR = $(EXAMPLE_PREFIJ)$(SULTRAS_PREFIJ)
EXAMPLE_MOTOR_DIR = $(EXAMPLE_PREFIJ)$(MOTOR_PREFIJ)

BUILD_EXAMPLES_DIR = $(BUILD_DIR)/$(EXAMPLES_DIR)
BUILD_MARSBOT_DIR = $(BUILD_DIR)/$(MARSBOT_DIR)

# -- Ficheros de example
EXAMPLE_SLINEA = $(EXAMPLE_PREFIJ)$(SLINEA_PREFIJ)$(INO_EXT)
EXAMPLE_SULTRAS = $(EXAMPLE_PREFIJ)$(SULTRAS_PREFIJ)$(INO_EXT)
EXAMPLE_MOTOR = $(EXAMPLE_PREFIJ)$(MOTOR_PREFIJ)$(INO_EXT)

# -- Fichero final
MARSBOT = $(MARSBOT_PREFIJ)$(INO_EXT)

# -- Fichero de cabeceras
HEADER_LIB = headerLibs$(HEADER_EXT)

# -- Puerto de carga
TTY = /dev/ttyACM0
# -- Permisos
TTY_PERM = a+rw

# ============================= ORDENES

all: mars examples

# ============================= ORDENES PRIVADAS (NO USAR!!!!!)

createBuild:
	$(A)mkdir -p $(BUILD_DIR)

buildProject:
	$(A)echo "Construyendo proyecto de sketch: $(SKETCH) en [$(BUILD_TYPE_DIR)/$(TYPE_TARGET)]"
	$(A)mkdir -p $(BUILD_TYPE_DIR)/$(TYPE_TARGET)/$(DEP_DIR)
	$(A)cp -r $(SOURCE_SKETCH_DIR)/$(TYPE_TARGET) ./$(BUILD_TYPE_DIR)
	$(A)cp -r $(SOURCE_DIR) ./$(BUILD_TYPE_DIR)/$(TYPE_TARGET)/$(DEP_DIR)
	$(A)echo "Objetivo construido correctamente!"
	$(A)echo
	
cleanProject:
	- $(A)echo "Eliminado build de $(SKETCH)"
	- $(A)rm -r ./$(BUILD_TYPE_DIR)/$(TYPE_TARGET)/* 2> /dev/null
	- $(A)rmdir ./$(BUILD_TYPE_DIR)/$(TYPE_TARGET) 2> /dev/null
	- $(A)echo "Build de $(SKETCH) eliminado correctamente!"
	- $(A)echo

# ============================= ORDENES ACCESIBLES

mars:
	$(A)echo "Construyendo build de $(MARSBOT) en [$(BUILD_MARSBOT_DIR)/]"
	$(A)mkdir -p $(BUILD_MARSBOT_DIR)/
	$(A)cp -r $(MAIN_DIR)/* $(BUILD_MARSBOT_DIR)/
	$(A)cp -r $(SRC_DIR)/* $(BUILD_MARSBOT_DIR)/$(CORE_DIR)
	$(A)echo "Objetivo construido correctamente!"
	$(A)echo

examples: createBuild exampleSensorLinea exampleSensorUltrasonidos exampleMotor

detectTTY:
	$(A)echo "Detectando puerto TTY de placa Arduino..."
	$(A)ls $(TTY)
	$(A)echo "Se necesitan permisos elevados para permitir acceso al puerto:"
	$(A)sudo chmod $(TTY_PERM) $(TTY)
	$(A)echo "Puerto de placa configurado correctamente!"
	$(A)echo

exampleSensorLinea:
	$(A)make buildProject SKETCH=$(EXAMPLE_SLINEA) BUILD_TYPE_DIR=$(BUILD_EXAMPLES_DIR) TYPE_TARGET=$(EXAMPLE_SLINEA_DIR) DEP_DIR=$(SENSORES_DIR) SOURCE_SKETCH_DIR=$(EXAMPLES_DIR) SOURCE_DIR=$(SRC_DIR)/$(SENSORES_DIR)/$(SLINEA_DIR)/
	
exampleSensorUltrasonidos:
	$(A)make buildProject SKETCH=$(EXAMPLE_SULTRAS) BUILD_TYPE_DIR=$(BUILD_EXAMPLES_DIR) TYPE_TARGET=$(EXAMPLE_SULTRAS_DIR) DEP_DIR=$(SENSORES_DIR) SOURCE_SKETCH_DIR=$(EXAMPLES_DIR) SOURCE_DIR=$(SRC_DIR)/$(SENSORES_DIR)/$(SULTRAS_DIR)/
	
exampleMotor:
	$(A)make buildProject SKETCH=$(EXAMPLE_MOTOR) BUILD_TYPE_DIR=$(BUILD_EXAMPLES_DIR) TYPE_TARGET=$(EXAMPLE_MOTOR_DIR) SOURCE_SKETCH_DIR=$(EXAMPLES_DIR) SOURCE_DIR=$(SRC_DIR)/$(MOTOR_DIR)/

cleanExampleSensorLinea:
	$(A)make cleanProject SKETCH=$(EXAMPLE_SLINEA) BUILD_TYPE_DIR=$(BUILD_EXAMPLES_DIR) TYPE_TARGET=$(EXAMPLE_SLINEA_DIR)
	
cleanExampleSensorUltraSonidos:
	$(A)make cleanProject SKETCH=$(EXAMPLE_SULTRAS) BUILD_TYPE_DIR=$(BUILD_EXAMPLES_DIR) TYPE_TARGET=$(EXAMPLE_SULTRAS_DIR)
	
cleanExampleMotor:
	$(A)make cleanProject SKETCH=$(EXAMPLE_MOTOR) BUILD_TYPE_DIR=$(BUILD_EXAMPLES_DIR) TYPE_TARGET=$(EXAMPLE_MOTOR_DIR)
	
cleanMars:
	- $(A)echo "Eliminado build de $(MARSBOT)"
	- $(A)rm -r $(BUILD_MARSBOT_DIR) 2> /dev/null
	- $(A)echo "Build de $(MARSBOT) eliminado correctamente!"
	
clean: cleanExampleSensorLinea cleanExampleSensorUltraSonidos cleanExampleMotor cleanMars
	- $(A)rmdir $(BUILD_DIR)/$(EXAMPLES_DIR) 2> /dev/null
	- $(A)rmdir $(BUILD_DIR)/$(MARSBOT_DIR) 2> /dev/null
	- $(A)rmdir $(BUILD_DIR) 2> /dev/null


