run: main
	./program

main: setup
	g++ -I../include -I. main.cc -o program -L ../lib -ltrx -lz

setup:
	mkdir -p output

clean:
	rm -f ./program
	rm -rf output
