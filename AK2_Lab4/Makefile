all: compile addlib link

compile:
	g++ -o obj/calculator.o -c calculator.cpp
	g++ -o obj/main.o -c main.cpp

addlib:
	ar ruv lib/libcalculator.a obj/calculator.o
	ranlib lib/libcalculator.a

link:
	g++ -o bin/main obj/main.o -lcalculator -Llib

run:
	./bin/main

clean:
	rm bin/**
	rm obj/**
	rm lib/**