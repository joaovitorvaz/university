# Em caso de erros de execução do Makefile, se atente ao seguinte:
# ao compilar em Linux, está sendo utilizado o javac e em Windows, o javac.exe

ifeq ($(OS),Windows_NT)
# Execução Windows
COMPILER = javac.exe -Xlint
BINARIES = $(EXEC_PROG)

SOURCES := $(shell find -name '*.java')

OBJECTS = $(SOURCES:.java=.class)

%.class: %.java
	$(COMPILER) -d . -classpath . $<

all: $(OBJECTS)
	@echo Build Completed

broker:
	java.exe appl.Broker

client:
	java.exe appl.OneAppl

.PHONY: clean
clean:
	find . -type f -name '*.class' -delete

else
# Execução Linux
COMPILER = javac -Xlint
BINARIES = $(EXEC_PROG)

SOURCES := $(shell find -name '*.java')

OBJECTS = $(SOURCES:.java=.class)

%.class: %.java
	$(COMPILER) -d . -classpath . $<

all: $(OBJECTS)
	@echo Build Completed

broker:
	java appl.Broker

client:
	java appl.OneAppl

.PHONY : clean
clean:
	find . -type f -name '*.class' -delete
endif