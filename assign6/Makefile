#declaring the variables
cc=g++
ccFLAGS=-Wall
#creating executable assign6
assign6: assign6.o Person.o Name.o Place.o Date.o textCanvas.o
	$(cc) $(ccFLAGS) -o assign6 assign6.o Person.o Name.o Place.o Date.o textCanvas.o
#object file for Person
Person.o: Person.cc Person.h
	$(cc) $(ccFLAGS) -c -std=c++11 Person.cc
#object file for Name
Name.o: Name.cc Name.h
	$(cc) $(ccFLAGS) -c -std=c++11 Name.cc
#object file for Place
Place.o: Place.cc Place.h
	$(cc) $(ccFLAGS) -c -std=c++11 Place.cc
#object file for Date
Date.o: Date.cc Date.h
	$(cc) $(ccFLAGS) -c -std=c++11 Date.cc
#object file for assign6
assign6.o: assign6.cc assign6.h
	$(cc) $(ccFLAGS) -c -std=c++11 assign6.cc
#object file for textCanvas
textCanvas.o: textCanvas.cc textCanvas.h
	$(cc) $(ccFLAGS) -c -std=c++11 textCanvas.cc
#pseudo target to clean object files
clean:
	rm -f *.o assign6 
