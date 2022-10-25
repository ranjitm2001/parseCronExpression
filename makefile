all:
	g++ src/main.cpp src/accessories/*.cpp -o output

clean:
	rm output