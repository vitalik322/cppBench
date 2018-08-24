SOURCES := $(shell find $(SOURCEDIR) -name '*.cpp' -o -name '*.h')

all: ${SOURCES}
	g++ -std=c++11 -O0 ${SOURCES} -o measurer
