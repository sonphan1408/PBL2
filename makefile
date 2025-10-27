CXX = g++
CXXFLAGS = -std=c++17 -O2 -Wall
OBJS = main.o Dinic.o Graph.o Problem1.o Problem2.o   

main.exe: $(OBJS)
	$(CXX) $(CXXFLAGS) -o main.exe $(OBJS)

main.o: main.cpp Problem1.h Problem2.h Problem.h
	$(CXX) $(CXXFLAGS) -c main.cpp

Problem1.o: Problem1.cpp Problem1.h Problem.h
	$(CXX) $(CXXFLAGS) -c Problem1.cpp

Problem2.o: Problem2.cpp Problem2.h Problem.h
	$(CXX) $(CXXFLAGS) -c Problem2.cpp

Graph.o: Graph.cpp Graph.h Edge.h
	$(CXX) $(CXXFLAGS) -c Graph.cpp

Dinic.o: Dinic.cpp Dinic.h Graph.h MyQueue.h
	$(CXX) $(CXXFLAGS) -c Dinic.cpp

clean:
	del *.o main.exe
