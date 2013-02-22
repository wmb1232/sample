#Baron, William
spantree: main.o edges.o cc.o nodes.o minHeap.o 
	g++ -Wall -g -ansi -o spantree nodes.o edges.o cc.o minHeap.o main.o
	
edges.o: edges.cpp edges.h
	g++ -Wall -g -ansi -c edges.cpp
	
nodes.o: nodes.cpp nodes.h
	g++ -Wall -g -ansi -c nodes.cpp
	
cc.o: cc.cpp cc.h
	g++ -Wall -g -ansi -c cc.cpp	
	
minHeap.o: minHeap.cpp minHeap.h
	g++ -Wall -g -ansi -c minHeap.cpp	
		
main.o: main.cpp adjlist.cpp adjlist.h stack.cpp stack.h
	g++ -Wall -g -ansi -c main.cpp

clean:
	rm -f spantree nodes.o edges.o cc.o minHeap.o main.o
