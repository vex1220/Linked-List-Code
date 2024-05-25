CC= g++
driver: mydriver.o 
	$(CC) -o driver mydriver.o
mydriver.o: mydriver.cpp
	$(CC) -c mydriver.cpp

