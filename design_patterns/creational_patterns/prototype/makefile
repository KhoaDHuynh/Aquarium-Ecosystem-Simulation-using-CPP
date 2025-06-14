# ==== MAKEFILE ================================================================
#     Makefile for the project.
# ==============================================================================

# ---- CONFIG ------------------------------------------------------------------
S_SOURE_PATH 	 = src
S_OBJECT_PATH 	 = obj
S_BIN_PATH 		 = bin
S_INCLUDE_PATH 	 = include
C_SRC_EXT 		 = cpp
C_BIN_NAME 		 = main

COMPILER 	    ?= g++
COMPILE_FLAGS    = -Wall #-Wextra -g

# ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-

# ---- REBUILD -----------------------------------------------------------------
# 1. The first step is to find all the source files in the source directory, so-
# rted by most recently modified
SOURCES  = $(shell find $(S_SOURE_PATH) -name '*.$(C_SRC_EXT)' -print| sort -k 1nr | cut -f2-)

# 2. Next, we need to define the object files that will be created from the
# source files. This is done by stripping the source path, replacing the .c
# extension with .o, and prepending the build path
OBJECTS  = $(SOURCES:$(S_SOURE_PATH)/%.$(C_SRC_EXT)=$(S_OBJECT_PATH)/%.o) 

# 3. The last step is to define the dependency files that will be created from
# the object files. This is done by replacing the .o extension with .d
# Set the dependency files that will be used to add header dependencies
DEPENDENCIES = $(shell find $(S_INCLUDE_PATH) -name '*.h' -print| sort -k 1nr | cut -f2-)
# ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-

# ---- MAKEFILE ----------------------------------------------------------------
.PHONY: all clean dirs print_files

all: $(S_BIN_PATH)/$(C_BIN_NAME)
	@echo "\nRunning ..."
	./$(S_BIN_PATH)/$(C_BIN_NAME)

# Link the object files to create the final executable
$(S_BIN_PATH)/$(C_BIN_NAME): dirs $(OBJECTS)
	@echo "\nLinking: $@"
	$(COMPILER) -o $@ $(OBJECTS) $(COMPILE_FLAGS)
	@echo "Files Linked Successfully !"

# Compile the source files into object files
$(S_OBJECT_PATH)/%.o: $(S_SOURE_PATH)/%.$(C_SRC_EXT)
	@echo "\nCompiling: $< -> $@"
	$(COMPILER) -c $< -o $@ $(COMPILE_FLAGS)
	@echo "File Compiled Successfully !"

# Clean the build and bin directories
clean:
	@echo "Cleaning ..."
	@rm -rfv $(S_OBJECT_PATH)
	@rm -rfv $(S_BIN_PATH)

# Print the files in the project
print_files:
	@echo "Sources: $(SOURCES)"
	@echo "Objects: $(OBJECTS)"
	@echo "Dependencies: $(DEPENDENCIES)"

# Create the directories
dirs: 
	@mkdir -p $(S_OBJECT_PATH)
	@mkdir -p $(S_BIN_PATH)
	@echo "Directories created"
# ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-