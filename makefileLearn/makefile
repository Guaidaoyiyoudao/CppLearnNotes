objects = main.o base.o sub.o
test: ${objects} 
	g++ -o test ${objects}
base.o:
	g++ -c Base.cpp -o base.o 
sub.o:
	g++ -c Sub.cpp -o sub.o
main.o:
	g++ -c main.cpp -o main.o
.PHONY:clean
clean:
	rm ${objects}
