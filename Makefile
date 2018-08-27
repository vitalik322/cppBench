SOURCES := $(shell find $(SOURCEDIR) -name '*.cpp' -o -name '*.h')

all: ${SOURCES}
	g++ -std=c++11 -O0 ${SOURCES} -o measurer

dbg: ${SOURCES}
	g++ -std=c++11 -g -O0 ${SOURCES} -o measurer

profile: ${SOURCES}
	g++ -std=c++11 -pg -O0 ${SOURCES} -o measurer
	./measurer
	 gprof measurer gmon.out > analysis.txt

o3: ${SOURCES}
	g++ -std=c++11 -O3 ${SOURCES} -o measurer
