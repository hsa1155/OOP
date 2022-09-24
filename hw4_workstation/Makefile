all:convex.exe

convex.exe:ConvexHull.cpp Line.cpp main.cpp Point.cpp
	g++ -o convex.exe main.cpp

clean:
	rm -rf convex.exe Output_brutal.txt Output_Javis.txt

run:
	chmod +x convex.exe
	./convex.exe
