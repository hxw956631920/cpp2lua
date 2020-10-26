

main:main.o hello.o
	g++ -o main main.o hello.o liblua.a -lpthread

main.o:main.cpp hello.h
	g++ -c -g main.cpp

hello.o:hello.cpp hello.h
	g++ -c -g hello.cpp

clean:
	rm -f *.o
