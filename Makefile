CXXFLAGS=-g -std=c++20
LDLIBS=-lstdc++

objects = binarysearch.o test.o selectionsort.o factorial_recurse.o \
          sum_recurse.o count_recurse.o max_recurse.o quicksort.o \
		  breadthfirstsearch.o dijkstras.o setcovering.o longestsubseq_dp.o \
		  longestsubstr_dp.o

output = $(basename $(objects))

all: $(output) $(objects)

.PHONY: clean
clean:
	-rm $(objects) $(output)
	-rm -rf *.dSYM