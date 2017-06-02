SRC_DIR = src
BUILD_DIR = build
INCLUDES_DIR = ./include

SRC = $(wildcard $(SRC_DIR)/*.cpp)
INCLUDES = -I$(INCLUDES_DIR)
OBJS = $(patsubst $(SRC_DIR)/%.cpp, $(BUILD_DIR)/%.o, $(SRC))
DEPS = $(patsubst $(SRC_DIR)/%.cpp, $(BUILD_DIR)/%.d, $(SRC))

vpath %.cpp $(SRC_DIR)

all: checdirs myubuntool

checdirs: $(BUILD_DIR)

$(BUILD_DIR):
	@mkdir -p $@

myubuntool: $(OBJS)
	@echo Creating executable: $@
	@g++ -o $@ $^ $(INCLUDES)

$(BUILD_DIR)/%.o: %.cpp
	@echo Compiling object file: $@
	@g++ -c $< $(INCLUDES) -o $@

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
	@g++ $< -MM -MT '$*.o $*.d ' -MD $(INCLUDES) -MF $(addprefix $(BUILD_DIR)/, $(notdir $@))
