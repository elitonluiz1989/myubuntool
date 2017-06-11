EXE := myubuntool

SRC_DIR := src
BUILD_DIR := build
INCLUDES_DIR := ./include
BIN_DIR := bin
DIRS := $(BUILD_DIR) $(BIN_DIR)

SRC := $(wildcard $(SRC_DIR)/*.cpp)
INCLUDES := $(addprefix -I, $(INCLUDES_DIR))
OBJS := $(patsubst $(SRC_DIR)/%.cpp, $(BUILD_DIR)/%.o, $(SRC))
DEPS := $(patsubst $(SRC_DIR)/%.cpp, $(BUILD_DIR)/%.d, $(SRC))
CPPFLAGS := -g -O0 -Wall -o
TARGET:= $(BIN_DIR)/$(EXE)

vpath %.cpp $(SRC_DIR)

all: checkdirs $(TARGET)

checkdirs: $(DIRS)

$(DIRS):
	@mkdir -p $@

$(TARGET): $(OBJS)
	@echo Creating executable: $@
	@g++ -o $@ $^ $(INCLUDES)

$(BUILD_DIR)/%.o: %.cpp
	@echo Compiling object file: $@
	@g++ -c $< $(INCLUDES) $(CPPFLAGS) $@

clean:
	@echo Cleaning
	-rm -f $(BUILD_DIR)/* *~

# To recompile whether wanted
remade:
	$(MAKE) clean
	$(MAKE)

-include $(DEPS)

# For the compiler knows the objects dependencies
$(BUILD_DIR)/%.d: %.cpp
	@g++ $< -MM -MT '$(BUILD_DIR)/$*.o $(BUILD_DIR)/$*.d ' -MD $(INCLUDES) -MF $(addprefix $(BUILD_DIR)/, $(notdir $@))
