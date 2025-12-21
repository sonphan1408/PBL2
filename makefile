CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -O2

OBJS = main.o \
       Application.o \
       Graph.o \
       Dinic.o \
       Problem1.o \
       Problem2.o \
       Problem3.o \
       Location.o \
       OriginalEdge.o \
       Edge.o

app: $(OBJS)
	$(CXX) $(CXXFLAGS) -o app $(OBJS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f *.o app
