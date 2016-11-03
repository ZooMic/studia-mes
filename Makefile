OPT = -std=c++11
CLASS = Net.o Element.o Node.o
run: clear
	./main
test: main
	rm -rf *.o && ./main
clear: main
	rm -rf *.o && clear
main: main.o $(CLASS)
	g++ main.o $(CLASS) $(OPT) -o main
main.o: main.cpp
	g++ -c main.cpp -o main.o
Net.o:
	g++ -c class/Net.cpp -o Net.o
Element.o:
	g++ -c class/Element.cpp -o Element.o
Node.o:
	g++ -c class/Node.cpp -o Node.o
