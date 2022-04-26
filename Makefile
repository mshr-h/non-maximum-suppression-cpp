all: nms.hpp
	g++ nms.cpp utils.cpp example.cpp `pkg-config opencv4 --cflags` `pkg-config opencv4 --libs` -std=c++14 -o example

run:
	./example

clean:
	rm -rf example
