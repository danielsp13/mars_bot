# ===================================================================================
#   SISTEMAS CON MICROPROCESADORES : UNIVERSIDAD DE GRANADA
# ===================================================================================
#   Autores:
#     - Martin Anaya Quesada
#     - Daniel Perez Ruiz
# ===================================================================================
# Makefile para construccion de codigo de Mars Rover Mini-Creator Bot
# ===================================================================================

# ============================= VARIABLES

# -- Prefijos
A = @ #Eliminar @ para ver órdenes de makefile explicitamente
EXAMPLE_PREFIJ = example
SLINEA_PREFIJ = SensorLinea
SULTRAS_PREFIJ = SensorUltrasonidos

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

EXAMPLE_SLINEA_DIR = $(EXAMPLE_PREFIJ)$(SLINEA_PREFIJ)
EXAMPLE_SULTRAS_DIR = $(EXAMPLE_PREFIJ)$(SULTRAS_PREFIJ)

# -- Ficheros de example
EXAMPLE_SLINEA = $(EXAMPLE_PREFIJ)$(SLINEA_PREFIJ)$(INO_EXT)
EXAMPLE_SULTRAS = $(EXAMPLE_PREFIJ)$(SULTRAS_PREFIJ)$(INO_EXT)

# -- Fichero de cabeceras
HEADER_LIB = headerLibs$(HEADER_EXT)

# -- Puerto de carga
TTY = /dev/ttyACM0
# -- Permisos
TTY_PERM = a+rw

# ============================= ORDENES

all: examples

examples: exampleSensorLinea exampleSensorUltrasonidos

detectTTY:
	$(A)echo "Detectando puerto TTY de placa Arduino..."
	$(A)ls $(TTY)
	$(A)echo "Se necesitan permisos elevados para permitir acceso al puerto:"
	$(A)sudo chmod $(TTY_PERM) $(TTY)
	$(A)echo "Puerto de placa configurado correctamente!
	$(A)echo

exampleSensorLinea:
	$(A)echo "Construyendo objetivo: $(EXAMPLE_SLINEA)"
	$(A)cp -r $(EXAMPLES_DIR)/$(EXAMPLE_SLINEA_DIR)/ .
	$(A)mkdir -p $(EXAMPLE_SLINEA_DIR)/$(SENSORES_DIR)/
	$(A)cp -r $(SRC_DIR)/$(SENSORES_DIR)/$(SLINEA_DIR)/ ./$(EXAMPLE_SLINEA_DIR)/$(SENSORES_DIR)/
	$(A)echo "Objetivo construido correctamente!"
	$(A)echo
	
exampleSensorUltrasonidos:
	$(A)echo "Construyendo objetivo $(EXAMPLE_SULTRAS)"
	$(A)cp -r $(EXAMPLES_DIR)/$(EXAMPLE_SULTRAS_DIR)/ .
	$(A)mkdir -p $(EXAMPLE_SULTRAS_DIR)/$(SENSORES_DIR)/
	$(A)cp -r $(SRC_DIR)/$(SENSORES_DIR)/$(SULTRAS_DIR)/ ./$(EXAMPLE_SULTRAS_DIR)/$(SENSORES_DIR)/
	$(A)echo "Objetivo construido correctamente!"
	$(A)echo

cleanExampleSensorLinea:
	$(A)echo "Eliminado build de $(EXAMPLE_SLINEA)"
	$(A)rm -r ./$(EXAMPLE_SLINEA_DIR)/* 2> /dev/null
	$(A)rmdir ./$(EXAMPLE_SLINEA_DIR) 2> /dev/null
	$(A)echo "Build de $(EXAMPLE_SLINEA) eliminado correctamente!"
	$(A)echo
	
cleanExampleSensorUltraSonidos:
	$(A)echo "Eliminando build de $(EXAMPLE_SULTRAS)"
	$(A)rm -r ./$(EXAMPLE_SULTRAS_DIR)/* 2> /dev/null
	$(A)rmdir ./$(EXAMPLE_SULTRAS_DIR) 2> /dev/null
	$(A)echo "Build de $(EXAMPLE_SLINEA) eliminado correctamente!"
	$(A)echo
	
clean: cleanExampleSensorLinea cleanExampleSensorUltraSonidos



