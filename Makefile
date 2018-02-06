##
##
##
ARCH = lib/libmysqlppc.a
EXES=bin/demo
SRC=$(wildcard src/*.cpp)
OBJ=$(patsubst %.cpp,%.o,$(SRC) )
RM :=rm -f 

CXXFLAGS = -g -Wall -std=c++0x -fPIC 
CPPFLAGS = -I./include -I./include/mysql
LIBS = ./lib/libmysqlclient.a 

all: $(OBJ) $(ARCH) $(EXES)

show:
	@echo "ARCH=$(ARCH)"
	@echo "SRC=$(SRC)"
	@echo "OBJ=$(OBJ)"

$(ARCH): $(OBJ)
	ar cru  $@ $^
	ranlib $(ARCH)

$(EXES): test/demo.cpp
	g++ $(CPPFLAGS) -lpthread -ldl -I./src -o $@ $^ $(ARCH) $(LIBS)

clean:
	$(RM) $(ARCH) src/*.o


