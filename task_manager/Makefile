CXX = g++
CXXFLAGS = -Wall -Wextra -Iinclude

SRC_DIR = .
INCLUDE_DIR = include
BUILD_DIR = build
BIN_DIR = bin
SRC = $(wildcard $(SRC_DIR)/*.cpp)
OBJS = $(patsubst $(SRC_DIR)/%.cpp,$(BUILD_DIR)/%.o,$(SRC))
TARGET = $(BIN_DIR)/main

all: $(TARGET)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(TARGET): $(OBJS)
	@mkdir -p $(BIN_DIR)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJS)

clean:
	rm -f $(OBJS) $(TARGET)
