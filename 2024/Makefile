


.PHONY = all directories clean 01 02 03

all: directories 01 02

directories:
	mkdir -p build


01: directories
	g++ 01/main.cpp -o build/exec01

02: directories
	g++ 02/main.cpp -o build/exec02



clean:
	rm -rf build