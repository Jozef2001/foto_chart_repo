CXX = g++
C = gcc
CXXFLAGS = -Wall -std=c++17 -Wno-unknown-pragmas
CFLAGS = -Wall
NAME = wykres_soft
LIB_MAIN = wykres.so `pkg-config gtkmm-3.0 --cflags --libs`
PYTHON_INCLUDE = /usr/include/python2.7/ #sciezka do folderu python2.7
PYTHON_LIB = /usr/lib/x86_64-linux-gnu #sciezka do libpython2.7.so

SOURCES_wykres = $(wildcard wykres.cpp)
LIB_wykres = -I$(PYTHON_INCLUDE) -L$(PYTHON_LIB) -lpython2.7 `pkg-config gtkmm-3.0 --cflags --libs`

all:
	$(CXX) $(CXXFLAGS) -o wykres.so -shared -fpic $(SOURCES_wykres) $(LIB_wykres)
	$(CXX) $(CXXFLAGS) -o $(NAME) main.cpp $(LIB_MAIN) $(LIB_wykres)
	LD_LIBRARY_PATH=$(PYTHON_LIB):. ./$(NAME)

clean:
	rm -f *.so $(NAME)
