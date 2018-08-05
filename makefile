# Started 12/02/17
# Finalized + Published 08/05/18
# Eric Graves

# Makefile for syl_test.cpp (includes syllable.cpp)

output: syl_test.o syllable.o
	g++ -std=c++0x -Wall syl_test.o syllable.o -o out

syl_test.o: syl_test.cpp
	g++ -c syl_test.cpp

syllable.o: syllable.cpp syllable.h
	g++ -c syllable.cpp

clean:
	rm *.o out

# Remaking shortcut
re:
	rm *.o out
	make
