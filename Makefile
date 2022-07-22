CXXFLAGS=-g -std=c++20
LDLIBS=-lstdc++

objects = binarysearch.o test.o
output = $(basename $(objects))

all: $(output) $(objects)
	
.PHONY: clean
clean:
	-rm $(objects) $(output)
	-rm -rf *.dSYM