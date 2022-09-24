all:shape.exe

shape.exe:main.cpp Circle.h Circle.cpp Rectangle.h Rectangle.cpp Shape.h Shape.cpp Triangle.h Triangle.cpp
	g++ -o shape.exe main.cpp Rectangle.cpp Circle.cpp Triangle.cpp Shape.cpp

clean:
	rm -rf shape.exe

run:shape.exe
	chmod +x shape.exe
	./shape.exe