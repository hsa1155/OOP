all:a.out hw1.class

a.out:hw1.cpp
	g++ hw1.cpp

hw1.class:hw1.java
	javac hw1.java

clean:
	rm -f a.out hw1.o hw1.class

cleantxt:
	rm -f cpp_result.txt java_result.txt py_result.txt