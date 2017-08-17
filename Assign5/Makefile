#This assignment is done by G.chaithnya Krishna
#Z1815642
#T.A:Nithin Devang
#CSCI 689
#Sec:0001


cc=g++


ccFLAGS=-Wall

#used to generate executable

assign5: assign5.o Class.o


	$(cc) $(ccFLAGS) -o assign5 assign5.o Class.o

#used to generate object file of Class.cc

Class.o: Class.cc Class.h


	$(cc) $(ccFLAGS) -c -std=c++11 Class.cc

#used to generate object file of assign5.cc

assign5.o: assign5.cc Class.h


	$(cc) $(ccFLAGS) -c -std=c++11 assign5.cc

#pseudo target:used to clean the .o files 

clean:

	rm *.o assign5
