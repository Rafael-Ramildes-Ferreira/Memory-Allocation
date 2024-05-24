PROJECT_MAIN := Memory-Allocation
CXX := g++

SRC_DIR := src
INC_DIR := inc
OBJ_DIR := obj
TEST_DIR := test
TEST_SRC_DIR := $(TEST_DIR)/src
TEST_OBJ_DIR := $(TEST_DIR)/obj

FLAGS := -I$(INC_DIR)/

SRC := $(wildcard $(SRC_DIR)/*.cpp)
INC := $(wildcard $(INC_DIR)/*.h $(INC_DIR)/*.hpp)
OBJ := $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SRC))
TEST_SRC := $(wildcard $(TEST_SRC_DIR)/*.cpp)
TEST_OBJ := $(patsubst $(TEST_SRC_DIR)/%.cpp,$(TEST_OBJ_DIR)/%.o,$(TEST_SRC))
TEST := $(patsubst $(TEST_SRC_DIR)/%.cpp,%,$(TEST_SRC))

all: $(PROJECT_MAIN)

$(PROJECT_MAIN): $(OBJ)
	$(CXX) -o $@ $^

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp $(INC) $(OBJ_DIR)
	$(CXX) -o $@ -c $< $(FLAGS)

$(OBJ_DIR):
	mkdir $(OBJ_DIR)

$(TEST): $(TEST_OBJ) $(filter-out obj/main.o, $(OBJ))
	$(CXX) -o $@ $^

$(TEST_OBJ_DIR)/%.o: $(TEST_SRC_DIR)/%.cpp $(INC) $(TEST_OBJ_DIR)
	$(CXX) -o $@ -c $< $(FLAGS)

$(TEST_OBJ_DIR):
	mkdir $(TEST_OBJ_DIR)

clean:
	rm -rf $(OBJ_DIR)
	rm -rf $(TEST_OBJ_DIR)
	rm $(PROJECT_MAIN)
	rm $(TEST)