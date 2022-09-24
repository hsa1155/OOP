all:mixed.exe

mixed.exe:main.cpp Mixed.cpp Mixed.h
	g++ -o mixed.exe main.cpp Mixed.cpp

clean:
	rm -rf mixed.exe

run:mixed.exe
	chmod +x mixed.exe
	./mixed.exe