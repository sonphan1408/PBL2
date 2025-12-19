# ====== Makefile SDL2 cho MSYS2 MinGW64 ======

# --------- Trình biên dịch ---------
CXX = g++
CXXFLAGS = -std=c++17 -O2 -Wall

# --------- Đường dẫn đến SDL2 (chỉnh theo thư mục của bạn) ---------
SDL2_INCLUDE = D:/Study/PBL2/SDL2-2.32.8/x86_64-w64-mingw32/include
SDL2_LIB = D:/Study/PBL2/SDL2-2.32.8/x86_64-w64-mingw32/lib

# --------- File nguồn và output ---------
SRC = main.cpp Graph.cpp Dinic.cpp Problem1.cpp Problem2.cpp
OBJ = $(SRC:.cpp=.o)
TARGET = main.exe

# --------- Quy tắc build chính ---------
$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJ) -L$(SDL2_LIB) -lmingw32 -lSDL2main -lSDL2

# --------- Biên dịch từng file .cpp thành .o ---------
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -I$(SDL2_INCLUDE) -c $< -o $@

# --------- Chạy chương trình sau khi build ---------
run: $(TARGET)
	./$(TARGET)

# --------- Dọn file tạm ---------
clean:
	rm -f *.o *.exe

# --------- Đánh dấu các target giả ---------
.PHONY: clean run
