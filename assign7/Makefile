#declaring and initaialsing the variables
cc=g++
ccFlags=-Wall
#defining the target for executable assign7
assign7:assign7.o Pieces.o
	$(cc) -o assign7 assign7.o Pieces.o
#defining the target for assign7.cc 
assign7.o:assign7.cc assign7.h Pieces.h
	$(cc) -c  $(ccFlags) -std=c++11 assign7.cc
#defining the target for Pieces.cc
Pieces.o:Pieces.cc Pieces.h
	$(cc) -c $(ccFlags) -std=c++11 Pieces.cc
#Pseudo target used to clean the object files and executables
clean:
	rm -f *.o assign7
