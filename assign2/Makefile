cc=g++
ccFLAGS=-Wall

assign2: assign2.o Functions.o

	$(cc) $(ccFLAGS) -o assign2 assign2.o Functions.o

Functions.o: Functions.cc Functions.h
 
	$(cc) $(ccFLAGS) -c Functions.cc

assign2.o: assign2.cc Functions.h

	$(cc) $(ccFLAGS) -c assign2.cc

clean:

	rm *.o assign2
