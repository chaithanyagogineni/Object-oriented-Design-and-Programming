#This assignment is done by G.Chaithanya Krishna
#ZID:Z1815642
#CSCI-689
#SEC-1
#DUE-DATE-02/17/2017
#This Makefile will generate the 2 executable 'generate' and 'thresh' and also cleans the executable files generated
cc=g++
ccflags=-Wall
assign3: generate thresh
generate: generate.o
	$(cc) -o generate generate.o
generate.o: generate.cc
	$(cc) $(ccflags) -c  -std=c++11 generate.cc
thresh: thresh.o
	$(cc) -o thresh thresh.o
thresh.o: thresh.cc
	$(cc) $(ccflags) -c -std=c++11 thresh.cc
clean:
	rm -f *.o generate thresh
