all: compile

run: compile exec clear

compile:
	g++ -std=c++11 -g main.cpp professor.cpp school.cpp -o exe

exec:
	./exe

clear:
	rm exe