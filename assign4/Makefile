assign4: assign4.cc a4-in.txt func.o
	g++ -o assign4 assign4.cc func.o

run:
	./assign4 a4-in.txt a4-out.txt

func.o: func.cc
	g++ -c func.cc

clean:
	-rm *.o assign4 a4-out.txt
