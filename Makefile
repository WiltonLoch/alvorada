TARGET = alvorada

SRC_DIR = src
OBJ_DIR = obj

SRC = $(wildcard $(SRC_DIR)/*.cpp)
OBJ = $(SRC:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)

CC = g++
CPPFLAGS = -Iinclude -Ilib/openssl/include/ -I../boost_1_71_0/ -Iutils
CCFLAGS = -Wall
LDFLAGS = 
LDLIBS = -lssl -lcrypto -lboost_serialization


.PHONY: all clean

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(LDFLAGS) $^ $(LDLIBS) -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CC) $(CPPFLAGS) $(CCFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)
