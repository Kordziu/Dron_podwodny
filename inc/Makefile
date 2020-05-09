CPPFLAGS= -c -g -Wall -pedantic -std=c++17 

__start__: dron_podwodny
	./dron_podwodny.out

dron_podwodny: Dr3D_gnuplot_api.o main.o
	g++ -o dron_podwodny.out main.o Dr3D_gnuplot_api.o -lpthread

main.o: main.cpp
	g++ ${CPPFLAGS} -o main.o main.cpp

Dr3D_gnuplot_api.o: Dr3D_gnuplot_api.cpp
	g++ ${CPPFLAGS} -o Dr3D_gnuplot_api.o Dr3D_gnuplot_api.cpp

clear:
	rm -f *.o dron_podwodny
