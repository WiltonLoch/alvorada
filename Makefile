TARGET = alvorada

SRC_DIR = src
OBJ_DIR = obj

INCLUDE_DIRS = include lib/openssl/include/ ../boost_1_71_0/ include/utils 

SRC = $(foreach dir, $(SRC_DIR), $(wildcard $(dir)/*.cpp))
OBJ = $(SRC:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)

CC = g++
CPPFLAGS = $(foreach dir, $(INCLUDE_DIRS), -I$(dir)) 
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
